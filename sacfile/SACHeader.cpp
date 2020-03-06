/*
 * SACHeader.cpp
 *
 *  Created on: 2019/11/18
 *      Author: kensuke
 */

#include <iostream>
#include <fstream>
#include "SACHeader.h"

template<typename T> T read_binary_as(std::istream& is);
std::string read_string(int, std::istream&);

SACHeader::SACHeader(std::string sac_path) {
    file_path = sac_path;
    read();
}
double SACHeader::getDelta() {
    return delta;
}
SACHeader::~SACHeader() {
    // TODO Auto-generated destructor stub
}
void SACHeader::read() {
    const char* sacfile = file_path.c_str();
    std::ifstream fin(sacfile, std::ios::in | std::ios::binary);
    if (!fin) {
        std::cout << file_path << " is funny." << std::endl;
    }
    delta = read_binary_as<float>(fin);
    depmin = read_binary_as<float>(fin); //4
    depmax = read_binary_as<float>(fin); //8
    scale = read_binary_as<float>(fin); //12
    odelta = read_binary_as<float>(fin); //16
    b = read_binary_as<float>(fin); //20
    e = read_binary_as<float>(fin); //24
    o = read_binary_as<float>(fin); //28
    a = read_binary_as<float>(fin); //32
    num9 = read_binary_as<float>(fin); //36
    t0 = read_binary_as<float>(fin); //40
    t1 = read_binary_as<float>(fin); //44
    t2 = read_binary_as<float>(fin); //48
    t3 = read_binary_as<float>(fin); //52
    t4 = read_binary_as<float>(fin); //56
    t5 = read_binary_as<float>(fin); //60
    t6 = read_binary_as<float>(fin); //64
    t7 = read_binary_as<float>(fin); //68
    t8 = read_binary_as<float>(fin); //72
    t9 = read_binary_as<float>(fin); //76
    f = read_binary_as<float>(fin); //80
    resp0 = read_binary_as<float>(fin); //84
    resp1 = read_binary_as<float>(fin); //88
    resp2 = read_binary_as<float>(fin); //92
    resp3 = read_binary_as<float>(fin); //96
    resp4 = read_binary_as<float>(fin); //100
    resp5 = read_binary_as<float>(fin); //104
    resp6 = read_binary_as<float>(fin); //108
    resp7 = read_binary_as<float>(fin); //112
    resp8 = read_binary_as<float>(fin); //116
    resp9 = read_binary_as<float>(fin); //120
    stla = read_binary_as<float>(fin);
    stlo = read_binary_as<float>(fin);
    stel = read_binary_as<float>(fin);
    stdp = read_binary_as<float>(fin);
    evla = read_binary_as<float>(fin);
    evlo = read_binary_as<float>(fin);
    evel = read_binary_as<float>(fin);
    evdp = read_binary_as<float>(fin);
    mag = read_binary_as<float>(fin);
    user0 = read_binary_as<float>(fin);
    user1 = read_binary_as<float>(fin);
    user2 = read_binary_as<float>(fin);
    user3 = read_binary_as<float>(fin);
    user4 = read_binary_as<float>(fin);
    user5 = read_binary_as<float>(fin);
    user6 = read_binary_as<float>(fin);
    user7 = read_binary_as<float>(fin);
    user8 = read_binary_as<float>(fin);
    user9 = read_binary_as<float>(fin);
    dist = read_binary_as<float>(fin);
    az = read_binary_as<float>(fin);
    baz = read_binary_as<float>(fin);
    gcarc = read_binary_as<float>(fin);
    num54 = read_binary_as<float>(fin);
    num55 = read_binary_as<float>(fin);
    depmen = read_binary_as<float>(fin);
    cmpaz = read_binary_as<float>(fin);
    cmpinc = read_binary_as<float>(fin);
    xminimum = read_binary_as<float>(fin);
    xmaximum = read_binary_as<float>(fin);
    yminimum = read_binary_as<float>(fin);
    ymaximum = read_binary_as<float>(fin);
    num63 = read_binary_as<float>(fin);
    num64 = read_binary_as<float>(fin);
    num65 = read_binary_as<float>(fin);
    num66 = read_binary_as<float>(fin);
    num67 = read_binary_as<float>(fin);
    num68 = read_binary_as<float>(fin);
    num69 = read_binary_as<float>(fin);
    nzyear = read_binary_as<int>(fin);
    nzjday = read_binary_as<int>(fin);
    nzhour = read_binary_as<int>(fin);
    nzmin = read_binary_as<int>(fin);
    nzsec = read_binary_as<int>(fin);
    nzmsec = read_binary_as<int>(fin);
    nvhdr = read_binary_as<int>(fin);
    norid = read_binary_as<int>(fin);
    nevid = read_binary_as<int>(fin);
    npts = read_binary_as<int>(fin);
    num80 = read_binary_as<int>(fin);
    nwfid = read_binary_as<int>(fin);
    nxsize = read_binary_as<int>(fin);
    nysize = read_binary_as<int>(fin);
    num84 = read_binary_as<int>(fin);
    iftype = read_binary_as<int>(fin);
    idep = read_binary_as<int>(fin);
    iztype = read_binary_as<int>(fin);
    num88 = read_binary_as<int>(fin);
    iinst = read_binary_as<int>(fin);
    istreg = read_binary_as<int>(fin);
    ievreg = read_binary_as<int>(fin);
    ievtyp = read_binary_as<int>(fin);
    iqual = read_binary_as<int>(fin);
    isynth = read_binary_as<int>(fin);
    imagtyp = read_binary_as<int>(fin);
    imagsrc = read_binary_as<int>(fin);
    num97 = read_binary_as<int>(fin);
    num98 = read_binary_as<int>(fin);
    num99 = read_binary_as<int>(fin);
    num100 = read_binary_as<int>(fin);
    num101 = read_binary_as<int>(fin);
    num102 = read_binary_as<int>(fin);
    num103 = read_binary_as<int>(fin);
    num104 = read_binary_as<int>(fin);
    leven = read_binary_as<int>(fin);
    lpspol = read_binary_as<int>(fin);
    lovrok = read_binary_as<int>(fin);
    lcalda = read_binary_as<int>(fin);
    num109 = read_binary_as<int>(fin);
    kstnm = read_string(8, fin);
    kevnm = read_string(16, fin);
    khole = read_string(8, fin);
    ko = read_string(8, fin);
    ka = read_string(8, fin);
    kt0 = read_string(8, fin);
    kt1 = read_string(8, fin);
    kt2 = read_string(8, fin);
    kt3 = read_string(8, fin);
    kt4 = read_string(8, fin);
    kt5 = read_string(8, fin);
    kt6 = read_string(8, fin);
    kt7 = read_string(8, fin);
    kt8 = read_string(8, fin);
    kt9 = read_string(8, fin);
    kf = read_string(8, fin);
    kuser0 = read_string(8, fin);
    kuser1 = read_string(8, fin);
    kuser2 = read_string(8, fin);
    kcmpnm = read_string(8, fin);
    knetwk = read_string(8, fin);
    kdatrd = read_string(8, fin);
    kinst = read_string(8, fin);
    fin.close();
}

std::string read_string(int length, std::istream& is) {
    char* buffer = new char[length + 1];
    is.read(buffer, sizeof(char) * length);
    buffer[length] = '\0';
    std::string str = buffer;
    return str;
}

template<typename T> T read_binary_as(std::istream& is) {
    T val;
    is.read((char*)&val, sizeof(T));
    return val;
}
