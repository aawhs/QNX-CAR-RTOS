/*
 * display.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Tianyang
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <chrono>
#include <thread>
#include "display.hpp"
#include <iostream>


void displayFunc(){

	while (1) {

		std::cout<<"Fuel Consumption | Engine Speed (RPM) | Engine Coolant Temperature | Current Gear | Vehicle Speed"<<std::endl;
		for(int i = 0; i < 5; i++){
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout<<appcore::readSharedMemFloat(5)<<"\t \t \t"<<appcore::readSharedMemFloat(6)<<"\t \t"<<appcore::readSharedMemFloat(7)<<"\t \t \t \t"<<appcore::readSharedMemFloat(8)<<"\t \t"<<appcore::readSharedMemFloat(9)<<std::endl;
		}
	}
}
