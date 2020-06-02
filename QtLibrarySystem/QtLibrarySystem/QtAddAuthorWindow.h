#pragma once

#include "QtAddWindowBase.h"
#include "ui_QtAddAuthorWindow.h"

namespace LibrarySystem::UI
{
	class QtAddAuthorWindow : public QtAddWindowBase
	{
		Q_OBJECT

	public:
		QtAddAuthorWindow(QWidget *parent = Q_NULLPTR);
		~QtAddAuthorWindow();

		// Returns data from window converted to string.It's always csv format, the same as for file saving/loading
		virtual std::string GetObjectString() override;

	private:
		// Copies data from widgets
		virtual void setDataFromUI() override;
		// Checks if data is correct
		virtual bool validateData() override;

		// Handler to widget
		Ui::QtAddAuthorWindow m_ui;

		// Author variables
		std::string m_name;
		std::string m_surname;
		std::string m_birthday;
		std::string m_authorType;
	};
}
