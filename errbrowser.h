#ifndef ERRBROWSER_H
#define ERRBROWSER_H

#include <QTextBrowser>
#include <string>

class ErrBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    explicit ErrBrowser(QWidget *parent);

    ~ErrBrowser();

    void WriteError(std::string str);

signals:

public slots:

};

#endif // ERRBROWSER_H
