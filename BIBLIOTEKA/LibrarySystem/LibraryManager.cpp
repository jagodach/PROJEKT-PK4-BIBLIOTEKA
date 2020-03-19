#include "pch.h"

#include <vector>

#include "Author.h"
#include "Book.h"
#include "EBook.h"
#include "Helpers.h"
#include "LendRecord.h"
#include "LibraryManager.h"
#include "Structs.h"
#include "User.h"

namespace LibrarySystem
{
	LibraryManager::LibraryManager()
	{
		// Sets root path for data saving
		m_datapath = std::filesystem::current_path().string();
		// Make sure that current user is nullptr (it always should be, but better make sure)
		m_currentUser = nullptr;

		// Loads data from files
		loadUsers();
		loadItems();
		loadCurrentLends();
		loadHistoricLends();
		loadAuthors();

		// Connects pointers to id's. In files we only save id of items, after loading we need to connect id's with actuial objects in memory.
		connectData();

		/* We find highest id used in "database" and set it for global highest id. 
		It allows us to almost always (w don't think we will reach uint (32bit) max value) give unique id to new object.
		We don't need to enter id manually.
		*/
		Helpers::SetNextId(FindHighestId());
	}

	LibraryManager::~LibraryManager()
	{
		// Saves all data to files
		saveUsers();
		saveItems();
		saveCurrentLends();
		saveHistoricLends();
		saveAuthors();

		// deallocating memory. We need to do it to avoid leaks
		Helpers::ClearAndDeallocateVector(m_authors);
		Helpers::ClearAndDeallocateVector(m_items);
		Helpers::ClearAndDeallocateVector(m_users);
		Helpers::ClearAndDeallocateVector(m_currentLends);
		Helpers::ClearAndDeallocateVector(m_historyLends);
	}

	bool LibraryManager::LoginUser(std::string username, std::string password)
	{
		/* We use range based loops as they are easier to write and it's  just better to use it.
		We use auto as it's easier. Normally we would need to write object type (in c++ it can be really strange type name).
		We use & to not copy values and operate on references.
		*/
		for (auto& user : m_users)
		{
			// We compare if username and password are correct. Compare returns -1 (lesser), 0 (equal), 1 (bigger)
			if (user->GetUsername().compare(username) == 0 && user->GetPassword().compare(password) == 0)
			{
				m_currentUser = user;
				return true;
			}
		}

		return false;
	}

	const bool LibraryManager::IsAdminLogged() const
	{
		return m_currentUser != nullptr && m_currentUser->IsAdmin();
	}

	Author* LibraryManager::AddAuthor(std::string stringToParse)
	{
		Author* newAuthor = new Author(stringToParse);
		m_authors.push_back(newAuthor);
		return newAuthor;
	}

	std::vector<std::string> LibraryManager::GetAuthorsToPrint()
	{
		return Helpers::ConvertToStringVector(m_authors);
	}

	bool LibraryManager::DeleteAuthor(unsigned int id)
	{
		return Helpers::RemoveIdFromVector(m_authors, id);
	}

	User* LibraryManager::AddUser(std::string stringToParse)
	{
		User* newUser = new User(stringToParse);
		m_users.push_back(newUser);
		return newUser;
	}

	std::vector<std::string> LibraryManager::GetUsersForPrint()
	{
		return Helpers::ConvertToStringVector(m_users);
	}

	User* LibraryManager::GetUser(unsigned int id)
	{
		for (auto& user : m_users)
		{
			if (user->GetId() == id)
			{
				return user;
			}
		}
		return nullptr;
	}

	bool LibraryManager::DeleteUser(unsigned int id)
	{
		return Helpers::RemoveIdFromVector(m_users, id);
	}

	LibraryItem * LibraryManager::AddItem(std::string stringToParse, ItemType itemType)
	{
		LibraryItem* newItem; 
		switch (itemType)
		{
		case ItemType::IT_Book:
			newItem = new Book(stringToParse);
			break;
		case ItemType::IT_EBook:
			newItem = new EBook(stringToParse);
			break;
		default:
			newItem = new LibraryItem(stringToParse);
			break;
		}		
		m_items.push_back(newItem);
		return newItem;
	}

