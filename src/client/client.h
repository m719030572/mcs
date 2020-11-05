#ifndef XGC_CLIENT_CLIENT_H
#define XGC_CLIENT_CLIENT_H
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/address.hpp>
static const std::string kServerIp="49.232.17.128";
static const int kListenPort=17777;
namespace xgc
{
namespace client
{
class Client
{
public:
    Client(/* args */);
    void Init(std::string ip=kServerIp,int port=kListenPort);
    int ConnectServer(std::string ip=kServerIp,int port=kListenPort);
    void DisconnectServer();
    ~Client();

private:
   boost::asio::io_service ios_;
   boost::asio::ip::tcp::socket tcp_socket_;
   boost::asio::ip::tcp::endpoint server_endpoint_;

};

}
}

#endif