/*
????????? ????, ???? ? ??????????? ?????? +
?? ????????? ???????? ????????? ????? ?? ?????? +
? ????? ?????????? ????? ? ?????? +
???????? ????? ??'????? ?????? ????? +
????????? ???????? ??????? ?????? ??????? +
????????? ??????????? ?? ????????? ?????? ??????? ???????
*/
#include "Header.h"

int main()
{
    vector<Text> texts;
    getTexts(texts);
    extendTexts(texts);
    toConsole(texts);
    shortestOfLongestRows(texts);
}