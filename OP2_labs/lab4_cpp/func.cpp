#pragma once
#include "Header.h"
#include "Teacher.h"
#include "Student.h"

void readFile(string filename, vector<Teacher> &teachers, vector<Student> &students)
{
	ifstream infile;
	infile.open(filename);
	vector<string> person;
	string row;
	while (getline(infile, row))
	{
		if ((row[1] == ' ') && ((row[0] == 'S') || (row[0] == 'T'))) {
			if (person.size() != 0)
			{
				if (person[0][0] == 'S')
				{
					students.push_back(Student(person));
					person.clear();
				}
				else if (person[0][0] == 'T')
				{
					teachers.push_back(Teacher(person));
					person.clear();
				}
			}
		}
		person.push_back(row);
	}
	if (person.size() != 0)
	{
		if (person[0][0] == 'S')
		{
			students.push_back(Student(person));
			person.clear();
		}
		else if (person[0][0] == 'T')
		{
			teachers.push_back(Teacher(person));
			person.clear();
		}
	}
	infile.close();
}

void outAvgTeacherPopularity(vector<Teacher> teachers)
{
	cout << "Calculating average popularity of these teachers: \n";
	float curr, all = 0, avg;
	for (Teacher teacher : teachers)
	{
		curr = teacher.getAvgPopularity();
		all += curr;
		cout << teacher.getName() << ' ' << curr << '\n';
	}
	avg = all / teachers.size();
	cout << "Average popularity: " << avg << "\n\n";
}

void outAvgStudentGrade(vector<Student> students)
{
	cout << "Calculating average grades of these students: \n";
	float curr, all = 0, avg;
	for (Student student : students)
	{
		curr = student.getAvgGrade();
		all += curr;
		cout << student.getName() << ' ' << curr << '\n';
	}
	avg = all / students.size();
	cout << "Average grades: " << avg << "\n\n";
}

void outMinorAcdDebtors(vector<Student> students)
{
	int count = 0;
	for (Student student : students)
	{
		if ((!student.isAdult()) && (student.hasAcdDebt())) { count++; }
	}
	cout << "less than 18 year old students with academic debt: " << count << '\n';
}