def fillInFile():
    infile = open('in.txt', 'a+')
    row = ' '
    print("Enter your text. At the end press Ctrl+X and then Enter.\n")
    while row[-1] != '\x18':
        row = input()
        if row[-1] == '\x18':
            infile.write(row[:-1] + '\n')
        else:
            infile.write(row + '\n') 
    infile.seek(0)
    return infile

def fillOutFile(text):
    outfile = open('out.txt', 'w+')
    for item in text:
        outfile.write(item)
    return outfile

def partition(text, low, high):
    i = (low-1)        
    pivot = text[high]    
    for j in range(low, high):
        if len(text[j]) >= len(pivot):
            i = i+1
            text[i], text[j] = text[j], text[i]
    text[i+1], text[high] = text[high], text[i+1]
    return (i+1)

def quickSort(text, low, high):
    if len(text) == 1:
        return text
    if low < high:
        pivotPos = partition(text, low, high)
        quickSort(text, low, pivotPos-1)
        quickSort(text, pivotPos+1, high)

def fileToConsole(file):
    text = file.readlines()
    for row in text:
        print(row, end = '')
    return text

def addCounter(text):
    for i in range(len(text)):
        text[i] = str(len(text[i]) - 1) + ' ' + text[i]

def toConsole(text):
    for row in text:
        print(row, end = '')
