#ifndef PROTOCOL_PARSER_HPP
#define PROTOCOL_PARSER_HPP
#include <stdint.h>


//test 01 02 05 20 71 77 65 72 

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



class protocol_parser{
	public:
	PROTOCOL_CMD_T cmd = PROT_CMD_EMPTY;
	
	
	protocol_parser(){
		
	}
	
	~protocol_parser(){
		
	}
	
	PROTOCOL_STATUS_T parse_and_execute(char * buff){
		
		PROTOCOL_STATUS_T st = PROT_OK;
		
		 
		
		if(PROT_START != buff[START_IND]){
			st = PROT_ERROR_WRONG_START;
		}else if(PROT_CMD_EMPTY == buff[CMD_IND]){
			st = PROT_ERROR_WRONG_CMD;
		}
		else{
			switch(buff[CMD_IND]){
				case PROT_CMD_STATUS:{
					printf("PROT_CMD_STATUS \n\r");
					break;
				}
				
				case PROT_CMD_RESET:{
					printf("PROT_CMD_RESET \n\r");
					break;
				}
				
				default:{
					st = PROT_ERROR_WRONG_CMD;
					printf("PROT_ERROR_WRONG_CMD \n\r");
				}
			}
		}	
		return  st;	
	}
	
};


#endif