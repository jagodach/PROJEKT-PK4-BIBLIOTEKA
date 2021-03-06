#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace LibrarySystem
{
	class Helpers
	{

	public:

		// Generates new id
		static unsigned int GetNextId();
		// Sets start id
		static void SetNextId(unsigned int newId);

		// Splits string to array by given delimeter
		static std::vector<std::string> SplitStringToArray(std::string stringToSplit, std::string delimiter);

		// Combines path from parts
		// Here is used std::filesystem. It's from c++17 (quite new feature). It's much better than other c++ files operations.
		static std::filesystem::path CombinePath(std::vector<std::string> pathComponents);

		// Reads file from location. It needs to be any kind of text file (.txt, .csv, .c, .cpp, etc)
		static std::vector<std::string> ReadFile(std::filesystem::path pathToFile);

		// Template to save FileRecord vector to file.
		// It allows to not read many times the same code - compiler is doing it for us.
		template<class T>
		static void SaveToCSVFile(std::vector<T> recordsToSave, std::filesystem::path pathToFile);
		// Template to convert FileRecords vector to display strings vector.
		template<class T>
		static std::vector<std::string> ConvertToStringVector(std::vector<T> recordsToConver);
		// Template to remove FileRecord from vector.
		// Vector is passed as reference (&) - it means that we pass address for vector and we use the same vector as the one passed (it's the same object, not only copied value)
		template<class T>
		static bool RemoveIdFromVector(std::vector<T>& recordsToConver, int id);

		// String to enum conversions
		static enum AuthorType ConvertAuthorToEnum(std::string enumString);
		static enum ItemType ConvertItemToEnum(std::string enumString);
		static enum UserType ConvertUserTypeToEnum(std::string enumString);

		// Enums to string conversions
		static std::string ConvertEnumToString(ItemType itemType);
		static std::string ConvertEnumToString(AuthorType authorType);
		static std::string ConvertEnumToString(UserType userType);

		// Checks if string ends with specific string. It's helping in parsing - we need to end string with delimiter to make correct split
		static bool HasEnding(std::string const &fullString, std::string const &ending);
	};

	// Template is literally writing the code with different classes. It checks if the syntax is possible at compilation time.
	template<class T>
	void Helpers::SaveToCSVFile(std::vector<T> recordsToSave, std::filesystem::path pathToFile)
	{
		std::ofstream fileToSave(pathToFile);
		
		std::for_each(recordsToSave.begin(), recordsToSave.end(), 
			[&fileToSave](const auto element)
		{
			fileToSave << element->ToCsvRecord() << std::endl;
		});

		fileToSave.close();
	}

	template<class T>
	static std::vector<std::string>
		Helpers::ConvertToStringVector(std::vector<T> recordsToConvert)
	{
		std::vector<std::string> records;

		std::for_each(recordsToConvert.begin(), recordsToConvert.end(), 
			[&records](const auto element)
		{
			records.push_back(element->ToString());
		});

		return records;
	}

	template<class T>
	static bool Helpers::RemoveIdFromVector(std::vector<T>& vector, int id)
	{
		auto beginSize = vector.size();
		vector.erase(std::remove_if(vector.begin(), vector.end(),
			[&vector, &id](const auto element)
		{
			return element->GetId() == id;
		}));

		return beginSize != vector.size();
	}

}

