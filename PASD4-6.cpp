#include <iostream>
#include <string>
using namespace std;

string antrian[10];
int jumlah = 0;


void tampilkan() {
    cout << "Antrian: [ ";
    for (int i = 0; i < jumlah; i++) {
        cout << antrian[i];
        if (i < jumlah - 1) cout << " | ";
    }
    cout << " ]" << endl;
}


void tambahBelakang(string os) {
    antrian[jumlah] = os;
    jumlah++;
}


void tambahSetelah(string target, string os) {
    for (int i = 0; i < jumlah; i++) {
        if (antrian[i] == target) {
            for (int j = jumlah; j > i + 1; j--) {
                antrian[j] = antrian[j - 1];
            }
            antrian[i + 1] = os;
            jumlah++;
            return;
        }
    }
}


void hapus(string os) {
    for (int i = 0; i < jumlah; i++) {
        if (antrian[i] == os) {
            for (int j = i; j < jumlah - 1; j++) {
                antrian[j] = antrian[j + 1];
            }
            jumlah--;
            return;
        }
    }
}


void reset() {
    jumlah = 0;
    antrian[0] = "Maemo";
    antrian[1] = "Symbian";
    antrian[2] = "Mac";
    antrian[3] = "Windows";
    antrian[4] = "Iphone";
    jumlah = 5;
}

int main() {
    cout << "=============================================" << endl;
    cout << "   PROGRAM QUEUE BERBAGAI MACAM OS          " << endl;
    cout << "=============================================" << endl;

    reset();
    cout << "\nAntrian awal:" << endl;
    tampilkan();

    reset();
    cout << "\na. Tambah 'Maemo 4' di paling belakang & hapus 'Mac'" << endl;
    tambahBelakang("Maemo 4");
    hapus("Mac");
    tampilkan();

    reset();
    cout << "\nb. Tambah 'Windows Mobile' setelah 'Windows' & hapus 'Iphone'" << endl;
    tambahSetelah("Windows", "Windows Mobile");
    hapus("Iphone");
    tampilkan();

    reset();
    cout << "\nc. Tambah 'Java Midlet' setelah 'Symbian' & hapus 'Maemo'" << endl;
    tambahSetelah("Symbian", "Java Midlet");
    hapus("Maemo");
    tampilkan();

    reset();
    cout << "\nd. Tambah 'Lion OS X' setelah 'Mac' & hapus 'Maemo'" << endl;
    tambahSetelah("Mac", "Lion OS X");
    hapus("Maemo");
    tampilkan();

    reset();
    cout << "\ne. Tambah 'Android' setelah 'Iphone' & hapus 'Maemo'" << endl;
    tambahSetelah("Iphone", "Android");
    hapus("Maemo");
    tampilkan();

    cout << "\n=============================================" << endl;
    cout << "   PROGRAM SELESAI                          " << endl;
    cout << "=============================================" << endl;

    return 0;
}