#include<iostream>
using namespace std;

struct DataKarakter {
    char karakter;
    int indeks;
};

struct HasilCari {
    int posisi[50];  
    int jumlah;    
};

HasilCari SearchSemuaKarakter(DataKarakter data[], int jumlahElemen, char cari) {
    HasilCari hasil;
    hasil.jumlah = 0;

    for (int count = 0; count < jumlahElemen; count++) {
        if (data[count].karakter == cari) {
            hasil.posisi[hasil.jumlah] = count;
            hasil.jumlah++;
        }
    }
    return hasil;
}

int main() {
    const int JmlElemenArray = 12;

    DataKarakter huruf[JmlElemenArray];
    char isiData[JmlElemenArray] = {'M','A','N','A','J','E','M','E','N','I','N','F'};

    for (int i = 0; i < JmlElemenArray; i++) {
        huruf[i].karakter = isiData[i];
        huruf[i].indeks   = i;
    }

    char karCari = 'N';

    cout << "******************************************" << endl;
    cout << "**   S E Q U E N T I A L   S E A R C H **" << endl;
    cout << "**  Cari Semua Kemunculan - Struct/Char  **" << endl;
    cout << "******************************************" << endl;

    cout << "Isi data nya adalah" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int count = 0; count < JmlElemenArray; count++) {
        cout << "\t" << "Data [" << huruf[count].indeks << "]" << " --> " << huruf[count].karakter << endl;
    }
    cout << "******************************************" << endl;
    cout << endl;

    cout << "Karakter yang akan dicari : " << karCari << endl;
    cout << endl;

    HasilCari hasil = SearchSemuaKarakter(huruf, JmlElemenArray, karCari);

    if (hasil.jumlah > 0) {
        cout << "Data '" << karCari << "' ditemukan sebanyak "
             << hasil.jumlah << " kali, pada posisi :" << endl;
        for (int i = 0; i < hasil.jumlah; i++) {
            cout << "\t --> Data[" << hasil.posisi[i] << "]" << endl;
        }
    } else {
        cout << "Data yang Anda cari tidak ditemukan" << endl;
    }

    cout << "******************************************" << endl;

    return 0;
}