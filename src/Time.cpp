//TIME.CPP v1.0 BY ALEXANDER MOT
//Created 07/04/2017
//Updated 15/04/2017

#include "../include/time.h"

//returns current times
string timeNow() {
    time_t now = time(0);
    string time = ctime(&now);
    return time;
}

//sleeps
void wait(int seconds) {
    #ifdef __APPLE__
    sleep(seconds);
    #endif
    #ifdef __linux__
    sleep(seconds);
    #endif
    #ifdef _WIN32
    Sleep((seconds * 1000));
    #endif
}
