#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void fillInFile(fstream&);
void fillOutFile(vector<string> text, ofstream& outfile);
int partition(vector<string>& text, int low, int high);
void quickSort(vector<string>& text, int low, int high);
vector<string> fileToConsole(fstream& outfile);
void addCounter(vector<string>& text);
void toConsole(vector<string> text);