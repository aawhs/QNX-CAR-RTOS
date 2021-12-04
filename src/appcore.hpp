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
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>

/* We specify the header as being at least a pulse */
/* All of your messages should start with this header */
/* This struct contains a type/subtype field as the first 4 bytes.
 * The type and subtype field can be used to identify the message that is being received.
/ * This allows you to identify data which isn't destined for your server. */
typedef struct _pulse msg_header_t;

class appcore
{
	public:
		appcore();
		static int getElapsedTimeSeconds();

	private:
		static struct timespec start_time; //time that program was started at
};



#endif /* APPCORE_HPP_ */
