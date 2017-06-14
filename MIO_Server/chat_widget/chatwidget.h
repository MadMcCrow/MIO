#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QtNetwork>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QKeyEvent>

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    ChatWidget();

    bool lancementServeur();
    void envoyerATous(const QString &message);

    ~ChatWidget();

signals:
    void toLog_s(QString text, int priority);

private slots:
    /// On réagi à l'arrivée d'un nouveau client
    void nouvelleConnexion_c();

    /// Slot appelé à la réception de données
    void donneesRecues_c();

    /// Slot appelé à la déconnection d'un client
    void deconnexionClient_c();

    /// Appelé lors d'un click pour envoyer
    void envoyerMessage_c();

    /// Appelé lors de la saisie de "enter" par l'utilisateur pour envoyer
    void enterPressed_c();

private:

    /// Elements de présentation
    QLabel *m_chatTitre;
    QPushButton *m_buttonEnvoyerMessage;
    QTextEdit *m_chatDisplay;
    QLineEdit *m_lineChat;

    /// Adresse IP du serveur

    /// Object qui représente le serveur sur le réseau
    QTcpServer *m_serveur;

    /// Liste de clients connectés
    QList<QTcpSocket *> m_clients;

    /// Taille des messages du chat
    quint16 m_tailleMessage;


};

#endif // CHATWIDGET_H
