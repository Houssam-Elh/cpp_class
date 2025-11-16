#include <iostream>
template <typename T>

T carre(T valeur) {
    // Le résultat aura le même type que la valeur d'entrée
    return valeur * valeur;
}


int main() {
    std::cout << "--- Exercice 5 ---" << std::endl;

    // Test avec un 'int'
    int a = 3;
    std::cout << "Le carre de " << a << " (int) est: " << carre(a) << std::endl;

    // Test avec un 'double'
    double b = 2.5;
    std::cout << "Le carre de " << b << " (double) est: " << carre(b) << std::endl;

    // Test avec un 'float'
    float c = 3.3f;
    std::cout << "Le carre de " << c << " (float) est: " << carre(c) << std::endl;

    return 0;
}