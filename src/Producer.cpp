/*
 * producer.cpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Ahmed
 */

#include "Producer.hpp"


//Constructors

Producer::Producer(string fileName)
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
	int index = 0;
	while(index < 20){
		cout << "Producer Thread Started" <<endl;
		elapsedTime = appcore::getElapsedTimeSeconds();
		data = dataVector[elapsedTime];
		index+=5;
		cout << "Elapsed Time : " << elapsedTime <<" Data : "<<data<<endl;
		cout << "Producer Thread Suspended" <<endl;
		sleep(5);
	}
}


