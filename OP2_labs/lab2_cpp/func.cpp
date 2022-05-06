#include "Header.h"

bool getRows(vector<string>& rows)
{
    string row;
    rows.clear();
    bool more = true;
    char moreTexts;
    cout << "Enter the text row by row. Type Ctrl+X to finish the text\n";
    while (more)
    {
        getline(cin, row);
        if (row == "\x18")
        {
            more = false;
        }
        else if (row != "")
        {
            if (row.back() == '\x18')
            {
                more = false;
                row = row.substr(0, row.length() - 1);
            }
            rows.push_back(row);
        }
    }
    cout << "\nWas this the last text? (y/n) ";
    cin >> moreTexts;
    cout << '\n';
    if (moreTexts == 'n') return true;
    else if (moreTexts == 'y') return false;
    else return true;
}

void getTexts(vector<Text>& texts)
{
    vector<string> rows;
    bool more;
    do
    {
        more = getRows(rows);
        if (rows.size() > 0)
        {
            Text currText(rows.size(), rows);
            texts.push_back(currText);
        }
    } while (more);
}

void extendTexts(vector<Text>& texts)
{
    string row;
    bool more = true;
    string strInput;
    int textInd;
    do
    {
        cout << "Enter text number to extend it, or Ctrl+X to quit\n";
        cin >> strInput;
        if (strInput == "\x18")
        {
            more = false;
        }
        else
        {
            textInd = stoi(strInput);
            if (textInd >= texts.size())
            {
                cout << "Error: text index is too big";
            }
            else
            {
                cout << "Enter the row\n";
                cin.ignore();
                getline(cin, row);
                texts[textInd].add(row);
            }
        }
    } while (more);
}

void toConsole(vector<Text> texts)
{
    vector<string> currText;
    for (int i = 0; i < texts.size(); i++)
    {
        cout << "\nText " << i << ":\n";
        currText = texts[i].getText();
        for (int j = 0; j < currText.size(); j++)
        {
            cout << currText[j] << '\n';
        }
        currText.clear();
    }
}

void shortestOfLongestRows(vector<Text> texts)
{
    string shortestRow = texts[0].getLongestRow();
    int shortestLength = shortestRow.length();
    int textInd = 0;
    for (int i = 0; i < texts.size(); i++)
    {
        if (texts[i].getLongestRow().length() < shortestLength)
        {
            shortestRow = texts[i].getLongestRow();
            shortestLength = shortestRow.length();
            textInd = i;
        }
    }
    cout << "\nShortest of the longest rows:\n" << shortestRow << "\n";
    cout << "Found in text: " << textInd << '\n';
}