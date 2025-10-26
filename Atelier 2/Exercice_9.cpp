#include <iostream>
#include <cmath>
using namespace std;

class vecteur3d {
private:
    float x, y, z;
public:
    // Constructeur
    vecteur3d(float a = 0, float b = 0, float c = 0) {
        x = a; y = b; z = c;
    }

    // Afficher les composantes du vecteur
    void affiche() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    // Somme de deux vecteurs (nouveau vecteur)
    vecteur3d somme(const vecteur3d& v) const {
        return vecteur3d(x + v.x, y + v.y, z + v.z);
    }

    // Produit scalaire
    float prodscalaire(const vecteur3d& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // Vérifie si deux vecteurs coïncident
    bool coincide(const vecteur3d& v) const {
        return (x == v.x && y == v.y && z == v.z);
    }

    // Norme du vecteur
    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Renvoie le vecteur de plus grande norme (par valeur)
    vecteur3d normaxVal(const vecteur3d& v) const {
        return (this->norme() > v.norme()) ? *this : v;
    }

    // Renvoie le vecteur de plus grande norme (par référence)
    const vecteur3d& normaxRef(const vecteur3d& v) const {
        return (this->norme() > v.norme()) ? *this : v;
    }

    // Renvoie un pointeur sur le vecteur de plus grande norme
    const vecteur3d* normaxPtr(const vecteur3d& v) const {
        return (this->norme() > v.norme()) ? this : &v;
    }
};

// Programme de test
int main() {
    vecteur3d v1(1, 2, 3);
    vecteur3d v2(4, 5, 6);

    cout << "Vecteur v1 : "; v1.affiche();
    cout << "Vecteur v2 : "; v2.affiche();

    // Somme
    vecteur3d v3 = v1.somme(v2);
    cout << "Somme v1+v2 : "; v3.affiche();

    // Produit scalaire
    cout << "Produit scalaire v1.v2 : " << v1.prodscalaire(v2) << endl;

    // Coincidence
    cout << "v1 et v2 coincident ? " << (v1.coincide(v2) ? "Oui" : "Non") << endl;
    vecteur3d v4(1, 2, 3);
    cout << "v1 et v4 coincident ? " << (v1.coincide(v4) ? "Oui" : "Non") << endl;

    // Normes
    cout << "Norme de v1 : " << v1.norme() << endl;
    cout << "Norme de v2 : " << v2.norme() << endl;

    // Normax
    vecteur3d vmax = v1.normaxVal(v2);
    cout << "Vecteur de plus grande norme (valeur) : "; vmax.affiche();

    const vecteur3d& vmaxr = v1.normaxRef(v2);
    cout << "Vecteur de plus grande norme (reference) : "; vmaxr.affiche();

    const vecteur3d* vmaxp = v1.normaxPtr(v2);
    cout << "Vecteur de plus grande norme (pointeur) : "; vmaxp->affiche();

    return 0;
}
