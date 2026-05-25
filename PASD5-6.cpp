/*
 * PASD5-6.cpp
 * Queue Linked List - Antrian berbagai macam OS
 * Antrian awal: Maemo -> Symbian -> Mac -> Windows -> Iphone
 *
 * Operasi:
 * a. Tambah "Maemo 4" paling bawah (last), hapus "Mac"
 * b. Tambah "Windows Mobile" di bawah "Windows", hapus "Iphone"
 * c. Tambah "Java Midlet" di bawah "Symbian", hapus "Maemo"
 * d. Tambah "Lion OS X" di bawah "Mac", hapus "Maemo"
 * e. Tambah "Android" di bawah "Iphone", hapus "Maemo"
 */

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// DEKLARASI STRUKTUR
// ============================================================

typedef struct elm *alamatelm;
typedef struct elm {
    string data;
    alamatelm next;
} elemen;

typedef struct {
    elemen *first;
    elemen *last;
} queue;

// ============================================================
// FUNGSI DASAR QUEUE
// ============================================================

void buatQUkosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last  = NULL;
}

int isKosong(queue Q) {
    return (Q.first == NULL) ? 1 : 0;
}

int jmlElemen(queue Q) {
    int hasil = 0;
    elemen *bantu = Q.first;
    while (bantu != NULL) {
        hasil++;
        bantu = bantu->next;
    }
    return hasil;
}

// ADD di belakang (Enqueue)
void add(string data, queue *Q) {
    elemen *info = new elemen;
    info->data   = data;
    info->next   = NULL;

    if ((*Q).first == NULL) {
        (*Q).first = info;
    } else {
        (*Q).last->next = info;
    }
    (*Q).last = info;
    info = NULL;
}

// DEL dari depan (Dequeue)
void del(queue *Q) {
    if ((*Q).first != NULL) {
        elemen *hapus = (*Q).first;
        if (jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last  = NULL;
        } else {
            (*Q).first  = (*Q).first->next;
            hapus->next = NULL;
        }
        delete hapus;
    }
}

// ============================================================
// FUNGSI TAMBAHAN
// ============================================================

// Sisipkan elemen baru SETELAH node yang bernilai 'target'
void insertSetelah(string target, string dataBaru, queue *Q) {
    elemen *bantu = (*Q).first;
    while (bantu != NULL) {
        if (bantu->data == target) {
            elemen *baru = new elemen;
            baru->data   = dataBaru;
            baru->next   = bantu->next;
            bantu->next  = baru;
            // Update last jika disisipkan di akhir
            if (baru->next == NULL) {
                (*Q).last = baru;
            }
            return;
        }
        bantu = bantu->next;
    }
    cout << "[PERINGATAN] Target '" << target << "' tidak ditemukan!" << endl;
}

// Hapus elemen tertentu berdasarkan nilai data
void hapusData(string target, queue *Q) {
    if ((*Q).first == NULL) return;

    // Jika elemen pertama yang dihapus
    if ((*Q).first->data == target) {
        elemen *hapus = (*Q).first;
        if (jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last  = NULL;
        } else {
            (*Q).first = (*Q).first->next;
        }
        hapus->next = NULL;
        delete hapus;
        return;
    }

    // Cari di tengah/akhir
    elemen *prev  = (*Q).first;
    elemen *bantu = prev->next;
    while (bantu != NULL) {
        if (bantu->data == target) {
            prev->next = bantu->next;
            if (bantu->next == NULL) {  // hapus elemen terakhir
                (*Q).last = prev;
            }
            bantu->next = NULL;
            delete bantu;
            return;
        }
        prev  = bantu;
        bantu = bantu->next;
    }
    cout << "[PERINGATAN] Data '" << target << "' tidak ditemukan!" << endl;
}

// Tampilkan isi queue
void CetakQueue(queue Q) {
    if (isKosong(Q)) {
        cout << "Queue Kosong" << endl;
        return;
    }
    cout << "Isi Queue  : ";
    elemen *bantu = Q.first;
    int i = 1;
    while (bantu != NULL) {
        cout << "[" << i << "] " << bantu->data;
        if (bantu->next != NULL) cout << " -> ";
        bantu = bantu->next;
        i++;
    }
    cout << endl;
    cout << "Front      : " << Q.first->data << endl;
    cout << "Back       : " << Q.last->data  << endl;
    cout << "Jumlah     : " << jmlElemen(Q)  << " elemen" << endl;
}

