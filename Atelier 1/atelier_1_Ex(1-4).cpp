#include <iostream>

using namespace std;

void Exercice_1(){
    cout << '\n';
    cout << "-----------------------------------------------\n";
    cout << "--- Exercice 1: -------------------------------\n";
    cout << "-----------------------------------------------\n";
    
    char c = '\x01';
    short int p = 10;

    cout << p + 3  << " - type (int)" << '\n' ;        // = 13  type (int) 
    cout << c + 1 << "  - type (int)" << '\n' ;        // = 2   type (int) 
    cout << p + c << " - type (int)" << '\n' ;         // = 11  type (int)
    cout << 3 * p + 5 * c << " - type (int)" << '\n' ; // = 35  type (int)
}
void Exercice_2(){
    cout << '\n';
    cout << "-----------------------------------------------\n";
    cout << "--- Exercice 2: -------------------------------\n";
    cout << "-----------------------------------------------\n";
    
    char c = '\x05' ;
    int n = 5 ;
    long p = 1000 ;
    float x = 1.25 ;
    double z = 5.5 ;

    cout << n + c + p << " - type (long)" << '\n' ;          // = 1010 type (long)
    cout << 2*x + c << "  - type (float)" << '\n' ;          // = 7.5 type (float) 
    cout <<  (char)n + c << "   - type (int)" << '\n' ;      // = 10 type (int) 
    cout << (float)z + n / 2 << "  - type (float)" << '\n' ; // = 7.5 type (float)  
}
void Exercice_3(){
    cout << '\n';
    cout << "-----------------------------------------------\n";
    cout << "--- Exercice 3: -------------------------------\n";
    cout << "-----------------------------------------------\n";
    
    int n = 5 , p = 9 ;
    float x ;
    int q ;
    q = n < p ; cout << q << " Vrai" <<'\n';         // q = (5 < 9)  = vrai = 1
    q = n == p ; cout << q << " Faux" <<'\n';        // q = (5 == 9) = faux = 0 
    q = p % n + p > n ; cout << q << " Vrai" <<'\n'; // q = ("9 % 5" + 9 > 5) = 13 > 5 = vrai = 1
    x = p / n ; cout << x << '\n';                   // x = 9 / 5 = 1 ?? car p et n sont de type (int)
    x = (float) p / n ; cout << x << '\n';           // x = 9 / 5  = 1.8 ?? p devient (float) donc n devient automatiquement (float)
    x = (p + 0.5) / n ; cout << x << '\n';           // x = (9+0.5) / 5 = 1.9 ?? (p+0.5) est (float) donc n devient automatiquement (float)
    x = (int) (p + 0.5) / n ;                        // x = (int)(9+0.5) / 5 = (int)9.5 / 5 = 9 / 5 = 1 ?? (9.5) devient (int)=9 
    q = n * (p > n ? n : p) ; cout << q << '\n';     // q = 5 * (9 > 5 ? 5 : 9) = 5 * 5 = 25
    q = n * (p < n ? n : p) ; cout << q << '\n';     // q = 5 * (9 < 5 ? 5 : 9) = 5 * 9 = 45
}
void Exercice_4(){
    cout << '\n';
    cout << "-----------------------------------------------\n";
    cout << "--- Exercice 4: -------------------------------\n";
    cout << "-----------------------------------------------\n";

    int i , j , n ;
    i = 0 ;
    n = i++ ;
    cout << "A: i = " << i << "   n = " << n << '\n' ; // i = 1   ||   n = 0
    i = 10 ;
    n = ++i ;
    cout << "B: i = " << i << "  n = " << n << '\n' ; // i = 11   ||   n = 11
    i = 20 ;
    j = 5 ; 
    n = i++ * ++j ;
    cout << "C: i = " << i << "  j = " << j << "   n =  " << n << '\n' ; // i = 21   ||   j = 6   ||   n = 20 * 6 = 120
    i = 15 ;
    n = i+= 3 ;
    cout << "D: i = " << i << "  n = " << n << '\n' ; // n = 18   ||   i = 18 
    i = 3 ;
    j = 5 ;
    n = i *= --j ;
    cout << "E: i = " << i << "  j = " << j << "   n =  " << n << '\n' ; // i = 3 * 4 = 12   ||   j = 4   ||   n = 12 
}

int main(){
    Exercice_1();
    Exercice_2();
    Exercice_3();
    Exercice_4();
    return 0 ;
}