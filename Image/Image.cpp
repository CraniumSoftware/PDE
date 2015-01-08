// Copyright (c) 2015 Semi Essessi

#include "Image.h"

Image::Image()
// : mxInstrumentPosition()
: mdAcquisitionJDTBCT( 0 )
, mdExposureTimeInJulianDays( 1.0 / 86400.0 )
, mpfSamples( 0/*NULL*/ ) // SE - TODO: define NULL
, meSourceInstrument( UNKNOWN )
//, meReferenceFrame( SOLAR_SYSTEM_BARYCENTRE )
, miLineWidth( 0 )
, miLineCount( 0 )
, mfFilterWavelengthShortest( 280.0f )
, mfFilterWavelengthLongest( 640.0f )
{

}

Image::~Image()
{
    delete[] mpfSamples;
}
