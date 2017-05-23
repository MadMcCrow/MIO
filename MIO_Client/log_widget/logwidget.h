#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>

/**
 * @brief The LogWidget class Contains the log elements include in the main window
 */
class LogWidget : public QWidget
{
    /// Est là pour gérer des slots et les signals
    Q_OBJECT
public:
    LogWidget();

    ~LogWidget();
public slots:
    //void writeInLog_c(QString);


private:
    QTextEdit *m_logDisplay;
    QLabel *m_logTitre;
};

#endif // LOGWINDOW_H
