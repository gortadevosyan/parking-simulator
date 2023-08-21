

#ifndef P3_UTILS_H
#define P3_UTILS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>

class Utils {
public:
    static std::string getCurrentTimeStr();

    static time_t getCurrentTime();

    static double getTimeDiff(time_t start, time_t end);

    static std::string getTimeStr(time_t time);

    static void initRandom();

    static int getRandomInteger(int min, int max);

    static float getRandomFloat(float min,float max);
};

#endif //P3_UTILS_H
