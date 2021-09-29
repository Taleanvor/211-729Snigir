#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

// lab 17
int main() {
    // настройка вывода
    setlocale(LC_CTYPE, "rus");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);


    // ввод размера массива
    int N;
    cout << "Введите размер массива N" << endl;
    cin >> N;

    // ввод массива
    int A[N];
    cout << "Введите N элементов массива" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    //Пункт 1
        int K, L;
        cout << "Введите числа K и L, 1 <= K <= L <= N" << endl;
        cin >> K >> L;

        float medium = 0; // переменная результата пункта 1
        for(int i = K-1; i < L; i++) { // K и L соответствует номерам, начинающимся с единицы, а в массиве нумерация с нуля, поэтому так
            medium += A[i];
        }
        medium /= (L - K + 1);
        cout << "medium(K, L) = " << medium << endl;

    //Пункт 2
        bool progression = true; // флаг того, что элементы составляют прогрессию
        int diff = 0; // переменная результата пункта 2

        // проверка на условие отсутствия одинаковых элементов
        bool correct2 = true;
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                if (A[i] == A[j]) correct2 = false;
            }
        }

        if (!correct2) {
            cout << "Массив содержит одинаковые элементы, пункт 2 пропущен" << endl;
        } else {
            for (int i = 1; i < N-1; i++) {
                if ( 2*A[i] != A[i-1] + A[i+1] ) progression = false; // используем свойство среднего элемента
            }
            if (progression) {
                if (N > 1) diff = A[1] - A[0];
                cout << "diff = " << diff << endl;
            } else {
                cout << "Элементы массива не являются элементами геом. прогрессии" << endl; // отступил от задания с выводом нуля, т.к. иначе происходит путаница с массивами из одного элемента
            }
        }

    //пункт 3
        int min_elem = A[0]; // переменная результата пункта 3
        for (int i = 2; i < N; i += 2) { // четность заложена в счетчике
            if (A[i] < min_elem) min_elem = A[i];
        }
        cout << "min_elem = " << min_elem << endl;

    //пункт 4
        int local_max = -1; // переменная результата пункта 4

        // проверка для конца массива
        if (N > 1) {
            if (A[N-1] > A[N-2]) local_max = N-1;
        }

        // проверка в середине массива
        for (int i = N-2; i >= 1; i--) {
            if (A[i] > A[i+1] && A[i] > A[i-1]) local_max = i;
            break;
        }

        // проверка первого элемента
        if (N > 1 && local_max == -1) {
            if (A[0] > A[1]) local_max = 0;
        }

        cout << "local_max = " << local_max << endl;

    //пункт 5
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                if (A[i] == A[j]) {
                    cout << "Номера одинаковых элементов: " << i << " " << j << endl;
                    goto doublecycle_out; // выход из двойного цикла
                }
            }
        }
        doublecycle_out: //метка выхода из двойного цикла

    return 0;
}

// МИКРО вопрос к составителю:
// Почему задания предполагают, что нумерация массива начинается с единицы, а не с нуля?
