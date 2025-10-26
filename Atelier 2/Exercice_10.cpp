#include <iostream>
#include <cmath>
using namespace std;

class Complexe {
private:
    float re;
    float im;

public:
    Complexe(float r = 0, float i = 0) : re(r), im(i) {}

    Complexe operator+ (const Complexe& c) const {
        return Complexe(re + c.re, im + c.im);
    }

    Complexe operator- (const Complexe& c) const {
        return Complexe(re - c.re, im - c.im);
    }

    Complexe operator* (const Complexe& c) const {
        return Complexe(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    Complexe operator/ (const Complexe& c) const {
        float denom = c.re * c.re + c.im * c.im;
        if (denom == 0) {
            cout << "Erreur : Division par zero !" << endl;
            return Complexe(); // Retourne 0 + 0i en cas d’erreur
        }
        float r = (re * c.re + im * c.im) / denom;
        float i = (im * c.re - re * c.im) / denom;
        return Complexe(r, i);
    }

    bool operator== (const Complexe& c) const {
        return (re == c.re && im == c.im);
    }

    void affiche() const {
        cout << "Complexe : " << re;
        if (im >= 0)
            cout << " + " << im << "i" << endl;
        else
            cout << " - " << -im << "i" << endl;
    }
};

int main() {
    float r1, i1, r2, i2;
    cout << "Entrez la partie reelle et imaginaire du premier nombre : ";
    cin >> r1 >> i1;
    Complexe c1(r1, i1);

    cout << "Entrez la partie reelle et imaginaire du second nombre : ";
    cin >> r2 >> i2;
    Complexe c2(r2, i2);

    cout << "Choisissez l'operation :\n"
         << "1 - Egalite\n"
         << "2 - Addition\n"
         << "3 - Soustraction\n"
         << "4 - Multiplication\n"
         << "5 - Division\n"
         << "Votre choix : ";
    int choix;
    cin >> choix;

    switch (choix) {
        case 1:
            if (c1 == c2)
                cout << "Les deux nombres complexes sont egaux." << endl;
            else
                cout << "Les deux nombres complexes ne sont pas egaux." << endl;
            break;
        case 2:
            cout << "Addition : ";
            (c1 + c2).affiche();
            break;
        case 3:
            cout << "Soustraction : ";
            (c1 - c2).affiche();
            break;
        case 4:
            cout << "Multiplication : ";
            (c1 * c2).affiche();
            break;
        case 5:
            cout << "Division : ";
            (c1 / c2).affiche();
            break;
        default:
            cout << "Choix invalide !" << endl;
    }

    return 0;
}