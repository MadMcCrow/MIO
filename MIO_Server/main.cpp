#include "mio/Starter.h"
#include "miowindow.h"

#include "video_widget/videowidget.h"
#include "settingswindow.h"
#include "startwindow.h"
#include "mio/Frame.h"
#include "log_widget/logwidget.h"
#include <QtCore>
#include <QApplication>
#include <QObject>
#include <QMessageBox>
#include <QThread>

#define RAWTEST

/*
void DataRetriever(Starter &miovicon)
{
    miovicon.worker();
}
*/

class MioThread : public QThread
{
public slots:
    void dontRun(){dr = false;}
    void doRun(){dr = true;}
protected:
    void run() { msleep(5);if(dr)exec(); }
private:
    bool dr = true;
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ///@remark start the QT window
    MIOWindow MIOMainWindow;
    Starter miovicon("192.168.0.2:801");

    QCoreApplication::setOrganizationName("MIO");
    QCoreApplication::setApplicationName("MIO-Serveur");

    //creating the Vicon Thread
    MioThread Viconthread;


    miovicon.moveToThread(&Viconthread);
    ///@remark open the settings window if the connection failed.
#ifndef RAWTEST
    QObject::connect(&miovicon,
                     SIGNAL(ConnectionFailed_s()),
                     &MIOMainWindow,
                     SLOT(showSettings_c()));
#endif
    /// pass the data
    QObject::connect(&miovicon,
                     SIGNAL(DataRetrieved_s(Frame*)),
                     &MIOMainWindow,
                     SLOT(receiveGlData_c(Frame*)));

    miovicon.connect(&Viconthread,
                         SIGNAL(started()),
                         SLOT(retrieveData()));

    QObject::connect(&app,SIGNAL(aboutToQuit()),&Viconthread,SLOT(terminate()));
    Viconthread.connect(&app,
                         SIGNAL(lastWindowClosed()),
                         SLOT(terminate()));

    ///@remark We must launch the thread
    /// @todo launch it only when adress of the Vicon Machine is entered
    Viconthread.start();

    return app.exec();
    //return 0;
}
