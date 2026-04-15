#include <iostream>
#include <string.h>

using namespace std;

// Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

// Deklarasi stack menggunakan array
typedef struct {
    int top;
    NilaiMK Dat[10];
} 	stack;

// Deklarasi fungsi membuat stack kosong
void buatSTkosong(stack *S) {
    (*S).top = -1;
}

// Deklarasi fungsi nilai TRUE apabila stack Kosong
bool isKosong(stack S) {
    bool hasil = false;
    if(S.top == -1) {
        hasil = true;
    }
    return hasil;
}

// Deklarasi fungsi nilai TRUE apabila stack Penuh
bool isPenuh(stack S) {
    bool hasil = false;
    if(S.top == 9) {
        hasil = true;
    }
    return hasil;
}

// Deklarasi fungsi memasukkan elemen ke dalam stack
void push(string npm, string nama_mhs, double nilai, stack *S) {
    if(isPenuh(*S) == 1) {
        cout << "Stack Penuh" << endl;
    }
    else {
        if(isKosong(*S) == 1) {
            // jika stack kosong
            (*S).top = 0;
            (*S).Dat[0].npm = npm;
            (*S).Dat[0].nama_mhs = nama_mhs;
            (*S).Dat[0].nilai = nilai;
        }
        else {
            // jika stack tidak kosong
            (*S).top = (*S).top + 1;
            (*S).Dat[(*S).top].npm = npm;
            (*S).Dat[(*S).top].nama_mhs = nama_mhs;
            (*S).Dat[(*S).top].nilai = nilai;
        }
    }
}

// Deklarasi fungsi mengeluarkan elemen keluar stack
void Pop(stack *S) {
    if((*S).top == 0) {
        // jika berisi satu elemen
        (*S).top = -1;
    }
    else {
        if((*S).top != -1) {
            // jika stack tidak kosong
            (*S).top = (*S).top - 1;
        }
    }
}

// Deklarasi fungsi menampilkan isi stack
void CetakStack(stack S) {
    if(S.top != -1) {
        cout << " MENAMPILKAN STACK " << endl;
        int i;
        for(i=S.top; i>=0; i--) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke              : " << i << endl;
            cout << "Nomor Pokok Mahasiswa  : " << S.Dat[i].npm << endl;
            cout << "Nama Mahasiswa         : " << S.Dat[i].nama_mhs << endl;
            cout << "Nilai Mahasiswa        : " << S.Dat[i].nilai << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }
    else {
        cout << "Stack Kosong " << endl;
    }
}

int main() {
    stack S;

    buatSTkosong(&S);
    CetakStack(S);
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    push("4523210666", "Budi", 88.75, &S);
    push("4523210777", "Susi", 78.85, &S);
    push("4523210888", "Sari", 98.65, &S);
    push("4523210999", "Bimo", 68.55, &S);
    
    CetakStack(S);
    cout << "========================================" << endl;
    cout << endl;
    cout << endl;
    
    Pop(&S);
    CetakStack(S);
    cout << endl;
    cout << endl;
    
    Pop(&S);
    CetakStack(S);
    cout << "========================================" << endl;
    
    return 0;
}