#include "Get_ColorPair_numbers.hpp"

TelCoColorCoder::ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    TelCoColorCoder::MajorColor majorColor = 
        (TelCoColorCoder::MajorColor)(zeroBasedPairNumber / TelCoColorCoder::numberOfMinorColors);
    TelCoColorCoder::MinorColor minorColor =
        (TelCoColorCoder::MinorColor)(zeroBasedPairNumber % TelCoColorCoder::numberOfMinorColors);
    return TelCoColorCoder::ColorPair(majorColor, minorColor);
}

int TelCoColorCoder::GetPairNumberFromColor(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor) {
    return major * TelCoColorCoder::numberOfMinorColors + minor + 1;
}