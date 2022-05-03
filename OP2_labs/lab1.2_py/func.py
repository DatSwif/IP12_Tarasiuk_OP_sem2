def mins(hrsMins):
    hrsMins = hrsMins.split(':')
    return int(hrsMins[0]) * 60 + int(hrsMins[1])

def clock(mins):
    minute = str(mins % 60)
    if len(minute) == 1:
        minute = '0' + minute
    hour = str(mins // 60)
    if len(hour) == 1:
        hour = '0' + hour
    return hour + ':' + minute

def checkNew(start, new):
    if (new - start[-1] <= 150) and (new - start[-1] >= 110):
        print('Lesson added!')
        return True
    elif  new - start[-1] > 150:
        print('Lesson starts too late!')
        return False
    else:
        print('Lesson starts too early!')
        return False

def toConsole(sch):
    maxLen = 0
    for name in sch['name']:
        rowSize = len(name)
        if rowSize > maxLen:
            maxLen = rowSize
    for i in range(len(sch['name'])):
        symbols = len(sch['name'][i])
        print(sch['name'][i] + '.' * (maxLen - symbols + 3) + clock(sch['start'][i]) + '-' + clock(sch['end'][i]))

def fileToData(file):
    file.seek(0)
    sch = {'name' : [], 'start' : [], 'end' : []}
    while True:
        row = file.readline().decode('utf-8')
        if not row:
            break
        row = row.split('.') # deleting dots with which we divided name, start, end
        sch['name'].append(row[0])
        sch['start'].append(int(row[1]))
        sch['end'].append(int(row[2]))
    return sch

def getNewData(sch): 
    print("\nEnter lesson names and times. End with a ctrl+X character\n")
    endInput = False
    while not endInput:
        row = input()
        if row == '\x18':
            endInput = True
        elif row != '':
            if row[-1] == '\x18':
                endInput = True
                row = row[:-1]
            timeFromRow = mins(row.split()[-1]) 
            split_pos = row.rfind(' ')
            if sch['name'] == []:
                sch['name'].append(row[:split_pos])
                sch['start'].append(timeFromRow)
                sch['end'].append(timeFromRow + 105)
                print('Lesson added!')
            elif checkNew(sch['start'], timeFromRow):
                sch['name'].append(row[:split_pos])
                sch['start'].append(timeFromRow)
                sch['end'].append(timeFromRow + 105)
            if not endInput:
                print("\nCurrent schedule:")
                toConsole(sch)

def fillFile(file, sch):
    size = len(sch['name'])
    for i in range(size):
        file.write((sch['name'][i] + '.' + str(sch['start'][i]) + '.' + str(sch['end'][i]) + '\n').encode('utf-8'))