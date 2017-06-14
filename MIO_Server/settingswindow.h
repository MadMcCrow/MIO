#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QApplication>
#include<QMainWindow>
#include <QSettings>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include<QLineEdit>
#include <QFileDialog>
#include <QDesktopWidget>
#include <QBoxLayout>

/**
 * @brief The SettingsWindow class
 */
class SettingsWindow : public QWidget
{
    ///Est là pour géréer les SIGNALS et SLOTS personnalisés
    Q_OBJECT
public:
    /// Constructeur
    SettingsWindow();



    /// Destructeur
    ~SettingsWindow();


    /// @remark Signals personnalisés (syntaxe finissant par _s)
signals:
    void refresh_s();

    /// @remark Slots personnalisés (syntaxe finissant par _c)
public slots:

    /// Mettre à jour le chemin d'accès
    void setPath_c();

    /// Appliquer les modifications
    void apply_c();

    /// Annuler les modifications
    void cancel_c();


protected:
    QLabel *m_settingsTitle;
    QPushButton *m_ok;

    QPushButton *m_cancel;
    QPushButton *m_apply;

    int m_port;
    QString m_pseudo;
    QString m_path;

    QLineEdit *m_lineEditPort;
    QLineEdit *m_lineEditPseudo;
    QLineEdit *m_lineEditPath;


};

#endif // SETTINGSWINDOW_H
