#створити текстовий файл.
#сформувати новий текстовий файл, що складається з рядків вихідного файлу,
#розміщених у порядку спадання кількості символів
#на початку кожного рядка написати кількість символів у рядку
#вивести вміст обох файлів
from func import *

infile = fillInFile()
print("\nContents of input file:\n")

text = fileToConsole(infile)
quickSort(text, 0, len(text)-1)
print("\nSorted text rows:\n")
toConsole(text)
addCounter(text)
print("\nRows with counted symbols:\n")
toConsole(text)

outfile = fillOutFile(text)
outfile.seek(0)
print("\nContents of output file:\n")
fileToConsole(outfile)

infile.close()
outfile.close()
