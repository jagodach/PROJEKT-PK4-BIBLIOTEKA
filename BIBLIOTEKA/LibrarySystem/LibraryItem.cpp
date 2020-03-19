#include "pch.h"

#include <sstream>

#include "LibraryItem.h"

namespace LibrarySystem
{
	LibraryItem::LibraryItem(std::string stringToParse)
	{
		ParseFromString(stringToParse);
	}

	LibraryItem::LibraryItem(std::vector<std::string> stringToParse)
	{
		ParseFromString(stringToParse);
	}

	LibraryItem::~LibraryItem()
	{
		// We don't want to do here anything
	}

	void LibraryItem::LendItem()
	{
		m_bIsAvailable = false;
	}

	void LibraryItem::ReturnLendItem()
	{
		m_bIsAvailable = true;
	}

	void LibraryItem::ParseFromString(std::string string)
	{
		ParseFromString(Helpers::SplitStringToArray(string, ";"));
	}

	void LibraryItem::ParseFromString(std::vector<std::string> stringVector)
	{
		if (stringVector.size() >= 7)
		{
			m_Id = std::atoi(stringVector[0].c_str());
			m_lendPrice = std::atoi(stringVector[1].c_str());
			m_bIsAvailable = std::atoi(stringVector[2].c_str()) == 1 ? true : false;
			m_ItemType = Helpers::ConvertItemToEnum(stringVector[3].c_str());
			m_authorId = std::atoi(stringVector[4].c_str());
			m_creationDate = SimpleDate(stringVector[5]);
			m_addedToLibraryDate = SimpleDate(stringVector[6]);
		}
	}

	std::string LibraryItem::ToString()
	{
		// Use string stream as it's easier - don't need to convert numbers
		std::stringstream stream;
		stream << "Item id: " << m_Id << " - " << (m_bIsAvailable ? "is available" : "isn't available") << ". Author: " << m_authorId
			<< ". Created at: " << m_creationDate.ToString();
		return stream.str();
	}
	std::string LibraryItem::ToCsvRecord()
	{	
		// Use string stream as it's easier - don't need to convert numbers
		std::stringstream stream;
		stream << m_Id << ";" << m_lendPrice << ";" << m_bIsAvailable << ";" << Helpers::ConvertEnumToString(m_ItemType) << ";"
			<< m_authorId << ";" << m_creationDate.ToCsvRecord() << ";" + m_addedToLibraryDate.ToCsvRecord();
		return stream.str();
	}
}
