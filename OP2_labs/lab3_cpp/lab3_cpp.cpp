/*
Визначити клас "Roman_numerals", який задає число в римській формі запису (рядок)

Реалізувати для заданого класу:
декілька конструкторів, геттери, методи перетворення числа у десяткове

Перевантажити оператори:
префіксний "++" для інкрементації даного числа
"+=" для збільшення його на вказане римське число
"+" для додавання двох римських чисел

Cтворити три римських числа (R1, R2, R3), використовуючи різні конструктори
Інкрементувати число R1; R2 збільшити на вказану величину
Знайти суму R1 + R2 та зберегти її в R3
Перевести R3 в десятковий формат
*/

#include "Header.h"
#include "RomanNumeral.h"

int main()
{
    string num1, num2;
    cout << "Enter the numbers R1 and R2 (in arabic or roman)\n";
    cout << "Leave the row empty to set its value to 1 (default)\n";
    cin >> num1 >> num2;
    RomanNumeral R1 = createRomanNumeral(num1);
    RomanNumeral R2 = createRomanNumeral(num2);

    cout << "R1:\n";
    R1.displayValue();
    cout << "R2:\n";
    R2.displayValue();
    
    ++R1;
    cout << "R1 was incremented:\n";
    R1.displayValue();

    cout << "enter a roman number to add to R2\n";
    string addToR2;
    cin >> addToR2;
    if (isRoman(addToR2))
    {
        R2 += addToR2;
        cout << "added " << addToR2 << " to R2:\n";
        R2.displayValue();
    }
    else
    {
        cout << "Invalid value, R2 was not changed\n";
    }

    RomanNumeral R3 = R1 + R2;
    cout << "R3 = R1 + R2:'\n'";
    R3.displayValue();
}