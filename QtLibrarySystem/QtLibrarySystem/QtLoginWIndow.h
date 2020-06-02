#pragma once

#include <QDialog>
#include "ui_QtLoginWIndow.h"

namespace LibrarySystem::UI
{
	class QtLoginWIndow : public QDialog
	{
		Q_OBJECT

	public:
		QtLoginWIndow(QWidget *parent = Q_NULLPTR);
		~QtLoginWIndow();

		// Returns typed user
		std::string GetUser() { return m_ui.UserNameTextEdit->toPlainText().toStdString(); }
		// Returns typed password
		std::string GetPassword() { return m_ui.PasswordTextEdit->toPlainText().toStdString(); }

	private slots:
		// Handles login button release
		void handleLogin();
		// Handles cancel button release
		void handleCancel();

	private:

		// Handler to widget
		Ui::QtLoginWIndow m_ui;

		// Login data
		std::string m_username;
		std::string m_password;
	};
}
