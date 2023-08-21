#include "utils/Utils.h"

std::string Utils::getCurrentTimeStr() {
    std::string ret;
    char stime[255] = {'\0'};
    time_t curr_time = 0;
    time(&curr_time);
    strftime(stime, sizeof(stime), "%Y-%m, %H:%M:%S", localtime(&curr_time));
    ret = stime;
    return ret;
}

time_t Utils::getCurrentTime() {
    time_t curr_time = 0;
    time(&curr_time);
    return curr_time;
}

double Utils::getTimeDiff(time_t start, time_t end) {
    return difftime(end, start);
}

void Utils::initRandom() {
    srand(time(NULL));
}

int Utils::getRandomInteger(int min, int max) {
    int ret = rand() % (max - min + 1) + min;
    return ret;
}

float Utils::getRandomFloat(float min, float max) {
    float ret = min + (float) (rand()) / (float)(RAND_MAX) * (max - min);
    return ret;
}

std::string Utils::getTimeStr(time_t time) {
    std::string ret;
    char stime[255] = {'\0'};
    strftime(stime, sizeof(stime), "%Y-%m, %H:%M:%S", localtime(&time));
    ret = stime;
    return ret;
}









