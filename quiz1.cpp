#include <iostream>
#include <string>
using namespace std;

// Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} DataBuku;

// Deklarasi struktur elemen
typedef struct elm *alamatelem;
typedef struct elm {
    DataBuku Kontainer;
    alamatelem next;
} elemen;

// Deklarasi struktur stack
typedef struct {
    elemen* top;
} stack;

// Deklarasi fungsi membuat stack kosong
void buatSTkosong(stack *S) {
    (*S).top = NULL;
}

// Deklarasi fungsi mengecek stack kosong
int isKosong(stack S) {
    bool hasil = false;

    if (S.top == NULL) {
        hasil = true;
    }
    return hasil;
}

// Deklarasi fungsi menghitung jumlah elemen stack
int jmlElemen(stack S) {
    int hasil = 0;

    if (S.top != NULL) {
        // Kondisi stack tidak kosong
        elemen *bantu;

        // inisialisasi
        bantu = S.top;

        while (bantu != NULL) {
            hasil = hasil + 1;

            // iterasi
            bantu = bantu->next;
        }
    }
    return hasil;
}

// Deklarasi fungsi memasukkan elemen ke dalam stack
void push(string npm, string nama_mhs, double nilai, stack *S) {
    elemen *info;
    info = new elemen;

    info->Kontainer.npm = npm;
    info->Kontainer.nama_mhs = nama_mhs;
    info->Kontainer.nilai = nilai;

    if ((*S).top == NULL) {
        cout << "Stack Penuh" << endl;
        // jika stack kosong
        info->next = NULL;
    }
    else {
        // jika stack tidak kosong
        info->next = (*S).top;
    }

    (*S).top = info;
    info = NULL;
}

// Deklarasi fungsi mengeluarkan elemen dari stack
void Pop(stack *S) {
    if ((*S).top != NULL) {
        // jika list bukan stack kosong
        elemen *hapus = (*S).top;

        if (jmlElemen(*S) == 1) {
            // jika stack hanya satu elemen
            (*S).top = NULL;
        }
        else {
            (*S).top = (*S).top->next;
        }

        hapus->next = NULL;
        delete hapus;
    }
    else {
        cout << "Stack Kosong" << endl;
    }
}

// Deklarasi fungsi menampilkan isi stack
void CetakStack(stack S) {
    if (S.top != NULL) {
        cout << "MENAMPILKAN STACK " << endl;

        elemen *bantu = S.top;
        int i = 1;

        while (bantu != NULL) {
            cout << "----------------------------------------" << endl;
            cout << "Elemen ke              : " << i << endl;
            cout << "Pengarang              : "
                 << bantu->Kontainer.npm << endl;
            cout << "Judul Buku             : "
                 << bantu->Kontainer.nama_mhs << endl;
            cout << "Kode Buku              : "
                 << bantu->Kontainer.nilai << endl;

            // iterasi
            bantu = bantu->next;
            i = i + 1;
        }

        cout << "----------------------------------------" << endl;
    }
    else {
        cout << "Stack Kosong" << endl;
    }
}

// Menu Utama
int main() {
    stack S;

    buatSTkosong(&S);
    CetakStack(S);

    cout << endl;
    cout << endl;
    cout << "========================" << endl;

    push("Antonio", "Cara Bermain Free Fire", 12345100, &S);
    push("Fabian", "Ahli Mancing Mania", 12345200, &S);
    push("Ekky", "Tutor Hengker ala Wukong", 12345300, &S);
    push("Bjorpip", "Cara Merawat Rambut Gondrong", 12345400, &S);
    CetakStack(S);

    cout << "========================" << endl;
    cout << endl;
    cout << endl;

    Pop(&S);
    CetakStack(S);

    cout << endl;
    cout << endl;

    Pop(&S);
    CetakStack(S);

    cout << "========================" << endl;

    return 0;
}