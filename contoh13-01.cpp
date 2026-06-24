#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define HASHSIZE 100

// ===== Struct Data =====
struct HashData {
    char kode[20];
    char nama[50];
};

HashData *hashTable[HASHSIZE];

// ===== Deklarasi Fungsi =====
void Clear();
void insert(HashData *array);
void searching(HashData *cari);
int searchingProcess(HashData *cari, int rec);
void deleting(HashData *hapus);
int hashFunction(HashData *array);
bool isIndexEmpty(int rec);
int characterAmount(char array[]);
void DisplayTable();

// ===== Main Program =====
int main() {
    Clear(); // inisialisasi tabel hash agar semua bernilai NULL di awal

    char ulang = 'Y', menu;
    do {
        system("cls"); // di Linux bisa diganti system("clear");

        puts("        PROSES HASH TABLE                ");
        puts("");
        puts("1. Input");
        puts("2. Delete");
        puts("3. Find");
        puts("4. Display");
        puts("5. Clear");
        puts("x. Keluar");
        puts("");
        cout << "Menu pilihan Anda : ";
        cin >> menu;

        switch (menu) {
            case '1': {
                HashData *array;
                array = new HashData;
                puts("");
                cout << "KodeMK          : "; cin >> array->kode;
                cout << "Matakuliah      : "; cin >> array->nama;
                cout << endl;
                insert(array);
                break;
            }
            case '2': {
                HashData *hapus;
                hapus = new HashData;
                cout << "Hapus Matakuliah (KodeMK) : "; cin >> hapus->kode;
                deleting(hapus);
                break;
            }
            case '3': {
                HashData *cari;
                cari = new HashData;
                cout << "Cari MataKuliah (KodeMK) : "; cin >> cari->kode;
                searching(cari);
                break;
            }
            case '4':
                DisplayTable();
                break;
            case '5':
                Clear();
                puts("Tabel hash telah dikosongkan.");
                break;
            case 'x':
            case 'X':
                ulang = 'T';
                break;
            default:
                puts("Pilihan diluar Menu yang tersedia!");
                break;
        }
        cin.ignore();
        cin.get();
    } while (toupper(ulang) == 'Y');

    return 0;
}

// ===== Mengosongkan tabel hash =====
void Clear() {
    for (int i = 0; i < HASHSIZE; i++)
        hashTable[i] = NULL;
}

// ===== Menyisipkan data ke tabel hash =====
void insert(HashData *array) {
    int rec;
    rec = hashFunction(array);
    hashTable[rec] = array;
    cout << "Input successfully!" << endl;
    cout << "Data disimpan pada record indeks " << rec << endl;
}

// ===== Mencari data pada tabel hash =====
void searching(HashData *cari) {
    int rec;
    rec = hashFunction(cari);
    rec = searchingProcess(cari, rec);
    if (rec >= 0) {
        cout << "Data ditemukan pada record indeks " << rec << endl;
        cout << "Isi data : " << endl;
        cout << "=> KodeMK     : " << hashTable[rec]->kode << endl;
        cout << "=> Matakuliah : " << hashTable[rec]->nama << endl;
    } else {
        cout << "Maaf! Data tidak ditemukan." << endl;
    }
}

// ===== Proses pencocokan key pada index hasil hashing =====
int searchingProcess(HashData *cari, int rec) {
    int m, n, j = 0;
    bool equal = true;

    if (isIndexEmpty(rec) == false) {
        n = characterAmount(cari->kode);
        m = characterAmount(hashTable[rec]->kode);
        if (n == m) {
            while ((equal == true) && (cari->kode[j] != '\0')) {
                if (tolower(cari->kode[j]) != tolower(hashTable[rec]->kode[j]))
                    equal = false;
                j++;
            }
            if (equal == true)
                return rec;
            else
                return -1;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

// ===== Menghapus data dari tabel hash =====
void deleting(HashData *hapus) {
    int rec;
    rec = hashFunction(hapus);
    rec = searchingProcess(hapus, rec);
    if (rec >= 0) {
        cout << "Data :" << endl;
        cout << " => KodeMK     : " << hashTable[rec]->kode << endl;
        cout << " => MataKuliah : " << hashTable[rec]->nama << endl;
        cout << "terhapus!" << endl;
        hashTable[rec] = NULL;
    } else {
        cout << "Maaf! Data tidak ditemukan!" << endl;
    }
}

// ===== Fungsi HASH (modulo dari total kode ASCII karakter key) =====
int hashFunction(HashData *array) {
    int value = 0, rec, n;
    n = characterAmount(array->kode);
    for (int i = 0; i < n; i++) {
        value += array->kode[i];
    }
    rec = value % HASHSIZE;
    return rec;
}

// ===== Mengecek apakah index pada tabel hash masih kosong =====
bool isIndexEmpty(int rec) {
    if (hashTable[rec] == NULL)
        return true;
    else
        return false;
}

// ===== Menghitung jumlah karakter pada sebuah string =====
int characterAmount(char array[]) {
    int jumlah = 0;
    for (int i = 0; array[i] != '\0'; i++)
        jumlah++;
    return jumlah;
}

// ===== Menampilkan seluruh isi tabel hash =====
void DisplayTable() {
    cout << "\n";
    cout << "|--------|--------------|---------------------------------|" << endl;
    cout << "| Indeks |    KODEMK    |          Nama Mata Kuliah       |" << endl;
    cout << "|--------|--------------|---------------------------------|" << endl;
    for (int i = 0; i < HASHSIZE; i++) {
        if (isIndexEmpty(i) == false)
            cout << setw(6) << i << "   " << setw(10) << hashTable[i]->kode
                 << "\t" << hashTable[i]->nama << endl;
    }
}