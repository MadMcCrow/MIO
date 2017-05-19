#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>



class GLWidget;


class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:


private:

    GLWidget *glWidget;

};

#endif
