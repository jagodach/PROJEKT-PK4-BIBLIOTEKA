#include "QtAddWindowBase.h"
#include <QMessageBox>


namespace LibrarySystem::UI
{
	QtAddWindowBase::QtAddWindowBase(QWidget *parent)
		: QDialog(parent)
	{
	}

	QtAddWindowBase::~QtAddWindowBase()
	{
	}

	void QtAddWindowBase::handleAdd()
	{
		// Copy data from UI to class
		setDataFromUI();
		// Check if data is valid
		if (validateData())
		{
			// Returns accept as dialog result. Returns from method, so we can avoid using else and code indent.
			accept();
			return;
		}

		QMessageBox msgBox;
		msgBox.setText("Not all values selected.");
		msgBox.exec();
	}

	void LibrarySystem::UI::QtAddWindowBase::handleCancel()
	{
		reject();
	}
}
