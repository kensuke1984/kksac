/*
 * kksac.cpp
 *
 * Created on: 2020/3/7
 * Author: kensuke
 * version 0.0.1
 */

#include <iostream>
#include "SACFile.h";

void read_test();

int main()
{
    std::cout << "Hello Wordld!\n";
    read_test();
}

void read_test() {

    std::string fname = "dat/AMM.010202E.T";
    SACFile sf0(fname);
    SACFile sf1("dat/AMM.010202E.Tsc");
    std::ifstream ifs(fname);
    //return ifs.is_open();
   // std::cout << ifs.is_open();
  //  std::cout << sf.getDelta();
    //double data[] = { 1.,2. };
    double* data = sf0.getData();
    std::cout << data[3] << std::endl;
    data = sf1.getData();
    std::cout << data[3] << std::endl;
    delete data;
    std::cout << sf0.getString(KSTNM);
    //test();

   /* for (int i = 0; i <1; i++)
    {
        std::cout << data[i] << std::endl ;
    }*/


}
