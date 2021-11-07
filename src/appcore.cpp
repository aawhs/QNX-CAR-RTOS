/*
 * core.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: alec
 */

#include "appcore.hpp"

//Initialize the static start_time member
//see https://stackoverflow.com/questions/19469475/struct-static-member-meaning-definition
struct timespec appcore::start_time = {.tv_sec = 0, .tv_nsec = 0};

appcore::appcore()
{
	clock_gettime(CLOCK_REALTIME, &(start_time)); //get current time
}

int appcore::getElapsedTimeSeconds()
{
	timespec current_time;
	clock_gettime(CLOCK_REALTIME, &current_time);

	//Get the current seconds since program started
	int elapsed_seconds = current_time.tv_sec - start_time.tv_sec;
	long int elapsed_nanoseconds = current_time.tv_nsec - start_time.tv_nsec;

	//Round the nanosecond portion
	//If greater than or equal to 0.5 seconds, add another second
	if(elapsed_nanoseconds >= 500000000L)
	{
		elapsed_seconds += 1;
	}

	return elapsed_seconds;
}
