from Student import *
from Teacher import *

def readFile(filename, students, teachers):
    infile = open(filename, 'r')
    text = infile.read().split('\n')
    person = []
    for row in text:
        if (row[1] == ' ') and ((row[0] == 'S') or (row[0] == 'T')):
            if len(person) != 0:
                if person[0][0] == 'S':
                    students.append(Student(person))
                    person.clear()
                elif person[0][0] == 'T':
                    teachers.append(Teacher(person))
                    person.clear()
        person.append(row)
    if len(person) != 0:
        if person[0][0] == 'S':
            students.append(Student(person))
            person.clear()
        elif person[0][0] == 'T':
            teachers.append(Teacher(person))
            person.clear()
    infile.close()

def outAvgTeacherPopularity(teachers):
    print("Calculating average popularity of these teachers:")
    curr : float
    all : float = 0.0
    avg : float
    for teacher in teachers:
        curr = teacher.getAvgPopularity()
        all += curr
        print(teacher.getName(), curr)
    avg = all / len(teachers)
    print("Average popularity: ", avg, "\n")

def outAvgStudentGrade(students):
    print("Calculating average grades of these students: \n")
    curr : float
    all : float = 0.0
    avg : float
    for student in students:
        curr = student.getAvgGrade()
        all += curr
        print(student.getName(), curr)
    avg = all / len(students)
    print("Average grades: ", avg, "\n")

def outMinorAcdDebtors(students):
    count = 0
    for student in students:
        if (not student.isAdult()) and (student.hasAcdDebt()):
            count += 1
    print("less than 18 year old students with academic debt: ", count)