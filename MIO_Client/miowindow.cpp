#include "miowindow.h"
#include "chat_widget/chatwidget.h"
#include "startwindow.h"
#include "gl_widget/glskeleton.h"
#include <iostream>

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
    m_glWidget = new GLWidget;
    m_logWidget = new LogWidget;
    m_videoWidget = new VideoWidget;
    m_chatWidget = new ChatWidget(this);

    /// Connections
    QObject::connect(m_buttonQuit,
                     SIGNAL(clicked()),
                     qApp, SLOT(quit()));
    QObject::connect(m_buttonPref,
                     SIGNAL(clicked()),
                     m_settingsWindow, SLOT(show()));
    // update the GLSkeleton
    QObject::connect(this,
                     SIGNAL(updateGLSkeleton_s(GLSkeleton)),
                     m_glWidget,
                     SLOT(updateSkeleton_c(GLSkeleton)));

    // receive proof of update
    QObject::connect(m_glWidget,
                     SIGNAL(notifyMIOwindow_s()),
                     this,
                     SLOT(receivedGLnotify_c()));

    /// Mise en place des elements

    QWidget *zonePrincipale = new QWidget();

    QGridLayout *gridLayout = new QGridLayout;
    //gridLayout->addWidget(m_videoWidget, 0, 0, 1, 1);
    //gridLayout->addWidget(m_openGLWidget, 0, 1, 1, 1);
    gridLayout->addWidget(m_glWidget, 0, 0, 2, 2);
    //gridLayout->addWidget(m_chatWidget, 1, 0, 1, 2);
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


void MIOWindow::receiveGlData_c(Frame* F)
{
    GLSkeleton source;

    if(F->getSkeletonCount()<1)
    {
    std::cout<< "ErrorNoSkeleton" << std::endl;
    }else{
        source = F->getFrameSkeletons().at(0);
        std::cout <<"source size : " << source.size() << "  "<< std::endl;
        emit updateGLSkeleton_s(source);
    }
}

void MIOWindow::receivedGLnotify_c()
{
    emit finishedGLUpdate_s();
}

void MIOWindow::ErrorOnOther_c(size_t ErrCode){
    //Something went wrong
    //emit updateGLShape_s();
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
    delete m_glWidget;
    delete m_videoWidget;
    delete m_logWidget;
}
