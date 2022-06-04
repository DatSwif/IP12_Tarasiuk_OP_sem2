#pragma once
#include <ctime>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Date
{
	int year;
	int month;
	int day;
};

class Person
{
protected:
	Date birthday;
	string name;
public:
	int getAge();
	string getName();
};