	std::vector<std::string> LibraryManager::GetItemsForPrint()
	{
		return Helpers::ConvertToStringVector(m_items);
	}

	bool LibraryManager::LendItem(unsigned int itemId)
	{
		for (auto& item : m_items)
		{
			// We go for all items and find one with good id and available (if not we can't lend item)
			if (item->GetId() == itemId && item->GetIsAvailable())
			{
				item->LendItem();
				m_currentLends.push_back(new LendRecord(item, m_currentUser));
				return true;
			}
		}

		return false;
	}

	bool LibraryManager::LendItem(unsigned int itemId, class User* lendingUser)
	{
		for (auto& item : m_items)
		{
			// We go for all items and find one with good id and available (if not we can't lend item)
			if (item->GetId() == itemId && item->GetIsAvailable())
			{
				item->LendItem();
				m_currentLends.push_back(new LendRecord(item, lendingUser));
				return true;
			}
		}

		return false;
	}

	bool LibraryManager::DeleteItem(unsigned int id)
	{
		return Helpers::RemoveIdFromVector(m_items, id);
	}

	std::vector<std::string> LibraryManager::GetCurrentLendsForPrint()
	{
		// We get all lends foe admin, for normal user we print only users lends
		if (IsAdminLogged())
		{
			return Helpers::ConvertToStringVector(m_currentLends);
		}
		else
		{
			std::vector<LendRecord*> result;
			for (auto& lend : m_currentLends)
			{
				if (lend->GetUserId() == m_currentUser->GetId())
				{
					result.push_back(lend);
				}
			}
			return Helpers::ConvertToStringVector(result);
		}
	}

	std::vector<std::string> LibraryManager::GetHistoricLendsForPrint()
	{
		// We get all lends foe admin, for normal user we print only users lends
		if (IsAdminLogged())
		{
			return Helpers::ConvertToStringVector(m_historyLends);
		}
		else
		{
			std::vector<LendRecord*> result;
			for (auto& lend : m_historyLends)
			{
				if (lend->GetUserId() == m_currentUser->GetId())
				{
					result.push_back(lend);
				}
			}
			return Helpers::ConvertToStringVector(result);
		}
	}

	bool LibraryManager::ReturnLend(unsigned int lendId, double money)
	{
		// We use iterator, becasue we delete lend from one vector and move it to other vector
		for (auto it = m_currentLends.begin(); it != m_currentLends.end(); ++it)
		{
			if ((*it)->GetId() == lendId && !(*it)->WasReturned())
			{
				if ((*it)->ReturnItem(money))
				{
					//TODO: Check memory leak
					LendRecord* recordToMove = new LendRecord(*(*it));
					m_currentLends.erase(it);
					m_historyLends.push_back(recordToMove);
					return true;
				}
				else
				{
					return false;
				}
			}
		}

		return false;
	}

	bool LibraryManager::DeleteCurrentLend(unsigned int id)
	{
		return Helpers::RemoveIdFromVector(m_currentLends, id);
	}

