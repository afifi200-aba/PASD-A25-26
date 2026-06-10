#include<iostream>   
#include<cstdlib>    
#include<cstddef>    
using namespace std;

struct Node {
    struct Node *Left;
    char INFO;
    struct Node *Right;
};
typedef struct Node Simpul; 
Simpul *Root, *P, *Current;
Simpul *Q[129];

void Inisialisasi() {
    Root = NULL;
    P    = NULL;
}

void BuatSimpul(char X) {
    P = (Simpul*) malloc(sizeof(Simpul));
    if(P != NULL) {
        P -> INFO  = X;
        P -> Left  = NULL;
        P -> Right = NULL;
    } else {
        cout << "Memory Heap Full" << endl;
        exit(1);
    }
}

void BuatSimpulAkar() {
    if(Root == NULL) {
        if(P != NULL) {
            Root         = P;
            Root -> Left  = NULL;
            Root -> Right = NULL;
        } else
            cout << "Simpul Belum Dibuat" << endl;
    } else
        cout << "Pohon Sudah Ada!!!!!" << endl;
}

void InsertUrutNomor() {
    int i, j, Flag;
    char X;
    Flag = 0;
    i = 1; j = 1; 
    Q[i] = Root; 
    while(Flag == 0 && j < 127) {
        cin >> X;  
        if(X != '0') {
            BuatSimpul(X);
            Current = Q[i];
			Current -> Left = P;
            j++;  Q[j] = P;
        } else {
             Flag = 1;
            j++;  Q[j] = NULL;
        }
        if(Flag == 0) {
            if(X != '0') {
                cin >> X;  
                BuatSimpul(X);
                Current -> Right = P;
                j++;
                Q[j] = P;
            } else { 
                Flag = 1;
                j++;  Q[j] = NULL;
            }
        }
        i++;
    }
}

void BacaUrutNomor() {
    int i, j, n, Counter;
    i = 1; j = 1; n = 1; Counter = 0;
    cout << endl;
    while(Q[i] != NULL) {
        Current = Q[i];
        cout << Current -> INFO << endl;
        Counter++;
        if(Counter == n) {
            cout << endl;
            Counter = 0;
            n = n * 2;
        }
        if(Current -> Left != NULL) {
            j++;  Q[j] = Current -> Left;  
        }
        if(Current -> Right != NULL) {
            j++;  Q[j] = Current -> Right;  
        }
        i++;
    }
}

int main() {
    int i, j, Flag;
    char X;
    Inisialisasi();

    cout << "Masukkan karakter (akhiri dengan '0'):" << endl;
    cin >> X;            
    BuatSimpul(X);         
    BuatSimpulAkar();

    InsertUrutNomor();
    BacaUrutNomor();
       
    return 0;
}