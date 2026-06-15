#include <iostream>
using namespace std;

void HEAP(int CanArray[], int n, int i) {
    int temp;
    int CanBesar = i;
    int kiri = 2*i+1;
    int kanan = 2*i+2;

    if (kiri < n && CanArray[kiri] < CanArray[CanBesar])
        CanBesar = kiri;
    if (kanan < n && CanArray[kanan] < CanArray[CanBesar])
        CanBesar = kanan;

    if (CanBesar != i) {
        temp = CanArray[i];
        CanArray[i] = CanArray[CanBesar];
        CanArray[CanBesar] = temp;
        HEAP(CanArray, n, CanBesar);
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
    int CanArray[] = { 22, 7, 66, 28, 11, 63, 24, 12, 77, 99 };
    int n = 10;
    int i;

    cout << "Menampilkan Data Sebelum Diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (i = 0; i < n; i++) {
        cout << CanArray[i] << " ";
        cout << endl;
    }
    SortHEAP(CanArray, n);
    cout << endl;
    cout << "Menampilkan Data Setelah Diurutkan - HEAP SORT DESCENDING" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (i = n - 1; i >= 0; i--)
        cout << CanArray[i] << " ";
    cin.get();
}