	void LibraryManager::loadAuthors()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_authorsFileName);
		std::vector<std::string> authorsFileContent = Helpers::ReadFile(Helpers::CombinePath(pathParts));

		for (int i = 0; i < authorsFileContent.size(); ++i)
		{
			std::vector<std::string> splittedLine = Helpers::SplitStringToArray(authorsFileContent[i], ",");
			if (splittedLine.size() > 0)
			{
				AuthorType authorType = Helpers::ConvertAuthorToEnum(splittedLine[1]);
				switch (authorType)
				{
				default:
					m_authors.push_back(new Author(splittedLine));
					break;
				}
			}
		}
	}

	void LibraryManager::saveAuthors()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_authorsFileName);
		Helpers::SaveToCSVFile(m_authors, Helpers::CombinePath(pathParts));
	}

	void LibraryManager::loadUsers()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_usersFileName);
		std::vector<std::string> usersFileContent = Helpers::ReadFile(Helpers::CombinePath(pathParts));

		for (int i = 0; i < usersFileContent.size(); ++i)
		{
			std::vector<std::string> splittedLine = Helpers::SplitStringToArray(usersFileContent[i], ";");
			m_users.push_back(new User(splittedLine));
		}
	}
	void LibraryManager::saveUsers()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_usersFileName);
		Helpers::SaveToCSVFile(m_users, Helpers::CombinePath(pathParts));
	}
	void LibraryManager::loadItems()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_itemsFileName);
		std::vector<std::string> itemsFileContent = Helpers::ReadFile(Helpers::CombinePath(pathParts));

		for (int i = 0; i < itemsFileContent.size(); ++i)
		{
			std::vector<std::string> splittedLine = Helpers::SplitStringToArray(itemsFileContent[i], ";");
			if (splittedLine.size() > 3)
			{
				ItemType itemType = Helpers::ConvertItemToEnum(splittedLine[3]);
				switch (itemType)
				{
				case ItemType::IT_Item:
					m_items.push_back(new Book(splittedLine));
					break;
				case ItemType::IT_Book:
					m_items.push_back(new Book(splittedLine));
					break;
				case ItemType::IT_EBook:
					m_items.push_back(new EBook(splittedLine));
					break;
				default:
					break;
				}
			}
		}
	}
	void LibraryManager::saveItems()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_itemsFileName);
		Helpers::SaveToCSVFile(m_items, Helpers::CombinePath(pathParts));
	}

	void LibraryManager::loadCurrentLends()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_currentLendsFileName);
		std::vector<std::string> lendsFileContent = Helpers::ReadFile(Helpers::CombinePath(pathParts));

		for (int i = 0; i < lendsFileContent.size(); ++i)
			m_currentLends.push_back(new LendRecord(lendsFileContent[i]));
	}

	void LibraryManager::saveCurrentLends()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_currentLendsFileName);
		Helpers::SaveToCSVFile(m_currentLends, Helpers::CombinePath(pathParts));
	}

	void LibraryManager::loadHistoricLends()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_historyLendsFileName);
		std::vector<std::string> lendsFileContent = Helpers::ReadFile(Helpers::CombinePath(pathParts));

		for (int i = 0; i < lendsFileContent.size(); ++i)
			m_historyLends.push_back(new LendRecord(lendsFileContent[i]));
	}

	void LibraryManager::saveHistoricLends()
	{
		std::vector<std::string> pathParts;
		pathParts.push_back(m_datapath);
		pathParts.push_back(m_historyLendsFileName);
		Helpers::SaveToCSVFile(m_historyLends, Helpers::CombinePath(pathParts));
	}

	void LibraryManager::connectData()
	{
		for (auto& lend : m_currentLends)
		{
			for (auto& user : m_users)
			{
				if (user->GetId() == lend->GetUserId())
				{
					lend->BindUser(user);
				}
			}

			for (auto& item : m_items)
			{
				if (item->GetId() == lend->GetItemId())
				{
					lend->BindItem(item);
				}
			}
		}

		for (auto& lend : m_historyLends)
		{
			for (auto& user : m_users)
			{
				if (user->GetId() == lend->GetUserId())
				{
					lend->BindUser(user);
				}
			}

			for (auto& item : m_items)
			{
				if (item->GetId() == lend->GetItemId())
				{
					lend->BindItem(item);
				}
			}
		}
	}

	int LibraryManager::FindHighestId()
	{
		int highestId = -1;
		for (auto& user : m_users)
			highestId = user->GetId() > highestId ? user->GetId() : highestId;
		for (auto& item : m_items)
			highestId = item->GetId() > highestId ? item->GetId() : highestId;
		for (auto& author : m_authors)
			highestId = author->GetId() > highestId ? author->GetId() : highestId;
		for (auto& lend : m_currentLends)
			highestId = lend->GetId() > highestId ? lend->GetId() : highestId;
		for (auto& lend : m_historyLends)
			highestId = lend->GetId() > highestId ? lend->GetId() : highestId;

		return highestId;
	}
}
