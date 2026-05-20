#include<iostream>
using namespace std;

int A[] = {64, 25, 12, 22, 11, 90, 47, 33};
int n = 8;

void Tampil() {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void bubble_sort_desc() {
    int k = 0;
    int flag = 1;
    while (k <= n - 2 && flag == 1) {
        int i = 0;
        flag = 0;
        while (i <= n - 2 - k) {
            if (A[i] < A[i+1]) {  
                flag = 1;
                int X = A[i];
                A[i]   = A[i+1];
                A[i+1] = X;
            }
            i++;
        }
        cout << "Pass " << k+1 << ": ";
        Tampil();
        k++;
    }
}

int main() {
    cout << "*--------------------------------------*" << endl;
    cout << "* Selamat datang di aplikasi          *" << endl;
    cout << "* Bubble Sort - Descending (Flag)     *" << endl;
    cout << "*--------------------------------------*" << endl;

    cout << "Data awal   : ";
    Tampil();
    cout << "--------------------------------------" << endl;
    cout << "Proses Bubble Sort (Descending)......" << endl;
    cout << "--------------------------------------" << endl;

    bubble_sort_desc();

    cout << "--------------------------------------" << endl;
    cout << "Hasil akhir : ";
    Tampil();
    cout << "--------------------------------------" << endl;
    cout << " TERIMA KASIH " << endl;
    cout << "--------------------------------------" << endl;
    return 0;
}