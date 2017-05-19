#include "mainwindow.h"
#include "window.h"
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>

MainWindow::MainWindow()
{
    setCentralWidget(new Window());
    QMenuBar *menuBar = new QMenuBar;
    QMenu *menuWindow = menuBar->addMenu(tr("&Window"));
    QAction *addNew = new QAction(menuWindow);
    addNew->setText(tr("Add new"));
    menuWindow->addAction(addNew);
    connect(addNew, &QAction::triggered, this, &MainWindow::onAddNew);
    setMenuBar(menuBar);
}

void MainWindow::onAddNew()
{
    if (!centralWidget())
        setCentralWidget(new Window());
    else
        QMessageBox::information(0, tr("Cannot add new window"), tr("Already occupied. Undock first."));
}
