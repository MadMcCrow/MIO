#include "logwidget.h"

LogWidget::LogWidget() :QWidget()
{
    /// Titre du layout
    m_logTitre = new QLabel("Log");
    /// Case de texte réglée en lecture seule
    m_logDisplay = new QTextEdit;
    m_logDisplay->setReadOnly(true);

    /// On organise les éléments dans un layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_logTitre, 0, 0, 1, 1);
    layout->addWidget(m_logDisplay, 1, 0, 1, 1);
    setLayout(layout);

    /// On définit le chemin d'enregistrement du fichier et on ouvre un log file
    QString path(QStandardPaths::DesktopLocation+"MIOLog.rtf");
    m_file.setFileName("/Volumes/SSHD/users/David/Desktop/Hello.txt");

    /// On ouvre le fichier
    m_file.open(QIODevice::WriteOnly);

    /// On définit la priorité par défaut à 0
    m_priorite=0;
}

/**
 * @brief LogWidget::writeInLog_c Slot pour afficher un message dans le log
 * @param texte
 * @param priority
 */
void LogWidget::writeInLog_c(QString texte, int priority)
{
    /// On affiche uniquement si la priorité de l'info est assez haute par rapport au choix de l'utilisateur
    if (priority > m_priorite)
        m_logDisplay->append(texte);

    /// On créé un data stream
    QDataStream out(&m_file);
    /// we will serialize the data into the file
    out << texte;
    //std::cout << texte << std::endl;
}


LogWidget::~LogWidget()
{


}
