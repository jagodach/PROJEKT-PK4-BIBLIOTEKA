#pragma once

#include "QtAddWindowBase.h"
#include "ui_QtAddUserWindow.h"

namespace LibrarySystem::UI
{
	class QtAddUserWindow : public QtAddWindowBase
	{
		Q_OBJECT

	public:
		QtAddUserWindow(QWidget *parent = Q_NULLPTR);
		~QtAddUserWindow();

		// Returns data from window converted to string.It's always csv format, the same as for file saving/loading
		virtual std::string GetObjectString() override;

	private:
		// Copies data from widgets
		virtual void setDataFromUI() override;
		// Checks if data is correct
		virtual bool validateData() override;

		// Handler to widget
		Ui::QtAddUserWindow m_ui;

		// Author User
		std::string m_name;
		std::string m_surname;
		std::string m_birthday;
		std::string m_username;
		std::string m_password;
		std::string m_userType;
	};
}
