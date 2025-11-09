#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ----------- Classe Client -----------
class Client {
    string nom, CIN;
    int id;
public:
    Client(int id, string nom, string CIN)
        : id(id), nom(nom), CIN(CIN) {}
    int getId() const { return id; }
    string getNom() const { return nom; }
    string getCIN() const { return CIN; }
};

// ----------- Classe CompteBancaire -----------
class CompteBancaire {
    int numero;
    double solde;
    string codeSecret; // private/confidential
    const Client& proprietaire; // reference
    // AgentBancaire and Banque are friends for access
    friend class AgentBancaire;
    friend class Banque;
public:
    CompteBancaire(int numero, double solde, string codeSecret, const Client& proprietaire)
        : numero(numero), solde(solde), codeSecret(codeSecret), proprietaire(proprietaire) {}

    int getNumero() const { return numero; }
    double getSolde() const { return solde; }
    const Client& getClient() const { return proprietaire; }

    // Dépôt and retrait secure, no public access to codeSecret
    void deposer(double montant) { solde += montant; }
    void retirer(double montant) { if (solde >= montant) solde -= montant; }
};

// ----------- Classe AgentBancaire -----------
class AgentBancaire {
    string nomAgent;
public:
    AgentBancaire(string nomAgent) : nomAgent(nomAgent) {}

    // Opérations confidentielles:
    void consulterCodeSecret(const CompteBancaire& c) const {
        cout << "Le code secret du compte #" << c.numero << " est: " << c.codeSecret << endl;
    }
    void transferer(CompteBancaire& src, CompteBancaire& dest, double montant) {
        if(src.solde >= montant) {
            src.solde -= montant;
            dest.solde += montant;
            cout << "Transfert de " << montant << " de #" << src.numero << " vers #" << dest.numero << " effectue." << endl;
        } else
            cout << "Solde insuffisant pour transfert." << endl;
    }
    string getNom() const { return nomAgent; }
};

// ----------- Classe Banque -----------
class Banque {
    vector<Client> clients;
    vector<CompteBancaire*> comptes; // comptes sont "possédés" et seront supprimés par la banque
public:
    ~Banque() {
        for (auto c : comptes) delete c;
    }
    Client& ajouterClient(int id, string nom, string CIN) {
        clients.emplace_back(id, nom, CIN);
        return clients.back();
    }
    CompteBancaire* ouvrirCompte(int numero, double solde, string code, Client& c) {
        CompteBancaire* cb = new CompteBancaire(numero, solde, code, c);
        comptes.push_back(cb);
        return cb;
    }

    void afficherTousClients() const {
        for(const auto& c : clients)
            cout << "Client #" << c.getId() << " | Nom: " << c.getNom() << " | CIN: " << c.getCIN() << endl;
    }

    void afficherTousComptes() const {
        for (const auto& c : comptes)
            cout << "Compte #" << c->getNumero() << " | Solde: " << c->getSolde()
                 << " | Proprietaire: " << c->proprietaire.getNom() << endl;
    }

    // Audit interne: afficher infos confidentielles
    void rapportComplet() const {
        cout << "=== Rapport Complet ===" << endl;
        for (const auto& c : comptes) {
            cout << "Compte #" << c->numero << ", Code secret: " << c->codeSecret
                 << ", Solde: " << c->solde << ", Client: " << c->proprietaire.getNom() << endl;
        }
    }
};

// ----------- MAIN pour test -----------
int main() {
    Banque b;
    // Création des clients
    Client& cl1 = b.ajouterClient(1, "Ali", "X123");
    Client& cl2 = b.ajouterClient(2, "Nada", "Y456");

    // Ouverture des comptes
    CompteBancaire* comp1 = b.ouvrirCompte(101, 1000, "abc123", cl1);
    CompteBancaire* comp2 = b.ouvrirCompte(202, 500, "xyz789", cl2);

    // Dépôts & retraits
    comp1->deposer(200);
    comp2->retirer(100);

    // Agent bancaire effectue des opérations confidentielles
    AgentBancaire agent("Mme Karim");
    agent.consulterCodeSecret(*comp1);
    agent.transferer(*comp1, *comp2, 300);

    // Affichage des données (public/privé)
    cout << "\n--- Clients enregistres:" << endl;
    b.afficherTousClients();

    cout << "\n--- Comptes clients:" << endl;
    b.afficherTousComptes();

    // Audit interne complet (accès aux codes secrets etc.)
    cout << "\nRapport d'audit interne:" << endl;
    b.rapportComplet();

    return 0;
}