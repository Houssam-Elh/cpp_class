#pragma once 

class vect {
protected: 
    int nelem; // nombre d'éléments
    int* adr;  // adresse zone dynamique
public:
    // Constructeur
    vect(int n) : nelem(n) {
        if (n > 0) {
            adr = new int[nelem];
        } else {
            adr = nullptr;
        }
    }

    // Destructeur
    virtual ~vect() {
        delete[] adr;
    }

    // Opérateur [] pour accéder aux éléments
    int& operator[](int index) {
        return adr[index];
    }
};