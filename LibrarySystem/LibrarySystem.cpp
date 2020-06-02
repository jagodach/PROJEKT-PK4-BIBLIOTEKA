// LibrarySystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <vld.h>

#include <iostream>
#include <sstream>
#include <string>

#include "Author.h"
#include "LibraryItem.h"
#include "LibraryManager.h"
#include "User.h"

namespace LibrarySystem::Globals
{
	LibraryManager* LibraryManager;
}

void AddUser(bool bPrintMenuInfo, bool bAddAdmin)
{
	if (bPrintMenuInfo)
	{
		system("cls");
		std::cout << "**USERS MENU**" << std::endl;
	}

	std::cout << "Adding user." << std::endl;

	std::string personDelimiter = ",";
	std::string userDelimiter = ";";
	std::string input;
	std::stringstream userStream;
	// Auto generate item id
	userStream << LibrarySystem::Helpers::GetNextId() << userDelimiter;

	std::cout << "Set user name" << std::endl;
	std::cin >> input;
	userStream << input << personDelimiter;

	std::cout << "Set user surname" << std::endl;
	std::cin >> input;
	userStream << input << personDelimiter;

	std::cout << "Set user birthday [dd-mm-yyyy]" << std::endl;
	std::cin >> input;
	userStream << input << userDelimiter;

	std::cout << "Set username" << std::endl;
	std::cin >> input;
	userStream << input << userDelimiter;

	std::cout << "Set surname" << std::endl;
	std::cin >> input;
	userStream << input << userDelimiter;

	if (bAddAdmin)
	{
		userStream << LibrarySystem::Helpers::ConvertEnumToString(LibrarySystem::UserType::UT_Admin) << userDelimiter;
	}
	else
	{
		std::cout << "Set account type [admin, user]" << std::endl;
		std::cin >> input;
		userStream << input << userDelimiter;
	}

	auto newUser = LibrarySystem::Globals::LibraryManager->AddUser(userStream.str());

	if (newUser != nullptr)
	{
		std::cout << "Added user: " << newUser->ToString() << std::endl;
	}
	else
	{
		std::cout << "Failed to add user" << std::endl;
	}

	std::cout << "Press any button to return" << std::endl;
	std::cin.get();
	std::cin.get();
}

bool UsersMenu(bool bAddAdmin)
{
	int option;
	bool doLoop = true;
	int index;
	std::string input;
	std::vector<std::string> users;

	while (doLoop)
	{
		system("cls");
		std::cout << "**USERS MENU**" << std::endl;
		std::cout << "1. Add user" << std::endl;
		std::cout << "2. View user" << std::endl;
		std::cout << "3. Delete user" << std::endl;
		std::cout << "0. Return" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
			AddUser(true, false);

			break;
		case 2:
			system("cls");
			std::cout << "**USERS MENU**" << std::endl;
			std::cout << "Users:" << std::endl;
			users = LibrarySystem::Globals::LibraryManager->GetUsersForPrint();

			index = 0;
			for (auto& user : users)
			{
				std::cout << user << std::endl;
				++index;
			}

			std::cout << "Press any button to return" << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		case 3:
			system("cls");
			std::cout << "**USERS MENU**" << std::endl;
			std::cout << "Users:" << std::endl;
			users = LibrarySystem::Globals::LibraryManager->GetUsersForPrint();

			index = 0;
			for (auto& user : users)
			{
				std::cout << user << std::endl;
				++index;
			}

			std::cout << "Select index to remove" << std::endl;
			std::cin.get();
			std::cin >> index;

			LibrarySystem::Globals::LibraryManager->DeleteUser(index);

			break;
		case 0:
			return true;
		}
	}

	return false;
}

