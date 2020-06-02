#include "QtLoginWIndow.h"
#include <QMessageBox>

namespace LibrarySystem::UI
{
	QtLoginWIndow::QtLoginWIndow(QWidget *parent)
		: QDialog(parent)
	{
		m_ui.setupUi(this);
		connect(m_ui.LoginButton, SIGNAL(released()), this, SLOT(handleLogin()));
		connect(m_ui.CancelButton, SIGNAL(released()), this, SLOT(handleCancel()));
	}

	QtLoginWIndow::~QtLoginWIndow()
	{
	}

	void QtLoginWIndow::handleLogin()
	{
		if (GetUser().length() > 0 && GetPassword().length() > 0)
		{
			accept();
			return;
		}

		QMessageBox msgBox;
		msgBox.setText("No password or no username.");
		msgBox.exec();
	}

	void QtLoginWIndow::handleCancel()
	{
		reject();
	}
}
