#include <iostream>
#include <cstring>
using namespace std;

class Fichier {
    char *P;
    int longueur;
public:
    Fichier(int l = 0) : longueur(l) {
        P = new char[longueur];
    }
    void Remplit() {
        for (int i = 0; i < longueur; i++)
            P[i] = 'A' + i % 26; // rempli arbitrairement
    }
    void Affiche() {
        for (int i = 0; i < longueur; i++)
            cout << P[i];
        cout << endl;
    }
    ~Fichier() {
        delete[] P;
    }
};

int main() {
    Fichier *f = new Fichier(10);
    f->Remplit();
    f->Affiche();
    delete f;
    return 0;
}