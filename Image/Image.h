// Copyright (c) 2015 Semi Essessi

#ifndef IMAGE_H
#define IMAGE_H

// SE - NOTE: I normally hate abbreviated variable names in today's world of autocomplete and knowing
// that programming is about thinking and not typing, but without it the variable names are unwieldy
//
// JDT          Julian date and time
//
// BCT          Barycentric coordinate time
//              = time as if measured at the Solar System barycentre
// 


class Image
{

    enum SourceInstrument
    {
        UNKNOWN,
        VOYAGER_2_IMAGING_SCIENCE_SUBSYSTEM_NARROW_ANGLE_CAMERA,
        VOYAGER_2_IMAGING_SCIENCE_SUBSYSTEM_WIDE_ANGLE_CAMERA,
    };

    enum ReferenceFrame
    {
        SOLAR_SYSTEM_BARYCENTRE,
        JOVICENTRIC,
        CRONOCENTRIC,
        URANOCENTRIC,
        NEPTUNOCENTRIC,
    };

public:

    Image();
    ~Image();

    bool LoadFromCompressedVoyagerData( const void* const pFileData );

    bool SaveJPEG( const char* const szPath );
    bool SavePNG( const char* const szPath );

private:

    // Vector3 mxInstrumentPosition;     // SE - TODO: a vector class

    double mdAcquisitionJDTBCT;          // SE - NOTE: this is inherited from the formats which leave it ambiguous if this is the start, middle, or end of exposure time
    double mdExposureTimeInJulianDays;

    float* mpfSamples;

    SourceInstrument meSourceInstrument;
    // ReferenceFrame meReferenceFrame;

    int miLineWidth;
    int miLineCount;

    float mfFilterWavelengthShortest;
    float mfFilterWavelengthLongest;

};

#endif
