#include "QtAddAuthorWindow.h"
#include "Author.h"
#include <sstream>
#include <QMessageBox>

namespace LibrarySystem::UI
{
	QtAddAuthorWindow::QtAddAuthorWindow(QWidget *parent)
		: QtAddWindowBase(parent)
	{
		m_ui.setupUi(this);

		connect(m_ui.AddButton, SIGNAL(released()), this, SLOT(handleAdd()));
		connect(m_ui.CancelButton, SIGNAL(released()), this, SLOT(handleCancel()));

		m_ui.AuthorTypeComboBox->addItem(QString::fromStdString(Helpers::ConvertEnumToString(AuthorType::AT_Author)));
		m_ui.AuthorTypeComboBox->addItem(QString::fromStdString(Helpers::ConvertEnumToString(AuthorType::AT_BookAuthor)));
	}

	QtAddAuthorWindow::~QtAddAuthorWindow()
	{
	}

	std::string QtAddAuthorWindow::GetObjectString()
	{
		std::stringstream stream;
		stream << Helpers::GetNextId() << ";" << m_authorType << ";" << m_name << "," << m_surname << "," << m_birthday;
		return stream.str();
	}

	void QtAddAuthorWindow::setDataFromUI()
	{
		m_name = m_ui.NameTextEdit->toPlainText().toStdString();
		m_surname = m_ui.SurnameTextEdit->toPlainText().toStdString();
		m_birthday = m_ui.BirthdayDateEdit->date().toString("dd-MM-yyyy").toStdString();
		m_authorType = m_ui.AuthorTypeComboBox->currentText().toStdString();
	}

	bool QtAddAuthorWindow::validateData()
	{
		return !m_name.empty() && !m_surname.empty() && !m_birthday.empty() && !m_authorType.empty();
	}

}