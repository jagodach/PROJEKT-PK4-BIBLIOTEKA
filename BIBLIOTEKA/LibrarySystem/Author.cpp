#include "pch.h"

#include <sstream>

#include "Author.h"

namespace LibrarySystem
{
	Author::Author(std::vector<std::string> stringToParse)
	{
		ParseFromString(stringToParse);
	}

	Author::Author(std::string stringToParse)
	{
		ParseFromString(stringToParse);
	}

	Author::~Author()
	{
	}

	void Author::ParseFromString(std::string string)
	{
		ParseFromString(Helpers::SplitStringToArray(string, ","));
	}

	void Author::ParseFromString(std::vector<std::string> stringVector)
	{
		if (stringVector.size() >= 5)
		{
			m_Id = std::atoi(stringVector[0].c_str());
			m_AuthorType = Helpers::ConvertAuthorToEnum(stringVector[1]);
			m_personData = PersonData(std::vector<std::string>(stringVector.begin() + 2, stringVector.begin() + 5));
		}
	}

	std::string Author::ToString()
	{
		std::stringstream stream;
		stream << "Author Id: " << m_Id << ". Name: " << m_personData.m_Name << ", surname: " << m_personData.m_Surname
			<< ". Author birthday: " << m_personData.m_Birthday.ToString() << "[" << m_personData.GetAge() << "]" << ". Author type: " << Helpers::ConvertEnumToString(m_AuthorType);
		return stream.str();
	}

	std::string Author::ToCsvRecord()
	{
		std::stringstream stream;
		stream << m_Id << "," << Helpers::ConvertEnumToString(m_AuthorType) << "," << m_personData.m_Name << "," << m_personData.m_Surname << "," << m_personData.m_Birthday.ToCsvRecord() << ",";
		return stream.str();
	}
}
