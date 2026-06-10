//Heap Tree Sort - Descending menggunakan Min-Heap
#include <iostream>
using namespace std;

void HEAP(int CanArray[], int n, int i) {
    int temp;
    int CanKecil = i;
    int kiri  = 2 * i + 1;
    int kanan = 2 * i + 2;

    if (kiri  < n && CanArray[kiri]  < CanArray[CanKecil])
        CanKecil = kiri;
    if (kanan < n && CanArray[kanan] < CanArray[CanKecil])
        CanKecil = kanan;

    if (CanKecil != i) {
        temp = CanArray[i];
        CanArray[i] = CanArray[CanKecil];
        CanArray[CanKecil] = temp;
        HEAP(CanArray, n, CanKecil);
    }
}

void SortHEAP(int CanArray[], int n) {
    int temp;

    for (int i = n / 2 - 1; i >= 0; i--)
        HEAP(CanArray, n, i);
    for (int i = n - 1; i >= 0; i--) {
        temp = CanArray[0];
        CanArray[0] = CanArray[i];
        CanArray[i] = temp;
        HEAP(CanArray, i, 0);
    }
}

int main() {
    int CanArray[8];
    int n = 8;
    int i;

    cout << "Masukkan 8 data: ";
    for (i = 0; i < n; i++)
        cin >> CanArray[i];

    cout << endl;
    cout << "Menampilkan Data Sebelum Diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (i = 0; i < n; i++)
        cout << CanArray[i] << " ";
    cout << endl;

    SortHEAP(CanArray, n);

    cout << endl;
    cout << "Menampilkan Data Setelah Diurutkan - HEAP SORT" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (i = 0; i < n; i++)
        cout << CanArray[i] << " ";
    cout << endl;

    cin.get();
}