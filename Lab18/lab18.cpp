#include <iostream>
#include <clocale>

using namespace std;

void task_1() {
    // ввод размера массивов
    int N;
    cout << "Введите размер массивов N" << endl;
    cin >> N;

    // ввод массива А
    int A[N];
    cout << "Введите N элементов массива А" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // ввод массива B
    int B[N];
    cout << "Введите N элементов массива B" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // меняем местами элементы массивов
    for (int i = 0; i < N; i++) {
        A[i] = A[i] + B[i];
        B[i] = A[i] - B[i];
        A[i] = A[i] - B[i];
    }

    // вывод массива A
    cout << "A: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << endl;

    // вывод массива B
    cout << "B: ";
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    } cout << endl;
}
void task_2() {
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

    // заполняем массив результатов
    float B[N];
    for (int i = 0; i < N; i++) {
        B[i] = 0;
        for (int j = 0; j <= i; j++) {
            B[i] += A[j];
        }
        B[i] /= (i+1);
    }

    // вывод массива
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    } cout << endl;
}
void task_3() {
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

    // делаем таск
    // ищем последний нечетный элемент
    int delta = 0;
    for (int i = N-1; i >= 0; i--) {
        if (A[i] % 2 == 1) {
            delta = A[i];
            break;
        }
    }
    // увеличиваем нечетные элементы
    if (delta != 0) {
        for (int i = 0; i < N; i++) {
            if (A[i] % 2 == 1) {
                A[i] += delta;
            }
        }
    }

    // вывод массива
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << endl;
}
void task_4() {
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

    // делаем таск
    // ищем макс и мин элементы (их номера)
    int i_max = 0;
    int i_min = 0;
    for (int i = 1; i < N; i++) {
        if (A[i_max] < A[i]) i_max = i;
        if (A[i_min] > A[i]) i_min = i;
    }
    // обнуляем
    for (int i = i_min + 1; i <= i_max - 1; i++) {
        A[i] = 0;
    }

    // вывод массива
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << endl;
}
void task_5() {
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

    // делаем таск
    for (int i = N-1; i > 0; i--) { // идем с конца, ибо знаем A[0] > A[1] из условия
        if (A[0] > A[i]) { // проверяем когда подойдет
            int mem = A[0]; // запоминаем вставляемый элемент
            for (int j = 0; j < i; j++) { // сдвигаем нужную часть массива
                A[j] = A[j+1];
            }
            A[i] = mem; // вставляем элемент на освободившееся место
            break;
        }
    }

    // вывод массива
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << endl;
}

int main() {
    setlocale(LC_CTYPE, "rus");

    int task_number = -1;
    cout << "Введите номер задания" << endl;
    cin >> task_number;

    switch (task_number) {
    case 1:
        task_1();
        break;
    case 2:
        task_2();
        break;
    case 3:
        task_3();
        break;
    case 4:
        task_4();
        break;
    case 5:
        task_5();
        break;
    default:
        cout << "Такого номера задания не предусмотрено" << endl;
    }

    return 0;
}
