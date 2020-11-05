icloud :servermain.o Message.o Serialization.o server.o
	g++ -o icloud servermain.o message.o serialization.o server.o -lpthread -lboost_serialization
servermain.o :servermain.cpp 
	g++ -c servermain.cpp 
Message.o : ../message_tools/message.cpp
	g++ -c ../message_tools/message.cpp 
Serialization.o : ../message_tools/serialization.cpp
	g++ -c ../message_tools/serialization.cpp -lboost_serialization
server.o :server.cpp
	g++ -c server.cpp -I../ -I../message_tools
clean :
	rm *.o icloud
