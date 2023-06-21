#include<iostream>
#include<string>
using namespace std;

struct number {
    double num1;
    double num2;
    double answer;
    char operation;
} a[9];

void add();
void subs();
void multi();
void divi();
void showhistory();
char back, history, yn;
string ptr;

int main() {
    do {
        cout << "Calculator" << endl << endl;
        cout << "Input an equation:" << endl;
        cin >> a[0].num1;
        cin >> a[0].operation;
        cin >> a[0].num2;

        if (a[0].operation == '+') {
            add();
            cout << a[0].num1 << "+" << a[0].num2 << "=" << a[0].answer << endl;
        }
        else if (a[0].operation == '-') {
            subs();
            cout << a[0].num1 << "-" << a[0].num2 << "=" << a[0].answer << endl;
        }
        else if (a[0].operation == '*') {
            multi();
            cout << a[0].num1 << "*" << a[0].num2 << "=" << a[0].answer << endl;
        }
        else if (a[0].operation == '/') {
            if (a[0].num2 == 0) {
                cout << "UNDEFINED" << endl;
            }
            else {
                divi();
                cout << a[0].num1 << "/" << a[0].num2 << "=" << a[0].answer << endl;
            }
        }
        else {
            cout << "Invalid operator" << endl;
            continue;
        }

        for (int i = 9; i > 0; i--) {
            a[i].num1 = a[i - 1].num1;
            a[i].operation = a[i - 1].operation;
            a[i].num2 = a[i - 1].num2;
            a[i].answer = a[i - 1].answer;
        }

        cout << "Show History? [Y/N]:";
        cin >> yn;
        cout << endl << endl;
        if (yn == 'y' || yn == 'Y') {
            showhistory();
        }

     cout << "Return [Y/N]:";
        cin >> back;
        cout << endl << endl;
    } while (back == 'y' || back == 'Y');

    return 0;
}

void add() {
    a[0].answer = a[0].num1 + a[0].num2;
}

void subs() {
    a[0].answer = a[0].num1 - a[0].num2;
}

void multi() {
    a[0].answer = a[0].num1 * a[0].num2;
}

void divi() {
    a[0].answer = a[0].num1 / a[0].num2;
}

void showhistory() {
    string *pointer = &ptr;

    for (int i = 0; i < 6; i++) {
        cout << (a[i].num1) << (a[i].operation) << (a[i].num2) << " = " << (a[i].answer) << "\n" << pointer + i << endl << endl;
    }
}