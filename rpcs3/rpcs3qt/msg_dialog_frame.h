#pragma once

#include "stdafx.h"
#include "Emu/Memory/vm.h"
#include "Emu/Cell/Modules/cellMsgDialog.h"
#include "Emu/System.h"
#include "Emu/Memory/Memory.h"
#include "Emu/Cell/lv2/sys_time.h"
#include "custom_dialog.h"

#include <QPushButton>
#include <QStaticText>
#include <QDialog>
#include <QInputDialog>
#include <QFormLayout>
#include <QProgressBar>
#include <QLabel>
#include <QButtonGroup>
#include <QLineEdit>

#ifdef _WIN32
#include <QWinTaskbarProgress>
#include <QWinTaskbarButton>
#include <QWinThumbnailToolBar>
#include <QWinThumbnailToolbutton>
#elif HAVE_QTDBUS
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusConnection>
#endif

class msg_dialog_frame : public QObject, public MsgDialogBase
{
	Q_OBJECT

#ifdef _WIN32
	QWinTaskbarButton* m_tb_button = nullptr;
	QWinTaskbarProgress* m_tb_progress = nullptr;
#elif HAVE_QTDBUS
	int* progressValue = nullptr;
#endif

	custom_dialog* m_dialog =nullptr;
	QLabel* m_text = nullptr;
	QLabel* m_text1 = nullptr;
	QLabel* m_text2 = nullptr;
	QPushButton* m_button_ok = nullptr;
	QPushButton* m_button_yes = nullptr;
	QPushButton* m_button_no = nullptr;
	QProgressBar* m_gauge1 = nullptr;
	QProgressBar* m_gauge2 = nullptr;

	custom_dialog* m_osk_dialog = nullptr;
	char16_t* m_osk_text_return;

	const int m_gauge_max = 100;

public:
	msg_dialog_frame();
	~msg_dialog_frame();
	virtual void Create(const std::string& msg) override;
	virtual void CreateOsk(const std::string& msg, char16_t* osk_text, u32 charlimit) override;
	virtual void ProgressBarSetMsg(u32 progressBarIndex, const std::string& msg) override;
	virtual void ProgressBarReset(u32 progressBarIndex) override;
	virtual void ProgressBarInc(u32 progressBarIndex, u32 delta) override;
#ifdef HAVE_QTDBUS
private:
	void UpdateProgress(int progress, bool disable = false);
#endif
};
