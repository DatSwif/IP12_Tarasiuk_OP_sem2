#include "Header.h"

void fillInFile(fstream& infile)
{
	infile.open("in.txt", ios::app | ios::in);
	string row = " ";
	cout << "Enter your text. At the end press Ctrl+X and then Enter.\n\n";
	while (row.back() != '\x18')
	{
		getline(cin, row);
		if (row.back() == '\x18')
		{
			infile << row.substr(0, row.size() - 1) << '\n';
		}
		else
		{
			infile << row << '\n';
		}
	}
	infile.seekg(0);
}

void fillOutFile(vector<string> text, ofstream& outfile)
{
	outfile.open("out.txt", ios::out);
	for (string row : text)
	{
		outfile << row;
	}
}

int partition(vector<string>& text, int low, int high)
{
	int i = low - 1;
	string pivot = text[high];
	string temp;
	for (int j = low; j < high; j++)
	{
		if (text[j].length() >= pivot.length())
		{
			i++;
			temp = text[i];
			text[i] = text[j];
			text[j] = temp;
		}
	}
	temp = text[i + 1];
	text[i + 1] = text[high];
	text[high] = temp;
	return i + 1;
}

void quickSort(vector<string>& text, int low, int high)
{
	if (text.size() == 1)
	{
		return;
	}
	if (low < high)
	{
		int pivotPos = partition(text, low, high);
		quickSort(text, low, pivotPos - 1);
		quickSort(text, pivotPos + 1, high);
	}
}

vector<string> fileToConsole(fstream& file)
{
	file.seekg(0);
	string line = " ";
	vector<string> text;
	while (getline(file, line))
	{
		text.push_back(line + '\n');
		cout << line << '\n';
	}
	return text;
}

void addCounter(vector<string>& text)
{
	for (int i = 0; i < text.size(); i++)
	{
		text[i] = to_string(text[i].length() - 1) + ' ' + text[i];
	}
}

void toConsole(vector<string> text)
{
	for (string row : text)
	{
		cout << row;
	}
}