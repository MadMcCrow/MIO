#include "mio/Starter.h"
#include "miowindow.h"

#include "gl_widget/openglwidget.h"
#include "video_widget/videowidget.h"
#include "settingswindow.h"
#include "startwindow.h"
#include "log_widget/logwidget.h"

#include <QApplication>
#include <QObject>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    Starter *miovicon = new Starter();

    QApplication app(argc, argv);

    ///@remark start the QT window
    MIOWindow *MIOMainWindow = new MIOWindow;


    ///@remark modify the GL widget content
    GLWidget Temp;
    Temp.setSkeleton(miovicon->getFirstSkeleton());

    delete miovicon;
    return app.exec();
}
