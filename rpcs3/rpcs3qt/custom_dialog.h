#pragma once

#include <QDialog>
#include <QKeyEvent>
#include <QIcon>

class custom_dialog : public QDialog
{
	Q_OBJECT

		bool m_disable_cancel;
public:
	explicit custom_dialog(bool disableCancel, QWidget* parent = 0)
		: QDialog(parent), m_disable_cancel(disableCancel)
	{
		setWindowIcon(QIcon(":/rpcs3.ico"));

		if (m_disable_cancel)
		{
			setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
		}
	}
private:
	void keyPressEvent(QKeyEvent* event)
	{
		// this won't work with Alt+F4, the window still closes
		if (m_disable_cancel && event->key() == Qt::Key_Escape)
		{
			event->ignore();
		}
		else
		{
			QDialog::keyPressEvent(event);
		}
	}
	void closeEvent(QCloseEvent* event)
	{
		// spontaneous: don't close on external system level events like Alt+F4
		if (m_disable_cancel && event->spontaneous())
		{
			event->ignore();
		}
		else
		{
			QDialog::closeEvent(event);
		}
	}
};