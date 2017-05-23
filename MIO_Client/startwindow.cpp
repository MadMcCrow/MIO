#include "startwindow.h"

#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>

StartWindow::StartWindow(QMainWindow *MainWindow) : QWidget()
{
    ///Parametres de base de la fenetre
    move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    setWindowTitle("Welcome");

    /// Initialisation des Widgets

    m_labelTexte = new QLabel("Bienvenue dans MIO !");

    m_labelInfos = new QLabel("Version Client 1.0");

    m_labelCredits = new QLabel("Hadrien Marquez, David Schreck, Antoine Olivier, Noe Perard-Gayot");

    /// Logo de demarrage
    m_logo = new QLabel();
    m_logo->setPixmap(QPixmap("/Volumes/SSHD/users/David/Desktop/MIO_logo.png"));

    /// Boutons
    m_buttonStart = new QPushButton("Start");
    m_buttonQuit = new QPushButton("Quitter");


    ///Contenu de la fenetre avec positionnement des elements a  l'aide des layouts
    QVBoxLayout *VLayout = new QVBoxLayout;

    VLayout->addWidget(m_labelTexte);
    VLayout->addWidget(m_labelInfos);
    VLayout->addWidget(m_labelCredits);
    VLayout->addWidget(m_logo);

    QHBoxLayout *HLayoutBottom = new QHBoxLayout;
    HLayoutBottom->addWidget(m_buttonQuit);
    HLayoutBottom->addWidget(m_buttonStart);

    VLayout->addLayout(HLayoutBottom);
    setLayout(VLayout);

    QObject::connect(m_buttonQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_buttonStart, SIGNAL(clicked()), this, SLOT(close()));

}

//Destructeur
StartWindow::~StartWindow()
{

    delete m_labelTexte;
    delete m_labelInfos;
    delete m_labelCredits;
    delete m_logo;
    delete m_buttonStart;
    delete m_buttonQuit;

}


