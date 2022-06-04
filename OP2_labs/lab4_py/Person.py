from datetime import date
from dataclasses import dataclass

@dataclass
class Birthday:
    year : int
    month : int
    day : int

class Person(object):
    def __init__(self, row):
        birthdayNums = row[row.rfind(' ') + 1 : ].split('.')
        self.birthday = Birthday(int(birthdayNums[2]), int(birthdayNums[1]), int(birthdayNums[0]))
        self.name = row[ : row.rfind(' ')]

    def getAge(self):
        now = str(date.today()).split('-')
        now = Birthday(int(now[0]), int(now[1]), int(now[2]))
        if now.day < self.birthday.day:
            now.month -= 1
        if now.month < self.birthday.month:
            now.year -= 1
        return now.year - self.birthday.year

    def getName(self):
        return self.name
