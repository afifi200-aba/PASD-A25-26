#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

void Q_Sort(int[], int, int);

int main() {
    int NumList[7] = {85, 92, 78, 90, 88, 75, 95};
    cout << "Data SEBELUM diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int d=0; d<7; d++) {
        cout << setw(3) << NumList[d];
    }
    cout << endl << endl;
    Q_Sort(NumList, 0, 6);
    cout << "Data SETELAH diurutkan" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int iii=0; iii<7; iii++) {
        cout << setw(3) << NumList[iii];
    }
    cin.get();
}

void Q_Sort(int Angka[], int Kiri, int Kanan) {
    int pivot, Kiri_Hold, Kanan_Hold;
    Kiri_Hold = Kiri;
    Kanan_Hold = Kanan;
    pivot = Angka[Kiri];
    while (Kiri < Kanan) {
        while ((Angka[Kanan] <= pivot) && (Kiri < Kanan))
            Kanan--;
        if (Kiri != Kanan) {
            Angka[Kiri] = Angka[Kanan];
            Kiri++;
        }
        while ((Angka[Kiri] >= pivot) && (Kiri < Kanan)) {
            Kiri++;
        }
        if (Kiri != Kanan) {
            Angka[Kanan] = Angka[Kiri];
            Kanan--;
        }
    }
    Angka[Kiri] = pivot;
    pivot = Kiri;
    Kiri = Kiri_Hold;
    Kanan = Kanan_Hold;
    if (Kiri < pivot)
        Q_Sort(Angka, Kiri, pivot-1);
    if (Kanan > pivot)
        Q_Sort(Angka, pivot+1, Kanan);
}