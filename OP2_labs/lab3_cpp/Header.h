#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cout; 
using std::cin;
using std::string;

bool isNumber(string str);
bool isRoman(string str);
string toRoman(int arabic);
int toArabic(string roman);