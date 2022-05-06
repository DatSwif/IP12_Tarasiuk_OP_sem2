#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct schedule
{
	vector<string> name;
	vector<int> start, end;
};

string multiply(char symbol, int num);
vector<string> split(string row, char splitter);
int mins(string hrsMins);
string clock(int minute);
bool checkNew(vector<int> starts, int newStart);
void toConsole(schedule sch);
void fileToData(ifstream& file, schedule& sch);
void getNewData(schedule& sch);
void fillFile(ofstream& file, schedule sch);