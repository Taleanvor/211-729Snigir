#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void workflow_1() {
    string S;
    cout << "Введите строку S" << endl;

    cin.ignore();
    getline(cin, S);

    int count = 0;
    for (int i = 0; i < S.size()-1; i++) {
        if ((S[i] != ' ') && (S[i+1] == ' ')) count++;
    }
    if (S[S.size() - 1] != ' ') count++;

    cout << count;
};
void workflow_2() {
    string S;
    cout << "Введите строку S" << endl;

    cin.ignore();
    getline(cin, S);

    int count = 1;
    int min = S.size();
    for (int i = 1; i < S.size(); i++) {
        if (S[i] != ' ') count++;
        if ((S[i] == ' ') && (S[i-1] != ' ')) {
            if (min > count) min = count;
            count = 0;
        }
    } if (min > count) min = count;

    cout << min;
};
void workflow_3() {
    string S;
    cout << "Введите строку S" << endl;

    cin.ignore();
    getline(cin, S);

    for (int i = 0; i < S.size(); i++) {

        char C = S[i];

        if (C != ' ') {
            int pos = i;
            while (S.find(C, pos+1) != string::npos) {
                pos = S.find(C, pos+1);
                S.replace(pos, 1, 1, '.');
            }
        }
    }

    cout << S;
};
void workflow_4() {
    string S;
    cout << "Введите строку S" << endl;

    cin.ignore();
    getline(cin, S);

    int count = 0;

    string glas = "уУеЕыЫаАоОэЭяЯиИюЮёЁ";
    for (int i = 0; i < S.size(); i++) {
        if (glas.find(S[i]) != string::npos) count++;
    }

    cout << count;
};
void workflow_5() {
    string S;
    cout << "Введите строку S" << endl;

    cin.ignore();
    getline(cin, S);

    int pos1 = S.rfind('/');
    int pos2 = S.rfind('.');

    cout << S.substr(pos1+1, pos2-pos1-1);
};
void workflow_6() {
    string S;
    cout << "Введите строку S" << endl;

    cin.ignore();
    getline(cin, S);

    int pos1 = S.rfind('/');
    int pos2 = S.rfind('/', pos1-1);

    cout << S.substr(pos2+1, pos1-pos2-1);
};
void workflow_7() {
    string S;
    cout << "Введите строку S" << endl;

    cin.ignore();
    getline(cin, S);

    string Res = "";
    for(int i = 0; i < S.size(); i++) {
        if (i%2 == 0) Res += S[i];
    }
    for(int i = S.size()-1; i >= 0; i--) {
        if (i%2 == 1) Res += S[i];
    }

    cout << Res;
};

int main() {
    setlocale(LC_ALL, "Russian");

    int wf_numb = 0;

    cout << "Задание 24" << endl;
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
        case 6:
            workflow_6();
            break;
        case 7:
            workflow_7();
            break;
        default:
            cout << "Введенный сабномер задания неверен" << endl;
    }

    //cin;
    return 0;
}
