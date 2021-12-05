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
	Producer producer2("dataset-Engine_speed.txt", 1);
	Producer producer3("dataset-Engine_coolant_temperature.txt", 2);
	Producer producer4("dataset-Current_Gear.txt", 3);
	Producer producer5("dataset-Vehicle_speed.txt", 4);

	thread thr_command (&commandprocessor::run);
	thread thr_prod_1 (&Producer::run, &producer1);
	thread thr_prod_2 (&Producer::run, &producer2);
	thread thr_prod_3 (&Producer::run, &producer3);
	thread thr_prod_4 (&Producer::run, &producer4);
	thread thr_prod_5 (&Producer::run, &producer5);
	thread thr_display (&displayFunc);

	thr_command.join();
	cout << "Command Threads Ended" << endl;

	thr_prod_1.join();
	thr_prod_2.join();
	thr_prod_3.join();
	thr_prod_4.join();
	thr_prod_5.join();
	cout << "Producer Threads Ended" <<endl;

	thr_display.join();
	cout << "Display thread ended" << endl;


	return 0;

}
