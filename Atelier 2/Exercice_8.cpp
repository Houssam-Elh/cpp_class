#include <iostream>
using namespace std;

class Voiture {
private:
    string marque;
    string modele;
    int annee;
    float kilometrage;
    float vitesse;

public:
    // Constructeur par défaut
    Voiture() {
        marque = "";
        modele = "";
        annee = 0;
        kilometrage = 0;
        vitesse = 0;
    }

    // Constructeur paramétré
    Voiture(string m, string mo, int a, float km, float v) {
        marque = m;
        modele = mo;
        annee = a;
        kilometrage = km;
        vitesse = v;
    }

    // Méthode pour accélérer
    void accelerer(float val) {
        vitesse += val;
        cout << "La voiture accelere. Nouvelle vitesse : " << vitesse << " km/h" << endl;
    }

    // Méthode pour freiner
    void freiner(float val) {
        vitesse -= val;
        if (vitesse < 0) vitesse = 0;
        cout << "La voiture freine. Nouvelle vitesse : " << vitesse << " km/h" << endl;
    }

    // Méthode pour afficher les informations
    void afficherInfo() {
        cout << "------ Informations Voiture ------" << endl;
        cout << "Marque      : " << marque << endl;
        cout << "Modele      : " << modele << endl;
        cout << "Annee       : " << annee << endl;
        cout << "Kilometrage : " << kilometrage << " km" << endl;
        cout << "Vitesse     : " << vitesse << " km/h" << endl;
        cout << "----------------------------------" << endl;
    }

    // Méthode pour avancer d'une certaine distance
    void avancer(float distance) {
        kilometrage += distance;
        cout << "La voiture avance de " << distance << " km. Nouveau kilometrage : " << kilometrage << " km" << endl;
    }
    
    // Destructeur
    ~Voiture() {
        cout << "Votre voiture est detruite!!" << endl;
    }
};

// Programme test de la classe
int main() {
    Voiture v1("Porsche", "Panamera", 2023, 3000, 170); // Voiture paramétrée
    v1.afficherInfo();

    v1.accelerer(120);
    v1.freiner(50);
    v1.avancer(100);

    v1.afficherInfo();

    // v1 sera détruite automatiquement à la fin de main

    return 0;
}