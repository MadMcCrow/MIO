#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QMessageBox>
#include <QBoxLayout>

/**
 * @brief The StartWindow class
 */
class StartWindow : public QWidget
{
    //Est là pour géréer les SIGNALS et SLOTS personnalisés
    Q_OBJECT
public:
    StartWindow(QMainWindow *MainWindow);


    ~StartWindow();

/// Slots personnalisés
public slots:


/// Signals personnalisés
signals:

private:
    /// Texte de demarrage
    QLabel *m_labelTexte;

    /// Versions du logiciel
    QLabel *m_labelInfos;

    /// Credits
    QLabel *m_labelCredits;

    /// Logo de demarrage
    QLabel *m_logo;

    /// Boutons
    QPushButton *m_buttonStart;
    QPushButton *m_buttonQuit;


};

#endif // STARTWINDOW_H
