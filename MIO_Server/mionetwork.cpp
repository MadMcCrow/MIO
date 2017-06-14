#include "mionetwork.h"


void MIONetwork::startNetworking_c()
{
        delete m_server;
        m_server = new QTcpServer(this);
        /// Démarrage du serveur sur toutes les IP disponibles et sur le port définit dans les préférences (doit être compris entre 1 024 et 65 535)
        /// @todo add settings support
        QSettings Settings;
        int port = Settings.value("Port").toInt();
        if (port < 1024 || port > 65535)
            port = 50585;
        if (!m_server->listen(QHostAddress::Any, port))
        {
            /// Si le serveur n'a pas été démarré correctement
            emit toLog_s(" <br/>Le serveur n'a pas pu être démarré correctement. Raison :<br/>" + m_server->errorString(), 1);
            return;
        }
        else /// Si le serveur a été démarré correctement
        {
            emit toLog_s("<br/>Le serveur a démarré sur le port " + QString::number(m_server->serverPort()) + "<br/> et sur les adresses IP", 1);

            /// On liste toutes les adresses de la machine
            QList<QHostAddress> hosts = QNetworkInterface::allAddresses();

            for (int i = 0; i < hosts.count(); ++i)
            {
                /// On affiche les adresses au format ipv4 dans le log
                if (hosts[i].protocol() == QAbstractSocket::IPv4Protocol)
                    emit toLog_s(hosts[i].toString(), 1);
            }


            emit toLog_s("<br/> Des utilisateurs peuvent maintenant se connecter. ", 1);


            /// connecte un signal qui écoute l'arrivée d'un client.
            connect(m_server, SIGNAL(newConnection()), this, SLOT(newConnection_c()));

        }
}

void MIONetwork::sendData_c(quint8 key, QDataStream &stream)
{
    //On prépare le paquet à envoyer

        ///QByteArray est une suite d'octets
        QByteArray paquet;
        QDataStream out(&paquet, QIODevice::WriteOnly);

        /// On écrit un 0 d'entête réservé à la caractérisation du paquet
        out << (quint8)key;
        /// On écrit 0 au début du paquet pour réserver la place pour écrire la taille
        out << (quint16) sizeof(stream);
        /// On ajoute le message à la suite
        out << stream;
        /// Envoi du paquet préparé à tous les clients connectés au serveur
            for (int i = 0; i < m_clients.size(); i++)
            {
                m_clients[i]->write(paquet);
            }
}


void MIONetwork::newConnection_c(){

}

void MIONetwork::endConnection_c(){

}

void MIONetwork::qtcpReceived_c(){
    static quint16 packetSize = 0;
    static quint8  packetType;
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender()); /// let socket be what the sender is. (some sort of reverse cast)
     if (socket == 0) ///< if error, exit @see http://doc.qt.io/qt-5/qobject.html#qobject_cast
         return;

     /// Constructs a data stream that uses the I/O device socket.
     QDataStream in(socket);

     /// Si on ne connaît pas encore la taille du message, on essaie de la récupérer
     if (packetSize == 0)
     {
         /// if no header: return.
         if ((size_t) socket->bytesAvailable() < sizeof(quint16) + sizeof(quint8))
             return;
         /// Si on a reçu l'entête tailleMessage+caractérisation
         in >> packetSize;
         in >> packetType;
         emit toLog_s("Message en reception, taille ="+ QString::number(packetSize) + " type = " + QString::number(packetType), 1);
     }
     if (socket->bytesAvailable() < packetSize)
         return;
    else{
         emit receivedData_s(packetType,in);
         packetSize = 0;
         packetType = 0;
     }
     return;
}
