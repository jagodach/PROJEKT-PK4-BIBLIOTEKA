#pragma once

#include "Structs.h"
#include "User.h"
#include "LibraryItem.h"
#include "FileRecord.h"

namespace LibrarySystem
{
	// Class that represents lend
	class LendRecord : public FileRecord
	{

	private:

		// Date when item was lended
		SimpleDate m_lendDate;
		// Date when item have to be returned
		SimpleDate m_returnDate;
		// Default price to pay for lend
		int m_priceToPay;
		// Id of user that made the lend
		int m_userId;
		// Pointer to user
		std::shared_ptr<User> m_user;
		// Id of lended item
		int m_lendedItemId;
		// Pointer to lended item
		std::shared_ptr<LibraryItem> m_lendedItem;
		// True if lend was returned
		bool m_bWasReturned;


	public:

		// Format: id;dd-mm-yyyy;dd-mm-yyyy;userId;itemId;price;wasReturned
		LendRecord(std::string stringToParse);
		// Creates lend from item and user
		LendRecord(std::shared_ptr<LibraryItem> itemToLend, std::shared_ptr<User> lendingUser);
		~LendRecord();

		// Returns id of user that made the lend
		int GetUserId() const { return m_userId; }
		// Returns Pointer to user
		std::shared_ptr<User> GetUser() const { return m_user; }
		// Returns id of lended item
		int GetItemId() const { return m_lendedItemId; }
		// Returns pointer to item
		std::shared_ptr<LibraryItem> GetItem() const { return m_lendedItem; }
		// Returns m_bWasReturned
		bool WasReturned() const { return m_bWasReturned; }
		// Returns lend date
		SimpleDate GetLendDate() const { return m_lendDate; }
		// Returns return date
		SimpleDate GetReturnDate() const { return m_returnDate; }

		// Binds user pointer to lend
		void BindUser(std::shared_ptr<User> user);
		// Binds item to lend
		void BindItem(std::shared_ptr<LibraryItem> item);

		// Returns how much have to be paid for lend. It contains extra charge for being late with returning the lend
		double  GetLendPrice();
		// Returns lend
		std::shared_ptr<LibraryItem> ReturnItem(double money);

		// Format: id;dd-mm-yyyy;dd-mm-yyyy;userId;itemId;price;wasReturned
		virtual void ParseFromString(std::string string) override;
		// Format: id;dd-mm-yyyy;dd-mm-yyyy;userId;itemId;price;wasReturned
		virtual void ParseFromString(std::vector<std::string> stringVector) override;
		// Converts object to print string
		virtual std::string ToString() override;
		// Converts object to csv format
		virtual std::string ToCsvRecord() override;
	};
}

