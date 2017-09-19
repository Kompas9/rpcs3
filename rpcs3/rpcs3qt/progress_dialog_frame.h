#pragma once

#include "stdafx.h"
#include "Emu/Memory/vm.h"
#include "Emu/Cell/Modules/cellMsgDialog.h"
#include "Emu/System.h"
#include "Emu/Memory/Memory.h"
#include "Emu/Cell/lv2/sys_time.h"

#include <QProgressBar>
#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>

#ifdef _WIN32
#include <QWinTaskbarProgress>
#include <QWinTaskbarButton>
#include <QWinThumbnailToolBar>
#include <QWinThumbnailToolbutton>
#elif HAVE_QTDBUS
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusConnection>
#endif

class progress_dialog_frame : public QObject, public MsgDialogBase
{
	Q_OBJECT

	//static QWidget* s_widget;
	static QScrollArea* s_scroll_area;
	static QGridLayout* s_grid_layout;
	static int s_progress_count;
	static int s_progress_max;
	static int s_progress_value;

#ifdef _WIN32
	static QWinTaskbarButton* s_tb_button;
	static QWinTaskbarProgress* s_tb_progress;
#elif HAVE_QTDBUS
	static int* s_progressValue;
#endif

	const int m_progress_max = 100;
	int m_progress_old = 0;
	int m_progress_tmp = 0;

	QWidget* m_text_container = nullptr;
	QLabel* m_text = nullptr;
	QProgressBar* m_progress_bar = nullptr;

public:
	progress_dialog_frame();
	~progress_dialog_frame();
	bool Finished();

	virtual void Create(const std::string& msg) override;
	virtual void CreateOsk(const std::string& msg, char16_t* osk_text, u32 charlimit) override {};
	virtual void ProgressBarSetMsg(u32 progressBarIndex, const std::string& msg) override;
	virtual void ProgressBarReset(u32 progressBarIndex) override;
	virtual void ProgressBarInc(u32 progressBarIndex, u32 delta) override;

private:
	void SetValue(int value);
	void SetText(const QString& text);
	void UpdateThumbnailProgressBar();
#ifdef HAVE_QTDBUS
	void UpdateProgress(int progress, bool disable = false);
#endif
};