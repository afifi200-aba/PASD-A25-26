#include <iostream>
using namespace std;

int main() {

    int pilihan = 0;
    int jumlah;
    int i;
    int ketemu;

    string kendaraan[100];
    string cari;

    while(pilihan != 3) {

        cout << "======================================" << endl;
        cout << "      PROGRAM SEQUENTIAL SEARCH      " << endl;
        cout << "======================================" << endl;
        cout << "1. Input Data Kendaraan" << endl;
        cout << "2. Cari Kendaraan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        if(pilihan == 1) {

            cout << "Input jumlah kendaraan : ";
            cin >> jumlah;

            for(i = 0; i < jumlah; i++) {
                cout << "Input nomor kendaraan ke-" << i + 1 << " : ";
                cin >> kendaraan[i];
            }

            cout << "Data berhasil disimpan!" << endl;
        }

       
        if(pilihan == 2) {

            cout << "Input nomor kendaraan yang dicari : ";
            cin >> cari;

            ketemu = 0;

            for(i = 0; i < jumlah; i++) {

                if(kendaraan[i] == cari) {

                    cout << "Kendaraan ditemukan pada index ke-" << i << endl;
                    ketemu = 1;
                }

            }

            if(ketemu == 0) {
                cout << "Data kendaraan tidak ditemukan!" << endl;
            }
        }

       
        if(pilihan == 3) {

            cout << "Program selesai..." << endl;

        }

    }

    return 0;
}