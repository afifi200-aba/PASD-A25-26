#include<iostream>
#include<string.h>
using namespace std;

struct DataArray {
    int data[10];
    int data2[10];
    int n;
};

DataArray db;

void tukar(int a, int b) {
    int t;
    t = db.data[b];
    db.data[b] = db.data[a];
    db.data[a] = t;
}

void Input() {
    cout << "Masukkan jumlah data = "; cin >> db.n;
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < db.n; i++) {
        cout << "Masukkan data ke-" << (i+1) << " = "; cin >> db.data[i];
        db.data2[i] = db.data[i];
    }
    cout << endl;
}

void Tampil() {
    for (int i = 0; i < db.n; i++) {
        cout << db.data[i] << " ";
    }
    cout << endl;
}

void bubble_sort_desc() {
    for (int i = 1; i < db.n; i++) {
        for (int j = db.n - 1; j >= i; j--) {
            if (db.data[j] > db.data[j-1]) tukar(j, j-1);
        }
        Tampil();
    }
    cout << endl;
}

int main() {
    cout << "*--------------------------------------*" << endl;
    cout << "* Selamat datang di aplikasi          *" << endl;
    cout << "* Bubble Sort - Descending (Struct)   *" << endl;
    cout << "*--------------------------------------*" << endl;
    Input();
    cout << "Proses Bubble Sort (Descending)......" << endl;
    cout << "--------------------------------------" << endl;
    Tampil();
    bubble_sort_desc();
    cout << "--------------------------------------" << endl;
    cout << " TERIMA KASIH " << endl;
    cout << "--------------------------------------" << endl;
    return 0;
}