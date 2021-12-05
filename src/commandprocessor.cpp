/*
 * commandprocessor.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Karim
 */

#include "commandprocessor.hpp"

using namespace std;

commandprocessor::commandprocessor() {
	// Initialize default values in shared memory.
	init();
}

commandprocessor::~commandprocessor()
{

}

void commandprocessor::init()
{
    // Create task pairs with task number and period length
    const int DEFAULT_PERIOD = 5;
    const float DEFAULT_VALUE = 0.0f;
    const int NUMBER_OF_TASKS = 5;

    // Initialize all int values to default period.
	for(int i = 0; i < 5; i++)
	{
		appcore::writeSharedMem(i, DEFAULT_PERIOD);
	}


	// Initialize all float values to default values
	for(int i=5; i<10;i++)
	{
		appcore::writeSharedMem(i, DEFAULT_VALUE);
	}
}

void commandprocessor::updatePeriod() {
    // Get taskNum and period from user input.
    int taskNum, period;

    cout << "Enter task number (1 to 5) and period: ";
    cin >> taskNum >> period;

    while (taskNum < 1 or taskNum > 5)
    {
        cout << "Enter valid task number (1 to 5) and period: ";
        cin >> taskNum >> period;
    }

    // Write period to shared memory for given taskNum.
    appcore::writeSharedMem(taskNum-1, period);
}

void commandprocessor::run()
{
	while(true)
	{
		updatePeriod();
	}
}


