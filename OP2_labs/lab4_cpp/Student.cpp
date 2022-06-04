#pragma once
#include "Student.h"

Student::Student(vector<string> text)
{
	group = text[0].substr(text[0].rfind(' ') + 1, text[0].length() - text[0].rfind(' '));
	text[0] = text[0].substr(2, text[0].rfind(' ') - 2);
	birthday.year = stoi(text[0].substr(text[0].rfind('.') + 1, 4));
	text[0] = text[0].substr(0, text[0].rfind('.'));
	birthday.month = stoi(text[0].substr(text[0].rfind('.') + 1, 2));
	text[0] = text[0].substr(0, text[0].rfind('.'));
	birthday.day = stoi(text[0].substr(text[0].rfind(' ') + 1, 2));
	name = text[0].substr(0, text[0].rfind(' '));
	studentSubject buffer;
	for (size_t i = 1; i < text.size(); i++)
	{
		buffer.name = text[i].substr(0, text[i].rfind(' '));
		buffer.grade = stoi(text[i].substr(text[i].rfind(' ') + 1, text[i].length() - text[i].rfind(' ')));
		subjects.push_back(buffer);
	}
}
float Student::getAvgGrade()
{
	float all = 0, avg;
	for (studentSubject subject : subjects) { all += subject.grade; }
	avg = all / subjects.size();
	return avg;
}
bool Student::hasAcdDebt()
{
	for (studentSubject subject : subjects)
	{
		if (subject.grade < 60) { return true; }
	}
	return false;
}
bool Student::isAdult()
{
	if (getAge() < 18)
	{
		return false;
	}
	else return true;
}