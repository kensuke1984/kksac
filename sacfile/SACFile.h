/*
 * SACFile.h
 *
 *  Created on: 2019/11/15
 *      Author: kensuke
 */

#ifndef SACFILE_H_
#define SACFILE_H_
#include"SACHeader.h"  

class SACFile : public SACHeader {
    double* data;
    void readData();
public:
    SACFile(std::string);
    double* getData();
    virtual ~SACFile();
};

#endif /* SACFILE_H_ */
