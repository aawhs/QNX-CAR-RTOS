/*
 * producer.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Ahmed
 */

#include "Producer.hpp"


//Constructors

Producer::Producer(string fileName, int task)
{
    setFileName(fileName);
}

Producer::~Producer()
{

}

void Producer::setFileName(string fileName)
{
    filename = fileName;
}

string Producer::getFileName()
{
    return filename;
}

void Producer::setTaskNumber(int task)
{
	tasknumber = task;
}

int Producer::getTaskNumber()
{
	return tasknumber;
}

bool Producer::openFile()
{
    filestream.open(filename);
        if(!filestream){
            cerr << "Error: file " << filename << " could not be opened" <<endl;
            exit(1);
        }
    return true;
}


bool Producer::loadData()
{
    filestream >> data;
    while(!filestream.eof()){
        dataVector.push_back(data);
        filestream >> data;
    }

    cout << "Data " << filename << " record count: " << dataVector.size() << endl;

    if(filestream.eof()){
        return true;
    }
    return false;
}

void Producer::run()
{
	int elapsedTime;
	int period;
	int index = 0;
	while(index < dataVector.size()-1){
		cout << "Producer Thread Started" <<endl;

		elapsedTime = appcore::getElapsedTimeSeconds();
		period = appcore::readSharedMemInt(tasknumber);
		data = dataVector[elapsedTime];

		appcore::writeSharedMem(tasknumber+5,data);

		cout << "Elapsed Time : " << elapsedTime <<" Data : "<<appcore::readSharedMemFloat(tasknumber+5)<<endl;
		cout << "Producer Thread Suspended" <<endl;

		sleep(period);
	}
}


