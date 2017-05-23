#include "mio/Starter.h"
#include "miowindow.h"

#include "gl_widget/openglwidget.h"
#include "video_widget/videowidget.h"
#include "settingswindow.h"
#include "startwindow.h"
#include "mio/Frame.h"
#include "log_widget/logwidget.h"

#include <QApplication>
#include <QObject>
#include <QMessageBox>

Frame Current;
void DataRetriever(Starter &miovicon)
{
    miovicon.worker();

}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ///@remark start the QT window
    MIOWindow MIOMainWindow;
        Starter miovicon("localhost:801");
        /// pass the data
        QObject::connect(&miovicon, SIGNAL(DataRetrieved_s(Frame)),
                         &MIOMainWindow, SLOT(ReceiveGlData_c(Frame)));

    std::thread DataDog_t([&miovicon](){DataRetriever(miovicon);}); ///< because it's a retriever ;)

    return app.exec();
    //return 0;
}
