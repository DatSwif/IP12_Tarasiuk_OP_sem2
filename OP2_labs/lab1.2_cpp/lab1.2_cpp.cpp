#include "Header.h"

int main()
{
	string filename;
	cout << "Enter file name:\n";
	getline(cin, filename);
	schedule sch;
	ifstream readFile(filename.c_str(), ios::binary);
	if (readFile.good()) //file exists
	{
		fileToData(readFile, sch);
		cout << "\nFile contents:\n";
		toConsole(sch);
	}
	else
	{
		cout << "\nA new file will be created\n";
	}
	readFile.close();

	getNewData(sch);

	ofstream writeFile;
	writeFile.open(filename, ios::binary);
	fillFile(writeFile, sch);
	writeFile.close();

	cout << "\nFile contents:\n";
	schedule finalData;
	readFile.open(filename, ios::binary);
	fileToData(readFile, finalData);
	readFile.close();
	toConsole(finalData);
}