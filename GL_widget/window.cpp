#include "glwidget.h"
#include "window.h"
#include "mainwindow.h"
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>
#include <QMessageBox>

Window::Window()
{
    glWidget = new GLWidget;

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *container = new QHBoxLayout;
    container->addWidget(glWidget);


    QWidget *w = new QWidget;
    w->setLayout(container);
    mainLayout->addWidget(w);
    setLayout(mainLayout);


    setWindowTitle(tr("GL Viewport"));
}




void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}
