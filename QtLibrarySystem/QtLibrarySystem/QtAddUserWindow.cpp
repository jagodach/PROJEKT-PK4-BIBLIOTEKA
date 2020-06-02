#include "QtAddUserWindow.h"
#include "User.h"
#include <sstream>
#include <QMessageBox>

namespace LibrarySystem::UI
{
	QtAddUserWindow::QtAddUserWindow(QWidget *parent)
		: QtAddWindowBase(parent)
	{
		m_ui.setupUi(this);

		connect(m_ui.AddButton, SIGNAL(released()), this, SLOT(handleAdd()));
		connect(m_ui.CancelButton, SIGNAL(released()), this, SLOT(handleCancel()));
		
		m_ui.UserTypeComboBox->addItem(QString::fromStdString(Helpers::ConvertEnumToString(UserType::UT_Admin)));
		m_ui.UserTypeComboBox->addItem(QString::fromStdString(Helpers::ConvertEnumToString(UserType::UT_User)));
	}

	QtAddUserWindow::~QtAddUserWindow()
	{

	}

	std::string QtAddUserWindow::GetObjectString()
	{
		//id;name,surname,dd-mm-yyyy;username;password;usertype
		std::stringstream stream;
		stream << Helpers::GetNextId() << ";" << m_name << "," << m_surname << "," << m_birthday << ";" << m_username << ";"
			<< m_password << ";" << m_userType;
		return stream.str();
	}

	bool QtAddUserWindow::validateData()
	{
		return !m_name.empty() && !m_surname.empty() && !m_birthday.empty() && !m_username.empty() && !m_password.empty() && !m_userType.empty();
	}

	void QtAddUserWindow::setDataFromUI()
	{
		m_name = m_ui.NameTextEdit->toPlainText().toStdString();
		m_surname = m_ui.SurnameTextEdit->toPlainText().toStdString();
		m_birthday = m_ui.BirthdayDateEdit->date().toString("dd-MM-yyyy").toStdString();
		m_username = m_ui.UsernameTextEdit->toPlainText().toStdString();
		m_password = m_ui.PasswordTextEdit->toPlainText().toStdString();
		m_userType = m_ui.UserTypeComboBox->currentText().toStdString();
	}

}
