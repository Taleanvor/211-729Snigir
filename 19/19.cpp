#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

void workflow_1() {
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

    // удаление
    for (int i = 0; i < N - 1; i++) { // основной цикл прохода
        if (A[i] == A[i+1]) { // проверяем текущий по следующим
            for (int j = i; j < N - 1; j++) { // смещаем остаток массива влево
                A[j] = A[j+1];
            }
            N--; i--; // уменьшаем размер на 1, и счетчик оставляем на том же месте
        }
    }

    // вывод массива
    cout << "A: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << endl;
};
void workflow_2() {
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

    // удаление
    for (int i = 0; i < N; i++) { // основной цикл прохода
            cout << "A: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << endl;

        int current_value = A[i];
        int value_count = 0;
        int second_index = -1;

        for (int j = 0; j < N; j++) { // второй цикл прохода
            if (A[j] == current_value) {
                value_count++;
                second_index = j;
            }
        }

        if (value_count == 2) {
            for (int k = second_index; k < N - 1; k++) { // смещаем остаток массива влево
                A[k] = A[k+1];
            }

            for (int k = i; k < N - 1; k++) { // смещаем остаток массива влево
                A[k] = A[k+1];
            }

            N -= 2; i--; // уменьшаем размер на 2, счетчик оставляем там же
        }

    }

    // вывод массива
    cout << "A: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << endl;
};
void workflow_3() {
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

    // поиск
    int min_index = N-1;
    int max_index = 0;

    for (int i = 0; i < N; i++) {
        if (A[max_index] < A[i]) max_index = i;
        if (A[min_index] > A[i]) min_index = i;
    }

    // вставка
    int B[N+2]; int diff = 0;
    for (int i = 0; i < N; i++) {
        B[i+diff] = A[i];
        if (max_index == i) {
            diff++;
            B[i+diff] = 0;
        }
        if (min_index == i) {
            diff++;
            B[i+diff] = 0;
        }
    }

    // вывод массива
    cout << "B: ";
    for (int i = 0; i < N+2; i++) {
        cout << B[i] << " ";
    } cout << endl;
};
void workflow_4() {
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

    // поиск
    int negative_count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) negative_count++;
    }

    // вставка
    int B[N+negative_count]; int diff = 0;
    for (int i = 0; i < N; i++) {
        B[i+diff] = A[i];
        if (A[i] < 0) {
            diff++;
            B[i+diff] = 0;
        }
    }

    // вывод массива
    cout << "B: ";
    for (int i = 0; i < N+2; i++) {
        cout << B[i] << " ";
    } cout << endl;
};
void workflow_5() {
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

    // поиск
    int positive_count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) positive_count++;
    }

    // вставка
    int B[N+positive_count]; int diff = 0;
    for (int i = 0; i < N; i++) {
        B[i+diff] = A[i];
        if (A[i] > 0) {
            diff++;
            B[i+diff] = 0;
        }
    }

    // вывод массива
    cout << "B: ";
    for (int i = 0; i < N+2; i++) {
        cout << B[i] << " ";
    } cout << endl;
};

int main() {
    setlocale(LC_ALL, "Russian");

    int wf_numb = 0;

    cout << "Задание 19" << endl;
    cout << "Введите сабномер задания (от одного до пяти)" << endl;
    cin >> wf_numb;

    switch (wf_numb) {
        case 1:
            workflow_1();
            break;
        case 2:
            workflow_2();
            break;
        case 3:
            workflow_3();
            break;
        case 4:
            workflow_4();
            break;
        case 5:
            workflow_5();
            break;
        default:
            cout << "Введенный сабномер задания неверен" << endl;
    }

    cin;
    return 0;
}
