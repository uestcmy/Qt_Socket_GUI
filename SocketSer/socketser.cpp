#include <stdio.h>
#include <sys/resource.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <arpa/inet.h>

#include "socketser.h"
#include "ui_socketser.h"

extern char buff[100];
extern int sockser;
extern socklen_t size;
extern sockaddr_in addrrcv;
extern socketser w;

socketser::socketser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::socketser)
{
    ui->setupUi(this);
}

socketser::~socketser()
{
    delete ui;
}

void socketser::on_pushButton_clicked()
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);
    pthread_t enb_dl_phy_thread;
    pthread_create(&enb_dl_phy_thread, NULL,recv_thread_start, NULL);
}

void * recv_thread_start(void *ptr)
{
    while(1)
    {
        recvfrom(sockser,&buff,sizeof(buff),0,(struct sockaddr *)&addrrcv,&size);
        w.printtext();
    }
    pthread_exit(NULL);
}

int socketser::printtext()
{
    ui->textBrowser->append(buff);
    return 0;
}
