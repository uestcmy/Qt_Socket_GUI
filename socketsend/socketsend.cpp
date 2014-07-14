#define WIN

#ifdef LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#endif

#ifdef WIN
#include <Winsock2.h>
#include <Windows.h>
#include <WinSock.h>
#include <winerror.h>
#include <winsock.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")
#endif

#include "socketsend.h"
#include "ui_socketsend.h"

socketsend::socketsend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::socketsend)
{
    ui->setupUi(this);
}

socketsend::~socketsend()
{
    delete ui;
}

void socketsend::on_SendButton0_clicked()
{
    num=sendto(sockcli,"0\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))-2;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton1_clicked()
{
    num=sendto(sockcli,"1\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))-1;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::setsocketinitialize()
{
    #ifdef WIN
    WSADATA	wsaData;
    if(WSAStartup(MAKEWORD(2,0),&wsaData)!=0)
    {
        ui->textBrowser->append("WSAStartup ERROR!");
    }
    #endif

    sockcli=socket(AF_INET,SOCK_DGRAM,0);
    addrSrv.sin_addr.s_addr=htonl(INADDR_ANY);
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(6001);
    bind(sockcli,(sockaddr*)&addrSrv,sizeof(sockaddr));

    addrrcv.sin_addr.s_addr=inet_addr("192.168.128.71");
    addrrcv.sin_family=AF_INET;
    addrrcv.sin_port=htons(6000);
}
