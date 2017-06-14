#include "startwindow.h"

StartWindow::StartWindow() : QWidget()
{
    ///Parametres de base de la fenetre
    move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    setWindowTitle("Welcome");
    /// La fenêtre est modale, on ne peut pas modifier les autres fenêtres quand elle est ouverte
    setWindowModality(Qt::WindowModal);

    /// Initialisation des Widgets

    m_labelTexte = new QLabel("Bienvenue dans MIO !");

    m_labelInfos = new QLabel("Version Serveur 1.0");

    m_labelCredits = new QLabel("Hadrien Marquez, David Schreck, Antoine Olivier, Noe Perard-Gayot");

    /// Logo de demarrage
    m_logo = new QLabel();
    //m_logo->setPixmap(QPixmap("MIO_logo.png"));

    /// Boutons
    m_buttonStart = new QPushButton("Start");

    ///Contenu de la fenetre avec positionnement des elements a  l'aide des layouts
    QVBoxLayout *VLayout = new QVBoxLayout;

    VLayout->addWidget(m_labelTexte);
    VLayout->addWidget(m_labelInfos);
    VLayout->addWidget(m_labelCredits);
    VLayout->addWidget(m_logo);

    VLayout->addWidget(m_buttonStart);

    setLayout(VLayout);

    QObject::connect(m_buttonStart, SIGNAL(clicked()), this, SLOT(close()));
}


///Destructeur
StartWindow::~StartWindow()
{

    delete m_labelTexte;
    delete m_labelInfos;
    delete m_labelCredits;
    delete m_logo;
    delete m_buttonStart;
}
