#ifndef WAIT_H
#define WAIT_H

#include <iostream>
#include <ctime>
using namespace std;

#ifdef __APPLE__
#include <unistd.h>
#endif
#ifdef __linux__
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#endif

string timeNow();
void wait(int seconds);

#endif
