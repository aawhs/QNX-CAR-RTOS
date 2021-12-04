/*
 * commandprocessor.hpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Karim
 */

#ifndef COMMANDPROCESSOR_HPP_
#define COMMANDPROCESSOR_HPP_


#include "appcore.hpp"
#include <vector>
#include <iostream>

class commandprocessor {
public:
	commandprocessor();
	static void updatePeriod();
private:
	static void init();
};


#endif /* COMMANDPROCESSOR_HPP_ */
