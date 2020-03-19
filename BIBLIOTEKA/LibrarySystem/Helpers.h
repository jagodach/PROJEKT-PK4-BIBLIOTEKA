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
		template<class T>
		static void ClearAndDeallocateVector(std::vector<T>& vector);

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
		
		for (auto& record : recordsToSave)
		{
			fileToSave << record->ToCsvRecord() << std::endl;
		}

		fileToSave.close();
	}

	template<class T>
	static std::vector<std::string>
		Helpers::ConvertToStringVector(std::vector<T> recordsToConver)
	{
		std::vector<std::string> records;

		for (auto& record : recordsToConver)
		{
			records.push_back(record->ToString());
		}

		return records;
	}

	template<class T>
	static bool Helpers::RemoveIdFromVector(std::vector<T>& recordsToConver, int id)
	{
		/* Here we use iterator loop, because it's better for this case. To erase we need position of element in vector - iterator it is.
		 We use auto, writing iterator type is not fun ;) -> std::Vector<Author*>::iterator or auto - choice is simple
		*/
		for (auto it = recordsToConver.begin(); it != recordsToConver.end(); ++it)
		{
			if ((*it)->GetId() == id)
			{
				delete (*it);
				recordsToConver.erase(it);
				// We need to return after erase - you can't remove item and iterater forward for loop.
				return true;
			}
		}
		return false;
	}

	template<class T>
	void Helpers::ClearAndDeallocateVector(std::vector<T>& vector)
	{
		for (auto v : vector)
			delete v;
		vector.clear();
	}

}

