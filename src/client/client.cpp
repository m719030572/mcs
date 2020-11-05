#include "client.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include "config.h"
#include "message.h"
#include "serialization.h"
using boost::asio::ip::tcp;
using boost::asio::ip::address; 
using boost::asio::io_service;
using boost::asio::buffer;
using xgc::client::Client;
using namespace xgc::message_tools;
using namespace std;
Client::Client():ios_(),tcp_socket_(ios_){
    

}
Client::~Client()
{
    ;
}
void Client::Init(std::string ip,int port){
    xgclog<<"client starting."<<xgcendl;
    address addr=addr.from_string(ip);
    assert(addr.is_v4());
    xgclog<<addr.to_string()<<xgcendl;
    tcp::endpoint ep(addr,port);
    server_endpoint_=ep;
    xgclog<<"client started."<<xgcendl;
    
}

int Client::ConnectServer(std::string ip,int listen_port){
    xgclog<<"client connecting."<<xgcendl;
    tcp_socket_.connect(server_endpoint_);
    boost::array<char,1000> msgs;
    tcp_socket_.read_some(buffer(msgs));
    std::string msg=msgs.data();
    cout<<"msgs:"<<msg<<endl;
    Message r_message=Serialization::disSerialize(msg);
    if(r_message.GetControlWord()==ControlType::kAck)
    {
        xgclog<<"recive from ip:"<<tcp_socket_.remote_endpoint().address()<<"\t port:"<<tcp_socket_.remote_endpoint().port()<<xgcendl;
        xgclog<<"recive ACK from server."<<xgcendl;
        xgclog<<"socket has been connected."<<xgcendl;
        Message ack_message(ControlType::kAck);
        tcp_socket_.write_some(buffer(Serialization::serialize(ack_message)));
    }
}
void Client::DisconnectServer()
{
    tcp_socket_.close();
}
