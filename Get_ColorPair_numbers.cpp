#include <iostream>
#include <iomanip>
#include "Get_ColorPair_numbers.hpp"
using namespace std;

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

void TelCoColorCoder::PrintReferenceManual() {
    cout << "25-pair color code";

    cout
        << left
        << setw(15)
        << "Pair no."
        << left
        << setw(15)
        << "Major color"
        << left
        << setw(15)
        << "Minor color "
        << endl;

    for (int i = 1; i < 26; i++)
    {
        cout
            << left
            << setw(15)
            << i
            << left
            << setw(15)
            << MajorColorNames[i]
            << left
            << setw(15)
            << MinorColorNames[i]
            << endl;
    }
}