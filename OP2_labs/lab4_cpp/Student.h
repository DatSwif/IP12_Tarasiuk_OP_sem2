#pragma once
#include "Person.h"

struct studentSubject {
	string name;
	int grade;
};

class Student : public Person
{
	string group;
	vector<studentSubject> subjects;
public:
	Student(vector<string>);
	float getAvgGrade();
	bool hasAcdDebt();
	bool isAdult();
};

