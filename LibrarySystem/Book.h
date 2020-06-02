#pragma once

#include "LibraryItem.h"

namespace LibrarySystem
{
	// Class that represents book
	class Book : public LibraryItem
	{

	private:

		// Release verion of the book
		int m_releaseVersion;

	public:

		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release
		Book(std::string stringToParse);
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release
		Book(std::vector<std::string> stringToParse);
		virtual ~Book();

		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release
		virtual void ParseFromString(std::string string) override;
		// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;release
		virtual void ParseFromString(std::vector<std::string> stringVector) override;
		// Converts object to print string
		virtual std::string ToString() override;
		// Converts object to csv format
		virtual std::string ToCsvRecord() override;

	protected:

		// It's added, because child classes need default constructor
		Book() {}
	};
}

