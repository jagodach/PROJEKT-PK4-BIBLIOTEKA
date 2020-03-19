#include "pch.h"
#include "Book.h"

namespace LibrarySystem
{
	Book::Book(std::string stringToParse)
	{
		ParseFromString(stringToParse);
	}

	Book::Book(std::vector<std::string> stringToParse)
	{
		ParseFromString(stringToParse);
	}

	Book::~Book()
	{
	}

	void Book::ParseFromString(std::vector<std::string> stringVector)
	{
		if (stringVector.size() >= 8)
		{
			LibraryItem::ParseFromString(stringVector);
			m_releaseVersion = std::atoi(stringVector[7].c_str());
		}
	}

	void LibrarySystem::Book::ParseFromString(std::string string)
	{
		LibraryItem::ParseFromString(string);
	}

	std::string LibrarySystem::Book::ToString()
	{
		// Here string stream is not used as it's not really needed
		return LibraryItem::ToString() + ". Book release version: " + std::to_string(m_releaseVersion);
	}

	std::string LibrarySystem::Book::ToCsvRecord()
	{
		return LibraryItem::ToCsvRecord() + ";" + std::to_string(m_releaseVersion);
	}
}
