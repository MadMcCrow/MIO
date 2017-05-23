/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *serveurIP;
    QLabel *label_2;
    QSpinBox *serveurPort;
    QPushButton *boutonConnexion;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QTextEdit *listeMessages;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *pseudo;
    QLabel *label_4;
    QLineEdit *message;
    QPushButton *boutonEnvoyer;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QStringLiteral("ChatWidget"));
        ChatWidget->resize(628, 480);
        QIcon icon;
        icon.addFile(QStringLiteral("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChatWidget->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(ChatWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ChatWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        serveurIP = new QLineEdit(ChatWidget);
        serveurIP->setObjectName(QStringLiteral("serveurIP"));
        serveurIP->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(serveurIP);

        label_2 = new QLabel(ChatWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        serveurPort = new QSpinBox(ChatWidget);
        serveurPort->setObjectName(QStringLiteral("serveurPort"));
        serveurPort->setMinimumSize(QSize(60, 0));
        serveurPort->setMinimum(1024);
        serveurPort->setMaximum(65535);
        serveurPort->setValue(50885);

        horizontalLayout->addWidget(serveurPort);

        boutonConnexion = new QPushButton(ChatWidget);
        boutonConnexion->setObjectName(QStringLiteral("boutonConnexion"));

        horizontalLayout->addWidget(boutonConnexion);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        listeMessages = new QTextEdit(ChatWidget);
        listeMessages->setObjectName(QStringLiteral("listeMessages"));
        listeMessages->setReadOnly(true);

        verticalLayout_2->addWidget(listeMessages);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(ChatWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        pseudo = new QLineEdit(ChatWidget);
        pseudo->setObjectName(QStringLiteral("pseudo"));
        pseudo->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(pseudo);

        label_4 = new QLabel(ChatWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        message = new QLineEdit(ChatWidget);
        message->setObjectName(QStringLiteral("message"));

        horizontalLayout_2->addWidget(message);

        boutonEnvoyer = new QPushButton(ChatWidget);
        boutonEnvoyer->setObjectName(QStringLiteral("boutonEnvoyer"));
        boutonEnvoyer->setIcon(icon);

        horizontalLayout_2->addWidget(boutonEnvoyer);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QApplication::translate("ChatWidget", "Chat Widget - Client", Q_NULLPTR));
        label->setText(QApplication::translate("ChatWidget", "IP du serveur :", Q_NULLPTR));
        serveurIP->setText(QApplication::translate("ChatWidget", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChatWidget", "Port du serveur :", Q_NULLPTR));
        boutonConnexion->setText(QApplication::translate("ChatWidget", "Connexion", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChatWidget", "Pseudo :", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChatWidget", "Message :", Q_NULLPTR));
        boutonEnvoyer->setText(QApplication::translate("ChatWidget", "Envoyer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
