#include<iostream>
using namespace std;

struct CanBTree // Deklarasi simpul
{
    int *d;
    CanBTree **CanAnakPointer;
    bool l;
    int n;
}*r = NULL, *np = NULL, *x = NULL;

CanBTree* init() // Membuat Simpul
{
    int i;
    np = new CanBTree;
    np->d = new int[6]; // menyiapkan hanya 6 data
    np->CanAnakPointer = new CanBTree *[7];
    np->l = true;
    np->n = 0;
    for (i = 0; i < 7; i++) {
        np->CanAnakPointer[i] = NULL;
    }
    return np;
}

void PohonB(CanBTree *p) // Proses BTree
{
    cout << endl;
    int i;
    for (i = 0; i < p->n; i++) {
        if (p->l == false) {
            PohonB(p->CanAnakPointer[i]);
        }
        cout << " " << p->d[i];
    }
    if (p->l == false) {
        PohonB(p->CanAnakPointer[i]);
    }
    // cout << endl;
}

void Urut(int *p, int n) // Pengurutan dgn tree
{
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = i; j <= n; j++) {
            if (p[i] > p[j]) {
                t    = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

int PecahAnak(CanBTree *x, int i) {
    int j, mid;
    CanBTree *np1, *np3, *y;
    np3 = init(); // membuat node baru
    np3->l = true;
    if (i == -1) {
        mid = x->d[2]; // mencari titik tengah
        x->d[2] = 0;
        x->n--;

        // Pindahkan elemen kanan ke np3
        for (j = 3; j < 6; j++) {
            np3->d[j - 3] = x->d[j];
            np3->CanAnakPointer[j - 3] = x->CanAnakPointer[j];
            np3->n++;
            x->d[j] = 0;
            x->n--;
        }

        for (j = 0; j < 6; j++) {
            x->CanAnakPointer[j] = NULL;
        }

        np1 = init();
        np1->l = false;
        np1->d[0] = mid;
        np1->CanAnakPointer[np1->n]     = x;
        np1->CanAnakPointer[np1->n + 1] = np3;
        np1->n++;
        r = np1;
    } else {
        y = x->CanAnakPointer[i];
        mid = y->d[2];
        y->d[2] = 0;
        y->n--;

        for (j = 3; j < 6; j++) {
            np3->d[j - 3] = y->d[j];
            np3->n++;
            y->d[j] = 0;
            y->n--;
        }

        x->CanAnakPointer[i + 1] = y;
        x->CanAnakPointer[i + 1] = np3;
    }
    return mid;
}

void Sisip(int a) {
    int i, t;
    x = r;
    if (x == NULL) {
        r = init();
        x = r;
    } else {
        if (x->l == true && x->n == 6) {
            t = PecahAnak(x, -1);
            x = r;
            for (i = 0; i < (x->n); i++) {
                if ((a > x->d[i]) && (a < x->d[i + 1])) {
                    i++;
                    break;
                } else if (a < x->d[0]) {
                    break;
                } else {
                    continue;
                }
            }
            x = x->CanAnakPointer[i];
        } else {
            while (x->l == false) {
                for (i = 0; i < (x->n); i++) {
                    if ((a > x->d[i]) && (a < x->d[i + 1])) {
                        i++;
                        break;
                    } else if (a < x->d[0]) {
                        break;
                    } else {
                        continue;
                    }
                }

                if ((x->CanAnakPointer[i])->n == 6) {
                    t = PecahAnak(x, i);
                    x->d[x->n] = t;
                    x->n++;
                    continue;
                } else {
                    x = x->CanAnakPointer[i];
                }
            }
        }
    }
    x->d[x->n] = a;
    Urut(x->d, x->n);
    x->n++;
}

int main() {
    int i, n, t;
    cout << "Masukkan Jumlah Elemen Yang Akan Diinput = ";cin >> n;
    cout << endl;

    for (i = 0; i < n; i++) {
        cout << "Masukkan Isi Elemen = ";
        cin >> t;
        Sisip(t);
    }

    cout << endl;
    cout << endl;
    cout << "HASIL PENGURUTAN MENGGUNAKAN BTREE" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    PohonB(r);
    cout << endl;

    return 0;
}