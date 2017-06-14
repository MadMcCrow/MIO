#ifndef MIOWINDOW_H
#define MIOWINDOW_H

#include <startwindow.h>
#include "settingswindow.h"
#include "gl_widget/glwidget.h"
#include "log_widget/logwidget.h"
#include "video_widget/videowidget.h"
#include "chat_widget/chatwidget.h"
#include "mio/Frame.h"
#include "mionetwork.h"

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>

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

    ~MIOWindow();

/// @remark Slots personnalisés (syntaxe finissant par _c)
public slots:

    void receiveGlData_c(Frame* F);

        /**
         * @brief receivedGLnotify_c -GL widget notifies
         * Used for notifying the gl update, but could be used
         * for other things like error.
         * @todo implement other reaction
         * @see #GLWidget/notifyMIOwindow_s()
         */
        void receivedGLnotify_c();

        /**
         * @brief ErrorOnOther_c - get notified of an error
         * @param ErrCode - an indication of who failed
         * @todo implement this everywhere.
         */
        void ErrorOnOther_c(size_t ErrCode);



    /// @remark Signals personnalisés (syntaxe finissant par _s)
signals:
    void toLog_s(QString texte, int priority);

    /**
     * @brief quit_s Allows to emit a quit signal at any time
     */
    void quit_s();


    void updateGLSkeleton_s(GLSkeleton sk);
    //void updateGLShape_s(glshape sh);

    /**
     * @brief finishedGLUpdate_s
     * Specific Signal to tell all threads
     * that we're done with the Frame.
     */
    void finishedGLUpdate_s();

private:

    /// Boutons
    QPushButton *m_buttonPref;
    QPushButton *m_buttonQuit;

    /// Fenetres détachées
    SettingsWindow *m_settingsWindow;
    StartWindow *m_startWindow;

    /// Widgets principaux
    GLWidget *m_GLWidget;
    VideoWidget *m_videoWidget;
    ChatWidget *m_chatWidget;
    LogWidget *m_logWidget;
    MIONetwork *m_network;

};


#endif // MIOWINDOW_H

