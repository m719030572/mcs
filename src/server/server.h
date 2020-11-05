#ifndef XGC_SERVER_SERVER_H
#define XGC_SERVER_SERVER_H
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/address.hpp>
static const std::string kServerIp="49.232.17.128";
static const int kListenPort=8888;
namespace xgc
{
namespace server
{
class Server
{
public:
    Server(std::string ip=kServerIp,int port=kListenPort);
    void Init();
    int ConnectServer(std::string ip=kServerIp,int port=kListenPort);
    bool IsAcceptorHasOpen();
    void WaitforConnect();
    bool SendMessage();
    void DisconnectServer();
    ~Server();

private:
    boost::asio::io_service ios_;
    boost::asio::ip::tcp::socket tcp_socket_;
    boost::asio::ip::address server_ip_;
    int server_listen_port_;
    boost::asio::ip::tcp::endpoint server_endpoint_;
    boost::asio::ip::tcp::acceptor server_acceptor_;


};

}
}

#endif