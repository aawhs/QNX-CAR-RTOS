/*
 * producer.hpp
 *
 *  Created on: Nov. 7, 2021
 *      Author: Ahmed
 */

#ifndef PRODUCER_HPP_
#define PRODUCER_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "appcore.hpp"

using namespace std;
class Producer
{
private:

    //Data Members
   string filename = "";
   ifstream filestream;
   float data = 0.0;
   vector <float> dataVector;

public:

    //Constructor & Deconstructor
    Producer(string);
    ~Producer();

    //Setters and getters
    void setFileName(string);
    string getFileName();

    //File stream
    bool openFile();

    //Get Data
    bool loadData();

    void run();
};

#endif /* PRODUCER_HPP_ */
