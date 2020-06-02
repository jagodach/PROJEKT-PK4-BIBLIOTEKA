#include "QtLibrarySystem.h"
#include "QtLoginWIndow.h"
#include "QtAddUserWindow.h"
#include "LibraryItem.h"
#include "LendRecord.h"
#include "Helpers.h"
#include "QtAddAuthorWindow.h"
#include "QtAddItemWindow.h"
#include "QInputDialog.h"
#include "QMessageBox"
#include <sstream>

namespace LibrarySystem::UI
{
	QtLibrarySystem::QtLibrarySystem(QWidget *parent)
		: QMainWindow(parent)
	{
		m_ui.setupUi(this);

		// Create LibraryManager
		m_libraryManager = std::make_unique<LibraryManager>();

		auto logged = false;
		// Show login window as login as user is logging
		while (!logged)
		{
			// Check if user can log - if there are no users, show dialog to add user
			if (m_libraryManager->CanLogin())
			{
				auto loginWindow = std::make_unique<QtLoginWIndow>(this);

				if (loginWindow->exec() == QDialog::Rejected)
				{
					close();
					return;
				}

				logged = m_libraryManager->LoginUser(loginWindow->GetUser(), loginWindow->GetPassword());
			}
			else
			{
				auto addUserWindow = std::make_unique<QtAddUserWindow>(this);

				if (addUserWindow->exec() == QDialog::Accepted)
				{
					m_libraryManager->AddUser(addUserWindow->GetObjectString());
				}
			}
		}

		setubView(m_libraryManager->IsAdminLogged());
		connectSignals();
	}
	void QtLibrarySystem::setupItemsView(bool bIsAdmin)
	{
		m_ui.ItemsTableWidget->setRowCount(m_libraryManager->GetItems().size());
		m_ui.ItemsTableWidget->setColumnCount(7);
		QStringList tableHeader;
		tableHeader  << "#" << "Name" << "Lend Price" << "Available" << "Item type" << "Author" << "Creation date";
		m_ui.ItemsTableWidget->setHorizontalHeaderLabels(tableHeader);
		// index loop, because we need index here
		for (auto i = 0; i < m_libraryManager->GetItems().size(); ++i)
		{
			auto currentItem = m_libraryManager->GetItems()[i];
			m_ui.ItemsTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
			m_ui.ItemsTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(currentItem->GetItemName())));
			m_ui.ItemsTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(currentItem->GetLendPrice())));
			m_ui.ItemsTableWidget->setItem(i, 3, new QTableWidgetItem(currentItem->GetIsAvailable() ? "True" : "False"));
			m_ui.ItemsTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(Helpers::ConvertEnumToString(currentItem->GetItemType()))));
			m_ui.ItemsTableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(currentItem->GetAuthorName())));
			m_ui.ItemsTableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(currentItem->GetCreationDate().ToString())));
		}

		if (!bIsAdmin)
		{
			m_ui.AddItemButton->setVisible(false);
			m_ui.DeleteItemButton->setVisible(false);
		}
	}

	void QtLibrarySystem::handleAddAuthor()
	{
		auto addAuthorWindow = std::make_unique<QtAddAuthorWindow>(this);

		if (addAuthorWindow->exec() == QDialog::Accepted)
		{
			m_libraryManager->AddAuthor(addAuthorWindow->GetObjectString());
			setupAuthorsView(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::handleAddItem()
	{
		auto addItemWindow = std::make_unique<QtAddItemWindow>(m_libraryManager.get(), this);

		if (addItemWindow->exec() == QDialog::Accepted)
		{
			m_libraryManager->AddItem(addItemWindow->GetObjectString(), addItemWindow->GetItemType());
			setupItemsView(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::setubView(bool bIsAdmin)
	{
		setupItemsView(bIsAdmin);
		setupAuthorsView(bIsAdmin);
		setupLendsView(bIsAdmin);
		setupUsersTable(bIsAdmin);
	}

	void QtLibrarySystem::setupAuthorsView(bool bIsAdmin)
	{
		m_ui.AuthorsTableWidget->setRowCount(m_libraryManager->GetAuthors().size());
		m_ui.AuthorsTableWidget->setColumnCount(5);
		QStringList tableHeader;
		tableHeader << "#" << "Name" << "Surname" << "Birthday" << "Profession";
		m_ui.AuthorsTableWidget->setHorizontalHeaderLabels(tableHeader);
		for (auto i = 0; i < m_libraryManager->GetAuthors().size(); ++i)
		{
			auto currentAuthor = m_libraryManager->GetAuthors()[i];
			m_ui.AuthorsTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
			m_ui.AuthorsTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(currentAuthor->GetPersonData().m_Name)));
			m_ui.AuthorsTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(currentAuthor->GetPersonData().m_Surname)));
			m_ui.AuthorsTableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(currentAuthor->GetPersonData().m_Birthday.ToString())));
			m_ui.AuthorsTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(Helpers::ConvertEnumToString(currentAuthor->GetAuthorType()))));
		}

		if (!bIsAdmin)
		{
			m_ui.AddAuthorButton->setVisible(false);
			m_ui.DeleteAuthorButton->setVisible(false);
		}
	}

	void QtLibrarySystem::setupLendsView(bool bIsAdmin)
	{
		std::vector<std::shared_ptr<LendRecord>> lends;

		if (!bIsAdmin)
		{
			auto currentUserId = m_libraryManager->GetCurrentUser()->GetId();

			std::for_each(m_libraryManager->GetAllCurrentLends().begin(), m_libraryManager->GetAllCurrentLends().end(),
				[&](auto lend) {
				if (lend->GetUserId() == currentUserId)
				{
					lends.push_back(lend);
				}});
		}
		else
		{
			lends = m_libraryManager->GetAllCurrentLends();
		}


		m_ui.LendsTableWidget->setRowCount(lends.size());
		m_ui.LendsTableWidget->setColumnCount(7);
		QStringList tableHeader;
		tableHeader << "#" << "User" << "Item" << "Returned" << "Lend date" << "Return date" << "Price";
		m_ui.LendsTableWidget->setHorizontalHeaderLabels(tableHeader);
		for (auto i = 0; i < lends.size(); ++i)
		{
			auto currentLend = lends[i];
			m_ui.LendsTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
			m_ui.LendsTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(currentLend->GetUser()->GetFullName())));
			m_ui.LendsTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(currentLend->GetItem()->GetDescription())));
			m_ui.LendsTableWidget->setItem(i, 3, new QTableWidgetItem(currentLend->WasReturned() ? "True" : "False"));
			m_ui.LendsTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(currentLend->GetLendDate().ToString())));
			m_ui.LendsTableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(currentLend->GetReturnDate().ToString())));
			m_ui.LendsTableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(currentLend->GetLendPrice())));
		}

		if (!bIsAdmin)
		{
			m_ui.ReturnLendButton->setVisible(false);
			m_ui.DeleteLendButton->setVisible(false);
			m_ui.LendForUserButton->setVisible(false);
		}
	}

	void QtLibrarySystem::setupUsersTable(bool bIsAdmin)
	{
		if (!bIsAdmin)
		{
			m_ui.MainMenuTabWidget->removeTab(usersTabIndex);
			return;
		}

		m_ui.UsersTableWidget->setRowCount(m_libraryManager->GetUsers().size());
		m_ui.UsersTableWidget->setColumnCount(7);
		QStringList tableHeader;
		tableHeader << "#" << "Name" << "Surname" << "Birthday" << "Username" << "Password" << "User type";
		m_ui.UsersTableWidget->setHorizontalHeaderLabels(tableHeader);
		for (auto i = 0; i < m_libraryManager->GetUsers().size(); ++i)
		{
			auto currentUser = m_libraryManager->GetUsers()[i];
			m_ui.UsersTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
			m_ui.UsersTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(currentUser->GetPersonData().m_Name)));
			m_ui.UsersTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(currentUser->GetPersonData().m_Surname)));
			m_ui.UsersTableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(currentUser->GetPersonData().m_Birthday.ToString())));
			m_ui.UsersTableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(currentUser->GetUsername())));
			m_ui.UsersTableWidget->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(currentUser->GetPassword())));
			m_ui.UsersTableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(Helpers::ConvertEnumToString(currentUser->GetUserType()))));
		}
	}

	void QtLibrarySystem::handleAddUser()
	{
		auto addUserWindow = std::make_unique<QtAddUserWindow>(this);

		if (addUserWindow->exec() == QDialog::Accepted)
		{
			m_libraryManager->AddUser(addUserWindow->GetObjectString());
			setupUsersTable(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::connectSignals()
	{
		connect(m_ui.AddUserButton, SIGNAL(released()), this, SLOT(handleAddUser()));
		connect(m_ui.AddAuthorButton, SIGNAL(released()), this, SLOT(handleAddAuthor()));
		connect(m_ui.AddItemButton, SIGNAL(released()), this, SLOT(handleAddItem()));
		connect(m_ui.LendButton, SIGNAL(released()), this, SLOT(handleLendItem()));
		connect(m_ui.LendForUserButton, SIGNAL(released()), this, SLOT(handleLendItemForUser()));
		connect(m_ui.ReturnLendButton, SIGNAL(released()), this, SLOT(handleReturnLend()));

		connect(m_ui.DeleteAuthorButton, SIGNAL(released()), this, SLOT(handleDeleteAuthor()));
		connect(m_ui.DeleteItemButton, SIGNAL(released()), this, SLOT(handleDeleteItem()));
		connect(m_ui.DeleteLendButton, SIGNAL(released()), this, SLOT(handleDeleteLend()));
		connect(m_ui.DeleteUsersButton, SIGNAL(released()), this, SLOT(handleDeleteUser()));
	}

	void QtLibrarySystem::handleLendItem()
	{
		auto items = m_ui.ItemsTableWidget->selectionModel()->selectedRows();
		if (items.size() > 0)
		{
			auto row = items[0].row();
			m_libraryManager->LendItem(m_libraryManager->GetItems()[row]->GetId());

			setupItemsView(m_libraryManager->IsAdminLogged());
			setupLendsView(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::handleLendItemForUser()
	{
		QInputDialog qDialog;

		QStringList users;
		for (auto user : m_libraryManager->GetUsers())
		{
			std::stringstream stream;
			stream << user->GetId() << ". " << user->GetFullName();
			users.push_back(QString::fromStdString(stream.str()));
		}
		qDialog.setWindowTitle("Choose action");
		qDialog.setOptions(QInputDialog::UseListViewForComboBoxItems);
		qDialog.setComboBoxItems(users);
		 
		auto index = 0;
		if (qDialog.exec())
		{
			auto user = qDialog.textValue().toStdString();
			index = std::atoi(user.substr(0, user.find(".")).c_str());
		}

		auto items = m_ui.ItemsTableWidget->selectionModel()->selectedRows();
		if (items.size() > 0)
		{
			auto row = items[0].row();
			m_libraryManager->LendItem(m_libraryManager->GetItems()[row]->GetId(), m_libraryManager->GetUser(index));

			setupItemsView(m_libraryManager->IsAdminLogged());
			setupLendsView(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::handleReturnLend()
	{
		auto lends = m_ui.LendsTableWidget->selectionModel()->selectedRows();
		if (lends.size() > 0)
		{
			auto row = lends[0].row();
			auto money = QInputDialog::getInt(this, tr("Return lend dialog"), tr("Money paid"), QLineEdit::Normal);
			auto wasReturned = m_libraryManager->ReturnLend(m_libraryManager->GetAllCurrentLends()[row]->GetId(), money);

			if (!wasReturned)
			{
				QMessageBox msgBox;
				msgBox.setText("Paid not enough.");
				msgBox.exec();
				return;
			}

			setupItemsView(m_libraryManager->IsAdminLogged());
			setupLendsView(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::handleDeleteAuthor()
	{
		auto items = m_ui.AuthorsTableWidget->selectionModel()->selectedRows();
		if (items.size() > 0)
		{
			auto row = items[0].row();
			m_libraryManager->DeleteAuthor(m_libraryManager->GetAuthors()[row]->GetId());

			setupAuthorsView(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::handleDeleteLend()
	{
		auto lends = m_ui.LendsTableWidget->selectionModel()->selectedRows();
		if (lends.size() > 0)
		{
			auto row = lends[0].row();
			m_libraryManager->DeleteCurrentLend(m_libraryManager->GetAllCurrentLends()[row]->GetId());
			setupItemsView(m_libraryManager->IsAdminLogged());
			setupLendsView(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::handleDeleteUser()
	{
		auto items = m_ui.UsersTableWidget->selectionModel()->selectedRows();
		if (items.size() > 0)
		{
			auto row = items[0].row();
			m_libraryManager->DeleteUser(m_libraryManager->GetUsers()[row]->GetId());

			setupUsersTable(m_libraryManager->IsAdminLogged());
		}
	}

	void QtLibrarySystem::handleDeleteItem()
	{
		auto items = m_ui.ItemsTableWidget->selectionModel()->selectedRows();
		if (items.size() > 0)
		{
			auto row = items[0].row();
			m_libraryManager->DeleteItem(m_libraryManager->GetItems()[row]->GetId());

			setupItemsView(m_libraryManager->IsAdminLogged());
			setupLendsView(m_libraryManager->IsAdminLogged());
		}
	}

}