// Inisialisasi antrian awal: Maemo -> Symbian -> Mac -> Windows -> Iphone
void inisialisasiAwal(queue *Q) {
    buatQUkosong(Q);
    add("Maemo",   Q);
    add("Symbian", Q);
    add("Mac",     Q);
    add("Windows", Q);
    add("Iphone",  Q);
}

// ============================================================
// MAIN
// ============================================================
int main() {
    queue Q;

    cout << "============================================================" << endl;
    cout << "         PASD5-6 : QUEUE OS DENGAN LINKED LIST             " << endl;
    cout << "     Antrian Awal: Maemo -> Symbian -> Mac -> Windows -> Iphone" << endl;
    cout << "============================================================" << endl;

    // --------------------------------------------------------
    // SOAL a: Tambah "Maemo 4" paling akhir, hapus "Mac"
    // --------------------------------------------------------
    cout << "\n============================================================" << endl;
    cout << "SOAL A: Tambah 'Maemo 4' paling akhir, hapus 'Mac'" << endl;
    cout << "============================================================" << endl;

    inisialisasiAwal(&Q);
    cout << "\n[Sebelum]" << endl;
    CetakQueue(Q);

    hapusData("Mac", &Q);
    add("Maemo 4", &Q);

    cout << "\n[Sesudah] Hapus 'Mac', tambah 'Maemo 4' di akhir:" << endl;
    CetakQueue(Q);

    // --------------------------------------------------------
    // SOAL b: Tambah "Windows Mobile" di bawah "Windows", hapus "Iphone"
    // --------------------------------------------------------
    cout << "\n============================================================" << endl;
    cout << "SOAL B: Tambah 'Windows Mobile' di bawah 'Windows', hapus 'Iphone'" << endl;
    cout << "============================================================" << endl;

    inisialisasiAwal(&Q);
    cout << "\n[Sebelum]" << endl;
    CetakQueue(Q);

    hapusData("Iphone", &Q);
    insertSetelah("Windows", "Windows Mobile", &Q);

    cout << "\n[Sesudah] Hapus 'Iphone', sisip 'Windows Mobile' setelah 'Windows':" << endl;
    CetakQueue(Q);

    // --------------------------------------------------------
    // SOAL c: Tambah "Java Midlet" di bawah "Symbian", hapus "Maemo"
    // --------------------------------------------------------
    cout << "\n============================================================" << endl;
    cout << "SOAL C: Tambah 'Java Midlet' di bawah 'Symbian', hapus 'Maemo'" << endl;
    cout << "============================================================" << endl;

    inisialisasiAwal(&Q);
    cout << "\n[Sebelum]" << endl;
    CetakQueue(Q);

    hapusData("Maemo", &Q);
    insertSetelah("Symbian", "Java Midlet", &Q);

    cout << "\n[Sesudah] Hapus 'Maemo', sisip 'Java Midlet' setelah 'Symbian':" << endl;
    CetakQueue(Q);

    // --------------------------------------------------------
    // SOAL d: Tambah "Lion OS X" di bawah "Mac", hapus "Maemo"
    // --------------------------------------------------------
    cout << "\n============================================================" << endl;
    cout << "SOAL D: Tambah 'Lion OS X' di bawah 'Mac', hapus 'Maemo'" << endl;
    cout << "============================================================" << endl;

    inisialisasiAwal(&Q);
    cout << "\n[Sebelum]" << endl;
    CetakQueue(Q);

    hapusData("Maemo", &Q);
    insertSetelah("Mac", "Lion OS X", &Q);

    cout << "\n[Sesudah] Hapus 'Maemo', sisip 'Lion OS X' setelah 'Mac':" << endl;
    CetakQueue(Q);

    // --------------------------------------------------------
    // SOAL e: Tambah "Android" di bawah "Iphone", hapus "Maemo"
    // --------------------------------------------------------
    cout << "\n============================================================" << endl;
    cout << "SOAL E: Tambah 'Android' di bawah 'Iphone', hapus 'Maemo'" << endl;
    cout << "============================================================" << endl;

    inisialisasiAwal(&Q);
    cout << "\n[Sebelum]" << endl;
    CetakQueue(Q);

    hapusData("Maemo", &Q);
    insertSetelah("Iphone", "Android", &Q);

    cout << "\n[Sesudah] Hapus 'Maemo', sisip 'Android' setelah 'Iphone':" << endl;
    CetakQueue(Q);

    cout << "\n============================================================" << endl;
    cout << "                      SELESAI                               " << endl;
    cout << "============================================================" << endl;

    return 0;
}
