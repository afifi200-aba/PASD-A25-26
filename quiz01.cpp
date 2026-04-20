#include <iostream>
#include <string.h>
using namespace std;

#define MAX 10

struct pelanggan {
    char id[15];
    char nama[30];
    float totalBelanja;
};
struct pelanggan queue[MAX];
int awal, akhir;

void init() {
    awal  = -1;
    akhir = -1;
}
int isKosong() {
    if (akhir == -1) return 1;
    else return 0;
}
int isPenuh() {
    if (akhir == MAX - 1) return 1;
    else return 0;
}
void enqueue(struct pelanggan p) {
    if (isPenuh()) {
        cout << "\nQueue penuh! Data tidak dapat ditambahkan.\n";
    } else if (isKosong()) {
        awal  = 0;
        akhir = 0;
        queue[awal] = p;
        cout << "\nData pelanggan berhasil ditambahkan ke antrian.\n";
    } else {
        akhir++;
        queue[akhir] = p;
        cout << "\nData pelanggan berhasil ditambahkan ke antrian.\n";
    }
}
void dequeue() {
    int i;
    if (isKosong()) {
        cout << "\nQueue kosong! Tidak ada data yang bisa dihapus.\n";
    } else {
        cout << "\nData yang dihapus dari antrian:\n";
        cout << "--------------------------------\n";
        cout << "ID Pelanggan   : " << queue[awal].id        << "\n";
        cout << "Nama Pelanggan : " << queue[awal].nama      << "\n";
        cout << "Total Belanja  : Rp " << queue[awal].totalBelanja << "\n";
        cout << "--------------------------------\n";

        for (i = awal; i < akhir; i++)
            queue[i] = queue[i + 1];
        akhir--;

        if (akhir < 0) {
            awal  = -1;
            akhir = -1;
        }
    }
}
void cetakQueue() {
    int i;
    cout << "\n================================\n";
    cout << "       ISI ANTRIAN PELANGGAN\n";
    cout << "================================\n";
    if (isKosong()) {
        cout << "Queue kosong. Tidak ada data pelanggan.\n";
    } else {
        cout << "Jumlah data : " << (akhir - awal + 1) << " / " << MAX << "\n";
        cout << "--------------------------------\n";
        for (i = awal; i <= akhir; i++) {
            cout << "No. " << (i - awal + 1) << "\n";
            cout << "ID Pelanggan   : " << queue[i].id           << "\n";
            cout << "Nama Pelanggan : " << queue[i].nama         << "\n";
            cout << "Total Belanja  : Rp " << queue[i].totalBelanja << "\n";
            cout << "--------------------------------\n";
        }
    }
    cout << "\n";
}
struct pelanggan inputPelanggan() {
    struct pelanggan p;
    cout << "\n";
    cout << "Masukkan ID Pelanggan   : "; cin >> p.id;
    cout << "Masukkan Nama Pelanggan : "; cin >> p.nama;
    cout << "Masukkan Total Belanja  : Rp "; cin >> p.totalBelanja;
    return p;
}
int main() {
    struct pelanggan p;
    char pilih;
    init();
    cout << "================================\n";
    cout << "    PROGRAM QUEUE PELANGGAN\n";
    cout << "================================\n";
    do {
        cout << "\nMENU PILIHAN:\n";
        cout << "1. Tambah Data Pelanggan\n";
        cout << "2. Hapus Data Pelanggan\n";
        cout << "3. Tampilkan Queue\n";
        cout << "4. Keluar Program\n";
        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih) {
            case '1':
                p = inputPelanggan();
                enqueue(p);
                break;
            case '2':
                dequeue();
                break;
            case '3':
                cetakQueue();
                break;
            case '4':
                cout << "\nProgram selesai. Terima kasih!\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Masukkan 1-4.\n";
                break;
        }
    } while (pilih != '4');
    return 0;
}