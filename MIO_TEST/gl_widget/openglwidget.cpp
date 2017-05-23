#include "openglwidget.h"

#include <QLabel>

OpenGLWidget::OpenGLWidget(): QWidget()
{
        setMinimumSize(200, 200);
        QPixmap bkgnd("/Volumes/SSHD/users/David/Desktop/MIO_logo.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

        QLabel *Titre = new QLabel("OpenGL Widget", this);


}



OpenGLWidget::~OpenGLWidget()
{

}
