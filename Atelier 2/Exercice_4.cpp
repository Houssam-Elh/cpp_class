#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Entrez la taille du tableau : ";
    cin >> n;

    // Allocation dynamique du tableau principal
    int* tab = new int[n];

    // Remplissage du tableau
    for (int i = 0; i < n; i++) {
        cout << "Entrez l'element " << i+1 << " : ";
        cin >> tab[i];
    }

    // Allocation dynamique du tableau des carrés
    int* tabCarre = new int[n];

    // Remplissage du tableau des carrés
    for (int i = 0; i < n; i++) {
        tabCarre[i] = tab[i] * tab[i];
    }

    // Affichage du tableau des carrés
    cout << "Tableau des carres : " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Le carre d'element " << i+1 << " : " << tabCarre[i] << endl;
    }
    cout << endl;

    // Libération de la mémoire
    delete[] tab;
    delete[] tabCarre;

    return 0;
}