#pragma once

#include <QDialog>
namespace LibrarySystem::UI
{
	// Class that is base for all add dialogs. It ensures that all classes will have similar structure.
	class QtAddWindowBase : public QDialog
	{
		Q_OBJECT

	public:
		QtAddWindowBase(QWidget *parent);
		~QtAddWindowBase();

		// Returns data from window converted to string.It's always csv format, the same as for file saving/loading
		virtual std::string GetObjectString() = 0;

	private slots:
		// Handles add button release - copies data from widgets, check if it's valid and return result
		virtual void handleAdd();
		// Handles cancel button release
		virtual void handleCancel();

	private:
		// Copies data from widgets
		virtual void setDataFromUI() = 0;
		// Checks if data is correct
		virtual bool validateData() = 0;
	};
}
