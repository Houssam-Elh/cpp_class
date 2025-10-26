#include <iostream>
using namespace std;

// Incrémenter un entier par référence
void incrementer(int& x) {
    x++;
}

// Permuter deux entiers par référence
void permuter(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int a = 5, b = 10;
    cout << "On a A = " << a << endl;
    cout << "On a B = " << b << endl;

    incrementer(a);
    cout << "Apres incrementation, a = " << a << endl;

    permuter(a, b);
    cout << "Apres permutation, a = " << a << ", b = " << b << endl;
    return 0;
}