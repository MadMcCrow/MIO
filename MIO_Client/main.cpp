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


/*
void DataRetriever(Starter &miovicon)
{
    miovicon.worker();
}
*/

class MioThread : public QThread
{
protected:
    void run() { exec(); }
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ///@remark start the QT window
    MIOWindow MIOMainWindow;
    Starter miovicon("localhost:801");

    //creating the Vicon Thread
    MioThread Viconthread;

    miovicon.moveToThread(&Viconthread);
    ///@remark open the settings window if the connection failed.
    QObject::connect(&miovicon,
                     SIGNAL(ConnectionFailed_s()),
                     &MIOMainWindow,
                     SLOT(showSettings_c()));

    /// pass the data
    QObject::connect(&miovicon,
                     SIGNAL(DataRetrieved_s(Frame*)),
                     &MIOMainWindow,
                     SLOT(receiveGlData_c(Frame*)));

    miovicon.connect(&Viconthread,
                         SIGNAL(started()),
                         SLOT(retrieveData()));

    ///@remark We must launch the thread
    /// @todo launch it only when adress of the Vicon Machine is entered
    Viconthread.start();

    return app.exec();
    //return 0;
}
