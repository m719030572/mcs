#include<iostream>
#include "client.h"
#include "message.h"
using namespace std;
using namespace xgc::client;
using xgc::message_tools::Message;
using xgc::message_tools::ControlType;
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 

std::string serialize(const Message &msg)
{
    std::ostringstream os;
    boost::archive::text_oarchive archive(os);
    archive<<msg;
    // cout<<os.str()<<endl;
    return os.str();
}
 Message disSerializem(const std::string message)
{
    Message msg;
    std::istringstream is(message);
    boost::archive::text_iarchive archive(is);
    archive>>msg;
    return msg;
}

int main(){
    Client test_client;
    test_client.Init();
    test_client.ConnectServer();
    test_client.DisconnectServer();
    //Message msg;
    //string strm=serialize(msg);
    //cout<<strm<<endl;

}
