#include <iostream>
#include "vect.h" // On inclut le fichier .h fourni dans l'exercice

/**
 * Classe vectok, dérivée de vect
 * qui gère correctement l'affectation et la transmission par valeur
 */
class vectok : public vect {
public:
    vectok(int n) : vect(n) {}

    /**
     * Constructeur par recopie (Deep Copy)
     * Gère la transmission par valeur (ex: quand on passe à une fonction)
     */
    vectok(const vectok& other) : vect(other.nelem) {
        // 'vect(other.nelem)' alloue la nouvelle zone mémoire
        // 'adr' et 'nelem' sont accessibles car 'protected'
        for (int i = 0; i < nelem; ++i) {
            adr[i] = other.adr[i];
        }
    }

    /**
     * Opérateur d'affectation (Deep Copy)
     * Gère l'affectation (ex: v2 = v1;)
     */
    vectok& operator=(const vectok& other) {
        // Éviter l'auto-affectation (ex: v1 = v1)
        if (this == &other) {
            return *this;
        }

        // Libérer l'ancienne mémoire de cet objet
        delete[] adr;

        // Allouer de la nouvelle mémoire et copier les attributs
        nelem = other.nelem;
        adr = new int[nelem];

        // Copier les données
        for (int i = 0; i < nelem; ++i) {
            adr[i] = other.adr[i];
        }

        // Renvoyer une référence à cet objet pour le chaînage
        return *this;
    }

    /**
     * Fonction membre 'taille'
     */
    int taille() const {
        return nelem; // 'nelem' est hérité de 'vect'
    }
};


/**
 * Petit programme d'essai
 */

// Fonction d'aide pour afficher (teste le constructeur de copie)
void Afficher(vectok v, const char* nom) {
    std::cout << "Affichage de " << nom << " (taille " << v.taille() << "): ";
    for (int i = 0; i < v.taille(); ++i) {
        std::cout << v[i] << " "; 
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "--- Exercice 3 ---" << std::endl;

    // Crée v1 et le remplit
    vectok v1(5);
    for (int i = 0; i < v1.taille(); ++i) {
        v1[i] = (i + 1) * 10; // v1 = {10, 20, 30, 40, 50}
    }

    // Test 1: Transmission par valeur (Constructeur de copie)
    std::cout << "Test de la transmission par valeur (constructeur de copie):" << std::endl;
    Afficher(v1, "v1"); 

    // Test 2: Opérateur d'affectation
    std::cout << "\nTest de l'operateur d'affectation:" << std::endl;
    vectok v2(2); // Crée v2 avec une taille différente
    v2[0] = 99;
    v2[1] = 99;
    Afficher(v2, "v2 avant (v2=v1)");
    
    v2 = v1; // Appel à l'opérateur d'affectation
    Afficher(v2, "v2 apres (v2=v1)");
    
    // Test 3: Preuve de la "Deep Copy"
    std::cout << "\nTest de la 'deep copy' (preuve):" << std::endl;
    v1[0] = 1234; // On modifie v1
    
    Afficher(v1, "v1 modifie");
    Afficher(v2, "v2 (non modifie)"); // v2 ne doit pas changer

    return 0;
}