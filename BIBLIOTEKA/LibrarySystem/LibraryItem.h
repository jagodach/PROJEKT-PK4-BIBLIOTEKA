#pragma once

#include "FileRecord.h"
#include "Structs.h"

namespace LibrarySystem
{
	// Class that represents library item
	class LibraryItem : public FileRecord
	{

	private:

		// Price to pay for lend
		int m_lendPrice;
		// True if item can be lended
		bool m_bIsAvailable;
		// Item type
		ItemType m_ItemType;
		// Author id
		int m_authorId;
		// Pointer to author
		class Author* m_author;
		// Date when item was created by author
		SimpleDate m_creationDate;
		// Date when item was added to library
		SimpleDate m_addedToLibraryDate;


	public:
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy
		LibraryItem(std::string stringToParse);
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy
		LibraryItem(std::vector<std::string> stringToParse);
		virtual ~LibraryItem();

		// Gets m_bIsAvailable. Const - method doesn't change object
		bool GetIsAvailable() const { return m_bIsAvailable; }
		// Gets m_lendPrice. Const - method doesn't change object
		bool GetLendPrice() const { return m_lendPrice; }
		// Sets object state to lend
		void LendItem();
		// Returns lended item
		void ReturnLendItem();

		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy
		virtual void ParseFromString(std::string string) override;
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy
		virtual void ParseFromString(std::vector<std::string> stringVector) override;
		// Converts object to print string
		virtual std::string ToString() override;
		// Converts object to csv format
		virtual std::string ToCsvRecord() override;

	protected:

		// It's added, because child classes need default constructor
		LibraryItem() {}
	};
}

