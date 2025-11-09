#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Classe Telechargeable
class Telechargeable {
public:
    virtual void telecharger() const = 0; // Méthode pure virtuelle
    void afficherMessage() const {
        cout << "La ressource a ete telechargee." << endl;
    }
};

// Classe de base Ressource
class Ressource {
protected:
    int id;
    string titre;
    string auteur;
    int annee;

public:
    Ressource(int id, string titre, string auteur, int annee)
        : id(id), titre(titre), auteur(auteur), annee(annee) {}

    virtual ~Ressource() {} // Ajout du destructeur virtuel

    virtual void afficherInfos() const {
        cout << "ID: " << id << ", Titre: " << titre << ", Auteur: " << auteur << ", Annee: " << annee;
    }

    virtual void telecharger() const = 0;

    // Surcharge opérateur ==
    bool operator==(const Ressource& other) const {
        return id == other.id;
    }

    // Pour accès dans Mediatheque
    string getTitre() const { return titre; }
    int getAnnee() const { return annee; }
    string getAuteur() const { return auteur; }
};

// Classe Livre
class Livre : public Ressource, public Telechargeable {
    int nbPages;
public:
    Livre(int id, string titre, string auteur, int annee, int nbPages)
        : Ressource(id, titre, auteur, annee), nbPages(nbPages) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << ", Pages: " << nbPages << endl;
    }

    void telecharger() const override {
        cout << "Telechargement du livre \"" << titre << "\"" << endl;
        afficherMessage();
    }
};

// Classe Magazine
class Magazine : public Ressource, public Telechargeable {
    int numero;
public:
    Magazine(int id, string titre, string auteur, int annee, int numero)
        : Ressource(id, titre, auteur, annee), numero(numero) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << ", Numero: " << numero << endl;
    }

    void telecharger() const override {
        cout << "Telechargement du magazine \"" << titre << "\"" << endl;
        afficherMessage();
    }
};

// Classe Video
class Video : public Ressource, public Telechargeable {
    float duree;
public:
    Video(int id, string titre, string auteur, int annee, float duree)
        : Ressource(id, titre, auteur, annee), duree(duree) {}

    void afficherInfos() const override {
        Ressource::afficherInfos();
        cout << ", Duree: " << duree << " min" << endl;
    }

    void telecharger() const override {
        cout << "Telechargement de la video \"" << titre << "\"" << endl;
        afficherMessage();
    }
};

// Classe Mediatheque
class Mediatheque {
    vector<Ressource*> ressources;
public:
    ~Mediatheque() {
        // Nettoyage automatique
        for (auto r : ressources)
            delete r;
    }

    void ajouterRessource(Ressource* r) {
        ressources.push_back(r);
    }

    void afficherRessources() const {
        for (const auto& r : ressources) {
            r->afficherInfos();
        }
    }

    // Recherche par titre
    void rechercher(string titre) const {
        for (const auto& r : ressources) {
            if (r->getTitre() == titre) {
                r->afficherInfos();
            }
        }
    }

    // Recherche par année
    void rechercher(int annee) const {
        for (const auto& r : ressources) {
            if (r->getAnnee() == annee) {
                r->afficherInfos();
            }
        }
    }

    // Recherche par auteur + année
    void rechercher(string auteur, int annee) const {
        for (const auto& r : ressources) {
            if (r->getAuteur() == auteur && r->getAnnee() == annee) {
                r->afficherInfos();
            }
        }
    }
};

int main() {
    Mediatheque m;

    Livre* l1 = new Livre(1, "C++ pour debutants", "Ahmad", 2023, 250);
    Magazine* m1 = new Magazine(2, "Science Today", "Sara", 2025, 12);
    Video* v1 = new Video(3, "Lecon de POO", "Ikram", 2024, 60.5);

    m.ajouterRessource(l1);
    m.ajouterRessource(m1);
    m.ajouterRessource(v1);

    cout << "Toutes les ressources:" << endl;
    m.afficherRessources();

    cout << "\nRecherche par titre 'C++ pour debutants':" << endl;
    m.rechercher("C++ pour debutants");

    cout << "\nRecherche par annee 2025:" << endl;
    m.rechercher(2025);

    cout << "\nRecherche par auteur 'Ikram' et annee 2024:" << endl;
    m.rechercher("Ikram", 2024);

    cout << "\nTest du telechargement et operateur ==" << endl;
    l1->telecharger();
    cout << "Comparaison de l1 et m1 : " << ((*l1 == *m1) ? "egaux" : "differents") << endl;

    // Pas besoin de delete, le destructeur de Mediatheque s’en charge !
    return 0;
}