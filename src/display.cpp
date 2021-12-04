#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <chrono>
#include <thread>


static void task_body(void) {
	static int cycles = 0;
	static uint64_t start;
	uint64_t current;
	struct timespec tv;

	const char *messgae1 = "/m1";
	const char *messgae2 = "/m2";
	const char *messgae3 = "/m3";
	const char *messgae4 = "/m4";
	const char *messgae5 = "/m5";
	const int SIZE = 4096;
	int shm_fd;
	//void *ptr1, ptr2, ptr3, ptr4, ptr5;


	/*
	//get first message
	//open the shared memory segment
	shm_fd = shm_open(messgae1, O_RDONLY, 0666);
	if (shm_fd == -1) {
    	perror("in shm_open()");
		exit(1);
	}
	//now map the shared memory segment in the address space of the process
	ptr1 = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr1 == MAP_FAILED) {
    	perror("in mmap()");
		exit(1);
	}

	//remove the shared memory segment
	if (shm_unlink(messgae1) == -1) {
    	perror("in shm_unlink()");
		exit(1);
	}


	//second message
	shm_fd = shm_open(messgae2, O_RDONLY, 0666);
	if (shm_fd == -1) {
    	perror("in shm_open()");
		exit(1);
	}

	//now map the shared memory segment in the address space of the process
	ptr2 = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr2 == MAP_FAILED) {
    	perror("in mmap()");
		exit(1);
	}

	//remove the shared memory segment
	if (shm_unlink(messgae2) == -1) {
    	perror("in shm_unlink()");
		exit(1);
	}


	//third message
	shm_fd = shm_open(messgae3, O_RDONLY, 0666);
	if (shm_fd == -1) {
    	perror("in shm_open()");
		exit(1);
	}

	//now map the shared memory segment in the address space of the process
	ptr3 = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr3 == MAP_FAILED) {
    	perror("in mmap()");
		exit(1);
	}

	//remove the shared memory segment
	if (shm_unlink(name) == -1) {
    	perror("in shm_unlink()");
		exit(1);
	}


	//fourth message
	shm_fd = shm_open(messgae4, O_RDONLY, 0666);
	if (shm_fd == -1) {
    	perror("in shm_open()");
		exit(1);
	}

	//now map the shared memory segment in the address space of the process
	ptr4 = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr4 == MAP_FAILED) {
    	perror("in mmap()");
		exit(1);
	}

	//remove the shared memory segment
	if (shm_unlink(name) == -1) {
    	perror("in shm_unlink()");
		exit(1);
	}

	//fifth message
	shm_fd = shm_open(messgae5, O_RDONLY, 0666);
	if (shm_fd == -1) {
    	perror("in shm_open()");
		exit(1);
	}

	//now map the shared memory segment in the address space of the process
	ptr5 = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if (ptr5 == MAP_FAILED) {
    	perror("in mmap()");
		exit(1);
	}

	//remove the shared memory segment
	if (shm_unlink(name) == -1) {
    	perror("in shm_unlink()");
		exit(1);
	}
	*/


	fprintf(stderr,"the first message is: \n");
	//fprintf(stderr,ptr1);
	fprintf(stderr,"the second message is: \n");
	//fprintf(stderr,ptr2);
	fprintf(stderr,"the third message is: \n");
	//fprintf(stderr,ptr3);
	fprintf(stderr,"the fourth message is: \n");
	//fprintf(stderr,ptr4);
	fprintf(stderr,"the fifth message is: \n");
	//fprintf(stderr,ptr5);
		//fprintf(stderr, "Ave interval between instances: %f millisecons\n",
			//(double)(current-start)/cycles);

}


void displayFunc(){

	while (1) {
		//wait_next_activation(); //wait for timer expiration
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		task_body(); //executes the task
	}
}
