#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::string;

class RomanNumeral
{
private:
	string romanValue;
	int arabicValue;
public:
	RomanNumeral()
	{
		romanValue = "I";
		arabicValue = 1;
	}
	RomanNumeral(int arabic)
	{
		arabicValue = arabic;
		romanValue = toRoman(arabic);
	}
	RomanNumeral(string roman)
	{
		romanValue = roman;
		arabicValue = toArabic(roman);
	}
	string getRoman()
	{
		return romanValue;
	}
	int getArabic()
	{
		return arabicValue;
	}
	RomanNumeral operator++()
	{
		++arabicValue;
		romanValue = toRoman(arabicValue);
		return *this;
	}
	RomanNumeral operator+=(string num2)
	{
		arabicValue += toArabic(num2);
		romanValue = toRoman(arabicValue);
		return *this;
	}
	RomanNumeral operator+(RomanNumeral num2)
	{
		return RomanNumeral(arabicValue + num2.arabicValue);
	}
	void displayValue()
	{
		cout << "Roman value: " << romanValue << '\n';
		cout << "Arabic value: " << arabicValue << '\n';
	}
};

RomanNumeral createRomanNumeral(string num);