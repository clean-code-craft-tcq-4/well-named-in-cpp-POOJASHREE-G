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
    cout << "25-pair color code" << endl;

    cout
        << left << setw(15) << "Pair no."
        << left << setw(15) << "Major color"
        << left << setw(15) << "Minor color "
        << endl;

    int i = 0;

    for (int j = 0; j < 5; j++) {
        for (int n = 0; n < 5; n++) {
            cout
                << left
                << setw(15)
                << ++i
                << left
                << setw(15)
                << MajorColorNames[j]
                << left
                << setw(15)
                << MinorColorNames[n]
                << endl;
        }
    }
}