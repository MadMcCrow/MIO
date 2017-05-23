#ifndef CHATWIDGET_H
#define CHATWIDGET_H


#include <QtWidgets>
#include <QtNetwork>
#include "ui_chatwidget.h"

class ChatWidget : public QWidget, private Ui::ChatWidget
{
    Q_OBJECT

    public:
        ChatWidget(QMainWindow *MainWindow);

        ~ChatWidget();

    private slots:
        /// Pour se connecter au serveur
        void on_boutonConnexion_clicked();

        /// Appelé lors d'un click pour envoyer
        void on_boutonEnvoyer_clicked();

        /// Appelé lors de la saisie de "enter" par l'utilisateur pour envoyer
        void on_message_returnPressed();

        /// Appelé quand on recoit un paquet du serveur
        void donneesRecues();

        /// Appelé lorsqu'on s'est connecté au serveur
        void connecte();

        /// Appelé lorsqu'on souhaite se déconnecter du serveur
        void deconnecte();

        /// Appelé quand il y a une erreur sur le réseau
        void erreurSocket(QAbstractSocket::SocketError erreur);

    private:
        /// Socket qui représente le serveur
        QTcpSocket *m_socket;

        /// Taille du message
        quint16 m_tailleMessage;


};

#endif // CHATWIDGET_H
