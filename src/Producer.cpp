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
    openFile();
    loadData();
    tasknumber = task;
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
	int datasize = dataVector.size()-1;
	while(index < datasize){
	#ifdef DEBUG
		cout << "Producer Thread Started" <<endl;
	#endif

		elapsedTime = appcore::getElapsedTimeSeconds();
		period = appcore::readSharedMemInt(tasknumber);
		data = dataVector[elapsedTime];

		appcore::writeSharedMem(tasknumber+5,data);
	#ifdef DEBUG
		cout << "Elapsed Time : " << elapsedTime <<" Data : "<<appcore::readSharedMemFloat(tasknumber+5)<<endl;
		cout << "Producer Thread Suspended" <<endl;
	#endif
		index += period;
		sleep(period);
	}
}


