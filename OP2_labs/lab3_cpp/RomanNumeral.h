#pragma once

class RomanNumeral
{
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
		return RomanNumeral(arabicValue + 1);
	}
	RomanNumeral operator+=(string num2)
	{
		return RomanNumeral(arabicValue + toArabic(num2));
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