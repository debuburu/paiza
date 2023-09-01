#include <iostream>
using namespace std;

int main(void){
    string str;
    getline(cin, str);

    const int LENGTH = str.length() + 2;
    for (int i = 0; i < LENGTH; i++) {
        cout << "+";
    }
    cout << endl;;

    cout << "+";
    cout << str;
    cout << "+" << endl;;

    for (int i = 0; i < LENGTH; i++) {
        cout << "+";
    }
    cout << endl;;

    return 0;
}