void AddAuthor(bool bPrintMenuInfo)
{
	system("cls");
	if (bPrintMenuInfo)
	{
		std::cout << "**AUTHORS MENU**" << std::endl;
		std::cout << "Adding author." << std::endl;
	}

	std::string delimiter = ",";
	std::string input;
	std::stringstream authorStream;
	// Auto generate item id
	authorStream << LibrarySystem::Helpers::GetNextId() << delimiter;

	std::cout << "Set author type [author, bookauthor]" << std::endl;
	std::cin >> input;
	authorStream << input << delimiter;

	std::cout << "Set author name" << std::endl;
	std::cin >> input;
	authorStream << input << delimiter;

	std::cout << "Set author surname" << std::endl;
	std::cin >> input;
	authorStream << input << delimiter;

	std::cout << "Set author birthday [dd-mm-yyyy]" << std::endl;
	std::cin >> input;
	authorStream << input << delimiter;

	auto newAuthor = LibrarySystem::Globals::LibraryManager->AddAuthor(authorStream.str());

	if (newAuthor != nullptr)
	{
		std::cout << "Added author: " << newAuthor->ToString() << std::endl;
	}
	else
	{
		std::cout << "Failed to add author" << std::endl;
	}

	std::cout << "Press any button to return" << std::endl;
	std::cin.get();
	std::cin.get();
}

bool AuthorsMenu(bool bAdminView)
{
	int option;
	bool doLoop = true;
	int index;
	std::string input;
	std::vector<std::string> authors;

	while (doLoop)
	{
		system("cls");
		std::cout << "**AUTHORS MENU**" << std::endl;
		if (bAdminView)
		{
			std::cout << "1. Add author" << std::endl;
		}
		std::cout << "2. View authors" << std::endl;
		if (bAdminView)
		{
			std::cout << "3. Delete author" << std::endl;
		}
		std::cout << "0. Return" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
			if (bAdminView)
				AddAuthor(true);

			break;
		case 2:
			system("cls");
			std::cout << "**AUTHORS MENU**" << std::endl;
			std::cout << "Authors:" << std::endl;
			authors = LibrarySystem::Globals::LibraryManager->GetAuthorsToPrint();

			for (auto& author : authors)
			{
				std::cout << author << std::endl;
			}

			std::cout << "Press any button to return" << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		case 3:
			if (bAdminView)
			{
				system("cls");
				std::cout << "**AUTHORS MENU**" << std::endl;
				std::cout << "Authors:" << std::endl;
				authors = LibrarySystem::Globals::LibraryManager->GetUsersForPrint();

				index = 0;
				for (auto& author : authors)
				{
					std::cout << author << std::endl;
					++index;
				}

				std::cout << "Select index to remove" << std::endl;
				std::cin.get();
				std::cin >> index;

				LibrarySystem::Globals::LibraryManager->DeleteAuthor(index);
			}

			break;
		case 0:
			return true;
		}
	}

	return false;
}

void AddItem(bool bPrintMenuInfo)
{
	system("cls");
	if (bPrintMenuInfo)
	{
		std::cout << "**ITEMS MENU**" << std::endl;
		std::cout << "Adding item." << std::endl;
	}

	std::vector<std::string> authors = LibrarySystem::Globals::LibraryManager->GetAuthorsToPrint();

	if (authors.size() > 0)
	{
		int index;
		std::string input;
		std::stringstream itemStream;
		// Auto generate item id
		itemStream << LibrarySystem::Helpers::GetNextId() << ";";

		std::cout << "Set item lend price" << std::endl;
		std::cin >> input;
		itemStream << input << ";";

		// New item is always available
		itemStream << 1 << ";";

		std::cout << "Set item type" << std::endl;
		std::cin >> input;
		itemStream << input << ";";

		LibrarySystem::ItemType itemType;
		itemType = LibrarySystem::Helpers::ConvertItemToEnum(input);

		// TODO: temp Author selection
		for (auto& author : authors)
		{
			std::cout << author << std::endl;
		}
		std::cout << "Select item author" << std::endl;
		std::cin.get();
		std::cin >> index;
		itemStream << index << ";";

		std::cout << "Set item creation date [dd-mm-yyyy]" << std::endl;
		std::cin >> input;
		itemStream << input << ";";

		// Added to library with current date
		itemStream << LibrarySystem::SimpleDate().ToCsvRecord() << ";";

		if (itemType == LibrarySystem::ItemType::IT_Book || itemType == LibrarySystem::ItemType::IT_EBook)
		{
			std::cout << "Set book release version" << std::endl;
			std::cin >> input;
			itemStream << input << ";";
		}

		if (itemType == LibrarySystem::ItemType::IT_EBook)
		{
			std::cout << "Set ebook format" << std::endl;
			std::cin >> input;
			itemStream << input << ";";
		}

		auto newItem = LibrarySystem::Globals::LibraryManager->AddItem(itemStream.str(), itemType);

		if (newItem != nullptr)
		{
			std::cout << "Added item: " << newItem->ToString() << std::endl;
		}
		else
		{
			std::cout << "Failed to add user" << std::endl;
		}
	}
	else
	{
		std::cout << "You can't add item. There are no authors in library." << std::endl;
	}

	std::cout << "Press any button to return" << std::endl;
	std::cin.get();
	std::cin.get();
}

