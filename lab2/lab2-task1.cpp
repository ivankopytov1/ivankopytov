#include <iostream>
//#include <clocale> не работает

using namespace std;

int main() 
{
    //setlocale(LC_ALL, "ru"); 
    double epsilon = 1e-4;
    double sum = 0;
    double a_n;
    int n = 1;

    do {
        // 1. Вычисляем текущий член ряда
        a_n = 1.0 / ((3.0 * n - 2.0) * (3.0 * n + 1.0));
        
        // 2. Добавляем его к сумме
        sum += a_n;
        
        // 3. Переходим к следующему n
        n++;
        
    // 4. Условие продолжения: цикл повторяется, пока модуль последнего добавленного члена >= epsilon
    } while (abs(a_n) >= epsilon);
    
    cout << "The sum of the series with precision e=" << epsilon << ": " << fixed << sum << endl;

    return 0;
}

//Вывод: The sum of the series with precision e=0.0001: 0.330097