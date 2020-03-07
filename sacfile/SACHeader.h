/*
 * SACHeader.h
 *
 * Created on: 2019/11/18
 * Author: kensuke
 * version 0.0.1
 */

#ifndef SACHEADER_H_
#define SACHEADER_H_
#include<fstream>
enum header {
    DELTA, // 0
    /*
    * Minimum value of dependent variable.
    */
    DEPMIN, // 1
    /**
    * Maximum value of dependent variable.
    */
    DEPMAX, // 2
    /**
    * Multiplying scale factor for dependent variable [not currently used]
    */
    SCALE, // 3
    /**
    * Observed increment if different from nominal value.
    */
    ODELTA, // 4
    /**
    * Beginning value of the independent variable. [required]
    */
    B, // 5
    /**
    * Ending value of the independent variable. [required]
    */
    E, // 6
    /**
    * Event origin time (seconds relative to reference time.)
    */
    O, // 7
    /**
    * First arrival time (seconds relative to reference time.)
    */
    A, // 8
    /**
    * INTERNAL (no use)
    */
    num9, // 9
    /**
    * User defined time picks or markers, n = 0 - 9 (seconds relative to
    * reference time).
    */
    T0, // 10
    /**
    * @see #T0
    */
    T1, // 11
    /**
    * @see #T0
    */
    T2, // 12
    /**
    * @see #T0
    */
    T3, // 13
    /**
    * @see #T0
    */
    T4, // 14
    /**
    * @see #T0
    */
    T5, // 15
    /**
    * @see #T0
    */
    T6, // 16
    /**
    * @see #T0
    */
    T7, // 17
    /**
    * @see #T0
    */
    T8, // 18
    /*
    * @see #T0
    */
    T9, // 19
    /**
    * Fini or end of event time (seconds relative to reference time.)
    */
    F, // 20
    /**
    * Instrument response parameters, n=0,9. [not currently used]
    */
    RESP0, // 21
    /**
    * @see #RESP0
    */
    RESP1, // 22
    /**
    * @see #RESP0
    */
    RESP2, // 23
    /**
    * @see #RESP0
    */
    RESP3, // 24
    /**
    * @see #RESP0
    */
    RESP4, // 25
    /**
    * @see #RESP0
    */
    RESP5, // 26
    /**
    * @see #RESP0
    */
    RESP6, // 27
    /**
    * @see #RESP0
    */
    RESP7, // 28
    /**
    * @see #RESP0
    */
    RESP8, // 29
    /**
    * @see #RESP0
    */
    RESP9, // 30
    /**
    * Station latitude (degrees, north positive)
    */
    STLA, // 31
    /**
    * Station longitude (degrees, east positive).
    */
    STLO, // 32
    /**
    * Station elevation above sea level (meters). [not currently used]
    */
    STEL, // 33
    /**
    * Station depth below surface (meters). [not currently used]
    */
    STDP, // 34
    /**
    * Event latitude (degrees, north positive).
    */
    EVLA, // 35
    /**
    * Event longitude (degrees, east positive).
    */
    EVLO, // 36
    /**
    * Event elevation (meters). [not currently used]
    */
    EVEL, // 37
    /**
    * Event depth below surface (meters). [not currently used]
    */
    EVDP, // 38
    /**
    * Event magnitude.
    */
    MAG, // 39

    /**
    * User defined variable storage area, n = 0,9.
    * (0, 1: for filter band)
    */
    USER0, // 40
    /**
    * @see #USER0
    */
    USER1, // 41
    /**
    * @see #USER0
    */
    USER2, // 42
    /**
    * @see #USER0
    */
    USER3, // 43
    /**
    * @see #USER0
    */
    USER4, // 44
    /**
    * @see #USER0
    */
    USER5, // 45
    /**
    * @see #USER0
    */
    USER6, // 46
    /**
    * @see #USER0
    */
    USER7, // 47
    /**
    * @see #USER0
    */
    USER8, // 48
    /**
    * @see #USER0
    */
    USER9, // 49