bool ItemsMenu(bool bAdminView)
{
	int option;
	bool doLoop = true;
	int index;
	std::string input;
	std::vector<std::string> items;
	std::vector<std::string> users;

	while (doLoop)
	{
		system("cls");
		std::cout << "**ITEMS MENU**" << std::endl;
		if (bAdminView)
			std::cout << "1. Add item" << std::endl;
		if (bAdminView)
		{
			std::cout << "2. View items" << std::endl;
			std::cout << "3. Delete item" << std::endl;
		}
		std::cout << "4. Lend item" << std::endl;
		std::cout << "0. Return" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
			if (bAdminView)
				AddItem(true);

			break;
		case 2:
			system("cls");
			std::cout << "**ITEMS MENU**" << std::endl;
			std::cout << "Items:" << std::endl;
			items = LibrarySystem::Globals::LibraryManager->GetItemsForPrint();

			for (auto& item : items)
			{
				std::cout << item << std::endl;
			}

			std::cout << "Press any button to return" << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		case 3:
			if (bAdminView)
			{
				system("cls");
				std::cout << "**ITEMS MENU**" << std::endl;
				std::cout << "Items:" << std::endl;
				items = LibrarySystem::Globals::LibraryManager->GetItemsForPrint();

				index = 0;
				for (auto& item : items)
				{
					std::cout << item << std::endl;
					++index;
				}

				std::cout << "Select index to remove" << std::endl;
				std::cin.get();
				std::cin >> index;

				LibrarySystem::Globals::LibraryManager->DeleteItem(index);
			}

			break;
		case 4:

			class LibrarySystem::User* user;
			bool bLended;


			if (!bAdminView)
			{
				bLended = false;
			}
			else
			{
				system("cls");
				std::cout << "**ITEMS MENU**" << std::endl;

				users = LibrarySystem::Globals::LibraryManager->GetUsersForPrint();

				for (auto& userr : users)
				{
					std::cout << userr << std::endl;
				}

				std::cout << "Select lending user" << std::endl;
				std::cin.get();
				std::cin >> index;
				auto user = LibrarySystem::Globals::LibraryManager->GetUser(index);

				system("cls");
				std::cout << "**ITEMS MENU**" << std::endl;
				if (user != nullptr)
				{
					std::cout << "Lending user: " << user->ToString() << std::endl;
					std::cout << "Items:" << std::endl;
					items = LibrarySystem::Globals::LibraryManager->GetItemsForPrint();

					for (auto& item : items)
					{
						std::cout << item << std::endl;
					}

					std::cout << "Select index to lend" << std::endl;
					std::cin.get();
					std::cin >> index;

					if (bAdminView)
					{
						bLended = LibrarySystem::Globals::LibraryManager->LendItem(index, user);
					}
					else
					{
						bLended = LibrarySystem::Globals::LibraryManager->LendItem(index);
					}
				}
			}

			if (bLended)
			{
				std::cout << "Lend successful" << std::endl;
			}
			else
			{
				std::cout << "Lend failed" << std::endl;
			}

			std::cout << "Press any button to return" << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		case 0:
			return true;
		}
	}

	return false;
}

