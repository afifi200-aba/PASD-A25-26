#include <iostream>
using namespace std;

//Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

//Deklarasi queue menggunakan array
typedef struct {
    int first;
    int last;
    NilaiMK Dat[10];
} Queue;  // <-- diganti dari 'queue' ke 'Queue'

//Deklarasi fungsi membuat queue kosong
void buatQUkosong(Queue *Q) {
    (*Q).first = -1;
    (*Q).last = -1;
}

//Deklarasi fungsi nilai TRUE apabila queue Kosong
bool isKosong(Queue Q) {
    bool hasil = false;
    if(Q.first == -1) {
        hasil = true;
    }
    return hasil;
}

//Deklarasi fungsi nilai TRUE apabila queue Penuh
bool isPenuh(Queue Q) {
    bool hasil = false;
    if(Q.last == 9) {
        hasil = true;
    }
    return hasil;
}

//Deklarasi fungsi memasukkan elemen ke dalam queue
void ADD(string npm, string nama_mhs, double nilai, Queue *Q) {
    if(isKosong(*Q) == 1) {
        //Jika Queue Kosong
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).Dat[0].npm = npm;
        (*Q).Dat[0].nama_mhs = nama_mhs;
        (*Q).Dat[0].nilai = nilai;
    }
    else {
        if(isPenuh(*Q) != 1) {
            //Jika Queue Tidak Kosong
            (*Q).last = (*Q).last + 1;
            (*Q).Dat[(*Q).last].npm = npm;
            (*Q).Dat[(*Q).last].nama_mhs = nama_mhs;
            (*Q).Dat[(*Q).last].nilai = nilai;
        }
        else {
            //Jika Queue PENUH
            cout << "QUEUE PENUH" << endl;
        }
    }
}

//Deklarasi fungsi mengeluarkan/menghapuskan elemen keluar queue
void DEL(Queue *Q) {
    if((*Q).last == 0) {
        (*Q).first = -1;
        (*Q).last = -1;
    }
    else {
        //Menggeser Elemen Ke Depan
        int i;
        for(i=((*Q).first + 1); i <= (*Q).last; i++) {
            (*Q).Dat[i-1].npm = (*Q).Dat[i].npm;
            (*Q).Dat[i-1].nama_mhs = (*Q).Dat[i].nama_mhs;
            (*Q).Dat[i-1].nilai = (*Q).Dat[i].nilai;
        }
        (*Q).last = (*Q).last - 1;
    }
}

//Deklarasi fungsi menampilkan isi queue
void CetakQueue(Queue Q)
{
    if(Q.first != -1)
    {
        cout << " MENAMPILKAN QUEUE " << endl;
        cout << " ~~~~~~~~~~~~~~~~ " << endl;
        int i;
        for(i=Q.last; i>=Q.first; i--)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke             : " << i << endl;
            cout << "Nomor Pokok Mahasiswa : " << Q.Dat[i].npm << endl;
            cout << "Nama Mahasiswa        : " << Q.Dat[i].nama_mhs << endl;
            cout << "Nilai Mahasiswa       : " << Q.Dat[i].nilai << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }
    else
    {
        cout << "Queue Kosong " << endl;
    }
}

int main() {
    Queue Q;  // <-- diganti dari 'queue' ke 'Queue'
    buatQUkosong(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    ADD("4523210666", "Budi", 88.75, &Q);
    ADD("4523210777", "Susi", 78.85, &Q);
    ADD("4523210888", "Nuri", 98.65, &Q);
    ADD("4523210999", "Bimo", 68.55, &Q);
    ADD("4523210555", "Arif", 78.85, &Q);
    ADD("4523210444", "Rido", 98.65, &Q);
    ADD("4523210222", "Ella", 68.55, &Q);
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