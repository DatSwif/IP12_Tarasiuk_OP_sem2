#pragma once
#include "Person.h"

int Person::getAge()
{
	time_t secondsNow = time(0);
	tm allNow;
	localtime_s(&allNow, &secondsNow);
	Date now;
	now.year = 1900 + allNow.tm_year;
	now.month = 1 + allNow.tm_mon;
	now.day = allNow.tm_mday;
	if (now.day < birthday.day) { now.month--; }
	if (now.month < birthday.month) { now.year--; }
	return now.year - birthday.year;
}
string Person::getName()
{
	return name;
}