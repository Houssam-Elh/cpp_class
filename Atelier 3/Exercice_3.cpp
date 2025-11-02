#include <iostream>
using namespace std;

struct Element {
    int valeur;
    Element *suivant;
};

class Liste {
    Element *premier;
public:
    Liste() : premier(nullptr) {}
    ~Liste() {
        while (premier != nullptr) {
            Element *tmp = premier;
            premier = premier->suivant;
            delete tmp;
        }
    }
    void ajouterDebut(int v) {
        Element *e = new Element{v, premier};
        premier = e;
    }
    void supprimerDebut() {
        if (premier) {
            Element *tmp = premier;
            premier = premier->suivant;
            delete tmp;
        }
    }
    void afficher() {
        Element *cur = premier;
        while (cur) {
            cout << cur->valeur << " ";
            cur = cur->suivant;
        }
        cout << endl;
    }
};

int main() {
    Liste l;
    l.ajouterDebut(1); l.ajouterDebut(2); l.ajouterDebut(3);
    l.afficher();
    l.supprimerDebut();
    l.afficher();
    return 0;
}