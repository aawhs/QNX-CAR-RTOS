/*
 * appcore.hpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Alec
 */

//Class to stores helper functions that can be used by the 3 components
//As well as track global state


#ifndef APPCORE_HPP_
#define APPCORE_HPP_

#include <ctime>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

//for shared mem
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>


class appcore
{
	public:
		appcore();
		static int getElapsedTimeSeconds();
		static float readSharedMemFloat(int loc);
		static int readSharedMemInt(int loc);
		static int writeSharedMem(int loc, float val);
		static int writeSharedMem(int loc, int val);
		static int dumpSharedMem();


	private:
		static struct timespec start_time; //time that program was started at

		static int shm_fd;
		static constexpr char *name = "/my_shm";
		static const int SHM_SIZE = 64;

		static int createSharedMem();

};



#endif /* APPCORE_HPP_ */
