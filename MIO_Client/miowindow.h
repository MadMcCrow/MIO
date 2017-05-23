#ifndef MIOWINDOW_H
#define MIOWINDOW_H

#include <settingswindow.h>
#include <gl_widget/openglwidget.h>
#include <log_widget/logwidget.h>
#include <video_widget/videowidget.h>
#include <chat_widget/chatwidget.h>
#include <startwindow.h>
#include <gl_widget/glwidget.h>
#include <mio/Frame.h>

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QMainWindow>

/**
 * @brief The MIOWindow class
 */
class MIOWindow : public QMainWindow // On hérite de QMainWindow
{
    //Est là pour géréer les SIGNALS et SLOTS personnalisés
    Q_OBJECT
public:
    //Default constructor
    MIOWindow();

    SettingsWindow *getSettings();
    ~MIOWindow();

    const GLWidget *getglWidgetContent();

/// @remark Slots personnalisés (syntaxe finissant par _c)
public slots:

    void showSettings_c();
    void quit_c();
    void ReceiveGlData_c(Frame F);

/// @remark Signals personnalisés (syntaxe finissant par _s)
signals:
    /**
     * @brief quit_s Allows to emit a quit signal at any time
     */
    void quit_s();

    /**
     * @brief changeGL_s -
     */
    void changeGlWidget_s(GLSkeleton sk);



private:
    /// Bouttons
    QPushButton *m_buttonPref;
    QPushButton *m_buttonQuit;

    /// Fenêtres
    SettingsWindow *m_settingsWindow;
    StartWindow *m_startWindow;

    /// Widgets
    //OpenGLWidget *m_openGLWidget;
    LogWidget *m_logWidget;
    VideoWidget *m_videoWidget;
    ChatWidget *m_chatWidget;
    GLWidget *m_glWidget;

};


#endif // MIOWINDOW_H

