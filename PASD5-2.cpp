#include <iostream>
#include <string>
using namespace std;


typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;


typedef struct elm *alamatelm;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelm next;
} elemen;


class Queue {
private:
    elemen *first;
    elemen *last;

public:
    
    Queue() {
        first = NULL;
        last  = NULL;
    }

   
    ~Queue() {
        elemen *bantu = first;
        while (bantu != NULL) {
            elemen *hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
    }

    bool isKosong() {
        return (first == NULL);
    }

   
    int jmlElemen() {
        int hasil = 0;
        if (first != NULL) {
            elemen *bantu = first;
            while (bantu != NULL) {
                hasil = hasil + 1;
                bantu = bantu->next;
            }
        }
        return hasil;
    }

    
    void add(string npm, string nama_mhs, double nilai) {
        elemen *info;
        info = new elemen;
        info->Kontainer.npm      = npm;
        info->Kontainer.nama_mhs = nama_mhs;
        info->Kontainer.nilai    = nilai;
        info->next = NULL;

        if (first == NULL) {
            first = info;
        } else {
            last->next = info;
        }
        last = info;
        info = NULL;
    }

    
    void del() {
        if (first != NULL) {
            elemen *hapus = first;

            if (jmlElemen() == 1) {
                first = NULL;
                last  = NULL;
            } else {
                first      = first->next;
                hapus->next = NULL;
            }
            delete hapus;
        }
    }

 
    void CetakQueue() {
        if (first != NULL) {
            cout << " MENAMPILKAN QUEUE " << endl;
            elemen *bantu = first;
            int i = 1;
            while (bantu != NULL) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "Elemen ke          : " << i << endl;
                cout << "Nomor Pokok Mahasiswa : " << bantu->Kontainer.npm      << endl;
                cout << "Nama Mahasiswa        : " << bantu->Kontainer.nama_mhs << endl;
                cout << "Nilai Mahasiswa       : " << bantu->Kontainer.nilai    << endl;
                bantu = bantu->next;
                i = i + 1;
            }
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        } else {
            cout << "Queue Kosong " << endl;
        }
    }
};


int main() {
    Queue Q;

    Q.CetakQueue();
    cout << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;

    
    Q.add("4523210666", "Budi",  88.75);
    Q.add("4523210777", "Susi",  78.85);
    Q.add("4523210888", "Nuri",  98.65);
    Q.add("4523210999", "Bimo",  68.55);
    Q.add("4523210555", "Arif",  78.85);
    Q.add("4523210444", "Rido",  98.65);
    Q.add("4523210222", "Ella",  68.55);

    Q.CetakQueue();
    cout << "======================" << endl;
    cout << endl;
    cout << endl;

    Q.del();
    Q.CetakQueue();
    cout << endl;
    cout << endl;

    Q.del();
    Q.CetakQueue();
    cout << "======================" << endl;

    return 0;
}