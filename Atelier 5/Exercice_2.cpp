#include <iostream>
#include <stdexcept> // On a besoin de cet outil pour les "alertes" standard

using namespace std;

class Test{
public:
    static int tableau[] ;
public :
    static int division(int indice, int diviseur) {
        
        // VÉRIFICATION 1 : Danger de la division par zéro
        if (diviseur == 0) {
            // Au lieu de planter, on lance une alerte !
            throw std::runtime_error("Erreur: Division par zero !");
        }

        // VÉRIFICATION 2 : Danger de l'indice invalide
        // (Le tableau a 10 éléments, donc les indices valides vont de 0 à 9)
        if (indice < 0 || indice >= 10) {
            // On lance une autre alerte !
            throw std::out_of_range("Erreur: Indice hors limites du tableau !");
        }
        // --- Zone sécurisée ---
        // Si on arrive ici, c'est que les deux vérifications ont réussi.
        // Le code est maintenant sûr.
        return tableau[indice] / diviseur;
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5} ;

int main() {
    int x, y;
    cout << "Entrez l'indice de l'entier a diviser: " << endl;
    cin >> x ;
    cout << "Entrez le diviseur: " << endl;
    cin >> y ;
    // On place le filet de sécurité
    try {
        // 1. On "essaie" le code dangereux
        int resultat = Test::division(x, y);

        // Si on arrive ici, c'est que tout s'est bien passé
        cout << "Le resultat de la division est: " << endl;
        cout << resultat << endl;
    } 
    catch (const std::exception& e) {
        // 2. On "attrape" l'alerte
        // 'e' est notre "alerte" (l'objet lancé par throw)
        // e.what() est le message d'erreur qu'on a écrit ("Erreur: Division par zero !")
        
        cerr << e.what() << endl; // On affiche l'erreur
        // 'cerr' est comme 'cout', mais pour les erreurs
    }

    return 0;
}