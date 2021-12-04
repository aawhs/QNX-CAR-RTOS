/*
 * producer.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Alec
 */

#include <iostream>
#include <thread>
#include "display.hpp"

#include "appcore.hpp"
#include "commandprocessor.hpp"
#include "Producer.hpp"



int main() {

	 char tmp[256];
	 getcwd(tmp, 256);
	 cout << "Current working directory: " << tmp << endl;

	appcore ac; //create instance so that starting time is initialized
	cout << "Initial time: " << appcore::getElapsedTimeSeconds() << std::endl;

	commandprocessor cp;

	//Dataset and task number (zero indexed, so task 1 fuel is 0)
	Producer producer1("dataset-Fuel_consumption.txt", 0);

	if(producer1.openFile()){
		cout << "File stream of File: " << producer1.getFileName() << " is open"<< endl;
	}
	if(producer1.loadData()){
		cout << "Data loaded"<< endl;
	}

	thread pthread1 (&Producer::run, &producer1);
	thread pthread2 (&displayFunc);

	pthread1.join();
	pthread2.join();
	cout << "Producer Threads Ended" <<endl;

	return 0;

}
