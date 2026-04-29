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
} queue;

//4. Deklarasi fungsi membuat queue kosong
void buatQUkosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

//5. Deklarasi fungsi membuat queue Kosong
int isKosong(queue Q) {
    bool hasil = false;

    if(Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

//6. Deklarasi fungsi menghitung jumlah elemen queue
int jmlElemen(queue Q) {
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
void add(string npm, string nama_mhs, double nilai, queue *Q) {
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
void del(queue *Q) {
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
void CetakQueue(queue Q)
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
            cout << "kode_barang : " << bantu -> Kontainer.npm << endl;
            cout << "Nama_barang        : " << bantu -> Kontainer.nama_mhs << endl;
            cout << "Jumlah_stok       : " << bantu -> Kontainer.nilai << endl;
      
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
    queue Q;
    buatQUkosong(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
    add("45", "Budi", 8.7, &Q);
    add("23", "Susi", 7.5, &Q);
    add("21", "Nuri", 9.6, &Q);
    add("99", "Bimo", 1.4, &Q);
    add("55", "Arif", 7.5, &Q);
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