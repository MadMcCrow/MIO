#include "miowindow.h"
#include "chat_widget/chatwidget.h"
#include "startwindow.h"

MIOWindow::MIOWindow() : QMainWindow()
{
    /// Paramètres de base de la fenêtre
    setWindowTitle("MIO - Projet ISIS");
    showMaximized();

    /// Initialisation
    ///
    /// Bouttons
    m_buttonPref = new QPushButton("Settings", this);
    m_buttonQuit = new QPushButton("Quit", this);

    /// Fenêtres
    m_settingsWindow = new SettingsWindow(this);
    m_startWindow = new StartWindow(this);

    /// Widgets
    //m_openGLWidget = new OpenGLWidget;
    m_glWidget = new GLWidget;
    m_logWidget = new LogWidget;
    m_videoWidget = new VideoWidget;
    m_chatWidget = new ChatWidget(this);

    /// Connections
    QObject::connect(m_buttonQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_buttonPref, SIGNAL(clicked()), m_settingsWindow, SLOT(show()));
    /// Mise en place des elements

    QWidget *zonePrincipale = new QWidget();

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(m_videoWidget, 0, 0, 1, 1);
    //gridLayout->addWidget(m_openGLWidget, 0, 1, 1, 1);
    gridLayout->addWidget(m_glWidget, 0, 1, 1, 1);
    gridLayout->addWidget(m_chatWidget, 1, 0, 1, 2);
    gridLayout->addWidget(m_buttonPref, 2, 0, 1, 1);
    gridLayout->addWidget(m_buttonQuit, 2, 1, 1, 1);

    zonePrincipale->setLayout(gridLayout);
    setCentralWidget(zonePrincipale);

    /// Afficher la startWindow
    //m_startWindow->show();

}


/// Getteurs
SettingsWindow* MIOWindow::getSettings()
{
    return m_settingsWindow;
}
/// added by noe
void MIOWindow::setglWidgetContent(GLWidget source)
{
    m_glWidget->setSkeleton(source.getSkeleton());
}

void MIOWindow::setglWidgetContent(GLSkeleton source)
{
    m_glWidget->setSkeleton(source);
}

const GLWidget* MIOWindow::getglWidgetContent()
{
    return m_glWidget;
}

/// Public slots

void MIOWindow::showSettings_c()
{
    m_settingsWindow->show();
}

void MIOWindow::quit_c()
{
    qApp->quit();
}


//Destructeur
MIOWindow::~MIOWindow()
{
    /// Boutons
    delete m_buttonPref;
    delete m_buttonQuit;

    /// Fenêtres séparées
    delete m_settingsWindow;
    delete m_startWindow;

    /// Widgets
    delete m_chatWidget;
    //delete m_openGLWidget;
    delete m_glWidget;
    delete m_videoWidget;
    delete m_logWidget;
}
