#define WIN

#ifdef LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#endif

#ifdef WIN
#include <Winsock2.h>
#include <Windows.h>
#include <WinSock.h>
#include <winerror.h>
#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")
#endif

#ifndef SOCKETSEND_H
#define SOCKETSEND_H

#include <QWidget>

namespace Ui {
class socketsend;
}

class socketsend : public QWidget
{
    Q_OBJECT
    
public:
    explicit socketsend(QWidget *parent = 0);

    long num;
    QString textout;

    //add recv text
//    socklen_t size_test;
//    int num_test;
//    char buff_test[100];
//    sockaddr_in addrSrv_test,addrrcv_test;
//    int sockser_test;
    //

    #ifdef LINUX
    struct sockaddr_in addrSrv,addrrcv;
    #endif

    #ifdef WIN
    SOCKADDR_IN addrSrv,addrrcv;
    #endif

    #ifdef LINUX
    int sockcli;
    #endif

    #ifdef WIN
    SOCKET sockcli;
    #endif

    void setsocketinitialize();

    ~socketsend();
    
private slots:
    void on_SendButton0_clicked();

    void on_SendButton1_clicked();

private:
    Ui::socketsend *ui;
};

#endif // SOCKETSEND_H
