#include <iostream>
#include <assert.h>
#include "TelCoColorCoder.hpp"
#include "Get_ColorPair_nums.hpp"

TelCoColorCoder::ColorPair GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    TelCoColorCoder::MajorColor majorColor = 
        (TelCoColorCoder::MajorColor)(zeroBasedPairNumber / TelCoColorCoder::numberOfMinorColors);
    TelCoColorCoder::MinorColor minorColor =
        (TelCoColorCoder::MinorColor)(zeroBasedPairNumber % TelCoColorCoder::numberOfMinorColors);
    return TelCoColorCoder::ColorPair(majorColor, minorColor);
}

int GetPairNumberFromColor(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor) {
    return major * TelCoColorCoder::numberOfMinorColors + minor + 1;
}

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}