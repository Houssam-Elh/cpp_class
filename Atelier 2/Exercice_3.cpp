#include <iostream>
using namespace std;

int main() {
    cout << "--------------------------------\n";
    cout << "-- Formalisme Tableau ----------\n";
    int Tb[10];

    cout << "Entrez 10 entiers :" << endl; // Remplissage du tableau
    for (int i = 0; i < 10; i++) {
        cout << "Tb[" << i+1 <<"] = ";
        cin >> Tb[i];
    }

    int min = Tb[0], max = Tb[0];

    // Recherche min et max
    for (int i = 1; i < 10; i++) {
        if (Tb[i] < min) min = Tb[i];
        if (Tb[i] > max) max = Tb[i];
    }

    cout << "Min : " << min << endl;
    cout << "Max : " << max << endl << endl;

    cout << "--------------------------------\n";
    cout << "-- Formalisme Pointeur ---------\n";
    int tabP[10];

    cout << "Entrez 10 entiers :" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "tabP[" << i+1 <<"] = ";
        cin >> *(tabP + i); // Notation pointeur pour remplir le tableau
    }

    int minP = *tabP, maxP = *tabP;

    for (int i = 1; i < 10; i++) {
        if (*(tabP + i) < minP)
            minP = *(tabP + i);
        if (*(tabP + i) > maxP)
            maxP = *(tabP + i);
    }

    cout << "Min : " << minP << endl;
    cout << "Max : " << maxP << endl;

    return 0;
}