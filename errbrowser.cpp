#include "errbrowser.h"

ErrBrowser::ErrBrowser(QWidget *parent) :
    QTextBrowser(parent)
{
}

ErrBrowser::~ErrBrowser()
{
}

void ErrBrowser::WriteError(std::string str)
{
    QColor prev_c = textColor();
    QColor qc;
    qc.setNamedColor(QString("red"));
    setTextColor(qc);
    append(QString(str.c_str()));
    setTextColor(prev_c);
}
