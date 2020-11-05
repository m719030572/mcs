#include "server.h"
#include <boost/lexical_cast.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include "config.h"
#include "serialization.h"
#include "message.h"
using xgc::server::Server;
using namespace xgc::message_tools;
using xgc::message_tools::Serialization;
using boost::asio::ip::tcp;
using boost::asio::ip::address;
using boost::asio::io_service;
using boost::asio::buffer;
using namespace std;
using namespace boost;
class RelationUint//装有一对链接的客户，存端口号，表示一对连接
{
    public:
    int client1;
    int client2;
    int port;
};

class ConnectManager
{
public:
    static list<RelationUint> ConnectList;//装有现有连接
    RelationUint createConnect();
};

Server::Server(std::string ip,int port)
        :ios_(),tcp_socket_(ios_),
        server_ip_(server_ip_.from_string(ip)),
        server_listen_port_(port),
        server_endpoint_(tcp::v4(),server_listen_port_),
        server_acceptor_(ios_,server_endpoint_){
    xgclog<<"server constrcuting."<<xgcendl;
    xgclog<<"server constructed."<<xgcendl;
}
Server::~Server()
{
    ;
}
void Server::Init()
{
    xgclog<<"server init."<<xgcendl;
    xgclog<<"server init success."<<xgcendl;

}

void Server::WaitforConnect()
{

    xgclog<<"server listening for "<<server_ip_<<":"<<server_listen_port_<<xgcendl;
    xgclog<<"max listen is "<<tcp_socket_.max_listen_connections<<xgcendl;
    server_acceptor_.accept(tcp_socket_);
    xgclog<<"client:ip:"<<tcp_socket_.remote_endpoint().address()<<"\tport:"<<tcp_socket_.remote_endpoint().port()<<xgcendl;
    Message ack_message(ControlType::kAck);
    string message=Serialization::serialize(ack_message);
    tcp_socket_.write_some(buffer(message));
    xgclog<<"service sending Ack:"<<message<<xgcendl;
    boost::array<char,1000> msgs;
    tcp_socket_.read_some(buffer(msgs));
    std::string msg=msgs.data();
    Message r_message=Serialization::disSerialize(msg);
    if(r_message.GetControlWord()==ControlType::kAck)
    {
        xgclog<<"socket has been connected."<<xgcendl;
    }
    else
    {
        xgclog<<"connection error."<<xgcendl;
    }
    
}

bool Server::IsAcceptorHasOpen()
{
    return server_acceptor_.is_open();
}