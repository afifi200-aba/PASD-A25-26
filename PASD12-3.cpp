#include <iostream>
using namespace std;

typedef struct simpul *altsimpul;
typedef struct jalur  *altjlr;

typedef struct simpul {
    char     kontainersimpul;
    altsimpul nextsimpul;
    altjlr    arc;
} cansimpul;

typedef struct jalur {
    int      kontainerjalur;
    altjlr   nextjalur;
    altsimpul tujuan;
} canjalur;

typedef struct {
    altsimpul first;
} graph;

void  simpulbaru(graph *G);
void  tambahsimpul(char c, graph *G);
void  tambahjalur(altsimpul awal, altsimpul tujuan, int beban);
altsimpul findsimpul(char c, graph G);
void  delJalur(char ctujuan, altsimpul awal);
void  tampilGraph(graph G);

void simpulbaru(graph *G) {
    (*G).first = NULL;
}

void tambahsimpul(char c, graph *G) {
    altsimpul baru;
    baru = new cansimpul;
    baru->kontainersimpul = c;
    baru->nextsimpul = NULL;
    baru->arc = NULL;

    if ((*G).first == NULL) {
        (*G).first = baru; 
    } else { 
        altsimpul last = (*G).first;
        while (last->nextsimpul != NULL) {
            last = last->nextsimpul;
        }
        last->nextsimpul = baru;
    }
}

void tambahjalur(altsimpul awal, altsimpul tujuan, int beban) {
    altjlr baru;
    baru = new canjalur;
    baru->kontainerjalur = beban;
    baru->nextjalur = NULL;
    baru->tujuan = tujuan;

    if (awal->arc == NULL) { 
        awal->arc = baru;
    } else { 
        altjlr last = awal->arc;
        while (last->nextjalur != NULL) {
            last = last->nextjalur;
        }
        last->nextjalur = baru;
    }
}

altsimpul findsimpul(char c, graph G) {
    altsimpul hasil = NULL;
    altsimpul bantu = G.first;
    bool ketemu = false;

    while ((bantu != NULL) && (ketemu == false)) {
        if (bantu->kontainersimpul == c) {
            hasil = bantu;
            ketemu = true;
        } else {
            bantu = bantu->nextsimpul;
        }
    }
    return hasil;
}

void delJalur(char ctujuan, altsimpul awal) {
    altjlr hapus = awal->arc;
    altjlr sebelum = NULL;

    while (hapus != NULL) {
        if (hapus->tujuan->kontainersimpul == ctujuan) {
            if (sebelum == NULL)
                awal->arc = hapus->nextjalur;
            else
                sebelum->nextjalur = hapus->nextjalur;
            delete hapus;
            return;
        }
        sebelum = hapus;
        hapus = hapus->nextjalur;
    }
    cout << "Jalur tidak ditemukan" << endl;
}

void tampilGraph(graph G) {
    altsimpul s = G.first;
    while (s != NULL) {
        cout << "Simpul " << s->kontainersimpul << " -> ";
        altjlr j = s->arc;
        while (j != NULL) {
            cout << j->tujuan->kontainersimpul << "(" << j->kontainerjalur << ") ";
            j = j->nextjalur;
        }
        cout << endl;
        s = s->nextsimpul;
    }
}

int main() {
    graph G;
    simpulbaru(&G);

    tambahsimpul('A', &G);
    tambahsimpul('B', &G);
    tambahsimpul('C', &G);
    tambahsimpul('D', &G);

    altsimpul a = findsimpul('A', G);
    altsimpul b = findsimpul('B', G);
    altsimpul c = findsimpul('C', G);
    altsimpul d = findsimpul('D', G);

    tambahjalur(a, b, 10);
    tambahjalur(a, c, 15);
    tambahjalur(b, d, 20);
    tambahjalur(c, d, 25);

    cout << "Graph sebelum delJalur:" << endl;
    tampilGraph(G);

    delJalur('C', a); 

    cout << "Graph setelah delJalur (A->C dihapus):" << endl;
    tampilGraph(G);

    cin.get();
}