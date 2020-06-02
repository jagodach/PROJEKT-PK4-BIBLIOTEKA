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

		// Returns author full name for printing in format: 'name surname'
		std::string GetFullName() const { return m_personData.m_Name + " " + m_personData.m_Surname; }
		// Returns m_personData
		PersonData GetPersonData() const { return m_personData; }
		// Returns m_AuthorType
		AuthorType GetAuthorType() const { return m_AuthorType; }

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
