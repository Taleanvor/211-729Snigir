#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

// lab 17
int main() {
    // ��������� ������
    setlocale(LC_CTYPE, "rus");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);


    // ���� ������� �������
    int N;
    cout << "������� ������ ������� N" << endl;
    cin >> N;

    // ���� �������
    int A[N];
    cout << "������� N ��������� �������" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    //����� 1
        int K, L;
        cout << "������� ����� K � L, 1 <= K <= L <= N" << endl;
        cin >> K >> L;

        float medium = 0; // ���������� ���������� ������ 1
        for(int i = K-1; i < L; i++) { // K � L ������������� �������, ������������ � �������, � � ������� ��������� � ����, ������� ���
            medium += A[i];
        }
        medium /= (L - K + 1);
        cout << "medium(K, L) = " << medium << endl;

    //����� 2
        bool progression = true; // ���� ����, ��� �������� ���������� ����������
        int diff = 0; // ���������� ���������� ������ 2

        // �������� �� ������� ���������� ���������� ���������
        bool correct2 = true;
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                if (A[i] == A[j]) correct2 = false;
            }
        }

        if (!correct2) {
            cout << "������ �������� ���������� ��������, ����� 2 ��������" << endl;
        } else {
            for (int i = 1; i < N-1; i++) {
                if ( 2*A[i] != A[i-1] + A[i+1] ) progression = false; // ���������� �������� �������� ��������
            }
            if (progression) {
                if (N > 1) diff = A[1] - A[0];
                cout << "diff = " << diff << endl;
            } else {
                cout << "�������� ������� �� �������� ���������� ����. ����������" << endl; // �������� �� ������� � ������� ����, �.�. ����� ���������� �������� � ��������� �� ������ ��������
            }
        }

    //����� 3
        int min_elem = A[0]; // ���������� ���������� ������ 3
        for (int i = 2; i < N; i += 2) { // �������� �������� � ��������
            if (A[i] < min_elem) min_elem = A[i];
        }
        cout << "min_elem = " << min_elem << endl;

    //����� 4
        int local_max = -1; // ���������� ���������� ������ 4

        // �������� ��� ����� �������
        if (N > 1) {
            if (A[N-1] > A[N-2]) local_max = N-1;
        }

        // �������� � �������� �������
        for (int i = N-2; i >= 1; i--) {
            if (A[i] > A[i+1] && A[i] > A[i-1]) local_max = i;
            break;
        }

        // �������� ������� ��������
        if (N > 1 && local_max == -1) {
            if (A[0] > A[1]) local_max = 0;
        }

        cout << "local_max = " << local_max << endl;

    //����� 5
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                if (A[i] == A[j]) {
                    cout << "������ ���������� ���������: " << i << " " << j << endl;
                    goto doublecycle_out; // ����� �� �������� �����
                }
            }
        }
        doublecycle_out: //����� ������ �� �������� �����

    return 0;
}

// ����� ������ � �����������:
// ������ ������� ������������, ��� ��������� ������� ���������� � �������, � �� � ����?
