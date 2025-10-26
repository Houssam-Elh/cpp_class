#include <iostream>
using namespace std;

// On évite <string>, donc on utilise tableau de char
void permute(string& s, int l, int r) {
    if (l == r) {
        cout << s << endl;
    } else {
        for (int i = l; i <= r; i++) {
            // Swap manuel sans bibliothèque
            char temp = s[l];
            s[l] = s[i];
            s[i] = temp;

            permute(s, l + 1, r);

            // Retour arrière
            temp = s[l];
            s[l] = s[i];
            s[i] = temp;
        }
    }
}

int main() {
    string s;
    cout << "Entrez une chaine : ";
    cin >> s;
    int n = 0;
    while (s[n] != '\0') n++;

    permute(s, 0, n - 1);
    return 0;
}