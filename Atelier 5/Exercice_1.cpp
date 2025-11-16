#include <iostream>  // Pour afficher des choses à l'écran (avec std::cout)
#include <set>       // Pour utiliser le conteneur 'std::set' 
#include <vector>    // Pour l'exemple de l'étape 4 [cite: 8]
#include <list>      // Pour l'exemple de l'étape 4 [cite: 8]
#include <string>    // Pour l'exemple de l'étape 4 [cite: 8]
#include <iterator>  // Pour std::begin et std::end (étape 4)

bool findInSet(const std::set<int>& s, int value) {
    return s.find(value) != s.end();
}

bool findWithIterators(std::set<int>::iterator begin, std::set<int>::iterator end, int value) {
    // Crée un nouveau marque-page 'it' et place-le au début
    for (auto it = begin; it != end; ++it) {
        // Regarde la valeur sur la "page" actuelle
        if (*it == value) {
            return true; // On l'a trouvé ! Arrête tout et renvoie "vrai".
        }
    }
    // Si la boucle est terminée, c'est qu'on a tout vérifié
    // sans rien trouver.
    return false; // Non trouvé
}

// "template <...>" : Ceci est un plan, pas une fonction normale.
// "typename IteratorType" : On invente un nom de type pour le marque-page.
// "typename ValueType" : On invente un nom de type pour la valeur.
template <typename IteratorType, typename ValueType>
bool genericFind(IteratorType begin, IteratorType end, const ValueType& value) {
    
    // Le corps est EXACTEMENT LE MÊME que l'étape 3 !
    for (auto it = begin; it != end; ++it) {
        if (*it == value) {
            return true;
        }
    }
    return false;
}



int main(){
    // ---------------------------------------------------------
    // 1. Créer et remplir le set de 1 à 100 [cite: 5]
    // ---------------------------------------------------------
    std::set<int> mySet;
    // 1. remplir le set avec tous les entiers de 1 à 100
    for (int i = 1; i <= 100; ++i) {
        mySet.insert(i);
    }
    std::cout << "--- Exercice 1 ---" << std::endl;
    std::cout << "1. Set cree avec " << mySet.size() << " elements." << std::endl;
    // ---------------------------------------------------------
    // 2. Test de la fonction findInSet [cite: 5]
    // ---------------------------------------------------------
    std::cout << "\n2. Test de findInSet():" << std::endl;
    std::cout << "   Recherche de 42 : "
              << (findInSet(mySet, 42) ? "Trouve" : "Non trouve") << std::endl;
    std::cout << "   Recherche de 101: "
              << (findInSet(mySet, 101) ? "Trouve" : "Non trouve") << std::endl;


    // ---------------------------------------------------------
    // 3. Test de la fonction findWithIterators [cite: 6]
    // ---------------------------------------------------------
    std::cout << "\n3. Test de findWithIterators():" << std::endl;
    std::cout << "   Recherche de 77 : "
              << (findWithIterators(mySet.begin(), mySet.end(), 77) ? "Trouve" : "Non trouve") << std::endl;


    // ---------------------------------------------------------
    // 4. Exemples d'appels de genericFind() [cite: 8]
    // ---------------------------------------------------------
    std::cout << "\n4. Test de genericFind():" << std::endl;

    // a) Exemple avec un vecteur de string
    std::vector<std::string> vecStrings = {"un", "vecteur", "de", "mots"};
    bool found_mots = genericFind(vecStrings.begin(), vecStrings.end(), std::string("mots"));
    std::cout << "   - sur std::vector<std::string>:" << std::endl;
    std::cout << "     Recherche de 'mots': "
              << (found_mots ? "Trouve" : "Non trouve") << std::endl;

    // b) Exemple avec une liste d'entiers
    std::list<int> listInts = {10, 20, 30, 40};
    bool found_30 = genericFind(listInts.begin(), listInts.end(), 30);
    std::cout << "   - sur std::list<int>:" << std::endl;
    std::cout << "     Recherche de 30: "
              << (found_30 ? "Trouve" : "Non trouve") << std::endl;


    // c) Exemple avec un tableau 'classique' de float
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    bool found_3_3 = genericFind(std::begin(floatArray), std::end(floatArray), 3.3f);
    std::cout << "   - sur tableau C de float[]:" << std::endl;
    std::cout << "     Recherche de 3.3: "
              << (found_3_3 ? "Trouve" : "Non trouve") << std::endl;

    return 0;
}