bool LendsMenu(bool bAdminView)
{
	int option;
	bool doLoop = true;
	int index;
	double money;
	std::string input;
	std::vector<std::string> lends;

	while (doLoop)
	{
		system("cls");
		std::cout << "**LENDS MENU**" << std::endl;
		std::cout << "1. View current lends" << std::endl;
		std::cout << "2. View historic lends" << std::endl;
		if (bAdminView)
		{
			std::cout << "3. Return lend" << std::endl;
			std::cout << "4. Delete lend" << std::endl;
		}
		std::cout << "0. Return" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
			system("cls");
			std::cout << "**LENDS MENU**" << std::endl;
			std::cout << "Current lends:" << std::endl;
			lends = LibrarySystem::Globals::LibraryManager->GetCurrentLendsForPrint();

			for (auto& lend : lends)
			{
				std::cout << lend << std::endl;
			}

			std::cout << "Press any button to return" << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		case 2:
			system("cls");
			std::cout << "**LENDS MENU**" << std::endl;
			std::cout << "History lends:" << std::endl;
			lends = LibrarySystem::Globals::LibraryManager->GetHistoricLendsForPrint();

			for (auto& lend : lends)
			{
				std::cout << lend << std::endl;
			}

			std::cout << "Press any button to return" << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		case 3:
			if (bAdminView)
			{
				system("cls");
				std::cout << "**LENDS MENU**" << std::endl;
				std::cout << "Current lends:" << std::endl;
				lends = LibrarySystem::Globals::LibraryManager->GetCurrentLendsForPrint();

				for (auto& lend : lends)
				{
					std::cout << lend << std::endl;
				}

				std::cout << "Select index to return lend" << std::endl;
				std::cin.get();
				std::cin >> index;

				std::cout << "Money paid" << std::endl;
				std::cin.get();
				std::cin >> money;

				if (LibrarySystem::Globals::LibraryManager->ReturnLend(index, money))
				{
					std::cout << "Return lend successful" << std::endl;
				}
				else
				{
					std::cout << "Return lend failed" << std::endl;
				}

				std::cout << "Press any button to return" << std::endl;
				std::cin.get();
				std::cin.get();
			}

			break;
		case 4:
			if (bAdminView)
			{
				system("cls");
				std::cout << "**LENDS MENU**" << std::endl;
				std::cout << "Current lends:" << std::endl;
				lends = LibrarySystem::Globals::LibraryManager->GetCurrentLendsForPrint();

				for (auto& lend : lends)
				{
					std::cout << lend << std::endl;
				}
				std::cout << "Select index to remove" << std::endl;
				std::cin.get();
				std::cin >> index;

				LibrarySystem::Globals::LibraryManager->DeleteCurrentLend(index);
			}

			break;
		case 0:
			return true;
		}
	}

	return false;
}

bool LoginMenu()
{
	bool doLoop = true;
	std::string username = "";
	std::string password = "";
	int option = 0;

	if (LibrarySystem::Globals::LibraryManager->CanLogin())
	{
		while (doLoop)
		{
			system("cls");
			std::cout << "**LOGIN MENU**" << std::endl;
			std::cout << "Enter username: ";
			std::cin >> username;
			std::cout << "Enter password: ";
			std::cin >> password;

			if (LibrarySystem::Globals::LibraryManager->LoginUser(username, password))
			{
				system("cls");
				std::cout << "**LOGIN MENU**" << std::endl;
				std::cout << "Login success: " << username << "! Press any key to continue" << std::endl;
				std::cin.get();
				std::cin.get();

				return true;
			}
			else
			{
				std::cout << "Login failed: " << username << "!" << std::endl;
				std::cout << "1. Try again" << std::endl;
				std::cout << "2. Close application" << std::endl;
				std::cin >> option;
				doLoop = option == 1;

			}
		}
	}
	else
	{
		system("cls");
		std::cout << "No users in database." << std::endl;
		AddUser(false, true);
		return LoginMenu();
	}

	return false;
}

bool MainMenu()
{
	bool bisAdminView = LibrarySystem::Globals::LibraryManager->IsAdminLogged();
	bool doLoop = true;

	while (doLoop)
	{
		system("cls");
		std::cout << "**MAIN MENU**" << std::endl;
		std::cout << "1. Authors management menu" << std::endl;
		std::cout << "2. Items management menu" << std::endl;
		std::cout << "3. Lends management" << std::endl;
		if (bisAdminView)
		{
			std::cout << "4. User management menu" << std::endl;
		}
		std::cout << "0. Exit" << std::endl;

		int option;
		std::cin >> option;

		switch (option)
		{
		case 1:
			AuthorsMenu(bisAdminView);
			break;
		case 2:
			ItemsMenu(bisAdminView);
			break;
		case 3:
			LendsMenu(bisAdminView);
			break;
		case 4:
			if (bisAdminView)
				UsersMenu(bisAdminView);
			break;
		case 0:
			return false;
		}
	}

	return false;
}

int main()
{
	LibrarySystem::Globals::LibraryManager = new LibrarySystem::LibraryManager();

	bool doLoop = LoginMenu();

	while (doLoop)
		doLoop = MainMenu();

	delete LibrarySystem::Globals::LibraryManager;
}
