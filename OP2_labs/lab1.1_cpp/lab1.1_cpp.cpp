#include "Header.h"

int main()
{
    fstream infile;
    fillInFile(infile);
    cout << "\nContents of input file:\n\n";
    vector<string> text = fileToConsole(infile);
    infile.close();

    quickSort(text, 0, text.size() - 1);
    cout << "\nSorted text rows:\n\n";
    toConsole(text);
    addCounter(text);
    cout << "\nRows with counted symbols:\n\n";
    toConsole(text);

    ofstream outfile;
    fillOutFile(text, outfile);
    outfile.close();

    fstream outfileIn;
    outfileIn.open("out.txt", ios::in);
    cout << "\nContents of output file:\n\n";
    fileToConsole(outfileIn);
}