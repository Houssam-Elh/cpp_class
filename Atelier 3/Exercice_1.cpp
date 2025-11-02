#include <iostream>
using namespace std;

class Pile {
    int *tab;
    int taille;
    int sommet;
public:
    Pile(int t = 0) {
        taille = t;
        tab = new int[taille];
        sommet = -1;
    }
    void empiler(int x) {
        if (sommet < taille - 1)
            tab[++sommet] = x;
        else
            cout << "Pile pleine\n";
    }
    int depiler() {
        if (sommet >= 0)
            return tab[sommet--];
        else {
            cout << "Pile vide\n";
            return -1;
        }
    }
    ~Pile() {
        delete[] tab;
    }
};

int main() {
    Pile p1(5), p2(3);
    p1.empiler(1); p1.empiler(2); p1.empiler(3);
    cout << p1.depiler() << endl;
    cout << p1.depiler() << endl;
    p2.empiler(11); p2.empiler(22);
    cout << p2.depiler() << endl;
    cout << p2.depiler() << endl;
    return 0;
}