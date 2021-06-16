CC=g++
CFLAGS=-g -Wall   
LFLAGS=-lpthread -lwiringPi -lrt 
TARGET = pserver

all: $(TARGET)
$(TARGET): tcp_pthread_server.o  protocol_parser.o timer.o
	$(CC) $(LFLAGS) timer.o tcp_pthread_server.o protocol_parser.o -o $(TARGET)

tcp_pthread_server.o: tcp_pthread_server.cpp  
	$(CC)  tcp_pthread_server.cpp $(CFLAGS) -c  
	
timer.o: timer.hpp timer.cpp
	$(CC) timer.hpp timer.cpp $(CFLAGS) -c  

protocol_parser.o: protocol_parser.cpp protocol_parser.hpp 
	$(CC) protocol_parser.cpp $(CFLAGS) -c  

clean:
	rm -f ./*.o   