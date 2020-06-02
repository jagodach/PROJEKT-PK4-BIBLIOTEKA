#pragma once

#include "QtAddWindowBase.h"
#include "Structs.h"
#include "LibraryManager.h"
#include "ui_QtAddItemWindow.h"

namespace LibrarySystem::UI
{
	class QtAddItemWindow : public QtAddWindowBase
	{
		Q_OBJECT

	public:
		QtAddItemWindow(LibraryManager* inLibraryManager, QWidget *parent = Q_NULLPTR);
		~QtAddItemWindow();

		// Returns data from window converted to string.It's always csv format, the same as for file saving/loading
		virtual std::string GetObjectString() override;
		// Returns selected item type
		ItemType GetItemType() { return m_itemType; };

	private slots:
		// Handles selection changed in item type combo box
		void handleSelectionChnged(int index);

	private:
		// Copies data from widgets
		virtual void setDataFromUI() override;
		// Checks if data is correct
		virtual bool validateData() override;

		// Refresh view to show/hide needed widgets
		void RefreshView();

		// Handler to widget
		Ui::QtAddItemWindow m_ui;

		// Pointer to library manager. We need it to show authors.
		const LibraryManager* m_libraryManager;

		// Item variables
		std::string m_name;
		int m_price;
		int m_authorIndex;
		ItemType m_itemType;
		std::string m_creationDate;
		int m_releaseVersion;
		std::string m_format;
	};
}
