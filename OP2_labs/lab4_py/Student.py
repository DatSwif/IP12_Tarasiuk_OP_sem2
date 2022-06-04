from Person import *

@dataclass
class StudentSubject:
    name : str
    grade : int

class Student(Person):
    def __init__(self, person):
        self.group = person[0][person[0].rfind(' ') + 1 : ]
        person[0] = person[0][2 : person[0].rfind(' ')]
        super().__init__(person[0])
        del person[0]
        self.subjects = []
        for row in person:
            self.subjects.append(StudentSubject(row[ : row.rfind(' ')], int(row[row.rfind(' ') + 1 : ])))

    def getAvgGrade(self):
        all : float = 0
        avg : float
        for subject in self.subjects:
            all += subject.grade
        avg = all / len(self.subjects)
        return avg

    def hasAcdDebt(self):
        for subject in self.subjects:
            if subject.grade < 60:
                return True
        return False

    def isAdult(self):
        if (self.getAge() < 18):
            return False
        else:
            return True