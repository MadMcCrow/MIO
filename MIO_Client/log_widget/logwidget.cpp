#include "logwidget.h"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QTextEdit>

LogWidget::LogWidget() :QWidget()
{
    /// Titre du layout
    m_logTitre = new QLabel("Log");
    /// Case de texte réglée en lecture seule
    m_logDisplay = new QTextEdit;
    m_logDisplay->setReadOnly(true);

    /// On organise les éléments dans un layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_logTitre, 0, 0, 1, 1);
    layout->addWidget(m_logDisplay, 1, 0, 1, 1);
    setLayout(layout);

}




LogWidget::~LogWidget()
{


}
