/*
 * SACHeader.cpp
 *
 * Created on: 2019/11/18
 * Author: kensuke
 * version 0.0.1
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

bool SACHeader::getBoolean(header bool_header) {
    switch (bool_header)
    {
    case LEVEN:
        return leven;
    case LPSPOL:
        return lpspol;
    case LOVROK:
        return lovrok;
    case LCALDA:
        return lcalda;
    default:
        throw std::invalid_argument(bool_header + " is not a header for bool.");
    }
}

int SACHeader::getEnumerated(header enum_header) {
    switch (enum_header)
    {
    case IFTYPE:
        return iftype;
    case IDEP:
        return idep;
    case IZTYPE:
        return iztype;
    case IINST:
        return iinst;
    case ISTREG:
        return istreg;
    case IEVREG:
        return ievreg;
    case IEVTYP:
        return ievtyp;
    case IQUAL:
        return iqual;
    case ISYNTH:
        return isynth;
    case IMAGTYP:
        return imagtyp;
    case IMAGSRC:
        return imagsrc;
    default:
        throw std::invalid_argument(enum_header + " is not a header for enumerated.");
    }
}

double SACHeader::getValue(header value_header) {
    switch (value_header) {
    case DELTA:
        return delta;
    case DEPMIN:
        return depmin;
    case DEPMAX:
        return depmax;
    case SCALE:
        return scale;
    case ODELTA:
        return odelta;
    case B:
        return b;
    case E:
        return e;
    case O:
        return o;
    case A:
        return a;
    case T0:
        return t0;
    case T1:
        return t1;
    case T2:
        return t2;
    case T3:
        return t3;
    case T4:
        return t4;
    case T5:
        return t5;
    case T6:
        return t6;
    case T7:
        return t7;
    case T8:
        return t8;
    case T9:
        return t9;
    case F:
        return f;
    case RESP0:
        return resp0;
    case RESP1:
        return resp1;
    case RESP2:
        return resp2;
    case RESP3:
        return resp3;
    case RESP4:
        return resp4;
    case RESP5:
        return resp5;
    case RESP6:
        return resp6;
    case RESP7:
        return resp7;
    case RESP8:
        return resp8;
    case RESP9:
        return resp9;
    case STLA:
        return stla;
    case STLO:
        return stlo;
    case STEL:
        return stel;
    case STDP:
        return stdp;
    case EVLA:
        return evla;
    case EVLO:
        return evlo;
    case EVEL:
        return evel;
    case EVDP:
        return evdp;
    case MAG:
        return mag;
    case USER0:
        return user0;
    case USER1:
        return user1;
    case USER2:
        return user2;
    case USER3:
        return user3;
    case USER4:
        return user4;
    case USER5:
        return user5;
    case USER6:
        return user6;
    case USER7:
        return user7;
    case USER8:
        return user8;
    case USER9:
        return user9;
    case DIST:
        return dist;
    case AZ:
        return az;
    case BAZ:
        return baz;
    case GCARC:
        return gcarc;
    case DEPMEN:
        return depmen;
    case CMPAZ:
        return cmpaz;
    case CMPINC:
        return cmpinc;
    case XMINIMUM:
        return xminimum;
    case XMAXIMUM:
        return xmaximum;
    case YMINIMUM:
        return yminimum;
    case YMAXIMUM:
        return ymaximum;
    default:
        throw std::invalid_argument(value_header + " is not a header for double values.");
    }
}
int SACHeader::getInt(header int_header) {
    switch (int_header) {
    case NZYEAR:
        return nzyear;
    case NZJDAY:
        return nzjday;
    case NZHOUR:
        return nzhour;
    case NZMIN:
        return nzmin;
    case NZSEC:
        return nzsec;
    case NZMSEC:
        return nzmsec;
    case NVHDR:
        return nvhdr;
    case NORID:
        return norid;
    case NEVID:
        return nevid;
    case NPTS:
        return npts;
    case NWFID:
        return nwfid;
    case NXSIZE:
        return nxsize;
    case NYSIZE:
        return nysize;
    default:
        throw std::invalid_argument(int_header + " is not a header for int values.");
    }
}

std::string SACHeader::getString(header str_header) {
    switch (str_header) {
    case KSTNM:
        return kstnm;
    case KEVNM:
        return kevnm;
    case KHOLE:
        return khole;
    case KO:
        return ko;
    case KA:
        return ka;
    case KT0:
        return kt0;
    case KT1:
        return kt1;
    case KT2:
        return kt2;
    case KT3:
        return kt3;
    case KT4:
        return kt4;
    case KT5:
        return kt5;
    case KT6:
        return kt6;
    case KT7:
        return kt7;
    case KT8:
        return kt8;
    case KT9:
        return kt9;
    case KF:
        return kf;
    case KUSER0:
        return kuser0;
    case KUSER1:
        return kuser1;
    case KUSER2:
        return kuser2;
    case KCMPNM:
        return kcmpnm;
    case KNETWK:
        return knetwk;
    case KDATRD:
        return kdatrd;
    case KINST:
        return kinst;
    default:
        throw std::invalid_argument(str_header + " is not a header for int values.");
    }
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
