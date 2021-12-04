/*
 * commandprocessor.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Karim
 */

#include "commandprocessor.hpp"

using namespace std;

int commandprocessor()
{
    // Create task pairs with task number and period length
    const int DEFAULT_PERIOD = 5;
    const int NUMBER_OF_TASKS = 5;

    vector<pair<int, int>> tasks;
    for (int i = 0; i < NUMBER_OF_TASKS; i++)
    {
        tasks.push_back(pair<int, int>(i+1, DEFAULT_PERIOD));
    }

    for (auto task : tasks)
    {
        cout << task.first << " " << task.second << endl;
    }

    // Write tasks to shared memory.

}

void updatePeriod() {
    // Get taskNum and period from user input.
    int taskNum, period;

    cout << "Enter taskNum and period:";
    cin >> taskNum >> period;

    while (taskNum < 1 or taskNum > 5)
    {
        cout << "Enter valid taskNum and period:";
        cin >> taskNum >> period;
    }

    cout << "Task:" << taskNum << ", Period: " << period << endl;

    // TODO: Write taskNum and period to shared memory.

}


