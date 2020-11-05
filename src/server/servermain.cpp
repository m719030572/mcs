#include<iostream>
#include "server.h"
using namespace std;
using namespace xgc::server;
int main()
{
    cout<<"test"<<endl;
    Server listen_server("49.232.17.128",17777);
    listen_server.Init();
    listen_server.WaitforConnect();

}