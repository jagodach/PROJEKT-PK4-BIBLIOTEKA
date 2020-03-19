#pragma once

#include "Structs.h"

namespace LibrarySystem
{
	// Class that represents user
	class User : public FileRecord
	{

	private:

		// User person data
		PersonData m_personData;
		// Username
		std::string m_username;
		// Password
		std::string m_password;
		// Type of user
		UserType m_userType;

	public:
		
		// Format: id;name,surname,birthday;username;password;usertype;
		User(std::string stringToParse);
		// Format: id;name,surname,birthday;username;password;usertype;
		User(std::vector<std::string> stringToParse);
		~User();

		// Returns username
		std::string GetUsername() const { return m_username; }
		// Returns password
		std::string GetPassword() const { return m_password; }
		// Returns if user is admin
		bool IsAdmin() const { return m_userType == UserType::UT_Admin; }

		// Format: id;name,surname,birthday;username;password;usertype;
		virtual void ParseFromString(std::string string) override;
		// Format: id;name,surname,birthday;username;password;usertype;
		virtual void ParseFromString(std::vector<std::string> stringVector) override;
		// Converts object to print string
		virtual std::string ToString() override;
		// Converts object to csv format
		virtual std::string ToCsvRecord() override;
	};
}

