#include <iostream>
using namespace std;

int main() {
    int a = 10;            // Déclaration d'un entier
    int& ref = a;          // Référence sur l’entier
    int* ptr = &a;         // Pointeur sur l’entier

    cout << "Valeur de a      : " << a << endl;
    cout << "Adresse de a     : " << &a << endl;

    cout << "Valeur ref       : " << ref << endl;
    cout << "Adresse de ref   : " << &ref << endl;

    cout << "Valeur pointée par ptr  : " << *ptr << endl;
    cout << "Adresse contenue dans ptr: " << ptr << endl;
    cout << "Adresse de ptr          : " << &ptr << endl;

    return 0;
}
