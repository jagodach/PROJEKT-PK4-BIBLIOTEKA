#include "pch.h"

#include <algorithm>
#include <cstdarg>

#include "Helpers.h"
#include "Structs.h"
#include "FileRecord.h"

namespace LibrarySystem
{
	// Static variable is created once per file. It's here because we are doing here operations on it. 
	// Later value is copied and returned to the place that requested it.
	namespace Globals
	{
		static int CurrentId = 0;
	}

	// ++variable - preincrementation. Increments value and returns it.
	// variable++ - postincrementation. Returns value and increments it.
	unsigned int Helpers::GetNextId()
	{
		return ++Globals::CurrentId;
	}

	void Helpers::SetNextId(unsigned int newId)
	{
		Globals::CurrentId = newId;
	}

	std::vector<std::string> LibrarySystem::Helpers::SplitStringToArray(std::string stringToSplit, std::string delimiter)
	{
		stringToSplit.erase(std::remove_if(stringToSplit.begin(), stringToSplit.end(), isspace), stringToSplit.end());

		// Adds delimeter to ending if it's missing. If there is no delimiter at the end - we won't get the last element from string.
		if (!HasEnding(stringToSplit, delimiter))
		{
			stringToSplit += delimiter;
		}

		std::vector<std::string> resultArray;

		// asa;asafas

		size_t position = 0;
		std::string token;
		// position = place of ;
		while ((position = stringToSplit.find(delimiter)) != std::string::npos)
		{
			// string from 0 to ;
			token = stringToSplit.substr(0, position);
			// save string
			resultArray.push_back(token);
			// remove string from 0 to ; + length of ; (asa; removed -> asafas left)
			stringToSplit.erase(0, position + delimiter.length());
		}

		return resultArray;
	}

	std::filesystem::path LibrarySystem::Helpers::CombinePath(std::vector<std::string> pathComponents)
	{
		std::filesystem::path resultPath = "";
		for (auto iterator = pathComponents.begin(); iterator != pathComponents.end(); ++iterator)
		{
			resultPath = resultPath / (*iterator).c_str();
		}
		return resultPath;
	}

	std::vector<std::string> LibrarySystem::Helpers::ReadFile(std::filesystem::path pathToFile)
	{
		std::vector<std::string> fileContent;

		std::ifstream file(pathToFile);
		if (file.is_open())
		{
			std::string line;
			while (getline(file, line))
			{
				fileContent.push_back(line);
			}
			file.close();
		}

		return fileContent;
	}

	AuthorType LibrarySystem::Helpers::ConvertAuthorToEnum(std::string enumString)
	{
		std::transform(enumString.begin(), enumString.end(), enumString.begin(), ::tolower);

		if (enumString == "none") return AuthorType::AT_None;
		if (enumString == "author") return AuthorType::AT_Author;
		if (enumString == "bookauthor") return AuthorType::AT_BookAuthor;
		else return AuthorType::AT_Max;
	}

	ItemType Helpers::ConvertItemToEnum(std::string enumString)
	{
		std::transform(enumString.begin(), enumString.end(), enumString.begin(), ::tolower);

		if (enumString == "none") return ItemType::IT_None;
		if (enumString == "item") return ItemType::IT_Item;
		if (enumString == "book") return ItemType::IT_Book;
		if (enumString == "ebook") return ItemType::IT_EBook;
		else return ItemType::IT_Max;
	}

	enum UserType Helpers::ConvertUserTypeToEnum(std::string enumString)
	{
		std::transform(enumString.begin(), enumString.end(), enumString.begin(), ::tolower);

		if (enumString == "none") return UserType::UT_None;
		if (enumString == "admin") return UserType::UT_Admin;
		if (enumString == "user") return UserType::UT_User;
		else return UserType::UT_Max;
	}

	bool Helpers::HasEnding(std::string const & fullString, std::string const & ending)
	{
		if (fullString.length() >= ending.length()) 
		{
			// Compares if last chars [amount of chars is equal to ending length] of string are equal to given ending
			return (fullString.compare(fullString.length() - ending.length(), ending.length(), ending) == 0);
		}
		else 
		{
			return false;
		}
	}
	std::string Helpers::ConvertEnumToString(ItemType itemType)
	{
		switch (itemType)
		{
		case ItemType::IT_None: return "none";
		case ItemType::IT_Item: return "item";
		case ItemType::IT_Book: return "book";
		case ItemType::IT_EBook: return "ebook";
		default: return "max";
		}
	}

	std::string Helpers::ConvertEnumToString(AuthorType authorType)
	{
		switch (authorType)
		{
		case AuthorType::AT_None: return "none";
		case AuthorType::AT_Author: return "author";
		case AuthorType::AT_BookAuthor: return "bookauthor";
		default: return "max";
		}
	}

	std::string Helpers::ConvertEnumToString(UserType userType)
	{
		switch (userType)
		{
		case UserType::UT_None: return "none";
		case UserType::UT_Admin: return "admin";
		case UserType::UT_User: return "user";
		default: return "max";
		}
	}

} //LibrarySystem
