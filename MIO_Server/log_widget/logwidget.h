#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QFile>
#include <QStandardPaths>


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

signals:
    void toLog_s(QString texte, int priority);

public slots:

void writeInLog_c(QString texte, int priority);

private:
    QTextEdit *m_logDisplay;
    QLabel *m_logTitre;
    QFile m_file;
    int m_priorite;
};

#endif // LOGWINDOW_H
