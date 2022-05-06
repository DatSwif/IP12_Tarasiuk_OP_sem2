#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Text
{
private:
	int textSize;
	int longestRowInd;
	int longestRowLength;
	vector<string> text;

public:
	Text(int size, vector<string> rows)
	{
		textSize = size;
		text = rows;
		longestRowInd = 0;
		longestRowLength = text[0].length();
		for (int i = 0; i < textSize; i++)
		{
			if (text[i].length() > longestRowLength)
			{
				longestRowLength = text[i].length();
				longestRowInd = i;
			}
		}
	}

	void add(string row)
	{
		text.push_back(row);
		if (text[textSize].length() > longestRowLength)
		{
			longestRowLength = text[textSize].length();
			longestRowInd = textSize;
		}
		textSize += 1;
	}

	vector<string> getText()
	{
		return text;
	}

	string getLongestRow()
	{
		return text[longestRowInd];
	}

	int getSize()
	{
		return textSize;
	}
};

bool getRows(vector<string>& rows);
void getTexts(vector<Text>& texts);
void extendTexts(vector<Text>& texts);
void toConsole(vector<Text> texts);
void shortestOfLongestRows(vector<Text> texts);