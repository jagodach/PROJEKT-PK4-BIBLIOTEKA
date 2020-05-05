#include "pch.h"

#include <sstream>

#include "User.h"

namespace LibrarySystem
{
	User::User(std::vector<std::string> stringToParse)
	{
		ParseFromString(stringToParse);
	}

	User::User(std::string stringToParse)
	{
		ParseFromString(stringToParse);
	}

	User::~User()
	{
	}

	void User::ParseFromString(std::string string)
	{
		ParseFromString(Helpers::SplitStringToArray(string, ";"));

	}

	void User::ParseFromString(std::vector<std::string> stringVector)
	{
		if (stringVector.size() == 5)
		{
			m_Id = std::atoi(stringVector[0].c_str());
			m_personData = PersonData(stringVector[1]);
			m_username = stringVector[2];
			m_password = stringVector[3];
			m_userType = Helpers::ConvertUserTypeToEnum(stringVector[4]);
		}
	}

	std::string User::ToString()
	{
		std::stringstream stream;
		stream << "User id: " << m_Id << ". Username: " << m_username << ". Password: " << m_password << ". Person data: " + m_personData.ToString()
			<< (m_userType == UserType::UT_Admin ? ". User is admin." : "");
		return stream.str();
	}

	std::string User::ToCsvRecord()
	{
		std::stringstream stream;
		stream << m_Id << ";" << m_personData.ToCsvRecord() << ";" + m_username << ";" + m_password << ";" + Helpers::ConvertEnumToString(m_userType);
		return stream.str();
	}
}
