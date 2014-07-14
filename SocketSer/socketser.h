
#include <unistd.h>
#include <sys/types.h>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#ifndef SOCKETSER_H
#define SOCKETSER_H

#include <QWidget>

void * recv_thread_start(void *ptr);
//socklen_t size;
//int num;
//sockaddr_in addrSrv,addrrcv;
//int sockser;

namespace Ui {
class socketser;
}

class socketser : public QWidget
{
    Q_OBJECT
    
public:
    explicit socketser(QWidget *parent = 0);

    //void printxfun();

    ~socketser();

    int printtext();

    //void setsocketinitialize();

private slots:

    void on_pushButton_clicked();


private:
    Ui::socketser *ui;
};

#endif // SOCKETSER_H
