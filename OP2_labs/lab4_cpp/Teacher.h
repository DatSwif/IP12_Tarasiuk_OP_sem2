#pragma once
#include "Person.h"

struct teacherSubject {
	string name;
	int popularity;
};

class Teacher : public Person
{
	vector<teacherSubject> subjects;
public:
	Teacher(vector<string>);
	float getAvgPopularity();
};

