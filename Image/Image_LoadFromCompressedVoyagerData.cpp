// Copyright (c) 2015 Semi Essessi

#include "Image.h"

#include <cstdlib>
#include <cstring>

void AdvancePastNextChar( const unsigned char*& pucByteStream, const char cChar )
{
    while( *pucByteStream != static_cast< unsigned char >( cChar ) )
    {
        ++pucByteStream;
    }

    ++pucByteStream;
}

void AdvancePastNextNull( const unsigned char*& pucByteStream )
{
    AdvancePastNextChar( pucByteStream, 0 );
}

int ExtractPseudoPointer( const unsigned char*& pucByteStream, const char* const szName )
{
    const bool bHistogramCorrect =
        strncmp( reinterpret_cast< const char* >( pucByteStream ),
        szName,
        strlen( szName ) ) == 0;
    if( !bHistogramCorrect )
    {
        return -1;
    }

    AdvancePastNextChar( pucByteStream, '=' );
    while( static_cast< const char >( *pucByteStream ) == ' ' )
    {
        ++pucByteStream;
    }

    return atoi( reinterpret_cast< const char* >( pucByteStream ) );
}

// SE - TODO: length so that this is super safe?

bool Image::LoadFromCompressedVoyagerData( const void* const pFileData )
{
    const unsigned char* pucByteStream = reinterpret_cast< const unsigned char* >( pFileData );

    // SE - this 'compressed' data format is a big wasteful pile of text with some
    // huffman tree inside of it somewhere...
    
    int iPsuedoPointer = 1; // the file format uses "pointers" to the data, which I assume are indices of rows

    // there seems to be some header - followed by null. skip it.

    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // some SFDU_LABEL

    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // some stray quote

    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // some file format and length thing

    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // some record type

    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // record bytes, should be 836
    //static const int iRecordBytes = 836;
    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // file record count, should be 860
    //static const int iRecordCount = 860;
    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // label records.
    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // some stray A
    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // some comment telling us about pointer things
    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // some stray %
    AdvancePastNextNull( pucByteStream );
    ++iPsuedoPointer;

    // some image histogram pointer (seems to be 55)
    const int iImageHistogramPointer = ExtractPseudoPointer( pucByteStream, "^IMAGE_HISTOGRAM" );

    AdvancePastNextNull( pucByteStream );
    AdvancePastNextNull( pucByteStream );
    iPsuedoPointer += 2;

    if( iImageHistogramPointer == -1 )
    {
        return false;
    }

    // some encoding histogram pointer (57?)
    const int iEncodingHistogramPointer = ExtractPseudoPointer( pucByteStream, "^ENCODING_HISTOGRAM" );

    AdvancePastNextNull( pucByteStream );
    AdvancePastNextNull( pucByteStream );
    iPsuedoPointer += 2;

    if( iEncodingHistogramPointer == -1 )
    {
        return false;
    }

    // engineering table (60?)
    const int iEngineeringTablePointer = ExtractPseudoPointer( pucByteStream, "^ENGINEERING_TABLE" );

    AdvancePastNextNull( pucByteStream );
    AdvancePastNextNull( pucByteStream );
    iPsuedoPointer += 2;

    if( iEngineeringTablePointer == -1 )
    {
        return false;
    }

    // image data (61?)
    const int iImagePointer = ExtractPseudoPointer( pucByteStream, "^IMAGE" );

    AdvancePastNextNull( pucByteStream );
    AdvancePastNextNull( pucByteStream );
    iPsuedoPointer += 2;

    if( iImagePointer == -1 )
    {
        return false;
    }

    int iSkipCount = iImageHistogramPointer;
    for( int i = 0; i < iSkipCount; ++i )
    {
        AdvancePastNextNull( pucByteStream );
    }

    return false;
}
