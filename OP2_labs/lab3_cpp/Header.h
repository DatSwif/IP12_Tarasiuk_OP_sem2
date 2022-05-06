#pragma once

#include "RomanNumeral.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

bool isNumber(string str);
bool isRoman(string str);
RomanNumeral createRomanNumeral(string num);
string toRoman(int arabic);
int toArabic(string roman);