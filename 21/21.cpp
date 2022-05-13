#include <iostream>
#include <iomanip>

using namespace std;

void workflow_1() {
    // ввод размера массива
    int M;
    cout << "Введите количество строк и столбцов M" << endl;
    cin >> M;

    // ввод массива
    int A[M][M];
    cout << "Введите элементы построчно" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    // вывод задания
    int Ibeg = 0, Ifin = 0, Jbeg = 0, Jfin = 0;

    int k = 1;
    int i = 0;
    int j = 0;

    while (k <= M * M){
        cout << A[i][j] << " ";

        if (i == Ibeg && j < M - Jfin - 1)
            ++j;
        else if (j == M - Jfin - 1 && i < M - Ifin - 1)
            ++i;
        else if (i == M - Ifin - 1 && j > Jbeg)
            --j;
        else
            --i;

        if ((i == Ibeg + 1) && (j == Jbeg) && (Jbeg != M - Jfin - 1)){
            ++Ibeg;
            ++Ifin;
            ++Jbeg;
            ++Jfin;
        }
        ++k;
    } cout << endl;

    // Вывод
    /*
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << left << setw(5) << A[i][j];
        } cout << endl;
    } */
};
void workflow_2() {
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

    int K;
    cout << "Введите число K" << endl;
    cin >> K;

    //
    int mult = 1;
    int sum = 0;

    for(int j = 0; j < N; j++) {
        mult *= A[K][j];
        sum += A[K][j];
    }

    cout << "произведение: " << mult << endl;
    cout << "сумма: " << sum << endl;

    // Вывод
    /*
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << left << setw(5) << A[i][j];
        } cout << endl;
    } */
};
void workflow_3() {
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

    //
    int min_mult = 1;
    int index;

    for (int j = 0; j < N; j++) {
        if (j == 0) {
            for (int i = 0; i < M; i++) {
                min_mult *= A[i][j];
                index = 0;
            }
        } else {

            int mult = 1;
            for (int i = 0; i < M; i++) {
                mult *= A[i][j];
            }
            if (mult < min_mult) {
                min_mult = mult;
                index = j;
            }
        }
    }

    cout << "произведение: " << min_mult << endl;
    cout << "номер столбца: " << index << endl;

    // Вывод
    /*
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << left << setw(5) << A[i][j];
        } cout << endl;
    } */
};
void workflow_4() {
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

    for (int j = 0; j < N; j++) {
        float medium = 0;
        int above_med_count = 0;

        for (int i = 0; i < M; i++) {
            medium += A[i][j];
        } medium /= M;

        for (int i = 0; i < M; i++) {
            if (A[i][j] > medium) above_med_count++;
        }

        cout << "В столбце " << j << " " << above_med_count << " элементов больше сред. ариф." << endl;
    }
};
void workflow_5() {
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

    // алгоритм
    int index = -1;
    for (int j = 0; j < N; j++) {

        bool flag_res = true;
        for (int i = 0; i < M; i++) {
            if (A[i][j] % 2 == 0) flag_res = false;
        }
        if (flag_res) {
            index = j;
            cout << "Это столбец " << j << endl;
            break;
        }
    }
    if (index == -1) {
        cout << "таких столбцов нет" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int wf_numb = 0;

    cout << "Задание 21" << endl;
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
