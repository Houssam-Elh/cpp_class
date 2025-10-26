#include <iostream>

using namespace std;
void remplir(int *arr, int n);  // Pour remplir le tableau
void afficher(const int *arr, int n);  // Pour afficher le tableau
int &trouverMax(int *arr, int n);  // Pour inverser le tableau
void inverser(int *arr, int n); // Pour inverser le tableau

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    remplir(arr, n);

    cout << "Here is the Original Arrey: \n";
    afficher(arr, n);

    cout << "Here is the maximum : " << trouverMax(arr, n) << '\n';
    
    inverser(arr, n);
    cout << "Here is the inversed array : ";
    afficher(arr, n);
    
    delete[] arr;
    return 0 ;
}

void remplir(int *arr, int n){
    for(int i=0 ; i<n ; i++){
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

void afficher(const int *arr, int n){
    cout << "arr[";
    for(int i=0; i<n ; i++){
        cout << arr[i];
        cout << (i!=n-1 ? ", " : "]\n");
    }
}

int &trouverMax(int *arr, int n){
    int *max = arr;
    for(int i=0 ; i<n ; i++){
        if(arr[i]>*max)
            max = &arr[i];
    }
    return *max;
}

void inverser(int *arr, int n){
    int aTemp[n];
    for(int i=0 ; i<n ; i++){
        aTemp[i]=arr[n-i-1];
    }
    for(int i=0 ; i<n ; i++){
        arr[i]=aTemp[i];
    }
    delete[] aTemp;
}
