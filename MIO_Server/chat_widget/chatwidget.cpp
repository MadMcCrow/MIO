#include "chatwidget.h"

ChatWidget::ChatWidget():QWidget()
{
    /// Initialisation des widgets du chat
    m_chatTitre = new QLabel("Chat");
    m_buttonEnvoyerMessage = new QPushButton("Envoyer");
    m_chatDisplay = new QTextEdit;
    m_chatDisplay->setReadOnly(true);
    m_lineChat = new QLineEdit;
    m_tailleMessage = 0;

    /// Disposition des widgets

    QVBoxLayout *Vlayout = new QVBoxLayout;
    Vlayout->addWidget(m_chatTitre);
    Vlayout->addWidget(m_chatDisplay);

    QHBoxLayout *Hlayout = new QHBoxLayout;
    Hlayout->addWidget(m_lineChat);
    Hlayout->addWidget(m_buttonEnvoyerMessage);

    Vlayout->addLayout(Hlayout);
    setLayout(Vlayout);


    /// Gestion du clavier

    // On créé l'évenement
    //QKeyEvent PressEnter(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
    //keyPressEvent(PressEnter);

    /// Connections
    connect(m_buttonEnvoyerMessage, SIGNAL(clicked()), this, SLOT(envoyerMessage_c()));

}


/**
 * @brief ChatWidget::lancementServeur Lance le QTcpServer
 * @return the state of the server
 */
bool ChatWidget::lancementServeur()
{

    /// Création d'un QTcpServer
    m_serveur = new QTcpServer(this);

    /// Démarrage du serveur sur toutes les IP disponibles et sur le port définit dans les préférences (doit être compris entre 1 024 et 65 535)
    if (!m_serveur->listen(QHostAddress::Any, 50585))
    {
        /// Si le serveur n'a pas été démarré correctement
        emit toLog_s(" <br/>Le serveur du chat n'a pas pu être démarré. Raison :<br/>" + m_serveur->errorString(), 1);
        return false;
    }
    else /// Si le serveur a été démarré correctement
    {

        emit toLog_s("<br/>Le chat a été démarré sur le port " + QString::number(m_serveur->serverPort()) + "<br/> et sur les adresses IP", 1);

        /// On liste toutes les adresses de la machine
        QList<QHostAddress> hosts = QNetworkInterface::allAddresses();

        for (int i = 0; i < hosts.count(); ++i)
        {
            /// On affiche les adresses au format ipv4 dans le log
            if (hosts[i].protocol() == QAbstractSocket::IPv4Protocol)
                emit toLog_s(hosts[i].toString(), 1);
        }


        emit toLog_s("<br/> Des utilisateurs peuvent maintenant se connecter. ", 1);


        /// On créé un signal qui écoute l'arrivée d'un client et le connecte
        connect(m_serveur, SIGNAL(newConnection()), this, SLOT(nouvelleConnexion_c()));

    }
    return true;
}




/**
 * @brief ChatWidget::nouvelleConnexion_c Slot réagissant à l'arrivée d'un nouvel utilisateur sur le chat
 */
void ChatWidget::nouvelleConnexion_c()
{
    envoyerATous("<em>Un nouvel utilisateur vient de se connecter</em>");
    emit toLog_s("<br/>Nouvelle connection au chat, adresse du client :", 1);


    /// Chaque client est représenté par un QTcpSocket
    QTcpSocket *nouveauClient = m_serveur->nextPendingConnection();

    emit toLog_s(nouveauClient->localAddress().toString(), 1);

    /// On met le nouveau client dans le tableau de client
    m_clients << nouveauClient;

    /// On signale que le nouveaux client a envoyé des données
    connect(nouveauClient, SIGNAL(readyRead()), this, SLOT(donneesRecues_c()));

    /// On signale que le client s'est déconnecté
    connect(nouveauClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient_c()));
}


/**
 * @brief ChatWidget::donneesRecues_c Slot réagissant à la réception de données
 */
void ChatWidget::donneesRecues_c()
{
    /// on reçoit un paquet (ou un sous-paquet) d'un des clients

    /// On détermine quel client envoie le message à l'aide de sender() qui renvoie le QObject à l'origine de l'envoi
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) /// Si on a un souci, on arrête la méthode
        return;

    /// Si tout va bien, on met dans in le socket du client
    QDataStream in(socket);

    /// Si on ne connaît pas encore la taille du message, on essaie de la récupérer
    if (m_tailleMessage == 0)
    {
        /// Si on n'a pas reçu la taille du message en entier, on sort de la méthode
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        /// Si on a reçu la taille du message en entier, on la récupère
        in >> m_tailleMessage;
        //emit toLog_s("Message en reception, taille ="+ QString::number(m_tailleMessage), 1);
    }

    /// Si on n'a pas encore tout reçu, on arrête la méthode
    if (socket->bytesAvailable() < m_tailleMessage)
        return;


    /// On stoque dans message le le flux
    QString message;
    in >> message;


    /// On renvoie le message à tous les clients
    envoyerATous(message);


    /// Remise de la taille du message à 0 pour permettre la réception des futurs messages
    m_tailleMessage = 0;
}

/**
 * @brief ChatWidget::deconnexionClient_c Slot appelé à la déconnection d'un client
 */
void ChatWidget::deconnexionClient_c()
{

    /// On détermine quel client se déconnecte
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    /// Si par hasard on n'a pas trouvé le client à l'origine du signal, on arrête la méthode
    if (socket == 0)
        return;

    /// On notifie la déconnection d'un client
    envoyerATous("<em>Un utilisateur vient de se déconnecter</em>");

    emit toLog_s("<br/> Un client vient de se déconnecter à l'adresse :", 1);
    emit toLog_s(socket->localAddress().toString(), 1);


    m_clients.removeOne(socket);

    /// On delete le socket plus tard pour éviter de supprimer le pointeur trop tôt
    socket->deleteLater();
}

/**
 * @brief ChatWidgetClient::envoyerMessage_c Slot pour envoyer le message
 */
void ChatWidget::envoyerMessage_c()
{
    if (m_lineChat->text()!="") // Si la case n'est pas vide
    {

        ///On créé un objet settings pour récupérer le nom du pseudo
        QSettings settings;

        envoyerATous("<strong>" + settings.value("Pseudo").toString() +"</strong> : " + m_lineChat->text());



        /// On vide la zone d'écriture du message
        m_lineChat->clear();

        /// On met le curseur à l'intérieur
        m_lineChat->setFocus();
    }
}

/**
 * @brief ChatWidgetClient::enterPressed_c Slot lorsequ'on appuie sur la touche entrée du chat
 */
void ChatWidget::enterPressed_c()
{
    envoyerMessage_c();
}


/**
 * @brief ChatWidget::envoyerATous On envoie un message à tous
 * @param message String contenant le message à envoyer
 */
void ChatWidget::envoyerATous(const QString &message)
{
    /// Préparation du paquet, QByteArray est une suite d'octets
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    /// On écrit 0 au début du paquet pour réserver la place pour écrire la taille
    out << (quint16) 0;
    /// On ajoute le message à la suite
    out << message;
    /// On se replace au début du paquet
    out.device()->seek(0);
    /// On écrase le 0 qu'on avait réservé par la longueur du message
    out << (quint16) (paquet.size() - sizeof(quint16));
    /// Envoi du paquet préparé à tous les clients connectés au serveur
    for (int i = 0; i < m_clients.size(); i++)
    {
        m_clients[i]->write(paquet);
    }
    /// On affiche le message sur la zone de Chat
    m_chatDisplay->append(message);

}

ChatWidget::~ChatWidget()
{

}