    /**
    * Station to event distance (km).
    */
    DIST, // 50
    /**
    * Event to station azimuth (degrees).
    */
    AZ, // 51
    /**
    * Station to event azimuth (degrees).
    */
    BAZ, // 52
    /**
    * Station to event great circle arc length (degrees).
    */
    GCARC, // 53
    /**
    * INTERNAL
    */
    num54, // 54
    /**
    * INTERNAL
    */
    num55, // 55
    /**
    * Mean value of dependent variable.
    */
    DEPMEN, // 56
    /**
    * Component azimuth (degrees clockwise from north).
    */
    CMPAZ, // 57
    /**
    * Component incident angle (degrees from vertical).
    */
    CMPINC, // 58
    /**
    * Minimum value of X (Spectral files only)
    */
    XMINIMUM, // 59
    /**
    * Maximum value of X (Spectral files only)
    */
    XMAXIMUM, // 60
    /**
    * Minimum value of Y (Spectral files only)
    */
    YMINIMUM, // 61
    /**
    * Maximum value of Y (Spectral files only)
    */
    YMAXIMUM, // 62
    /**
    * UNUSED
    */
    num63, // 63
    /**
    * UNUSED
    */
    num64, // 64
    /**
    * UNUSED
    */
    num65, // 65
    /**
    * UNUSED
    */
    num66, // 66
    /**
    * UNUSED
    */
    num67, // 67
    /**
    * UNUSED
    */
    num68, // 68
    /**
    * UNUSED
    */
    num69, // 69
    /**
    * GMT year corresponding to reference (zero) time in file.
    */
    NZYEAR, // 70
    /**
    * GMT julian day.
    */
    NZJDAY, // 71
    /**
    * GMT hour.
    */
    NZHOUR, // 72
    /**
    * GMT minute.
    */
    NZMIN, // 73
    /**
    * GMT second.
    */
    NZSEC, // 74
    /**
    * GMT millisecond.
    */
    NZMSEC, // 75
    /**
    * Header version number. Current value is the integer 6. Older version data
    * (NVHDR &gt; 6) are automatically updated when read into sac. [required]
    */
    NVHDR, // 76
    /**
    * Origin ID (CSS 3.0)
    */
    NORID, // 77
    /**
    * Event ID (CSS 3.0)
    */
    NEVID, // 78
    /**
    * Number of points per data component. [required]
    */
    NPTS, // 79
    /**
    * INTERNAL
    */
    num80, // 80
    /**
    * Waveform ID (CSS 3.0)
    */
    NWFID, // 81
    /**
    * Spectral Length (Spectral files only)
    */
    NXSIZE, // 82
    /**
    * Spectral Width (Spectral files only)
    */
    NYSIZE, // 83
    /**
    * UNUSED
    */
    num84, // 84
    /**
    * Type of file [required]: 1 ITIME {Time series file} IRLIM {Spectral
    * file---real and imaginary} IAMPH {Spectral file---amplitude and phase}
    * IXY {General x versus y dat a} IXYZ {General XYZ (3-D) file}
    */
    IFTYPE, // 85
    /**
    * Type of dependent variable:
    * <p>
    * 5 IUNKN (Unknown), 6 IDISP (Displacement in nm), 7 IVEL (Velocity in
    * nm/sec) IVOLTS (Velocity in volts) IACC (Acceleration in nm/sec/sec)
    */
    IDEP, // 86
    /**
    * Reference time equivalence:
    * <p>
    * IUNKN (Unknown) IB (Begin time) IDAY (Midnight of refernece GMT day) IO
    * (Event origin time) IA (First arrival time) ITn (User defined time pick
    * n, n=0,9)
    */
    IZTYPE, // 87
    /**
    * UNUSED
    */
    num88, // 88
    /**
    * Type of recording instrument. [not currently used]
    */
    IINST, // 89 IINST???
    /**
    * Station geographic region. [not currently used]
    */
    ISTREG, // 90
    /**
    * Event geographic region. [not currently used]
    */
    IEVREG, // 91
    /**
    * Type of event:
    * <p>
    * IUNKN (Unknown) INUCL (Nuclear event) IPREN (Nuclear pre-shot event)
    * IPOSTN (Nuclear post-shot event) IQUAKE (Earthquake) IPREQ (Foreshock)
    * IPOSTQ (Aftershock) ICHEM (Chemical explosion) IQB (Quarry or mine blast
    * confirmed by quarry) IQB1 (Quarry/mine blast with designed shot
    * info-ripple fired) IQB2 (Quarry/mine blast with observed shot info-ripple
    * fired) IQBX (Quarry or mine blast - single shot) IQMT
    * (Quarry/mining-induced events: tremors and rockbursts) IEQ (Earthquake)
    * IEQ1 (Earthquakes in a swarm or aftershock sequence) IEQ2 (Felt
    * earthquake) IME (Marine explosion) IEX (Other explosion) INU (Nuclear
    * explosion) INC (Nuclear cavity collapse) IO (Other source of known
    * origin) IL (Local event of unknown origin) IR (Regional event of unknown
    * origin) IT (Teleseismic event of unknown origin) IU (Undetermined or
    * conflicting information) IOTHER (Other)
    */
    IEVTYP, // 92
    /**
    * Quality of data [not currently used]:
    * <p>
    * IGOOD (Good data) IGLCH (Glitches) IDROP (Dropouts) ILOWSN (Low signal to
    * noise ratio) IOTHER (Other)
    */
    IQUAL, // 93
    /**
    * Synthetic data flag [not currently used]:
    * <p>
    * IRLDTA (Real data) ????? (Flags for various synthetic seismogram codes)
    */
    ISYNTH, // 94
    /**
    * Magnitude type: IMB (Bodywave Magnitude) IMS (Surfacewave Magnitude) IML
    * (Local Magnitude) IMW (Moment Magnitude) IMD (Duration Magnitude) IMX
    * (User Defined Magnitude)
    */
    IMAGTYP, // 95
    /**
    * Source of magnitude information: INEIC (National Earthquake Information
    * Center) IPDE (Preliminary Determination of Epicenter) IISC (Internation
    * Seismological Centre) IREB (Reviewed Event Bulletin) IUSGS (US Geological
    * Survey) IBRK (UC Berkeley) ICALTECH (California Institute of Technology)
    * ILLNL (Lawrence Livermore National Laboratory) IEVLOC (Event Location
    * (computer program) ) IJSOP (Joint Seismic Observation Program) IUSER (The
    * individual using SAC2000) IUNKNOWN (unknown)
    */
    IMAGSRC, // 96
    /**
    * UNUSED
    */
    num97, // 97
    /**
    * UNUSED
    */
    num98, // 98
    /**
    * UNUSED
    */
    num99, // 99
    /**
    * UNUSED
    */
    num100, // 100
    /**
    * UNUSED
    */
    num101, // 101
    /**
    * UNUSED
    */
    num102, // 102
    /**
    * UNUSED
    */
    num103, // 103
    /**
    * UNUSED
    */
    num104, // 104
    /**
    * TRUE if data is evenly spaced. [required]
    */
    LEVEN, // 105
    /**
    * TRUE if station components have a positive polarity (left-hand rule).
    */
    LPSPOL, // 106
    /**
    * TRUE if it is okay to overwrite this file on disk.
    */
    LOVROK, // 107
    /**
    * TRUE if DIST, AZ, BAZ, and GCARC are to be calculated from station and
    * event coordinates.
    */
    LCALDA, // 108
    /**
    * UNUSED
    */
    num109, // 109
    /**
    * Station name.
    */
    KSTNM, // 110-111
    /**
    * Event name.
    */
    KEVNM, // 112-115
    /**
    * Hole identification if nuclear event.
    */
    KHOLE, // 116-117
    /**
    * Event origin time identification.
    */
    KO, // 118-119
    /**
    * First arrival time identification.
    */
    KA, // 120-121
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT0, // 122-123
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT1, // 124-125
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT2, // 126-127
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT3, // 128-129
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT4, // 130-131
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT5, // 132-133
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT6, // 134-135
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT7, // 136-137
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT8, // 138-139
    /**
    * A User defined time pick identifications, n = 0 - 9.
    */
    KT9, // 140-141
    /**
    * Fini identification.
    */
    KF, // 142-143
    /**
    * User defined variable storage area, n = 0,2.
    */
    KUSER0, // 144-145
    /**
    * User defined variable storage area, n = 0,2.
    */
    KUSER1, // 146-147
    /**
    * User defined variable storage area, n = 0,2.
    */
    KUSER2, // 148-149
    /**
    * Component name.
    */
    KCMPNM, // 150-151
    /**
    * Name of seismic network.
    */
    KNETWK, // 152-153
    /**
    * Date data was read onto computer.
    */
    KDATRD, // 154-155
    /**
    * Generic name of recording instrument.
    */
    KINST
    // 156-157
};
class SACHeader {
    virtual void read();
protected:
    std::string file_path;
    /////////////////////////
    double delta; //0
    double depmin; //4
    double depmax; //8
    double scale; //12
    double odelta; //16
    double b; //20
    double e; //24
    double o; //28
    double a; //32
    double num9; //36
    double t0; //40
    double t1; //44
    double t2; //48
    double t3; //52
    double t4; //56
    double t5; //60
    double t6; //64
    double t7; //68
    double t8; //72
    double t9; //76
    double f;
    double resp0; //80
    double resp1; //84
    double resp2; //88
    double resp3; //92
    double resp4; //96
    double resp5; //100
    double resp6; //104
    double resp7; //108
    double resp8; //112
    double resp9; //116
    double stla; //120
    double stlo;
    double stel;
    double stdp;
    double evla;
    double evlo;
    double evel;
    double evdp;
    double mag;
    double user0;
    double user1;
    double user2;
    double user3;
    double user4;
    double user5;
    double user6;
    double user7;
    double user8;
    double user9;
    double dist;
    double az;
    double baz;
    double gcarc;
    double num54;
    double num55;
    double depmen;
    double cmpaz;
    double cmpinc;
    double xminimum;
    double xmaximum;
    double yminimum;
    double ymaximum;
    double num63;
    double num64;
    double num65;
    double num66;
    double num67;
    double num68;
    double num69;
    /////////////////////////
    int nzyear;
    int nzjday;
    int nzhour;
    int nzmin;
    int nzsec;
    int nzmsec;
    int nvhdr;
    int norid;
    int nevid;
    int npts;
    int num80;
    int nwfid;
    int nxsize;
    int nysize;
    int num84;
    int iftype;
    int idep;
    int iztype;
    int num88;
    int iinst;
    int istreg;
    int ievreg;
    int ievtyp;
    int iqual;
    int isynth;
    int imagtyp;
    int imagsrc;
    int num97;
    int num98;
    int num99;
    int num100;
    int num101;
    int num102;
    int num103;
    int num104;
    /////////////////////////
    bool leven;
    bool lpspol;
    bool lovrok;
    bool lcalda;
    bool num109;
    /////////////////////////
    std::string kstnm;
    std::string kevnm;
    std::string khole;
    std::string ko;
    std::string ka;
    std::string kt0;
    std::string kt1;
    std::string kt2;
    std::string kt3;
    std::string kt4;
    std::string kt5;
    std::string kt6;
    std::string kt7;
    std::string kt8;
    std::string kt9;
    std::string kf;
    std::string kuser0;
    std::string kuser1;
    std::string kuser2;
    std::string kcmpnm;
    std::string knetwk;
    std::string kdatrd;
    std::string kinst;

public:
    SACHeader(std::string);
    double getDelta();
    double getValue(header);
    bool getBoolean(header);
    int getEnumerated(header);
    int getInt(header);
    std::string getString(header);
    virtual ~SACHeader();
};

#endif /* SACHEADER_H_ */
