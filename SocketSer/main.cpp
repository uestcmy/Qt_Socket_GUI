
#include <unistd.h>
#include <sys/types.h>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include <QtGui/QApplication>
#include "socketser.h"

#define LINUX

#ifdef LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#endif

char buff[100];
socklen_t size;
int num;
sockaddr_in addrSrv,addrrcv;
int sockser;

int argc;
char *argv[100];
QApplication a(argc, argv);
socketser w;

int main()
{
    //w.setsocketinitialize();
    size=sizeof(sockaddr_in);
    sockser=socket(AF_INET,SOCK_DGRAM,0);
    addrSrv.sin_addr.s_addr=htonl(INADDR_ANY);
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(6000);

    bind(sockser,(sockaddr*)&addrSrv,sizeof(sockaddr));

    w.show();

    return a.exec();
}
