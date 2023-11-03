#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // Изменение кодировки терминала:
    system("chcp 1251 > nul");
    // Установка цвета фона терминала и цвета текста
    system("color 80");

    cout << endl;

    int deposit;                                                             // Объявляем переменные для записи данных
    int interest;
    int summ;
    int years = 0;
    string text;

    cout << " Введите размер вклада: ";                                      // Запрашиваем и записываем в переменные данные для вычисления 
    cin >> deposit;
    cout << " Введите процентную ставку: ";
    cin >> interest;
    cout << " Введите желаемую сумму: ";
    cin >> summ;

    if (summ < deposit || interest <= 0 || deposit <= 0) {                   // Условием проверяем корректность введёных данных 
        cout << " Введены некорректные данные!" << endl;
    }
    else {
        while (deposit < summ) {                                             // В цикле вычисляем кол-во лет для накопления summ 
            deposit += deposit * interest / 100;
            years++;
        }

        if (years % 10 == 0 || years % 10 >= 5 || (years / 10) % 10 == 1) {  // Условием присваиваем переменной text необхоимое склонение слова "год"
            text = " лет.";
        }
        else {
            if (years % 10 == 1) {
                text = " год.";
            }
            else {
                text = " года.";
            }
        }

        cout << " Придётся подождать: " << years << text << endl;           // Выводим сообщение с текстом о сроке необходимом для накопления summ
    }


    // Задержка окна консоли:
    system("pause > nul");

    return 0;
}
// Введите размер вклада : 100
// Введите процентную ставку : 10
// Введите желаемую сумму : 200
// Придётся подождать : 8 лет