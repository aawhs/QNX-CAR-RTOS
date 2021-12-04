/*
 * producer.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Alec
 */

#include <iostream>
#include <thread>

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
	cp.init();

	Producer producer1("dataset-Fuel_consumption.txt");

	if(producer1.openFile()){
		cout << "File stream of File: " << producer1.getFileName() << " is open"<< endl;
	}
	if(producer1.loadData()){
		cout << "Data loaded"<< endl;
	}

	thread pthread1 (&Producer::run, &producer1);

	pthread1.join();
	cout << "Producer Thread Ended" <<endl;

	return 0;

}
