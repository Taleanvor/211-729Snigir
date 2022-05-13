#include <iostream>
#include <iomanip>
#include <cmath>

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

    // поиск количества серий
    int series_count = 1;
    for (int i = 0; i < N-1; i++) {
        if (A[i] != A[i+1]) series_count++;
    }

    //
    int B[series_count];
    int C[series_count];

    int prev_ser_index = 0;
    int series = 0;
    for (int i = 0; i < N-1; i++) {
        if (A[i] != A[i+1]) {
            B[series] = i+1-prev_ser_index;
            prev_ser_index = i+1;

            C[series] = A[i];
            series++;
        }
        if (i == N-2) {
            B[series] = i+1-prev_ser_index + 1; //т.к. счетчик не увеличился
            prev_ser_index = i+1;

            C[series] = A[N-1];
            series++;
        }
    }

    // вывод массива
    cout << "B: ";
    for (int i = 0; i < series_count; i++) {
        cout << B[i] << " ";
    } cout << endl;

    cout << "C: ";
    for (int i = 0; i < series_count; i++) {
        cout << C[i] << " ";
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

    // ввод размера массива
    int L;
    cout << "Введите число L" << endl;
    cin >> L;

    int I[N]; // индикаторный массив для удаления
    for (int i = 0; i < N; i++) {
        I[i] = 0;
    }

    // поиск
    int left_ser_ind = 0;
    int right_ser_ind = 0;
    int length = 0;
    for (int i = 0; i < N-1; i++) {
        if (A[i] == A[i+1]) {
            right_ser_ind = i+1;
        }
        if (A[i] != A[i+1]) {
            right_ser_ind = i;
            length = right_ser_ind - left_ser_ind + 1;
            //cout << length << endl;
            if (length > L) {
                for(int j = left_ser_ind; j <= right_ser_ind; j++) I[j] = 1;
                I[left_ser_ind] = 2;
            }

            left_ser_ind = i+1;
        }

        if (i == N-2) {
            length = right_ser_ind - left_ser_ind + 1;
            if (length > L) {
                for(int j = left_ser_ind; j <= right_ser_ind; j++) I[j] = 1;
                I[left_ser_ind] = 2;
            }
            left_ser_ind = i+1;
        }
    }

    // удаление
    int diff = 0; int M = N;
    for (int i = 0; i < N; i++) {
        if (I[i] == 0) {
            A[i-diff] = A[i];
        }
        if (I[i] == 1) {
            diff++;
        }
        if (I[i] == 2) {
            A[i-diff] = 0;
        }
    }

    // вывод массива
    cout << "A: ";
    for (int i = 0; i < N-diff; i++) {
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

    // ввод размера массива
    int K;
    cout << "Введите число K" << endl;
    cin >> K;

    int I[N]; // индикаторный массив для замены
    for (int i = 0; i < N; i++) {
        I[i] = 0;
    }

    // поиск
    int left_ser_ind = 0;
    int right_ser_ind = 0;
    int series_number = 0;

    for (int i = 0; i < N-1; i++) {
        if (A[i] == A[i+1]) {
            right_ser_ind = i+1;
        }
        if (A[i] != A[i+1]) {
            right_ser_ind = i;
            series_number++;

            if (series_number == K) {
                for(int j = left_ser_ind; j <= right_ser_ind; j++) I[j] = 1;
            }

            left_ser_ind = i+1;
        }

        if (i == N-2) {
            series_number++;
            if (series_number == K) {
                for(int j = left_ser_ind; j <= right_ser_ind; j++) I[j] = 1;
            }

            left_ser_ind = i+1;
        }
    }

    for (int i = N-1; i > 0; i--) {
        if (I[i] == 1) {
            I[i] = 0;
        } else {
            I[i] = 2;
        }

        if (A[i] != A[i-1]) break;
    }

    // замена
    int B[N];
    bool flag_K_copied = false;
    bool flag_L_copied = false;

    int diff = 0;
    for(int i = 0; i<N; i++) {
        if (I[i] == 0) B[i+diff] = A[i];

        if (I[i] == 1 && !flag_L_copied) {
            flag_L_copied = true;
            for (int j = 0; j < N; j++) {
                if (I[j] == 2) {
                    B[i+diff] = A[j];
                    diff++;
                }
            }
        }
        if (I[i] == 1) diff--;

        if (I[i] == 2 && !flag_K_copied) {
            flag_K_copied = true;
            for (int j = 0; j < N; j++) {
                if (I[j] == 1) {
                    B[i+diff] = A[j];
                    diff++;
                }
            }
        }
        if (I[i] == 2) diff--;
    }


    // вывод массива
    cout << "B: ";
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    } cout << endl;
};
void workflow_4() {
    // ввод размера массива
    int N;
    cout << "Введите количество точек N" << endl;
    cin >> N;

    int X[N];
    int Y[N];

    // ввод массива
    int A[N];
    cout << "Введите точки (X, Y)" << endl;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    // поиск
    float r = -1.0;
    int index;
    for(int i = 0; i < N; i++) {
        if (X[i] < 0 && Y[i] > 0) {
            float rp = sqrt(X[i]*X[i] + Y[i]*Y[i]);
            if (rp > r) {
                r = rp;
                index = i;
            }
        }
    }

    // вывод
    if (r < 0) {
        cout << "Такой точки нет" << endl;
    } else {
        cout << X[index] << " " << Y[index] << endl;
    }
};
void workflow_5() {
    // ввод размера массива
    int N;
    cout << "Введите количество точек N" << endl;
    cin >> N;

    int X[N];
    int Y[N];

    // ввод массива
    int A[N];
    cout << "Введите точки (X, Y)" << endl;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    // поиск
    float p = -1.0;
    float pp;
    int index1, index2, index3;

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            for(int k = j+1; k < N; k++) {
                pp = sqrt((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]))
                   + sqrt((X[k]-X[j])*(X[k]-X[j]) + (Y[k]-Y[j])*(Y[k]-Y[j]))
                   + sqrt((X[i]-X[k])*(X[i]-X[k]) + (Y[i]-Y[k])*(Y[i]-Y[k]));

                if (pp > p) {
                    p = pp;
                    index1 = i;
                    index2 = j;
                    index3 = k;
                }
            }
        }
    }

    // вывод
    cout << X[index1] << " " << Y[index1] << endl;
    cout << X[index2] << " " << Y[index2] << endl;
    cout << X[index3] << " " << Y[index3] << endl;

};

int main() {
    setlocale(LC_ALL, "Russian");

    int wf_numb = 0;

    cout << "Задание 20" << endl;
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
