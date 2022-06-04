#pragma once
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>
#include "windows.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::ifstream;

void readFile(string filename, vector<Teacher>&, vector<Student>&);
void outAvgTeacherPopularity(vector<Teacher>);
void outAvgStudentGrade(vector<Student>);
void outMinorAcdDebtors(vector<Student>);