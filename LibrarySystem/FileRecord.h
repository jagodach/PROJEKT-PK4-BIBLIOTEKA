#pragma once

#include <string>
#include <vector>

namespace LibrarySystem
{
	// Base class for all objects that are saved to file. It's abstract class - don't have all implementations.
	// It's some way of making interfaces in C++ (but have field inside so it isn't normal interface)
	// Using this class makes all data loading and saving easier
	class FileRecord
	{

	protected:

		// Object id - it should be unique in database
		unsigned int m_Id;

	public:

		// Returns object id
		int GetId() const { return m_Id; }

		// Pure virtual, it doesn't have any implementation. It should parse object fields from string
		virtual void ParseFromString(std::string string) = 0;
		// Pure virtual, it doesn't have any implementation. It should parse object fields from string
		virtual void ParseFromString(std::vector<std::string> stringVector) = 0;
		// Pure virtual, it doesn't have any implementation. It create print string of object
		virtual std::string ToString() = 0;
		// Pure virtual, it doesn't have any implementation. It create csv format of object 
		// (it's not really important, but using standard for data saving makes reading easier)
		virtual std::string ToCsvRecord() = 0;
	};
}

