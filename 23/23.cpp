#include <iostream>
#include <iomanip>

using namespace std;

void workflow_1() {
    // ввод размера массива
    char C;
    cout << "Введите символ C" << endl;
    cin >> C;

    cout << (char)((int)C-1) << endl;
    cout << (char)((int)C) << endl;
    cout << (char)((int)C+1) << endl;
};
void workflow_2() {
    string S;
    cout << "Введите строку S" << endl;
    cin >> S;

    for(int i = S.size()-1; i > 0; i--) {
        S.insert(i,1,' ');
    }

    cout << S;
};
void workflow_3() {
    string S;
    cout << "Введите строку S" << endl;
    cin >> S;

    int count = 0;
    for(int i = 0; i < S.size(); i++) {
        if (('a' <= S[i]) && (S[i] <= 'z')) count++;
    }

    cout << count;
};
void workflow_4() {
    string S;
    cout << "Введите строку S" << endl;
    cin >> S;

    char C;
    cout << "Введите символ C" << endl;
    cin >> C;

    for(int i = S.size()-1; i >= 0; i--) {
        if (S[i] == C) S.insert(i,1,C);
    }

    cout << S;
};
void workflow_5() {
    string S;
    cout << "Введите строку S" << endl;
    cin >> S;

    string S0;
    cout << "Введите строку S0" << endl;
    cin >> S0;

    int count = 0;
    for(int i = 0; i < S.size(); i++) {
        int pos = S.find(S0, i);
        if (pos != -1) {
            count++;
            i = pos + 1;
        }
    }

    cout << count;
};

int main() {
    setlocale(LC_ALL, "Russian");

    int wf_numb = 0;

    cout << "Задание 23" << endl;
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
