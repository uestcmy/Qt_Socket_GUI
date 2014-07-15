#define LINUX

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

void socketsend::on_SendButton2_clicked()
{
    num=sendto(sockcli,"2\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))-0;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton3_clicked()
{
    num=sendto(sockcli,"3\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+1;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton4_clicked()
{
    num=sendto(sockcli,"4\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+2;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton5_clicked()
{
    num=sendto(sockcli,"5\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+3;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton6_clicked()
{
    num=sendto(sockcli,"6\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+4;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton7_clicked()
{
    num=sendto(sockcli,"7\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+5;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton8_clicked()
{
    num=sendto(sockcli,"8\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+6;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton9_clicked()
{
    num=sendto(sockcli,"9\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+7;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton10_clicked()
{
    num=sendto(sockcli,"10\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+8;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton11_clicked()
{
    num=sendto(sockcli,"11\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+9;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton12_clicked()
{
    num=sendto(sockcli,"12\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+10;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton13_clicked()
{
    num=sendto(sockcli,"13\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+11;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton14_clicked()
{
    num=sendto(sockcli,"14\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+12;
    textout=QString::number(num,10);
    ui->textBrowser->append(textout);
}

void socketsend::on_SendButton15_clicked()
{
    num=sendto(sockcli,"15\0",2,0,(struct sockaddr *)&addrrcv,sizeof(sockaddr))+13;
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

    addrrcv.sin_addr.s_addr=inet_addr("127.0.0.1");
    addrrcv.sin_family=AF_INET;
    addrrcv.sin_port=htons(6000);
}
