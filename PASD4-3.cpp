#include <iostream>
#include <string>
using namespace std;


typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;


typedef struct {
    int first;
    int last;
    NilaiMK Dat[10];
} queue;


void buatQUkosong(queue *Q) {
    (*Q).first = -1;
    (*Q).last  = -1;
}


bool isKosong(queue Q) {
    bool hasil = false;
    if (Q.first == -1) {
        hasil = true;
    }
    return hasil;
}


bool isPenuh(queue Q) {
    bool hasil = false;
    if (Q.last == 9) {
        hasil = true;
    }
    return hasil;
}


void ADD(string npm, string nama_mhs, double nilai, queue *Q) {
    if (isKosong(*Q) == 1) {
        
        (*Q).first = 0;
        (*Q).last  = 0;
        (*Q).Dat[0].npm      = npm;
        (*Q).Dat[0].nama_mhs = nama_mhs;
        (*Q).Dat[0].nilai    = nilai;
    } else {
        if (isPenuh(*Q) != 1) {
           
            (*Q).last = (*Q).last + 1;
            (*Q).Dat[(*Q).last].npm      = npm;
            (*Q).Dat[(*Q).last].nama_mhs = nama_mhs;
            (*Q).Dat[(*Q).last].nilai    = nilai;
        } else {
            
            cout << "QUEUE PENUH" << endl;
        }
    }
}


void DEL(queue *Q) {
    if ((*Q).last == 0) {
        (*Q).first = -1;
        (*Q).last  = -1;
    } else {
        
        int i;
        for (i = ((*Q).first + 1); i <= (*Q).last; i++) {
            (*Q).Dat[i-1].npm      = (*Q).Dat[i].npm;
            (*Q).Dat[i-1].nama_mhs = (*Q).Dat[i].nama_mhs;
            (*Q).Dat[i-1].nilai    = (*Q).Dat[i].nilai;
        }
        (*Q).last = (*Q).last - 1;
    }
}


void CetakQueue(queue Q) {
    if (Q.first != -1) {
        cout << " MENAMPILKAN QUEUE " << endl;
        cout << " ================= " << endl;
        int i;
        for (i = Q.last; i >= Q.first; i--) {
            cout << "----------------------------------------------" << endl;
            cout << "Elemen ke              : " << i << endl;
            cout << "Nomor Pokok Mahasiswa  : " << Q.Dat[i].npm      << endl;
            cout << "Nama Mahasiswa         : " << Q.Dat[i].nama_mhs << endl;
            cout << "Nilai Mahasiswa        : " << Q.Dat[i].nilai     << endl;
            cout << "----------------------------------------------" << endl;
        }
    } else {
        cout << "Queue Kosong " << endl;
    }
}

int main() {
    queue Q;
    buatQUkosong(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << "======================" << endl;

   
    ADD("4523210666", "Budi",  88.75, &Q);
    ADD("4523210777", "Susi",  78.85, &Q);
    ADD("4523210888", "Nuri",  90.65, &Q);
    ADD("4523210999", "Bimo",  68.55, &Q);
    ADD("4523210555", "Arif",  78.85, &Q);
    ADD("4523210444", "Rido",  90.65, &Q);
    ADD("4523210222", "Ella",  68.55, &Q);

    CetakQueue(Q);
    cout << "======================" << endl;
    cout << endl;
    cout << endl;

    DEL(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;

    DEL(&Q);
    CetakQueue(Q);
    cout << "======================" << endl;

    return 0;
}