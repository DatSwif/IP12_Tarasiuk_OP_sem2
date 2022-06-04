#pragma once
#include "Teacher.h"

Teacher::Teacher(vector<string> text)
{
	text[0] = text[0].substr(2, text[0].length() - 2);
	birthday.year = stoi(text[0].substr(text[0].rfind('.') + 1, 4));
	text[0] = text[0].substr(0, text[0].rfind('.'));
	birthday.month = stoi(text[0].substr(text[0].rfind('.') + 1, 2));
	text[0] = text[0].substr(0, text[0].rfind('.'));
	birthday.day = stoi(text[0].substr(text[0].rfind(' ') + 1, 2));
	name = text[0].substr(0, text[0].rfind(' '));
	teacherSubject buffer;
	for (size_t i = 1; i < text.size(); i++)
	{
		buffer.name = text[i].substr(0, text[i].rfind(' '));
		buffer.popularity = stoi(text[i].substr(text[i].rfind(' ') + 1, text[i].length() - text[i].rfind(' ')));
		subjects.push_back(buffer);
	}
}
float Teacher::getAvgPopularity()
{
	float all = 0, avg;
	for (teacherSubject subject : subjects) { all += subject.popularity; }
	avg = all / subjects.size();
	return avg;
}