#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Pelanggan {
private:
    string nama;
    string alamat;
    int umur;
    char kelamin;
    string noTelp;

public:
   
    void inputData() {
        cout << "Nama Pelanggan Toko         : ";
        cin.ignore();
        getline(cin, nama);

        cout << "Alamat Pelanggan Toko       : ";
        getline(cin, alamat);

        cout << "Umur Pelanggan Toko         : ";
        cin >> umur;

        cout << "Jenis Kelamin Pelanggan[L/P]: ";
        cin >> kelamin;

        cout << "No telp Pelanggan           : ";
        cin >> noTelp;
    }

   
    string getNama()   { return nama; }
    string getAlamat() { return alamat; }
    int    getUmur()   { return umur; }
    char   getKelamin(){ return kelamin; }
    string getNoTelp() { return noTelp; }
};

int main() {
    int jumlah;

    cout << "INPUT DATA PELANGGAN" << endl;
    cout << "Jumlah pelanggan : ";
    cin >> jumlah;
    cout << endl;

  
    Pelanggan* pelanggan = new Pelanggan[jumlah];

    
    for (int i = 0; i < jumlah; i++) {
        pelanggan[i].inputData();
        cout << endl;
    }

    
    string garis(54, '~');
    cout << garis << endl;
    cout << setw(30) << "Data Pelanggan Toko:" << endl;
    cout << garis << endl;

   
    cout << left
         << "! " << setw(10) << "Nama"
         << "! " << setw(10) << "Alamat"
         << "! " << setw(6)  << "Umur"
         << "! " << setw(8)  << "Kelamin"
         << "! " << setw(8)  << "No telp"
         << " !" << endl;
    cout << garis << endl;

    
    for (int i = 0; i < jumlah; i++) {
        cout << left
             << "  " << setw(12) << pelanggan[i].getNama()
             << setw(12) << pelanggan[i].getAlamat()
             << setw(6)  << pelanggan[i].getUmur()
             << setw(8)  << pelanggan[i].getKelamin()
             << setw(8)  << pelanggan[i].getNoTelp()
             << endl;
    }
    cout << garis << endl;

    delete[] pelanggan;
    return 0;
}