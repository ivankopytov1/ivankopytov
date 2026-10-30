#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a = 0.1;
    double b = 1.0;
    int k_steps = 9;
    int n_fixed = 10;
    double epsilon = 0.0001;

    // Шаг
    double h = (b - a) / k_steps;

    // Цикл по x от a до b с шагом h

    for (double x = a; x <= b + 1e-9; x += h) 
    {
        
        // а)

        double SN = 0.0;
        for (int k = 0; k <= n_fixed; ++k) {

            //(2k)!

            double fact = 1.0;
            for (int i = 2; i <= 2 * k; ++i) 
            {
                fact *= i;
            }
            
            double term = pow(-1, k) * pow(x, 2 * k) / fact;
        SN += term;
        }
        
        // б)
        
        double SE = 0.0;
        double term = 1.0;
        int k = 0;
        while (abs(term) >= epsilon) 
        {
            double fact = 1.0;
            for (int i = 2; i <= 2 * k; ++i) 
            {
                fact *= i;
            }
            
            term = pow(-1, k) * pow(x, 2 * k) / fact;
            SE += term;
            k++;
        }
        
        // Точное значение
        double Y = cos(x);
        
        // Вывод строки таблицы
        cout << fixed;
        cout << "|X = " << x << " |SN = " << SN << " |SE = " << SE <<  " |Y = " << Y << " |" << endl;
        //X - значение параметра; 
        //SN - значение суммы для заданного n; 
        //SE - значение суммы для заданной точности; 
        //Y - точное значение функции.
    }

    return 0;
}