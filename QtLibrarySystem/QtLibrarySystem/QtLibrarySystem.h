#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtLibrarySystem.h"
#include "LibraryManager.h"

namespace LibrarySystem::UI
{
	class QtLibrarySystem : public QMainWindow
	{
		Q_OBJECT

	public:
		QtLibrarySystem(QWidget *parent = Q_NULLPTR);

	private slots:
		// Handling buttons releases
		void handleAddUser();
		void handleAddAuthor();
		void handleAddItem();
		void handleLendItem();
		void handleLendItemForUser();
		void handleReturnLend();

		void handleDeleteAuthor();
		void handleDeleteLend();
		void handleDeleteUser();
		void handleDeleteItem();

	private:
		// Handler to widget
		Ui::QtLibrarySystemClass m_ui;

		// Pointer to main LibraryManasger - it's only one object per application
		std::unique_ptr<LibraryManager> m_libraryManager;

		// Setups view - fill with data, setup views for admin/user
		void setubView(bool bIsAdmin);
		void setupLendsView(bool bIsAdmin);
		void setupItemsView(bool bIsAdmin);
		void setupAuthorsView(bool bIsAdmin);
		void setupUsersTable(bool bIsAdmin);

		// Connects signals with methods
		void connectSignals();

		// Index of users tab - it's hidden for user accounts
		const int usersTabIndex = 3;
	};
}
