#include <iostream>
#include <string>
using namespace std;

// Deklarasi struktur data karyawan
typedef struct {
    string kode_barang;
    string nama_barang;
    int jumlah_stok;
} DataKaryawan;

// Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    DataKaryawan Kontainer;
    alamatelm next;
} elemen;

// 3. Deklarasi struktur queue
typedef struct {
    elemen *first;
    elemen *last;
} Queue;

// 4. Deklarasi fungsi membuat queue kosong
void buatQUkosong(Queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

// 5. Deklarasi fungsi cek queue Kosong
int isKosong(Queue Q) {
    bool hasil = false;
    if(Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

// 6. Deklarasi fungsi menghitung jumlah elemen queue
int jmlElemen(Queue Q) {
    int hasil = 0;
    if(Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;
        while(bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu -> next;
        }
    }
    return hasil;
}

// 7. Deklarasi fungsi memasukkan elemen ke dalam queue
void add(string nip, string nama_karyawan, double gaji, Queue *Q) {
    elemen *info;
    info = new elemen;
    info -> Kontainer.nip = nip;
    info -> Kontainer.nama_karyawan = nama_karyawan;
    info -> Kontainer.gaji = gaji;
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

// 8. Deklarasi fungsi mengeluarkan elemen keluar queue
void del(Queue *Q) {
    if((*Q).first != NULL) {
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

// 9. Deklarasi fungsi menampilkan isi queue
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
            cout << "NIP                : " << bantu -> Kontainer.nip << endl;
            cout << "Nama Karyawan      : " << bantu -> Kontainer.nama_karyawan << endl;
            cout << "Gaji               : " << bantu -> Kontainer.gaji << endl;
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

    // Cetak kondisi awal (kosong)
    CetakQueue(Q);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    // Tambahkan 7 data karyawan
    add("1001", "Andi", 500000, &Q);
    add("1002", "Budi", 650000, &Q);
    add("1003", "Citra", 700000, &Q);
    add("1004", "Dina", 450000, &Q);
    add("1005", "Eko", 800000, &Q);
    add("1006", "Fajar", 550000, &Q);
    add("1007", "Gita", 600000, &Q);

    // Tampilkan seluruh isi antrian
    CetakQueue(Q);
    cout << "=====================" << endl;
    cout << endl;
    cout << endl;

    // Penghapusan ke-1
    del(&Q);
    CetakQueue(Q);
    cout << endl;
    cout << endl;

    // Penghapusan ke-2
    del(&Q);
    CetakQueue(Q);
    cout << "=====================" << endl;

    return 0;
}