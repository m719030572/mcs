#include "message.h"
using xgc::message_tools::Message;
using xgc::message_tools::ControlType;
Message::Message()
{
    control_word_=ControlType::kAck;
    data_size_=10;  
    message_number_=20;  
    sender_identity_=30;  
    receiver_identity_=40;  
    check_sum_=50;
    data_="sasdasd";

}
Message::Message(ControlType control_word):control_word_(control_word)
{
    message_number_=10;
    sender_identity_=20;
    receiver_identity_=30;
    data_="null";
    CalculateDataSize();
    CalculateCheckSum();
}
Message::Message(ControlType control_word,size_t message_number,
                 unsigned int sender_identity,unsigned int receiver_identity,
                 std::string data):
        control_word_(control_word),message_number_(message_number),
        sender_identity_(sender_identity),receiver_identity_(receiver_identity),data_(data){
    CalculateDataSize();
    CalculateCheckSum();
}

void Message::SetControlWord(ControlType control_word){
    control_word_=control_word;
    CalculateCheckSum();
}

void Message::SetSenderIdentity(unsigned int sender_identity){
    sender_identity_=sender_identity;
    CalculateCheckSum();
}

void Message::SetReceiverIdentity(unsigned int receiver_identity){
    receiver_identity_=receiver_identity;
    CalculateCheckSum();
}

ControlType Message::GetControlWord(void){
    return control_word_;
}

unsigned int Message::GetSenderIdentity(void){
    return sender_identity_;
}

unsigned int Message::GetReceiverIdentity(void){
    return receiver_identity_;
}

std::string Message::GetMessageData(void){
    if(data_size_!=0)
        return data_;
}



void Message::SetMessageData(std::string data){
    data_ = data;
    CalculateDataSize();
    CalculateCheckSum();
}

void Message::CalculateDataSize(){
    if(!data_.empty())
    {
        data_size_=data_.size();
    }
    else
    {
        data_size_=0;
    }
    
}
void Message::CalculateCheckSum(){
    check_sum_=0;

}

