#include "QtAddItemWindow.h"
#include "Author.h"
#include <sstream>

namespace LibrarySystem::UI
{
	QtAddItemWindow::QtAddItemWindow(LibraryManager* inLibraryManager, QWidget *parent)
		: QtAddWindowBase(parent)
	{
		m_ui.setupUi(this);

		m_libraryManager = inLibraryManager;

		connect(m_ui.AddButton, SIGNAL(released()), this, SLOT(handleAdd()));
		connect(m_ui.CancelButton, SIGNAL(released()), this, SLOT(handleCancel()));
		connect(m_ui.ItemTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChnged(int)));

		m_ui.ItemTypeComboBox->addItem(QString::fromStdString(Helpers::ConvertEnumToString(ItemType::IT_Item)));
		m_ui.ItemTypeComboBox->addItem(QString::fromStdString(Helpers::ConvertEnumToString(ItemType::IT_Book)));
		m_ui.ItemTypeComboBox->addItem(QString::fromStdString(Helpers::ConvertEnumToString(ItemType::IT_EBook)));

		for (auto author : m_libraryManager->GetAuthors())
		{
			m_ui.AuthorComboBox->addItem(QString::fromStdString(author->GetFullName()));
		}

		setDataFromUI();
		RefreshView();
	}

	QtAddItemWindow::~QtAddItemWindow()
	{

	}

	void QtAddItemWindow::setDataFromUI()
	{
		m_name = m_ui.NameTextEdit->toPlainText().toStdString();

		try
		{
			m_price = std::atoi(m_ui.LendPriceTextEdit->toPlainText().toStdString().c_str());
		}
		catch (...)
		{
			m_price = 0;
		}

		m_authorIndex = m_ui.AuthorComboBox->currentIndex();
		m_itemType = Helpers::ConvertItemToEnum(m_ui.ItemTypeComboBox->currentText().toStdString());
		m_creationDate = m_ui.CreationDateEdit->date().toString("dd-MM-yyyy").toStdString();

		try
		{
			m_releaseVersion = std::atoi(m_ui.ReleaseVersionTextEdit->toPlainText().toStdString().c_str());
		}
		catch (...)
		{
			m_releaseVersion = 0;
		}

		m_format = m_ui.FormatTextEdit->toPlainText().toStdString();
	}

	void QtAddItemWindow::RefreshView()
	{
		switch (m_itemType)
		{
		case LibrarySystem::IT_EBook:
			m_ui.FormatTextEdit->setVisible(true);
			m_ui.ReleaseVersionTextEdit->setVisible(true);
			break;
		case LibrarySystem::IT_Book:
			m_ui.FormatTextEdit->setVisible(false);
			m_ui.ReleaseVersionTextEdit->setVisible(true);
			break;
		default:
			m_ui.FormatTextEdit->setVisible(false);
			m_ui.ReleaseVersionTextEdit->setVisible(false);
			break;
		}
	}

	void QtAddItemWindow::handleSelectionChnged(int index)
	{
		setDataFromUI();
		RefreshView();
	}

	// Format: id;lendPrice;isAvailable(0:1);itemtype;authorId;dd-mm-yyyy;dd-mm-yyyy;name
	std::string QtAddItemWindow::GetObjectString()
	{
		std::stringstream stream;
		stream << Helpers::GetNextId() << ";" << std::to_string(m_price) << ";" << "1" << ";" << Helpers::ConvertEnumToString(m_itemType) << ";" 
			<< std::to_string(m_libraryManager->GetAuthors()[m_authorIndex]->GetId()) << ";" << m_creationDate << ";" << SimpleDate().ToCsvRecord() << ";" << m_name << ";" << std::to_string(m_releaseVersion) << ";" << m_format;
		return stream.str();
	}

	bool QtAddItemWindow::validateData()
	{
		bool bBasicValidation = !m_name.empty() && m_price >= 0 && m_authorIndex >= 0 && !m_creationDate.empty();

		switch (m_itemType)
		{
		case LibrarySystem::IT_EBook:
			bBasicValidation = bBasicValidation && !m_format.empty();
		case LibrarySystem::IT_Book:
			bBasicValidation = bBasicValidation && m_releaseVersion >= 0;
			break;
		}
		return bBasicValidation;
	}

}
