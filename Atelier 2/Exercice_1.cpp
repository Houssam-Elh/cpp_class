#include <iostream>
using namespace std;

int count = 0;

void compteur() {
    count++;
    cout << "appel numero " << count << endl;
}

int main() {
    compteur(); // il appel numero 1
    compteur(); // il appel numero 2
    compteur(); // il appel numero 3
    return 0;
}