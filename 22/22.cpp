#include <iostream>
#include <iomanip>

using namespace std;

void workflow_1() {
    // ввод размера массива
    int M, N;
    cout << "Введите количество строк M и столбцов N" << endl;
    cin >> M >> N;

    // ввод массива
    int A[M][N];
    cout << "Введите элементы построчно" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }


    for (int i = 0; i < M; i++) {

        int index_min = 0;
        int index_max = 0;
        int min_el = A[i][0];
        int max_el = A[i][0];

        for (int j = 0; j < N; j++) {
            if (A[i][j] > max_el) {
                index_max = j;
                max_el = A[i][j];
            }
            if (A[i][j] < min_el) {
                index_min = j;
                min_el = A[i][j];
            }
        }

        int mem = A[i][index_min];
        A[i][index_min] = A[i][index_max];
        A[i][index_max] = mem;

    }

    // Вывод
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << left << setw(5) << A[i][j];
        } cout << endl;
    }
};
void workflow_2() {
    // ввод размера массива
    int M, N;
    cout << "Введите количество строк M и столбцов N" << endl;
    cin >> M >> N;

    //ввод массива
    int A[M][N];
    cout << "Введите элементы построчно" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int col_min = 0;
    int col_max = 0;

    int min_el = A[0][0];
    int max_el = A[0][0];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > max_el) {
                col_max = j;
                max_el = A[i][j];
            }
            if (A[i][j] < min_el) {
                col_min = j;
                min_el = A[i][j];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int mem = A[i][col_min];
        A[i][col_min] = A[i][col_max];
        A[i][col_max] = mem;
    }

    // Вывод
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << left << setw(5) << A[i][j];
        } cout << endl;
    }
};
void workflow_3() {
    // ввод размера массива
    int M, N;
    cout << "Введите количество строк M и столбцов N" << endl;
    cin >> M >> N;

    //ввод массива
    int A[M][N];
    cout << "Введите элементы построчно" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    // алгоритм
    for (int i = 0; i < M/2; i++) {
        for (int j = 0; j < N/2; j++) {

            int mem = A[i+M/2][j+N/2];
            A[i+M/2][j+N/2] = A[i][j];
            A[i][j] = mem;

        }
    }



    // Вывод
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << left << setw(5) << A[i][j];
        } cout << endl;
    }
};
void workflow_4() {
    // ввод размера массива
    int M, N;
    cout << "Введите количество строк M и столбцов N" << endl;
    cin >> M >> N;

    //ввод массива
    int A[M][N];
    cout << "Введите элементы построчно" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    // алгоритм
    for (int i = 0; i < M; i++) {
        for (int k = i; k < M; k++) {

            if (A[i][0] > A[k][0]) {
                for (int j = 0; j < N; j++) {
                    int mem = A[k][j];
                    A[k][j] = A[i][j];
                    A[i][j] = mem;
                }
            }

        }
    }

    // Вывод
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << left << setw(5) << A[i][j];
        } cout << endl;
    }
};
void workflow_5() {
        // ввод размера массива
    int M;
    cout << "Введите количество строк и столбцов M" << endl;
    cin >> M;

    //ввод массива
    int A[M][M];
    cout << "Введите элементы построчно" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    // алгоритм
    for (int k = -M+1; k <= 0; k++) {
        int L = M + k;

        int sum = 0;
        for (int j = 0; j < L; j++) {
            sum += A[M-L+j][j];
        }
        cout << sum << endl;
    }

    for (int k = 1; k < M; k++) {
        int L = M - k;

        int sum = 0;
        for (int i = 0; i < L; i++) {
            sum += A[i][M-L+i];
        }
        cout << sum << endl;
    }


    // Вывод
    /*
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << left << setw(5) << A[i][j];
        } cout << endl;
    } */
};

int main() {
    setlocale(LC_ALL, "Russian");

    int wf_numb = 0;

    cout << "Задание 22" << endl;
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
