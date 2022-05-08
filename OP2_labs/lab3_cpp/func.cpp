#include "Header.h"
#include "RomanNumeral.h"

bool isNumber(string str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}

bool isRoman(string str)
{
	return str.find_first_not_of("IVXLCDM") == string::npos;
}

RomanNumeral createRomanNumeral(string num)
{
    if (num.empty())
    {
        return RomanNumeral();
    }
    else if (isNumber(num))
    {
        return RomanNumeral(stoi(num));
    }
    else if (isRoman(num))
    {
        return RomanNumeral(num);
    }
    else
    {
        cout << "Invalid input. Creating a default RomanNumeral";
        return RomanNumeral();
    }
}

string toRoman(int arabic)
{
    int digit;
    string res;
    int power10 = 0;
    const char RD[3][3] = { {'I', 'V', 'X'}, {'X', 'L', 'C'}, {'C', 'D', 'M'}}; // RomanDigits
    while ((power10 < 3) && (arabic > 0))
    {
        digit = arabic % 10;
        switch (digit)
        {
        case 1:
            res = RD[power10][0] + res;
        case 2:
            res = "" + RD[power10][0] + RD[power10][0] + res;
        case 3:
            res = "" + RD[power10][0] + RD[power10][0] + RD[power10][0] + res;
        case 4:
            res = "" + RD[power10][0] + RD[power10][1] + res;
        case 5:
            res = RD[power10][1] + res;
        case 6:
            res = "" + RD[power10][1] + RD[power10][0] + res;
        case 7:
            res = "" + RD[power10][1] + RD[power10][0] + RD[power10][0] + res;
        case 8:
            res = "" + RD[power10][1] + RD[power10][0] + RD[power10][0] + RD[power10][0] + res;
        case 9:
            res = "" + RD[power10][0] + RD[power10][2] + res;
        }
        arabic /= 10;
        power10 += 1;
    }
    if (arabic > 0)
    {
        for (int i = 0; i < arabic; i++)
        {
            res = 'M' + res;
        }
    }
    return res;
}

int toArabic(string roman)
{
    int res;
    const string CorrToAD[3][10] = 
    {   {"\0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, 
        {"\0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
        {"\0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
    }; // corresponds to arabic digits
    
    for (int i = 0; i < 3; i++)
    {
        size_t posOf9 = roman.find(CorrToAD[i][9]);
        if (posOf9 != string::npos)
        {
            roman.replace(posOf9, 2, "");
            res += 9 * round(pow(10, i));
        } //converting all 9's
        size_t posOf4 = roman.find(CorrToAD[i][4]);
        if (posOf4 != string::npos)
        {
            roman.replace(posOf4, 2, "");
            res += 4 * round(pow(10, i));
        } //converting all 4's
        size_t posOf8 = roman.find(CorrToAD[i][8]);
        if (posOf8 != string::npos)
        {
            roman.replace(posOf8, 2, "");
            res += 8 * round(pow(10, i));
        } //converting all 8's
        size_t posOf3 = roman.find(CorrToAD[i][3]);
        if (posOf3 != string::npos)
        {
            roman.replace(posOf3, 2, "");
            res += 3 * round(pow(10, i));
        } //converting all 3's
        size_t posOf7 = roman.find(CorrToAD[i][7]);
        if (posOf7 != string::npos)
        {
            roman.replace(posOf7, 2, "");
            res += 7 * round(pow(10, i));
        } //converting all 7's
        size_t posOf2 = roman.find(CorrToAD[i][2]);
        if (posOf2 != string::npos)
        {
            roman.replace(posOf2, 2, "");
            res += 2 * round(pow(10, i));
        } //converting all 2's
        size_t posOf6 = roman.find(CorrToAD[i][6]);
        if (posOf6 != string::npos)
        {
            roman.replace(posOf6, 2, "");
            res += 6 * round(pow(10, i));
        } //converting all 6's
        size_t posOf1 = roman.find(CorrToAD[i][1]);
        if (posOf1 != string::npos)
        {
            roman.replace(posOf1, 2, "");
            res += 1 * round(pow(10, i));
        } //converting all 1's
        size_t posOf5 = roman.find(CorrToAD[i][5]);
        if (posOf5 != string::npos)
        {
            roman.replace(posOf5, 2, "");
            res += 5 * round(pow(10, i));
        } //converting all 5's
    }
    if (!roman.empty())
    {
        size_t MCount = roman.length();
        res += 1000 * MCount;
    } // converting all 1000's
    return res;
}