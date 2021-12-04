/*
 * core.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Alec
 */

#include "appcore.hpp"

//Initialize the static start_time member
//see https://stackoverflow.com/questions/19469475/struct-static-member-meaning-definition
struct timespec appcore::start_time = {.tv_sec = 0, .tv_nsec = 0};

//Initialize shm static members
int appcore::shm_fd = 0;


appcore::appcore()
{
	clock_gettime(CLOCK_REALTIME, &(start_time)); //get current time

	//initialize the shared memory
	createSharedMem();
}

int appcore::getElapsedTimeSeconds()
{
	timespec current_time;
	clock_gettime(CLOCK_REALTIME, &current_time);

	//Get the current seconds since program started
	int elapsed_seconds = current_time.tv_sec - start_time.tv_sec;
	long int elapsed_nanoseconds = current_time.tv_nsec - start_time.tv_nsec;

	//Ignore the nanosecond portion since all we want is seconds

	//Round the nanosecond portion
	//If greater than or equal to 0.99999... seconds, add another second
	//	if(elapsed_nanoseconds >= 500000000L)
	//	{
	//		elapsed_seconds += 1;
	//	}

	return elapsed_seconds;
}

float appcore::readSharedMemFloat(int loc)
{
	void *ptr;
	/* open the shared memory segment */
	//shm_fd = shm_open(name, O_RDONLY, 0666);
	if (shm_fd == -1) {
    	perror("in shm_open()");
		exit(1);
	}

	/* now map the shared memory segment in the address space of the process */
	ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
    	perror("in mmap()");
		exit(1);
	}

	/* now read from the shared memory region */
	printf("Content in the shared memory:\n");
	printf("    %s", ptr);
	/* remove the shared memory segment */
	if (shm_unlink(name) == -1) {
    	perror("in shm_unlink()");
		exit(1);
	}

	return 0;
}

int appcore::readSharedMemInt(int loc)
{
	void *ptr;
	ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
    	perror("in mmap()");
		exit(1);
	}
}

int appcore::writeSharedMem(int loc, float val)
{
	return 0;
}

int appcore::writeSharedMem(int loc, int val)
{
	return 0;
}

int appcore::createSharedMem()
{

	//std::cout << name;

	/* create the shared memory segment */
	shm_fd = shm_open(appcore::name, O_CREAT | O_RDWR, 0666);

	if (appcore::shm_fd == -1){
    	perror("In shm_open()");
		exit(1);
	}

}
