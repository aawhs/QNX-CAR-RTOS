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

    if(filestream.eof()){
        return true;
    }
    return false;
}

void Producer::run()
{
   int elapsedTime;
   while(true){
        cout << "Producer Thread Started" << endl;
        elapsedTime = appcore::getElapsedTime();
        data = dataVector(elapsedTime)
        cout << "Elapsed Time : " << elapsedTime << " - " << " data : " << data <<endl;
        cout << "Producer Thread Ended" << endl;
        Thread::thread.sleep(5);
   }
 
}


