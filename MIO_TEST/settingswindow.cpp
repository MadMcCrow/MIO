#include "settingswindow.h"
#include "startwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include <QSettings>

/**
 * @brief Fenêtre de préférences
 */
SettingsWindow::SettingsWindow(QMainWindow *MainWindow) : QWidget()
{
    /// Paramètres de base de la fenêtre
    //setMinimumSize(300, 500);
    move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    setWindowTitle("MIO Settings");

    /// Initialisation des attributs avec leur valeurs par défaut

    m_settingsTitle = new QLabel("Préferenes Serveur");

    QLabel *IPServeur = new QLabel("Adresse IP du Serveur");
    m_lineEditIP = new QLineEdit("127.0.0.1");
    //m_lineEditIP->setInputMask(QString("000.000.000.0;_"));
    m_IP = "127.0.0.1";

    QLabel *PortServeur = new QLabel("Port du Serveur");
    m_lineEditPort = new QLineEdit("50858");
    m_port = 50858;

    QLabel *pathLabel = new QLabel("Chemin d'enregistrement");
    m_lineEditPath = new QLineEdit;
    m_lineEditPath->setReadOnly(true);
    QPushButton *browsePath = new QPushButton("Browse");

    QLabel *pseudoLabel = new QLabel("Pseudo");
    m_lineEditPseudo = new QLineEdit("Client");


    /// Boutons

    m_ok = new QPushButton("Ok");
    m_ok->setDefault(true);
    m_apply = new QPushButton("Appliquer");
    m_cancel = new QPushButton("Annuler");


    /// Mise en place des éléments sur la page

    QVBoxLayout *VLayout = new QVBoxLayout;
    VLayout->addWidget(m_settingsTitle);

    QHBoxLayout *HLayoutIP = new QHBoxLayout;
    HLayoutIP->addWidget(IPServeur);
    HLayoutIP->addWidget(m_lineEditIP);
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

    QHBoxLayout *HLayoutBottom = new QHBoxLayout;
    HLayoutBottom->addWidget(m_cancel);
    HLayoutBottom->addWidget(m_apply);
    HLayoutBottom->addWidget(m_ok);
    VLayout->addLayout(HLayoutBottom);



    setLayout(VLayout);

    /// Connections
    ///
    QObject::connect(m_cancel,SIGNAL(clicked()), this, SLOT(cancel_c()));
    QObject::connect(m_apply,SIGNAL(clicked()), this, SLOT(apply_c()));
    QObject::connect(m_ok, SIGNAL(clicked()), this, SLOT(apply_c()));
    QObject::connect(m_ok, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(browsePath, SIGNAL(clicked()), this, SLOT(setPath_c()));

}

/// Getteurs

QString SettingsWindow::getPseudo()
{

    return m_pseudo;
}


/// Public slots

void SettingsWindow::writeSettings()
{
    QSettings settings("MIO", "ISIS");

    settings.beginGroup("Settings");
    settings.setValue("IP", m_IP);
    settings.setValue("Port", m_port);
    settings.setValue("Pseudo", m_pseudo);
    settings.setValue("Path", m_path);

    settings.endGroup();
}


void SettingsWindow::readSettings()
{
    QSettings settings("MIO", "ISIS");

    settings.beginGroup("Settings");
    //m_IP(settings.value("IP", QString()));
    //m_port=settings.value("pos").toInt;
    settings.endGroup();
}

void SettingsWindow::setPath_c()
{
    m_lineEditPath->insert(QFileDialog::getExistingDirectory(this));
}

void SettingsWindow::apply_c()
{
    m_IP=m_lineEditIP->text();
    m_port=m_lineEditPort->text().toInt();
    m_pseudo=m_lineEditPseudo->text();
    m_path=m_lineEditPath->text();
}

void SettingsWindow::cancel_c()
{
    m_lineEditIP->clear();
    m_lineEditIP->insert(m_IP);

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
