#ifndef XGC_SERVER_CONNECT_MANAGER_H
#define XGC_SERVER_CONNECT_MANAGER_H
#include "server.h"
#include <list>
#include <boost/asio
#include <boost/thread.hpp>
namespace xgc
{
namespace server
{
class ConnectManager


private：
    Server *listen_server;
    std::list<socket*> client_list;

};
}
#endif