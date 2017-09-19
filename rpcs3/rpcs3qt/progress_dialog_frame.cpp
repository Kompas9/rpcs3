#include "progress_dialog_frame.h"

constexpr auto qstr = QString::fromStdString;

//QWidget* progress_dialog_frame::s_widget = nullptr;
QScrollArea* progress_dialog_frame::s_scroll_area = nullptr;
QGridLayout* progress_dialog_frame::s_grid_layout = nullptr;
int progress_dialog_frame::s_progress_count = 0;
int progress_dialog_frame::s_progress_max = 0;
int progress_dialog_frame::s_progress_value = 0;

#ifdef _WIN32
QWinTaskbarButton* progress_dialog_frame::s_tb_button = nullptr;
QWinTaskbarProgress* progress_dialog_frame::s_tb_progress = nullptr;
#elif HAVE_QTDBUS
int* progress_dialog_frame::s_progressValue = nullptr;
#endif

progress_dialog_frame::progress_dialog_frame()
{
	if (++s_progress_count > 1)
	{
		return;
	}

	connect(s_scroll_area, &QWidget::destroyed, [=]
	{
		on_close(0);
	});

#ifdef _WIN32
	s_tb_button = new QWinTaskbarButton();
	s_tb_progress = s_tb_button->progress();
	s_tb_progress->setRange(0, m_progress_max);
	s_tb_progress->setVisible(true);
#elif HAVE_QTDBUS
	UpdateProgress(0);
	s_progressValue = new int(0);
#endif

	s_grid_layout = new QGridLayout;

	//s_widget = new QWidget;
	//s_widget->setLayout(s_grid_layout);

	s_scroll_area = new QScrollArea;
	s_scroll_area->setWindowIcon(QIcon(":/rpcs3.ico"));
	s_scroll_area->setWindowTitle(tr("Compiling Modules"));
	s_scroll_area->setLayout(s_grid_layout);
	s_scroll_area->show();

#ifdef _WIN32
	// if we do this before, the QWinTaskbarProgress won't show
	if (s_tb_button) s_tb_button->setWindow(s_scroll_area->windowHandle());
#endif
}

progress_dialog_frame::~progress_dialog_frame()
{
	s_grid_layout->removeWidget(m_text_container);
	s_grid_layout->removeWidget(m_progress_bar);

	if (m_text_container)
	{
		delete m_text_container;
	}
	if (m_progress_bar)
	{
		delete m_progress_bar;
	}

	s_progress_max -= m_progress_max;
	s_progress_value -= m_progress_bar->value();

	if (--s_progress_count > 0)
	{
		UpdateThumbnailProgressBar();
		return;
	}

#ifdef _WIN32
	if (s_tb_progress)
	{
		s_tb_progress->hide();
	}
	if (s_tb_button)
	{
		s_tb_button->deleteLater();
	}
#elif HAVE_QTDBUS
	if (s_progressValue)
	{
		UpdateProgress(0, false);
		delete s_progressValue;
	}
#endif
	if (s_scroll_area)
	{
		s_scroll_area->deleteLater();
	}
}

bool progress_dialog_frame::Finished()
{
	return m_progress_bar->value() == 100;
}

void progress_dialog_frame::Create(const std::string& msg)
{
	m_text = new QLabel(qstr(msg));
	m_text->setAlignment(Qt::AlignLeft);

	m_text_container = new QWidget();
	m_text_container->setLayout(new QVBoxLayout);
	m_text_container->layout()->addWidget(m_text);

	m_progress_bar = new QProgressBar();
	m_progress_bar->setRange(0, m_progress_max);
	m_progress_bar->setAlignment(Qt::AlignRight);

	s_grid_layout->addWidget(m_text_container, s_progress_count - 1, 0);
	s_grid_layout->addWidget(m_progress_bar,   s_progress_count - 1, 1);

	s_progress_max += m_progress_max;

	UpdateThumbnailProgressBar();
}

void progress_dialog_frame::ProgressBarSetMsg(u32 progressBarIndex, const std::string& msg)
{
	Q_UNUSED(progressBarIndex);
	SetText(qstr(msg));
}

void progress_dialog_frame::ProgressBarReset(u32 progressBarIndex)
{
	Q_UNUSED(progressBarIndex);
	SetValue(0);
	UpdateThumbnailProgressBar();
}

void progress_dialog_frame::ProgressBarInc(u32 progressBarIndex, u32 delta)
{
	Q_UNUSED(progressBarIndex);
	SetValue(m_progress_old + delta);
	UpdateThumbnailProgressBar();
}

void progress_dialog_frame::SetValue(int value)
{
	m_progress_old = m_progress_bar->value();
	m_progress_tmp = value;
	m_progress_bar->setValue(value);
}

void progress_dialog_frame::SetText(const QString& text)
{
	m_text->setText(text);
}

void progress_dialog_frame::UpdateThumbnailProgressBar()
{
	s_progress_value += m_progress_tmp - m_progress_old;

	int progress = 100 * s_progress_value / s_progress_max;

#ifdef _WIN32
	s_tb_progress->setValue(progress);
#elif HAVE_QTDBUS
	*s_progressValue = progress;
	UpdateProgress(*s_progressValue);
#endif
}

#ifdef HAVE_QTDBUS
void progress_dialog_frame::UpdateProgress(int progress, bool disable)
{
	QDBusMessage message = QDBusMessage::createSignal(QStringLiteral("/"),
		QStringLiteral("com.canonical.Unity.LauncherEntry"),
		QStringLiteral("Update"));
	QVariantMap properties;
	if (disable)
		properties.insert(QStringLiteral("progress-visible"), false);
	else
		properties.insert(QStringLiteral("progress-visible"), true);
	//Progress takes a value from 0.0 to 0.1
	properties.insert(QStringLiteral("progress"), (double)progress / (double)m_progress_max);
	message << QStringLiteral("application://rpcs3.desktop") << properties;
	QDBusConnection::sessionBus().send(message);
}
#endif
