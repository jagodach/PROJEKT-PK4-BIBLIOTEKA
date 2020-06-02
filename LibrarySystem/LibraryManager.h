#pragma once

#include <vector>

namespace LibrarySystem
{
	// Class that represents library manager. It makes most of logic in app. It holds all data as pointers.
	class LibraryManager
	{
	private:

		// Fields that help to combine path to data files
		// Datapaths root (by default it's directory of .exe file
		std::string m_datapath;
		const std::string m_authorsFileName = "Authors.csv";
		const std::string m_itemsFileName = "Items.csv";
		const std::string m_usersFileName = "Users.csv";
		const std::string m_currentLendsFileName = "CurrentLends.csv";
		const std::string m_historyLendsFileName = "HistoryLends.csv";

		// Currently logged user
		std::shared_ptr<class User> m_currentUser;

		// Vector of author available in library
		std::vector<std::shared_ptr<class Author>> m_authors;
		// Vector of items (books, ebooks, music) available in library
		std::vector<std::shared_ptr<class LibraryItem>> m_items;
		// Vector of users available in library
		std::vector<std::shared_ptr<class User>> m_users;
		// Vector of current lends in library
		std::vector<std::shared_ptr<class LendRecord>> m_currentLends;
		// Vector of historic lends in library
		std::vector<std::shared_ptr<class LendRecord>> m_historyLends;

	public:
		// Default constructor. Loads all data from files, allocates memory and binds data from different files. Initializes start value of Globals::CurrentId
		LibraryManager();
		// Default destructor. Saves all data to file and deallocate memory.
		~LibraryManager();

		// Returns all items
		const std::vector<std::shared_ptr<class LibraryItem>>& GetItems() const { return m_items; }
		// Returns all authors
		const std::vector<std::shared_ptr<class Author>>& GetAuthors() const { return m_authors; }
		// Returns all current lends for all users
		const std::vector<std::shared_ptr<class LendRecord>>& GetAllCurrentLends() const { return m_currentLends; }
		// Returns all current lends for current user
		const std::vector<std::shared_ptr<class LendRecord>> GetCurrentLendsForUser() const;
		// Returns all history lend
		const std::vector<std::shared_ptr<class LendRecord>>& GetHistoryLends() const { return m_historyLends; }
		// Returns all users
		const std::vector<std::shared_ptr<class User>>& GetUsers() const { return m_users; }

		// Checks if any user is in database. It's important so we now if we can make login or we need to create first user (first user must be admin)
		bool CanLogin() { return m_users.size() > 0; }
		// Logins user to manager. Without it, it can't lend. Returns true if user logged. 
		bool LoginUser(std::string userName, std::string password);
		// Return true if admin is logged to manager
		const bool IsAdminLogged() const;

		// Adds new author. Format for author: id;authortype;name,surname,dd-mm-yyyy
		std::shared_ptr<class Author> AddAuthor(std::string stringToParse);
		// Returns vector of authors strings (to print as list in gui)
		std::vector<std::string> GetAuthorsToPrint();
		// Returns pointer to author with given id
		std::shared_ptr<class Author> GetAuthor(unsigned int id);
		// Deletes author with given id
		bool DeleteAuthor(unsigned int id);

		// Adds new user. Format for user: id;name,surname,dd-mm-yyyy;username;password;usertype
		std::shared_ptr<class User> AddUser(std::string stringToParse);
		// Returns vector of users strings (to print as list in gui)
		std::vector<std::string> GetUsersForPrint();
		// Returns pointer to user with given id
		std::shared_ptr<class User> GetUser(unsigned int id);
		// Returns pointer to currently logged user
		std::shared_ptr<class User> GetCurrentUser() { return m_currentUser; }
		// Deletes user with given id
		bool DeleteUser(unsigned int id);

		// Adds new library item. Format for library item: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy
		std::shared_ptr<class LibraryItem> AddItem(std::string stringToParse, enum ItemType itemType);
		// Returns vector of library items strings (to print as list in gui)
		std::vector<std::string> GetItemsForPrint();
		// Lends item with given id
		bool LendItem(unsigned int itemId);
		// Lends item with given id
		bool LendItem(unsigned int itemId, std::shared_ptr<class User> lendingUser);
		// Deletes item with given id
		bool DeleteItem(unsigned int id);

		// Returns vector of current lends strings (to print as list in gui)
		std::vector<std::string> GetCurrentLendsForPrint();
		// Returns vector of historic lends strings (to print as list in gui)
		std::vector<std::string> GetHistoricLendsForPrint();
		// Returns lend and checks if paid money matches lend price
		bool ReturnLend(unsigned int lendId, double money);
		// Deletes item with given id
		bool DeleteCurrentLend(unsigned int id);

	private:

		// Loads authors from file
		void loadAuthors();
		//Saves authors to file
		void saveAuthors();

		// Loads users from file
		void loadUsers();
		// Saves users to file
		void saveUsers();

		// Loads items from file
		void loadItems();
		// Saves items to file
		void saveItems();

		// Loads current lends from file
		void loadCurrentLends();
		//Saves current lends to file
		void saveCurrentLends();

		// Loads historic lends from file
		void loadHistoricLends();
		// Saves historic lends from file
		void saveHistoricLends();

		// Connects pointers to ids in loaded data
		void connectData();

		// Finds highest Id in loaded data
		int FindHighestId();
	};
}

