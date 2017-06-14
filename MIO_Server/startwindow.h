#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>


/**
 * @brief The StartWindow class
 */
class StartWindow : public QWidget
{
    /// Est lÃ  pour gÃ©rÃ©er les SIGNALS et SLOTS personnalisÃ©s
    Q_OBJECT
public:
    /// Constructor
    StartWindow();


    /// Destructor
    ~StartWindow();

/// Slots personnalises en _c
public slots:


/// Signals personnalises en _s
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

};

#endif // STARTWINDOW_H
