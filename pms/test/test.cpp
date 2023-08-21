#include <iostream>
#include <cmath>
#include <unistd.h>

#include "math/Vec.h"
#include "utils/Utils.h"

using namespace std;

void testTime();

void testRandom();

int main() {
    testRandom();
    testTime();
    return 0;
}


void testTime() {
    string curr_time = Utils::getCurrentTimeStr();
    cout << curr_time << endl;
    time_t start = Utils::getCurrentTime();

    sleep(5);
    double duration = Utils::getTimeDiff(start, Utils::getCurrentTime());

    cout << "duration=" << duration << endl;
    curr_time = Utils::getCurrentTimeStr();
    cout << curr_time << endl;
}

void testRandom() {
    Utils::initRandom();
    for (int i = 0; i < 10; ++i) {
        cout << Utils::getRandomInteger(1, 100) << ",";
    }
    cout << endl;
    for (int i = 0; i < 10; ++i) {
        cout << Utils::getRandomInteger(1, 100) << ",";
    }
}
