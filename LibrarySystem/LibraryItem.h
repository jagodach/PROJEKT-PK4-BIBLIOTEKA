#pragma once

#include "FileRecord.h"
#include "Structs.h"
#include "Author.h"

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
		std::shared_ptr<class Author> m_author;
		// Date when item was created by author
		SimpleDate m_creationDate;
		// Date when item was added to library
		SimpleDate m_addedToLibraryDate;
		// Name/description of item
		std::string m_name;


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
		// Gets m_ItemType. Const - method doesn't change object
		ItemType GetItemType() const { return m_ItemType; }
		// Gets author full name. Const - method doesn't change object. It's made this way so we don't need to check author pointer outside this class
		std::string GetAuthorName() const { return m_author != nullptr ? m_author->GetFullName() : "None"; }
		// Gets m_authorId. Const - method doesn't change object
		int GetAuthorId() { return m_authorId; }
		// Gets m_creationDate. Const - method doesn't change object
		SimpleDate GetCreationDate() const { return m_creationDate; }
		// Gets m_name. Const - method doesn't change object
		std::string GetItemName() { return m_name; }
		// Sets object state to lend
		void LendItem();
		// Returns lend item
		void ReturnLendItem();

		// Binds author to item
		void BindAuthor(std::shared_ptr<Author> user);

		// Returns item description.
		virtual std::string GetDescription();

		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;name
		virtual void ParseFromString(std::string string) override;
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;name
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

