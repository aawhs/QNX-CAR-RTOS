/*
 * appcore.hpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: alec
 */

//Class to stores helper functions that can be used by the 3 components
//As well as track global state


#ifndef APPCORE_HPP_
#define APPCORE_HPP_

#include <ctime>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

class appcore
{
	public:
		appcore();
		static int getElapsedTimeSeconds();

	private:
		static struct timespec start_time; //time that program was started at
};



#endif /* APPCORE_HPP_ */
