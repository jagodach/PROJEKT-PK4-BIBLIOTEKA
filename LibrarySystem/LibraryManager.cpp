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
	}

	const std::vector<std::shared_ptr<class LendRecord>> LibraryManager::GetCurrentLendsForUser() const
	{
		std::vector<std::shared_ptr<LendRecord>> result;
		/* std::for_each algorithm to iterate over vector with lambda predicate */
		std::for_each(m_currentLends.begin(), m_currentLends.end(),
			[&](const auto& lend) // [values passed to lambda - &: passed 'this'](parameter used in lambda). Use auto as it's just easier (can copy code from other vector and type matches, don't have to deduce type manually)
		{
			if (lend->GetUserId() == m_currentUser->GetId())
			{
				result.push_back(lend);
			}
		});

		return result;
	}

	bool LibraryManager::LoginUser(std::string username, std::string password)
	{
		/* std::find_if algorithm to perform search on vector with lambda predicate */
		auto findResult = std::find_if(m_users.begin(), m_users.end(),
			[&username, &password](const auto& user) // [values passed to lambda](parameter used in lambda)
		{
			// Lambda body - condition
			return user->GetUsername().compare(username) == 0 && user->GetPassword().compare(password) == 0;
		});

		// Compare result with vector.end(). If it's different then we need to get element. Find if returns iterator.
		if (findResult != m_users.end())
		{
			m_currentUser = *findResult;
			return true;
		}

		return false;
	}

	const bool LibraryManager::IsAdminLogged() const
	{
		return m_currentUser != nullptr && m_currentUser->IsAdmin();
	}

	std::shared_ptr<Author> LibraryManager::AddAuthor(std::string stringToParse)
	{
		auto newAuthor = std::make_shared<Author>(stringToParse);
		m_authors.push_back(newAuthor);
		return newAuthor;
	}

	std::vector<std::string> LibraryManager::GetAuthorsToPrint()
	{
		return Helpers::ConvertToStringVector(m_authors);
	}

	std::shared_ptr<class Author> LibraryManager::GetAuthor(unsigned int id)
	{
		auto findResult = std::find_if(m_authors.begin(), m_authors.end(),
			[&id](const auto author)
		{
			return author->GetId() == id;
		});

		return findResult != m_authors.end() ? *findResult : nullptr;
	}

	bool LibraryManager::DeleteAuthor(unsigned int id)
	{
		return Helpers::RemoveIdFromVector(m_authors, id);
	}

	std::shared_ptr<User> LibraryManager::AddUser(std::string stringToParse)
	{
		auto newUser = std::make_shared<User>(stringToParse);
		m_users.push_back(newUser);
		return newUser;
	}

	std::vector<std::string> LibraryManager::GetUsersForPrint()
	{
		return Helpers::ConvertToStringVector(m_users);
	}

	std::shared_ptr<User> LibraryManager::GetUser(unsigned int id)
	{
		auto findResult = std::find_if(m_users.begin(), m_users.end(),
			[&id](const auto u)
		{
			return u->GetId() == id;
		});

		return findResult != m_users.end() ? *findResult : nullptr;
	}

	bool LibraryManager::DeleteUser(unsigned int id)
	{
		return Helpers::RemoveIdFromVector(m_users, id);
	}

	std::shared_ptr<LibraryItem> LibraryManager::AddItem(std::string stringToParse, ItemType itemType)
	{
		std::shared_ptr<LibraryItem> newItem;
		switch (itemType)
		{
		case ItemType::IT_Book:
			newItem = std::make_shared<Book>(stringToParse);
			break;
		case ItemType::IT_EBook:
			newItem = std::make_shared<EBook>(stringToParse);
			break;
		default:
			newItem = std::make_shared<LibraryItem>(stringToParse);
			break;
		}

		newItem->BindAuthor(GetAuthor(newItem->GetAuthorId()));

		m_items.push_back(newItem);
		return newItem;
	}

	std::vector<std::string> LibraryManager::GetItemsForPrint()
	{
		return Helpers::ConvertToStringVector(m_items);
	}

	bool LibraryManager::LendItem(unsigned int itemId)
	{
		return LendItem(itemId, m_currentUser);
	}

	bool LibraryManager::LendItem(unsigned int itemId, std::shared_ptr<class User> lendingUser)
	{
		auto findResult = std::find_if(m_items.begin(), m_items.end(),
			[&itemId](const auto i)
		{
			return i->GetId() == itemId && i->GetIsAvailable();
		});

		if (findResult != m_items.end())
		{
			(*findResult)->LendItem();
			m_currentLends.push_back(std::make_shared<LendRecord>((*findResult), lendingUser));
			return true;
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

		return Helpers::ConvertToStringVector(GetCurrentLendsForUser());
	}

	std::vector<std::string> LibraryManager::GetHistoricLendsForPrint()
	{
		// We get all lends foe admin, for normal user we print only users lends
		if (IsAdminLogged())
		{
			return Helpers::ConvertToStringVector(m_historyLends);
		}

		std::vector<std::shared_ptr<LendRecord>> result;
		std::for_each(m_historyLends.begin(), m_historyLends.end(),
			[&](auto l) {
			if (l->GetUserId() == m_currentUser->GetId())
			{
				result.push_back(l);
			}});

		return Helpers::ConvertToStringVector(result);
	}

	bool LibraryManager::ReturnLend(unsigned int lendId, double money)
	{
		// We use iterator, becasue we delete lend from one vector and move it to other vector
		for (auto it = m_currentLends.begin(); it != m_currentLends.end(); ++it)
		{
			if ((*it)->GetId() == lendId && !(*it)->WasReturned())
			{
				// Inverted if so we can avoid extra indent
				if (!(*it)->ReturnItem(money))
				{
					return false;
				}

				auto recordToMove = std::make_shared<LendRecord>(*(*it));
				m_currentLends.erase(it);
				m_historyLends.push_back(recordToMove);
				return true;
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

		std::for_each(authorsFileContent.begin(), authorsFileContent.end(),
			[&](auto line) {
			std::vector<std::string> splittedLine = Helpers::SplitStringToArray(line, ";");
			if (splittedLine.size() > 0)
			{
				AuthorType authorType = Helpers::ConvertAuthorToEnum(splittedLine[1]);
				switch (authorType)
				{
				default:
					m_authors.push_back(std::make_shared<Author>(splittedLine));
					break;
				}
			}});
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

		std::for_each(usersFileContent.begin(), usersFileContent.end(),
			[&](auto line) {
			std::vector<std::string> splittedLine = Helpers::SplitStringToArray(line, ";");
			m_users.push_back(std::make_shared<User>(splittedLine));
		});
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

		for (auto& line : itemsFileContent)
		{
			std::vector<std::string> splittedLine = Helpers::SplitStringToArray(line, ";");
			if (splittedLine.size() > 3)
			{
				ItemType itemType = Helpers::ConvertItemToEnum(splittedLine[3]);
				switch (itemType)
				{
				case ItemType::IT_Item:
					m_items.push_back(std::make_shared<Book>(splittedLine));
					break;
				case ItemType::IT_Book:
					m_items.push_back(std::make_shared<Book>(splittedLine));
					break;
				case ItemType::IT_EBook:
					m_items.push_back(std::make_shared<EBook>(splittedLine));
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

		std::for_each(lendsFileContent.begin(), lendsFileContent.end(),
			[&](auto line) {
			m_currentLends.push_back(std::make_shared<LendRecord>(line));
		});
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

		std::for_each(lendsFileContent.begin(), lendsFileContent.end(),
			[&](auto line) {
			m_historyLends.push_back(std::make_shared<LendRecord>(line));
		});
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
		for (auto& item : m_items)
		{
			for (auto& author : m_authors)
			{
				if (item->GetAuthorId() == author->GetId())
				{
					item->BindAuthor(author);
					break;
				}
			}
		}

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
