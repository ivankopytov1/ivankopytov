#include <iostream>
#include <cstdlib> // Для rand(), srand()
#include <ctime>   // Для time()

using namespace std;

int main() {
    // Настройка локали для корректного вывода кириллицы (опционально)

    const int N = 100; // Максимально возможный размер
    int a[N];          // Сам массив
    int n;             // Реальная (текущая) длина массива

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Ввод реальной длины массива
    do {
        cout << "Enter the actual length of the array (no more than " << N << "): "; //"Введите реальную длину массива (не более " << N << "): "
        cin >> n;
    } while (n <= 0 || n > N);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; 
    }

    // Полученный массив 
    cout << "Original array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;

    //3. Удалить последний элемент равный 0
    // Ищем с конца
    int indexToDelete = -1;
    bool f = false; // Наш флажок

    for (int i = n - 1; i >= 0; i--) {
        // Проверяем, что элемент равен 0 И мы его еще не находили (!found)
        if (a[i] == 0 && !f) {
            indexToDelete = i;
            f = true; // Поднимаем флажок, чтобы больше не перезаписывать индекс
        }
    }

    if (indexToDelete != -1) {
        cout << "Removing the last zero (index " << indexToDelete << ")..." << endl;
        // Сдвигаем элементы влево, начиная с найденного индекса
        for (int i = indexToDelete; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--; // Уменьшаем реальную длину
    } else {
        cout << "No elements equal to 0 were found." << endl;
    }
    

    // --- 4) Добавить после элемента с заданным индексом элемент 100 ---
    int k;
    cout << "Enter the index of the element AFTER which you need to insert 100 (from 0 to " << n - 1 << "): ";
    cin >> k;

    // Проверка корректности индекса и возможности вставки (есть ли место в массиве)
    if (k >= 0 && k < n && n < N) {
        // Сдвигаем элементы вправо, чтобы освободить место для вставки
        // Идем с конца текущей длины до индекса k+1
        for (int i = n; i > k + 1; i--) {
            a[i] = a[i - 1];
        }
        a[k + 1] = 100; // Вставляем значение
        n++;            // Увеличиваем реальную длину
        cout << "The element has been added." << endl;
    } else {
        cout << "Error: invalid index or array overflow." << endl;
    }

    // --- 5) Распечатать полученный массив ---
    cout << "The final array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
