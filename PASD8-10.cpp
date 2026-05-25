#include<iostream>
using namespace std;

struct DataKarakter {
    char karakter;
    int indeks;
};

int SearchKarakter(DataKarakter data[], int jumlahElemen, char cari) {
    int flag = -1;
    for (int count = 0; count < jumlahElemen; count++) {
        if (data[count].karakter == cari) {
            flag = count;
            break;
        }
    }
    return flag;
}

int main() {
    const int JmlElemenArray = 10;

    
    DataKarakter huruf[JmlElemenArray];
    char isiData[JmlElemenArray] = {'B','D','A','G','E','I','C','H','F','J'};

    for (int i = 0; i < JmlElemenArray; i++) {
        huruf[i].karakter = isiData[i];
        huruf[i].indeks   = i;
    }

    char karCari = 'H';

    cout << "******************************************" << endl;
    cout << "**   S E Q U E N T I A L   S E A R C H **" << endl;
    cout << "**     Data Karakter - Menggunakan Struct **" << endl;
    cout << "******************************************" << endl;

    cout << "Isi data nya adalah" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int count = 0; count < JmlElemenArray; count++) {
        cout << "t" << "Data [" << huruf[count].indeks << "]" << " --> " << huruf[count].karakter << endl;
    }

    cout << "******************************************" << endl;
    cout << endl;

    cout << "Karakter yang akan dicari : " << karCari << endl;

    int flag = SearchKarakter(huruf, JmlElemenArray, karCari);

    if (flag != -1)
        cout << "Data yang dicari ditemukan pada posisi : Data[" << flag << "]" << endl;
    else
        cout << "Data yang Anda cari tidak ditemukan" << endl;

    cout << "******************************************" << endl;

    return 0;
}