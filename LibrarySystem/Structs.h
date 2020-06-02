#pragma once

#include <string>
#include <chrono>
#include <ctime>

#include "Helpers.h"
#include "FileRecord.h"

namespace LibrarySystem
{
	// I use IT_,AT_,UT_, because in c++ different enums can't have the same name so the prefix allows to double enum name.

	enum ItemType
	{
		IT_None,
		IT_Item,
		IT_Book,
		IT_EBook,
		IT_Max
	};

	enum AuthorType
	{
		AT_None,
		AT_Author,
		AT_BookAuthor,
		AT_Max
	};

	enum UserType
	{
		UT_None,
		UT_Admin,
		UT_User,
		UT_Max
	};

	// Simple date struct (Struct instead of class as all is public). 
	// In c++ it's the only difference between class and struct. In general structs are used for data storing 
	struct SimpleDate : public FileRecord
	{
		int m_Day;
		int m_Month;
		int m_Year;

		// Creates today's date
		SimpleDate()
		{
			std::time_t time = std::time(0);
			std::tm* localTime = std::localtime(&time);

			m_Day = localTime->tm_mday;
			m_Month = localTime->tm_mon + 1;
			m_Year = localTime->tm_year + 1900;
		}

		//Format: dd-mm-yyyy
		SimpleDate(std::string date)
		{
			m_Day = 0;
			m_Month = 0;
			m_Year = 0;

			ParseFromString(date);
		}

		SimpleDate(int day, int month, int year)
		{
			m_Day = day;
			m_Month = month;
			m_Year = year;
		}

		//Format: dd-mm-yyyy
		virtual void ParseFromString(std::string string) override
		{
			ParseFromString(Helpers::SplitStringToArray(string, "-"));
		}
		//Format: dd-mm-yyyy
		virtual void ParseFromString(std::vector<std::string> stringVector) override
		{
			if (stringVector.size() == 3)
			{
				m_Day = std::min(std::stoi(stringVector[0]), 31);
				m_Month = std::min(std::stoi(stringVector[1]), 12);
				m_Year = std::stoi(stringVector[2]);

				if (!IsValid())
				{
					m_Day = 0;
					m_Month = 0;
					m_Year = 0;
				}
			}
		}
		// Converts object to print string
		virtual std::string ToString() override
		{
			return std::to_string(m_Day) + "-" + std::to_string(m_Month) + "-" + std::to_string(m_Year);
		}
		// Converts object to csv string
		virtual std::string ToCsvRecord() override
		{
			return std::to_string(m_Day) + "-" + std::to_string(m_Month) + "-" + std::to_string(m_Year);
		}

		SimpleDate operator= (SimpleDate dateToSet)
		{
			m_Day = dateToSet.m_Day;
			m_Month = dateToSet.m_Month;
			m_Year = dateToSet.m_Year;
			return *this;
		}
		SimpleDate operator+ (int daysToAdd)
		{
			int day = m_Day + daysToAdd;
			int month = m_Month;
			int year = m_Year;

			while (day > monthDays[month-1])
			{
				day -= monthDays[month-1];
				++month;
				if (month > 12)
				{
					m_Month -= 12;
					++year;
				}
			}

			return SimpleDate(day, month, year);
		}
		bool operator== (const SimpleDate& objectToCompare)
		{
			return m_Day == objectToCompare.m_Day && m_Month == objectToCompare.m_Month && m_Year == objectToCompare.m_Year;
		}
		bool operator< (const SimpleDate& objectToCompare)
		{
			return m_Year < objectToCompare.m_Year
				|| (m_Year == objectToCompare.m_Year
					&& (m_Month < objectToCompare.m_Month || (m_Month == objectToCompare.m_Month && m_Day < objectToCompare.m_Day)));
		}
		bool operator<= (const SimpleDate& objectToCompare)
		{
			return *this == objectToCompare || *this < objectToCompare;
		}

		// Checks if date is valid
		bool IsValid()
		{
			return m_Month <= 12 && m_Day <= monthDays[m_Month - 1] && m_Year <= SimpleDate().m_Year;
		}
		// Gets days from date to now
		int GetDaysToNow()
		{
			SimpleDate today;
			return today.countTotalDays() - countTotalDays();
		}
		// Gets weeks from date to now
		int GetWeeksToNow()
		{
			return GetDaysToNow() / 7;
		}
		// Gets years from date to now
		int GetYerasToNow()
		{
			std::time_t time = std::time(0);
			std::tm* localTime = std::localtime(&time);

			int age = (localTime->tm_year + 1900) - m_Year;
			if (m_Month > (localTime->tm_mon + 1))
				age -= 1;
			else if (m_Month == (localTime->tm_mon + 1) && m_Day > localTime->tm_mday)
				age -= 1;

			return age;
		}

	private:
		// Days in months
		const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
						   31, 31, 30, 31, 30, 31 };
		// Count leap years from 0.0.0000 to date
		int countLeapYears()
		{
			int yearsToCount = m_Year;
			if (m_Month <= 2)
				--yearsToCount;

			return yearsToCount / 4 - yearsToCount / 100 + yearsToCount / 400;
		}
		// Counts total days from 0.0.0000 to date
		int countTotalDays()
		{
			int totalDays = (m_Year - 1) * 365 + m_Day;
			totalDays += countLeapYears();
			for (int i = 0; i < m_Month - 1; i++)
				totalDays += monthDays[i];

			return totalDays;
		}
	};

	// Simple person data struct (Struct instead of class as all is public). 
	// In c++ it's the only difference between class and struct. In general structs are used for data storing 
	struct PersonData : public FileRecord
	{
		std::string m_Name;
		std::string m_Surname;
		SimpleDate m_Birthday;

		PersonData()
		{
			m_Name = "None";
			m_Surname = "None";
			m_Birthday = SimpleDate();
		}

		// Format: name,surname,birthday
		PersonData(std::string personData)
		{
			ParseFromString(personData);
		}
		// Format: name,surname,birthday
		PersonData(std::vector<std::string> personData)
		{
			ParseFromString(personData);
		}
		// Format: name,surname,birthday
		virtual void ParseFromString(std::string string) override
		{
			ParseFromString(Helpers::SplitStringToArray(string, ","));

		}
		// Format: name,surname,birthday
		virtual void ParseFromString(std::vector<std::string> stringVector) override
		{
			if (stringVector.size() == 3)
			{
				m_Name = stringVector[0];
				m_Surname = stringVector[1];
				m_Birthday = SimpleDate(stringVector[2]);
			}
		}
		// Converts object to print string
		virtual std::string ToString() override
		{
			return m_Name + " " + m_Surname + ". Birthday: " + m_Birthday.ToString();
		}
		// Converts object to csv string
		virtual std::string ToCsvRecord() override
		{
			return m_Name + "," + m_Surname + "," + m_Birthday.ToCsvRecord();
		}
		// Returns person age (years)
		int GetAge()
		{
			return m_Birthday.GetYerasToNow();
		}
	};
}