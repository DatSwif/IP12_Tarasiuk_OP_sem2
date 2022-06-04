//Спроєктувати клас "Особа", 
//що містить ПІБ, дату народження 
//і методи визначення її віку та обчислення рейтингу. 
//На основі цього класу створити класи-нащадки "Студент", 
//який містить додатково номер академічної групи студента,
//дисципліни, що вивчалися ним в останньому семестрі, 
//рейтинговий бал із цих дисциплін,
//та "Викладач", який містить додатково назви дисциплін, що викладає,
//рейтинговий бал популярності з кожної дисципліни від 1 до 10.
//Створити n студентів та m викладачів. 
//Для студентів розрахувати їх середній бал
//для викладачів середній бал популярності
//Визначити кількість неповнолітніх студентів, 
//що мають академічні заборгованості (менше 60 балів)
#pragma once
#include "Header.h"
#include "Teacher.h"
#include "Student.h"
    
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Data will be taken from the sample.txt file \nwhich is already filled with test data\n\n";
    string filename = "sample.txt";
    vector<Student> students;
    vector<Teacher> teachers;
    readFile(filename, teachers, students);
    outAvgStudentGrade(students);
    outAvgTeacherPopularity(teachers);
    outMinorAcdDebtors(students);
}

/*
Костюк Анастасія Сергіївна 79.33
Боцман Захар Валентинович 67.66
Дудка Ставніслав Олегович 78.00

avg 75

Лисенко Роман Павлович 9.00
Вєтрова Поліна Миколаївна 6.00
Мельник Станіслав Андрійович 9.50

avg 8.16

1 has debt
*/