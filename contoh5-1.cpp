#include <iostream>
#include <string>
using namespace std;

//Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

//Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelm next;
} elemen;

//3. Deklarasi struktur queue
typedef struct {
    elemen *first;
    elemen *last;
} Queue;

//4. Deklarasi fungsi membuat queue kosong
void buatQUkosong(Queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

//5. Deklarasi fungsi membuat queue Kosong
int isKosong(Queue Q) {
    bool hasil = false;

    if(Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

//6. Deklarasi fungsi menghitung jumlah elemen queue
int jmlElemen(Queue Q) {
    int hasil = 0;

    if(Q.first != NULL) {
        //Kondisi Queue Tidak Kosong
        elemen *bantu;
        //inisialisai
        bantu = Q.first;

        while(bantu != NULL) {
            hasil = hasil + 1;
            //interasi
            bantu = bantu -> next;
        }
    }
    return hasil;
}

//7. Deklarasi fungsi memasukkan elemen ke dalam queue
void add(string npm, string nama_mhs, double nilai, Queue *Q) {
    elemen *info;
    info = new elemen;
    info -> Kontainer.npm = npm;
    info -> Kontainer.nama_mhs = nama_mhs;
    info -> Kontainer.nilai = nilai;
    info -> next = NULL;

    if((*Q).first == NULL) {
        (*Q).first = info;
    }
    else {
        (*Q).last -> next = info;
    }
    (*Q).last = info;
    info = NULL;
}

//8. Deklarasi fungsi mengeluarkan elemen keluar queue
void del(Queue *Q) {
    if((*Q).first != NULL) {
        //jika queue bukan queue kosong
        elemen *hapus = (*Q).first;

        if(jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else {
            (*Q).first = (*Q).first -> next;
            hapus -> next = NULL;
        }
        delete hapus;
    }
}

//9. Deklarasi fungsi menampilkan isi queue
void CetakQueue(Queue Q)
{
    if(Q.first != NULL)
    {
        cout << " MENAMPILKAN QUEUE " << endl;
        elemen *bantu = Q.first;
        int i = 1;
        while(bantu != NULL)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke          : " << i << endl;
            cout << "Nomor Pokok Mahasiswa : " << bantu -> Kontainer.npm << endl;
            cout << "Nama Mahasiswa        : " << bantu -> Kontainer.nama_mhs << endl;
            cout << "Nilai Mahasiswa       : " << bantu -> Kontainer.nilai << endl;
        //iterasi
        bantu = bantu -> next;
        i = i + 1;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    else
    {
        cout << "Queue Kosong " << endl;
    }
}

int main() {
    Queue Q;
    buatQUkosong(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    add("4523210666", "Budi", 88.75, &Q);
    add("4523210777", "Susi", 78.85, &Q);
    add("4523210888", "Nuri", 98.65, &Q);
    add("4523210999", "Bimo", 68.55, &Q);
    add("4523210555", "Arif", 78.85, &Q);
    add("4523210444", "Rido", 98.65, &Q);
    add("4523210222", "Ella", 68.55, &Q);
    CetakQueue(Q);
    cout << "=====================" << endl;
    cout << endl;
    cout << endl;
    del(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;
    del(&Q);
    CetakQueue(Q);
    cout << "=====================" << endl;
    return 0;
}