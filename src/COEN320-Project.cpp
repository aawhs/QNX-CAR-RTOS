/*
 * producer.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Alec
 */

#include <iostream>


#include "appcore.hpp"
#include "Producer.hpp"


//The messaging system is essentially a 5 queue fan out / 5 queue fan in

//Struct for messages from Command to Producers
typedef struct _command_msg{
    msg_header_t hdr;
    int update_freq;
} command_msg_t;

//Struct for messages from Producers to Display
typedef struct _producer_msg{
    msg_header_t hdr;
    float value;
} producer_msg_t;

//Command input to producers attach points
#define ATTACH_INPUT_TO_PRODUCER_1 "c2p_1"
#define ATTACH_INPUT_TO_PRODUCER_2 "c2p_2"
#define ATTACH_INPUT_TO_PRODUCER_3 "c2p_3"
#define ATTACH_INPUT_TO_PRODUCER_4 "c2p_4"
#define ATTACH_INPUT_TO_PRODUCER_5 "c2p_5"


//Producers to display attach points
#define ATTACH_PRODUCER_1_TO_DISPLAY "p2d_1"
#define ATTACH_PRODUCER_2_TO_DISPLAY "p2d_2"
#define ATTACH_PRODUCER_3_TO_DISPLAY "p2d_3"
#define ATTACH_PRODUCER_4_TO_DISPLAY "p2d_4"
#define ATTACH_PRODUCER_5_TO_DISPLAY "p2d_5"



int main() {

	 char tmp[256];
	 getcwd(tmp, 256);
	 cout << "Current working directory: " << tmp << endl;

	appcore ac; //create instance so that starting time is initialized
	cout << "Initial time: " << ac.getElapsedTimeSeconds() << std::endl;

	Producer producer1("dataset-Fuel_consumption.txt");
	if(producer1.openFile()){
		cout << "File stream of File: " << producer1.getFileName() << " is open"<< endl;
	}
	if(producer1.loadData()){
		cout << "Data loaded"<< endl;
	}

	return 0;

}
