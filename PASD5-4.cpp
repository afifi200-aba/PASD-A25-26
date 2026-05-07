#include <iostream>
#include <string>
using namespace std;


typedef struct elm *alamatelm;
typedef struct elm {
    string data;
    alamatelm next;
} elemen;


typedef struct {
    elemen *first;
    elemen *last;
} queue;


void buatQUkosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last  = NULL;
}


int isKosong(queue Q) {
    bool hasil = false;
    if (Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}


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


void add(string data, queue *Q) {
    elemen *info;
    info = new elemen;
    info->data = data;
    info->next = NULL;

    if ((*Q).first == NULL) {
        (*Q).first = info;
    } else {
        (*Q).last->next = info;
    }
    (*Q).last = info;
    info = NULL;
}


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


void insertSetelah(string target, string dataBaru, queue *Q) {
    if ((*Q).first == NULL) {
        cout << "Queue kosong, tidak bisa insert." << endl;
        return;
    }

    elemen *bantu = (*Q).first;
    while (bantu != NULL) {
        if (bantu->data == target) {
            elemen *baru = new elemen;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;

            
            if (bantu == (*Q).last) {
                (*Q).last = baru;
            }
            return;
        }
        bantu = bantu->next;
    }
    cout << "Elemen '" << target << "' tidak ditemukan." << endl;
}


void CetakQueue(queue Q) {
    if (Q.first != NULL) {
        cout << " MENAMPILKAN QUEUE " << endl;
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke  : " << i << endl;
            cout << "Data       : " << bantu->data << endl;
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

    
    add("A", &Q);
    add("B", &Q);
    add("C", &Q);

    cout << "==================================================" << endl;
    cout << " ANTRIAN AWAL: A -> B -> C " << endl;
    cout << "==================================================" << endl;
    CetakQueue(Q);
    cout << endl;

    
    cout << "==================================================" << endl;
    cout << " (a) Memasukkan D setelah A " << endl;
    cout << "     Hasil yang diharapkan: A -> D -> B -> C" << endl;
    cout << "==================================================" << endl;
    insertSetelah("A", "D", &Q);
    CetakQueue(Q);
    cout << endl;

    
    buatQUkosong(&Q);
    add("A", &Q);
    add("B", &Q);
    add("C", &Q);

    
    cout << "==================================================" << endl;
    cout << " (b) Memasukkan F paling akhir, A B C dihapus " << endl;
    cout << "     Hasil yang diharapkan: F" << endl;
    cout << "==================================================" << endl;
    
    del(&Q); 
    del(&Q); 
    del(&Q); 
    
    add("F", &Q);
    CetakQueue(Q);
    cout << endl;

    
    buatQUkosong(&Q);
    add("A", &Q);
    add("B", &Q);
    add("C", &Q);

    
    cout << "==================================================" << endl;
    cout << " (c) Memasukkan F paling akhir, A B C dihapus " << endl;
    cout << "     Hasil yang diharapkan: F" << endl;
    cout << "==================================================" << endl;
    del(&Q);
    del(&Q); 
    del(&Q); 
    add("F", &Q);
    CetakQueue(Q);
    cout << endl;

    
    buatQUkosong(&Q);
    add("A", &Q);
    add("B", &Q);
    add("C", &Q);

    
    cout << "==================================================" << endl;
    cout << " (d) Memasukkan E setelah B " << endl;
    cout << "     Hasil yang diharapkan: A -> B -> E -> C" << endl;
    cout << "==================================================" << endl;
    insertSetelah("B", "E", &Q);
    CetakQueue(Q);
    cout << endl;

    cout << "==============================================" << endl;
    return 0;
}