from func import *
from os import path

filename = input('Enter file name:\n')

if path.isfile(filename):
    readFile = open(filename, 'rb')
    sch = fileToData(readFile)
    print("\nFile contents:")
    toConsole(sch)
    readFile.close()
else:
    print("A new file will be created")
    sch = {'name' : [], 'start' : [], 'end' : []}

writeFile = open(filename, 'wb')
getNewData(sch)
fillFile(writeFile, sch)
writeFile.close()

readFile = open(filename, 'rb')
print("\nYour today's schedule:")
toConsole(fileToData(readFile))
readFile.close()
