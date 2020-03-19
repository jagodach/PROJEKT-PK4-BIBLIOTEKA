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
		User* m_user;
		// Id of lended item
		int m_lendedItemId;
		// Pointer to lended item
		LibraryItem* m_lendedItem;
		// True if lend was returned
		bool m_bWasReturned;


	public:

		// Format: id;dd-mm-yyyy;dd-mm-yyyy;userId;itemId;price;wasReturned
		LendRecord(std::string stringToParse);
		// Creates lend from item and user
		LendRecord(LibraryItem* itemToLend, User* lendingUser);
		~LendRecord();

		// Returns id of user that made the lend
		int GetUserId() const { return m_userId; }
		// Returns id of lended item
		int GetItemId() const { return m_lendedItemId; }
		// Returns m_bWasReturned
		bool WasReturned() const { return m_bWasReturned; }

		// Binds user pointer to lend
		void BindUser(User* user);
		// Binds item to lend
		void BindItem(LibraryItem* item);
		
		// Returns how much have to be paid for lend. It contains extra charge for being late with returning the lend
		double  GetLendPrice();
		// Returns lend
		LibraryItem* ReturnItem(double money);

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

