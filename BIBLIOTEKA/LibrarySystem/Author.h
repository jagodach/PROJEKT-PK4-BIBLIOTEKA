#pragma once

#include "FileRecord.h"
#include "Structs.h"

namespace LibrarySystem
{
	// Class that represents item author
	class Author : public FileRecord
	{

	private:

		// Author type
		AuthorType m_AuthorType;
		// Author person data
		PersonData m_personData;

	public:

		// Format: id;authortype;name,surname,dd-mm-yyyy
		Author(std::vector<std::string> stringToParse);
		// Format: id;authortype;name,surname,dd-mm-yyyy
		Author(std::string stringToParse);
		virtual ~Author();

		// Format: id;authortype;name,surname,dd-mm-yyyy
		virtual void ParseFromString(std::string string) override;
		// Format: id;authortype;name,surname,dd-mm-yyyy
		virtual void ParseFromString(std::vector<std::string> stringVector) override;
		// Converts object to print string
		virtual std::string ToString() override;
		// Converts object to csv format
		virtual std::string ToCsvRecord() override;

	protected:

		// It's added, because child classes need default constructor
		Author() {}
	};

}
