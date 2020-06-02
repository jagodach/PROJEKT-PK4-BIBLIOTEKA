#include "pch.h"

#include <sstream>

#include "LendRecord.h"

namespace LibrarySystem
{
	LendRecord::LendRecord(std::string stringToParse)
	{
		ParseFromString(stringToParse);
	}

	LendRecord::LendRecord(std::shared_ptr<LibraryItem> itemToLend, std::shared_ptr<User> lendingUser)
	{
		// Generete new id for object
		m_Id = Helpers::GetNextId();
		// Lend date as today
		m_lendDate = SimpleDate();
		// Return date is today + 7 days
		m_returnDate = m_lendDate + 7;
		if (lendingUser != nullptr)
		{
			m_userId = lendingUser->GetId();
		}
		m_user = lendingUser;
		// Standard price is 5
		m_priceToPay = 5;
		if (itemToLend != nullptr)
		{
			m_lendedItemId = itemToLend->GetId();
			m_priceToPay = itemToLend->GetLendPrice();
		}
		m_lendedItem = itemToLend;
		m_bWasReturned = false;
	}

	LendRecord::~LendRecord()
	{
	}

	void LendRecord::BindUser(std::shared_ptr<User> user)
	{
		m_user = user;
	}

	void LendRecord::BindItem(std::shared_ptr<LibraryItem> item)
	{
		m_lendedItem = item;
	}

	double LendRecord::GetLendPrice()
	{
		SimpleDate today;

		// If today's date is earlier than return date - we only charge standard price
		if (today <= m_returnDate)
		{
			return m_priceToPay;
		}
		// Else we charge standard price + 10% of the price for every week 
		else
		{
			return m_priceToPay + ((double)m_priceToPay / 10) * m_returnDate.GetWeeksToNow();
		}
	}

	std::shared_ptr<LibraryItem> LendRecord::ReturnItem(double money)
	{
		// Check if user paid enough money to return the lend
		if (money >= GetLendPrice())
		{
			if (m_lendedItem)
			{
				m_lendedItem->ReturnLendItem();
			}
			return m_lendedItem;
		}
		else
		{
			return nullptr;
		}
	}

	void LendRecord::ParseFromString(std::string string)
	{
		ParseFromString(Helpers::SplitStringToArray(string, ";"));
	}

	void LendRecord::ParseFromString(std::vector<std::string> stringVector)
	{
		if (stringVector.size() == 7)
		{
			m_Id = std::atoi(stringVector[0].c_str());
			m_lendDate = SimpleDate(stringVector[1]);
			m_returnDate = SimpleDate(stringVector[2]);
			m_userId = std::atoi(stringVector[3].c_str());
			m_lendedItemId = std::atoi(stringVector[4].c_str());
			m_priceToPay = std::atoi(stringVector[5].c_str());
			m_bWasReturned = std::atoi(stringVector[6].c_str()) == 1 ? true : false;
		}
	}

	std::string LendRecord::ToString()
	{
		std::stringstream stream;
		if (m_user != nullptr && m_lendedItem != nullptr)
		{
			stream << "Lend Id: " << m_Id << ". Lend on: " << m_lendDate.ToString() << " by user: " << m_user->GetUsername()
				<< ". Item: " << m_lendedItem->ToString() << (m_bWasReturned ? ". Was returned" : (". Wasn't returned. Return date: "
					+ m_returnDate.ToString() + ". Price to pay: " + std::to_string(GetLendPrice())));
		}
		// It can happen if item or user were removed from database
		else
		{
			stream << "Lend Id: " << m_Id << ". Lend on: " << m_lendDate.ToString() << " by user: " << m_userId
				<< ". Item: " << m_lendedItemId << (m_bWasReturned ? ". Was returned" : (". Wasn't returned. Price to pay: " + std::to_string(GetLendPrice())));
		}

		return stream.str();
	}

	std::string LendRecord::ToCsvRecord()
	{
		std::stringstream stream;
		stream << m_Id << ";" << m_lendDate.ToCsvRecord() << ";" << m_returnDate.ToCsvRecord() << ";" << m_userId << ";" << m_lendedItemId << ";"
			<< m_priceToPay << ";" << m_bWasReturned;
		return stream.str();
	}

}
