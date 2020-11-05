#ifndef XGC_MESSAGE_TOOLS_MESSAGE_H
#define XGC_MESSAGE_TOOLS_MESSAGE_H
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include<stdint.h>
#include<string>
#include<string>
#include<boost/serialization/access.hpp>
namespace xgc::message_tools
{
enum class ControlType : uint8_t
{
    kVideo,
    kVoice,
    kOpintion,
    kLogin,
    kLogout,
    kAck,
    kSendPort
};
class Message
{
public:
    Message ();
    explicit Message(ControlType control_word);
    Message(ControlType conrtol_word,
            size_t message_number,
            unsigned int sender_identity,
            unsigned int receiver_identity,
            std::string data);
    void SetControlWord(ControlType control_word);
    void SetSenderIdentity(unsigned int sender_identity);
    void SetReceiverIdentity(unsigned int receiver_identity); 
    void SetMessageData(std::string data);
    ControlType GetControlWord(void);
    std::string GetMessageData(void);
    unsigned int GetSenderIdentity(void);
    unsigned int GetReceiverIdentity(void);
    template<class Archive>
    void serialize(Archive&ar,const uint version);
    

private:
    friend class boost::serialization::access;
    void CalculateCheckSum(void);
    void CalculateDataSize(void);
    ControlType control_word_;
    size_t data_size_;  // 标识数据区的长度
    size_t message_number_;  // 表示这个消息在消息流的位置
    unsigned int sender_identity_;  // 标识发送方的信息
    unsigned int receiver_identity_;  // 标识接收方的信息
    unsigned int check_sum_;  // 校验头部信息准确性
    std::string data_;  // 数据信息
};
template<class Archive>
void Message::serialize(Archive &ar,const uint version)
{
    ar & control_word_ & data_size_ & message_number_ & sender_identity_ &
         receiver_identity_ & check_sum_ & data_ ;
}

} 

#endif