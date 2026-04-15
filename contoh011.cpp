#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct elm {
    NilaiMK Kontainer;
    elm* next;
} elemen;

typedef struct {
    elemen* top;
} stack;

void buatSTkosong(stack* S) { S->top = NULL; }
bool isKosong(stack S) { return S.top == NULL; }
int jmlElemen(stack S) {
    int hasil = 0;
    elemen* bantu = S.top;
    while (bantu) {
        hasil++;
        bantu = bantu->next;
    }
    return hasil;
}

void push(string npm, string nama_mhs, double nilai, stack* S) {
    elemen* info = new elemen;
    info->Kontainer = {npm, nama_mhs, nilai};
    info->next = S->top;
    S->top = info;
}

void Pop(stack* S) {
    if (S->top) {
        elemen* hapus = S->top;
        S->top = S->top->next;
        delete hapus;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void CetakStack(stack S) {
    if (isKosong(S)) {
        cout << "Stack Kosong" << endl;
        return;
    }
    elemen* bantu = S.top;
    int i = 1;
    while (bantu) {
        cout << "Elemen ke : " << i << endl;
        cout << "Nomor Pokok Mahasiswa : " << bantu->Kontainer.npm << endl;
        cout << "Nama Mahasiswa : " << bantu->Kontainer.nama_mhs << endl;
        cout << "Nilai Mahasiswa : " << bantu->Kontainer.nilai << endl;
        bantu = bantu->next;
        i++;
    }
}

int main() {
    stack S;
    buatSTkosong(&S);
    push("4523210666", "Budi", 88.75, &S);
    push("4523210777", "Susi", 78.85, &S);
    push("4523210888", "Nuri", 98.65, &S);
    push("4523210999", "Bimo", 68.55, &S);
    push("4523210555", "Arif", 78.85, &S);
    push("4523210444", "Rido", 98.65, &S);
    push("4523210222", "Ella", 68.55, &S);
    CetakStack(S);
    Pop(&S);
    CetakStack(S);
    Pop(&S);
    CetakStack(S);
    return 0;
}