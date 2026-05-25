#include <iostream>
#include <string>
using namespace std;

// 1. Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

// 2. Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelm next;
} elemen;

// 3. Deklarasi struktur queue
typedef struct {
    elemen *first;
    elemen *last;
} queue;

// 4. Prosedur membuat queue kosong
void buatQUkosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last  = NULL;
}

// 5. Fungsi cek queue kosong
int isKosong(queue Q) {
    bool hasil = false;
    if (Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

// 6. Fungsi menghitung jumlah elemen queue
int jmlElemen(queue Q) {
    int hasil = 0;
    if (Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;
        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

// 7. Prosedur ADD (Enqueue)
void add(string npm, string nama_mhs, double nilai, queue *Q) {
    elemen *info;
    info = new elemen;
    info->Kontainer.npm      = npm;
    info->Kontainer.nama_mhs = nama_mhs;
    info->Kontainer.nilai    = nilai;
    info->next               = NULL;

    if ((*Q).first == NULL) {
        (*Q).first = info;
    } else {
        (*Q).last->next = info;
    }
    (*Q).last = info;
    info = NULL;
}

// 8. Prosedur DEL (Dequeue)
void del(queue *Q) {
    if ((*Q).first != NULL) {
        elemen *hapus = (*Q).first;
        if (jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last  = NULL;
        } else {
            (*Q).first   = (*Q).first->next;
            hapus->next  = NULL;
        }
        delete hapus;
    }
}

// 9. Prosedur menampilkan isi queue
void CetakQueue(queue Q) {
    if (Q.first != NULL) {
        cout << " MENAMPILKAN QUEUE " << endl;
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke              : " << i << endl;
            cout << "Nomor Pokok Mahasiswa  : " << bantu->Kontainer.npm      << endl;
            cout << "Nama Mahasiswa         : " << bantu->Kontainer.nama_mhs << endl;
            cout << "Nilai Mahasiswa        : " << bantu->Kontainer.nilai     << endl;
            bantu = bantu->next;
            i = i + 1;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    } else {
        cout << "Queue Kosong " << endl;
    }
}

int main() {
    queue Q;
    buatQUkosong(&Q);

    int n;
    cout << "=====================================" << endl;
    cout << "  QUEUE DENGAN LINKED LIST (INPUT)  " << endl;
    cout << "=====================================" << endl;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string npm, nama;
        double nilai;
        cout << "\n--- Data Mahasiswa ke-" << i << " ---" << endl;
        cout << "NPM       : "; cin >> npm;
        cin.ignore();
        cout << "Nama      : "; getline(cin, nama);
        cout << "Nilai     : "; cin >> nilai;
        add(npm, nama, nilai, &Q);
    }

    cout << "\n======================" << endl;
    CetakQueue(Q);
    cout << "======================" << endl;

    cout << "\n>> Dequeue (hapus elemen pertama)..." << endl;
    del(&Q);
    CetakQueue(Q);
    cout << "======================" << endl;

    cout << "\n>> Dequeue (hapus elemen pertama)..." << endl;
    del(&Q);
    CetakQueue(Q);
    cout << "======================" << endl;

    return 0;
}
