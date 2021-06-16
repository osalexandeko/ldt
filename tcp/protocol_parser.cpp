#include <iostream>
#include "protocol_parser.hpp"

using namespace std;

PROTOCOL_STATUS_T protocol_parser::parse_and_execute(char * buff){
		pthread_mutex_lock(_ptr_mutex);
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
					
					perform_event_by_timer( 1000, print_hi);
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
		pthread_mutex_unlock(_ptr_mutex);
		return  st;	
	}