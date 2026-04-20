#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

struct biodata {
    char nama[20];
    int usia;
};
struct biodata mhs;
struct biodata dataQueue[MAX];  
void init(void);
int full(void);
int empty(void);
struct biodata entridata(void);
void enqueue(struct biodata mhs);
struct biodata dequeue(void);
void display(struct biodata mhs);
void baca(void);
int awal, akhir;
char nocomment[10];

int main() {
    char pilih;
    cout << "== Program Entri Data Mahasiswa==\n";
    init();
    do {
        cout << "MENU PILIHAN :\n";
        cout << "1. Input Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Lihat Daftar Mahasiswa\n";
        cout << "4. Hapus Semua Data\n";
        cout << "5. Selesai.\n";
        cout << "Pilih 1 sd 5 : ";
        cin >> pilih;
        switch(pilih) {
            case '1' :  mhs = entridata(); enqueue(mhs); break;
            case '2' :  cout << "\nData yang dihapus : \n";
                        mhs = dequeue(); display(mhs); break;
            case '3' :  baca(); break;
            case '4' :  init(); cout << "\nData telah dikosongkan\n";
                        break;
            case '5' :  break;
            default  :  cout << "Pilih 1 sd 5!";
                        break;        }
        cout << "\n";
    }while(pilih != '5');
    return 0; }

void init(void) {
    awal = -1;
    akhir = -1;
}

void enqueue(struct biodata mhs) {
    if(empty() == true) {
        awal = 0;
        akhir = 0;
        dataQueue[awal] = mhs;  
    }else if(full() != true) {
        akhir++;
        dataQueue[akhir]=mhs;   
    }else cout << "Queue sudah penuh... \n";
}

struct biodata dequeue(void) {
    int i;
    if(empty() != true) {
        mhs=dataQueue[awal];
        for(i=awal;i<=akhir;i++)
            dataQueue[i]=dataQueue[i+1];
        akhir--;
        return(mhs);
    }else {
        cout << "Queue kosong...\n";
        return(mhs);  // <-- tambahkan ini
    }
}

int full(void) {
    if(akhir==MAX-1) return(true);
    else return(false);
}

int empty(void) {
    if(akhir == -1) return(true);
    else return(false);
}

void baca(void) {
    int i;
    cout << "\nIsi Queue : \n";
    if(empty() != true) {
        for(i=awal;i<=akhir;i++) {
            display(dataQueue[i]);  
        }
    }else cout << "Data kosong.";
    cout << "\n";
}

struct biodata entridata(void) {
    struct biodata mhs;
    cout << "\n";
    cout << "Masukkan Nama : ";cin >> mhs.nama;
    cout << "Masukkan Usia : ";cin >> mhs.usia;
    return(mhs);
}

void display(struct biodata mhs) {
    cout << "\n";
    cout << "Nama : " << mhs.nama << "\n";
    cout << "Usia : " << mhs.usia << "\n";
}