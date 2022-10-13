#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <ctime>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

#define TOP_LEFT 0
#define TOP_CENTER 1
#define TOP_RIGHT 2
#define MIDDLE_LEFT 3
#define MIDDLE_CENTER 4
#define MIDDLE_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_CENTER 7
#define DOWN_RIGHT 8