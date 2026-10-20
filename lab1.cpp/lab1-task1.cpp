#include <iostream>
#include <clocale> // У меня не работает!!!

using namespace std;

int main() {
    // 1. Подключаем руссификцию
    setlocale(LC_ALL, "ru"); // У меня не работает!!!
    // 2. Исходные данные
    // Явно указываем суффикс f для типа float
    float a_f = 1000.0;
    float b_f = 0.0001;

    double a_d = 1000.0;
    double b_d = 0.0001;

    // 3. Вычисления для типа float
    
    // Промежуточные переменные
    float sum_f = a_f + b_f;                 // (a + b)
    float square_sum_f = sum_f * sum_f;      // (a + b)^2
    
    float square_a_f = a_f * a_f;            // a^2
    
    float two_ab_f = 2.0f * a_f * b_f;       // 2ab
    
    // Числитель
    float numerator_f = square_sum_f - (square_a_f + two_ab_f); 
    
    // Знаменатель
    float denominator_f = b_f * b_f;         // b^2
    
    // Итоговый результат 
    float result_f = numerator_f / denominator_f;

    // 3. Вычисления для типа double
    
    // Промежуточные переменные
    double sum_d = a_d + b_d;                // (a + b)
    double square_sum_d = sum_d * sum_d;     // (a + b)^2
    
    double square_a_d = a_d * a_d;           // a^2
    
    double two_ab_d = 2.0 * a_d * b_d;       // 2ab
    
    // Числитель 
    double numerator_d = square_sum_d - (square_a_d + two_ab_d);
    
    // Знаменатель 
    double denominator_d = b_d * b_d;        // b^2
    
    // Итоговый результат 
    double result_d = numerator_d / denominator_d;

    cout << fixed;
    
    cout << "Результат float:  " << result_f << endl;
    cout << "Результат double: " << result_d << endl;

    return 0;
}
//Результат Float:  6250000.5000000000
//Результат Double: 1.0011717677



//Объяснение результатов:
//Тип float имеет всего около 7 значащих десятичных цифр
//Тип double имеет 15-17 значащих десятичных цифр