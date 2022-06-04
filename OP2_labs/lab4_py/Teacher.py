from Person import *

@dataclass
class TeacherSubject:
    name : str
    popularity : int

class Teacher(Person):
    def __init__(self, person):
        person[0] = person[0][2 : ]
        super().__init__(person[0])
        del person[0]
        self.subjects = []
        for row in person:
            self.subjects.append(TeacherSubject(row[ : row.rfind(' ')], int(row[row.rfind(' ') + 1 : ])))

    def getAvgPopularity(self):
        all : float = 0
        avg : float
        for subject in self.subjects:
            all += subject.popularity
        avg = all / len(self.subjects)
        return avg