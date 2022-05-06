#include "Header.h"

string multiply(char symbol, int num)
{
	string row;
	while (num--)
	{
		row += symbol;
	}
	return row;
}

vector<string> split(string row, char splitter)
{
	vector<string> rows;
	while (row.find(splitter) != string::npos)
	{
		int splitPos = row.find(splitter);
		rows.push_back(row.substr(0, splitPos));
		row = row.substr(splitPos + 1, row.length() - splitPos - 1);
	}
	rows.push_back(row);
	return rows;
}

int mins(string hrsMins)
{
	vector<string> hrsAndMins = split(hrsMins, ':');
	return stoi(hrsAndMins[0]) * 60 + stoi(hrsAndMins[1]);
}

string clock(int minute)
{
	string mm = to_string(minute % 60);
	if (mm.length() == 1)
	{
		mm = '0' + mm;
	}
	string hh = to_string(minute / 60);
	if (hh.length() == 1)
	{
		hh = '0' + hh;
	}
	return hh + ':' + mm;
}

bool checkNew(vector<int> starts, int newStart)
{
	int lastInd = starts.size() - 1;
	if ((newStart - starts[lastInd] <= 150) && (newStart - starts[lastInd] >= 110))
	{
		cout << "Lesson added!\n";
		return true;
	}
	else if (newStart - starts[lastInd] > 150)
	{
		cout << "Lesson starts too late!\n";
		return false;
	}
	else
	{
		cout << "Lesson starts too early!\n";
		return false;
	}
}

void toConsole(schedule sch)
{
	int maxLen = 0;
	int rowSize;
	int schSize = sch.name.size();
	for (string name : sch.name)
	{
		rowSize = name.length();
		if (rowSize > maxLen)
		{
			maxLen = rowSize;
		}
	}
	for (int i = 0; i < schSize; i++)
	{
		rowSize = sch.name[i].length();
		cout << sch.name[i] << multiply('.', maxLen - rowSize + 3) << clock(sch.start[i]) << '-' << clock(sch.end[i]) << '\n';
	}
}

void fileToData(ifstream& file, schedule& sch)
{
	file.seekg(0);
	int schLen;
	string schName;
	size_t nameSize;
	int schStart;
	int schEnd;
	file.read(reinterpret_cast<char*>(&schLen), sizeof(int));
	for (int i = 0; i < schLen; i++)
	{

		file.read(reinterpret_cast<char*>(&nameSize), sizeof(size_t));
		char* buffer = new char[nameSize + 1];
		file.read(buffer, nameSize);
		buffer[nameSize] = '\0';
		sch.name.push_back(buffer);
		delete[] buffer;

		file.read(reinterpret_cast<char*>(&schStart), sizeof(int));
		sch.start.push_back(schStart);

		file.read(reinterpret_cast<char*>(&schEnd), sizeof(int));
		sch.end.push_back(schEnd);
	}
}

void getNewData(schedule& sch)
{
	cout << "\nEnter lesson names and times. End with a ctrl+X character\n\n";
	bool endInput = false;
	string row;
	int timeFromRow;
	int split_pos;
	while (endInput != true)
	{
		getline(cin, row);
		if (row == "\x18")
		{
			endInput = true;
		}
		else if (row != "")
		{
			if (row.back() == '\x18')
			{
				endInput = true;
				row = row.substr(0, row.length() - 1);
			}
			vector<string> rows = split(row, ' ');
			int lastInd = rows.size() - 1;
			timeFromRow = mins(rows[lastInd]);
			split_pos = row.rfind(' ');
			if (sch.name.size() == 0)
			{
				sch.name.push_back(row.substr(0, split_pos));
				sch.start.push_back(timeFromRow);
				sch.end.push_back(timeFromRow + 105);
				cout << "Lesson added!\n";
			}
			else if (checkNew(sch.start, timeFromRow))
			{
				sch.name.push_back(row.substr(0, split_pos));
				sch.start.push_back(timeFromRow);
				sch.end.push_back(timeFromRow + 105);
			}
			if (endInput != true)
			{
				cout << "\nCurrent schedule:\n";
				toConsole(sch);
			}
		}
	}
}

void fillFile(ofstream& file, schedule sch)
{
	size_t nameSize;
	int schLen = sch.name.size();
	file.write(reinterpret_cast<char*>(&schLen), sizeof(int));
	for (int i = 0; i < schLen; i++)
	{
		nameSize = sch.name[i].size();
		file.write(reinterpret_cast<char*>(&nameSize), sizeof(size_t));
		file.write(sch.name[i].c_str(), nameSize);
		file.write(reinterpret_cast<char*>(&sch.start[i]), sizeof(int));
		file.write(reinterpret_cast<char*>(&sch.end[i]), sizeof(int));
	}
}