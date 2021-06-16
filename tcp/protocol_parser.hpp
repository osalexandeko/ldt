#ifndef PROTOCOL_PARSER_HPP
#define PROTOCOL_PARSER_HPP
#include <stdint.h>
#include<pthread.h>
#include "timer.hpp"


#define START_IND                               (0)
#define CMD_IND                                 (1)
#define PARAM_LENGTH_IND                        (2)
#define PARAM_BEGIN_IND                         (3)
						                      
#define PROT_START                              (0x01) 


typedef enum {
	PROT_CMD_EMPTY                               = 0,
	PROT_CMD_STATUS                              = 1,
	PROT_CMD_RESET                               = 2,
} PROTOCOL_CMD_T;

typedef enum {
	PROT_OK                                      = 0,
	PROT_ERROR_WRONG_CMD                         = 1,
	PROT_ERROR_WRONG_CS                          = 2,
	PROT_ERROR_WRONG_START                       = 3,
	
} PROTOCOL_STATUS_T;


/**
* protocol_parser - class.
*/
class protocol_parser{
	public:
	 
	pthread_mutex_t * _ptr_mutex = NULL;
	
	protocol_parser(){
		
	}
	
	//there is need for mutex.
	protocol_parser(pthread_mutex_t * ptr_mutex){
		_ptr_mutex = ptr_mutex;
	}
	
	~protocol_parser(){
		
	}
	
	static void print_hi(int sig){
		
		printf("hi from timer callback \r\n");
	}
	
	PROTOCOL_STATUS_T parse_and_execute(char * buff);
	
};


#endif