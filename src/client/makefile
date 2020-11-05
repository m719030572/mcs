FILEDIR=$(HOME)/codes/git/xgc/src
CC=g++ 
BOOSTLIB=/home/ubuntu/boost_1_73_0/stage/lib
BOOSTINC=-I/home/ubuntu/boost_1_73_0/include
client :main.o client.o message.o serialization.o 
	g++ -o client main.o client.o message.o serialization.o -lpthread -lboost_serialization -lboost_iostreams
	
main.o : clientmain.cpp client.h 
	g++ -c clientmain.cpp -o main.o -I../message_tools
client.o:client.cpp client.h
	g++ -c client.cpp -o client.o -I../ -I../message_tools
message.o: ../message_tools/message.cpp ../message_tools/message.h
	g++ -c /home/ubuntu/codes/git/xgc/src/message_tools/message.cpp -I../message_tools -I../ -o message.o
serialization.o: ../message_tools/serialization.cpp ../message_tools/serialization.h
	g++ -c ../message_tools/serialization.cpp -I../message_tools
clean:
	rm *.o client
