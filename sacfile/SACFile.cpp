/*
 * SACFile.cpp
 *
 *  Created on: 2019/11/15
 *      Author: kensuke
 */

#include "SACFile.h"
#include<iostream>
float read_binary_as_float(std::istream&);

SACFile::SACFile(std::string sac_path) :
    SACHeader(sac_path) {
    readData();
}

SACFile::~SACFile() {
    delete[] data;
}

double* SACFile::getData() {
    double* data = new double[npts];
    memcpy(data, SACFile::data, npts);
    return data;
}

void SACFile::readData() {
    const char* sacfile = file_path.c_str();
    std::ifstream fin(sacfile, std::ios::in | std::ios::binary);
    if (!fin) {
        std::cout << file_path << " is funny." << std::endl;
    }
    fin.seekg(632);
    data = new double[npts];
    for (int i = 0; i < npts; i++)
        data[i] = read_binary_as_float(fin);
    fin.close();
}
float read_binary_as_float(std::istream& is) {
    float val;
    is.read((char*)&val, sizeof(float));
    return val;
}
