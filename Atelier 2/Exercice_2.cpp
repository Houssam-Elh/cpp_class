#include <iostream>
using namespace std;

int multipleDe2(int n){
    return n % 2 == 0;
}
int multipleDe3(int n){
    return n % 3 == 0;
}

int main() {
    int n;
    cout << "donnez un entier : ";
    cin >> n;

    bool pair = multipleDe2(n);
    bool mult3 = multipleDe3(n);
    bool mult6 = (multipleDe2(n) && multipleDe3(n));


    if (pair) cout << "il est pair" << endl;
    if (mult3) cout << "il est multiple de 3" << endl;
    if (mult6) cout << "il est divisible par 6" << endl;

    return 0;
}