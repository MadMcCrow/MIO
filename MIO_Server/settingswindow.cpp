#include "settingswindow.h"


/**
 * @brief Fenêtre de préférences
 */
SettingsWindow::SettingsWindow() : QWidget()
{
    /// Paramètres de base de la fenêtre
    setMinimumSize(300, 100);
    move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    setWindowTitle("MIO Preferences Serveur");
    /// La fenêtre est modale, on ne peut pas modifier les autres fenêtres quand elle est ouverte
    setWindowModality(Qt::WindowModal);

    /// Initialisation des éléments des préférences avec leurs valeurs par défaut

    m_settingsTitle = new QLabel("Préferences Serveur");
    m_ok = new QPushButton("Ok");
    m_ok->setDefault(true);
    m_ok->setAutoDefault(true);
    m_cancel = new QPushButton("Annuler");
    m_apply = new QPushButton("Appliquer");


    QLabel *PortServeur = new QLabel("Port du Serveur");
    m_lineEditPort = new QLineEdit("50585");
    m_port = 50585; // Default value

    QLabel *pathLabel = new QLabel("Chemin d'enregistrement");
    m_lineEditPath = new QLineEdit;
    m_lineEditPath->setReadOnly(true);
    QPushButton *browsePath = new QPushButton("Browse");


    QLabel *pseudoLabel = new QLabel("Pseudo");
    m_lineEditPseudo = new QLineEdit("Serveur");
    m_pseudo = "Serveur"; // Default Value


    /// On initialise les preferences
    QSettings settings;
    settings.setValue("Port", m_lineEditPort->text());
    settings.setValue("Pseudo",m_lineEditPseudo->text());
    settings.setValue("Path", m_lineEditPath->text());


    /// Mise en place des éléments sur la page

    QVBoxLayout *VLayout = new QVBoxLayout;
    VLayout->addWidget(m_settingsTitle);

    QHBoxLayout *HLayoutIP = new QHBoxLayout;
    HLayoutIP->addWidget(PortServeur);
    HLayoutIP->addWidget(m_lineEditPort);
    VLayout->addLayout(HLayoutIP);

    QHBoxLayout *HLayoutPath = new QHBoxLayout;
    HLayoutPath->addWidget(pathLabel);
    HLayoutPath->addWidget(m_lineEditPath);
    HLayoutPath->addWidget(browsePath);
    VLayout->addLayout(HLayoutPath);

    QHBoxLayout *HLayoutPseudo = new QHBoxLayout;
    HLayoutPseudo->addWidget(pseudoLabel);
    HLayoutPseudo->addWidget(m_lineEditPseudo);
    VLayout->addLayout(HLayoutPseudo);

    VLayout->addStretch();

    QHBoxLayout *HLayoutBottom = new QHBoxLayout;
    HLayoutBottom->addWidget(m_cancel);
    HLayoutBottom->addWidget(m_apply);
    HLayoutBottom->addWidget(m_ok);
    VLayout->addLayout(HLayoutBottom);


    setLayout(VLayout);

    /// Connections

    QObject::connect(m_cancel,SIGNAL(clicked()), this, SLOT(cancel_c()));
    QObject::connect(m_apply,SIGNAL(clicked()), this, SLOT(apply_c()));
    QObject::connect(m_ok, SIGNAL(clicked()), this, SLOT(apply_c()));
    QObject::connect(m_ok, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(browsePath, SIGNAL(clicked()), this, SLOT(setPath_c()));

}

/// Slots

/**
 * @brief SettingsWindow::setPath_c
 */
void SettingsWindow::setPath_c()
{
    m_lineEditPath->insert(QFileDialog::getExistingDirectory(this));
}

/**
 * @brief SettingsWindow::apply_c Applique les réglages en mettant à jour le QSettings settings
 */
void SettingsWindow::apply_c()
{
    m_port=m_lineEditPort->text().toInt();
    m_pseudo=m_lineEditPseudo->text();
    m_path=m_lineEditPath->text();

    QSettings settings;
    settings.setValue("Port", m_lineEditPort->text());
    settings.setValue("Pseudo",m_lineEditPseudo->text());
    settings.setValue("Path", m_lineEditPath->text());

    /// On emet un signal comme quoi les preferences sont à jour
    emit refresh_s();

}

/**
 * @brief SettingsWindow::cancel_c Annule la modification des reglages
 */
void SettingsWindow::cancel_c()
{
    m_lineEditPort->clear();
    m_lineEditPort->insert(QString::number(m_port));

    m_lineEditPseudo->clear();
    m_lineEditPseudo->insert(m_pseudo);

    m_lineEditPath->clear();
    m_lineEditPath->insert(m_path);

    close();
}


///Destructeur
SettingsWindow::~SettingsWindow()
{

}
