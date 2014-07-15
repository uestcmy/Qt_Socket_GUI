#define LINUX

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
#pragma comment(lib, "ws2_32.lib")
#endif

#include <QtGui/QApplication>
#include "socketsend.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    socketsend w;
    w.setsocketinitialize();
    w.show();
    
    return a.exec();
}
