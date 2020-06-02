#include "pch.h"
#include "EBook.h"

namespace LibrarySystem
{
	EBook::EBook(std::string stringToParse)
	{
		ParseFromString(stringToParse);
	}

	EBook::EBook(std::vector<std::string> stringToParse)
	{
		ParseFromString(stringToParse);
	}

	EBook::~EBook()
	{

	}

	void EBook::ParseFromString(std::string string)
	{
		Book::ParseFromString(string);
	}

	void EBook::ParseFromString(std::vector<std::string> stringVector)
	{
		if (stringVector.size() >= 11)
		{
			Book::ParseFromString(stringVector);
			m_format = stringVector[10];
		}
	}

	std::string EBook::ToString()
	{
		return Book::ToString() + ". EBook format: " + m_format;
	}

	std::string EBook::ToCsvRecord()
	{
		return Book::ToCsvRecord() + ";" + m_format;
	}

}