/*
 * producer.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Alec
 */

#include <iostream>


#include "appcore.hpp"


//The IPC system is essentially a 5 variable fan out / 5 variable fan in
//But implemented with shared memory


int main() {
	//std::cout << "Hello World!!!" << std::endl; // prints Hello World!!!

	appcore ac; //create instance so that starting time is initialized
	std::cout << "Initial time: " << ac.getElapsedTimeSeconds() << std::endl;




	//IPC for command input task -> producer tasks

	//IPC for producer tasks -> consumer task


	//Create the command processor instance


	//Create the 5 producer instances


	//Create the consumer (display) instance





	return 0;

}
