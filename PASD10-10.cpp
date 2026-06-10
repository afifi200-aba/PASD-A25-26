#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct CanBTree { 
    char d[6][50];           
    CanBTree **CanAnakPointer;
    bool l;
    int n;
}*r = NULL, *np = NULL, *x = NULL;

CanBTree* init() {
    int i;
    np = new CanBTree;
    np->CanAnakPointer = new CanBTree *[7];
    np->l = true;
    np->n = 0;
    for (i = 0; i < 6; i++)
        strcpy(np->d[i], "");
    for (i = 0; i < 7; i++)
        np->CanAnakPointer[i] = NULL;
    return np;
}

void PohonB(CanBTree *p) {
    cout << endl;
    int i;
    for (i = 0; i < p->n; i++) {
        if (p->l == false)
            PohonB(p->CanAnakPointer[i]);
        cout << " " << p->d[i];
    }
    if (p->l == false)
        PohonB(p->CanAnakPointer[i]);
}

void Urut(CanBTree *p) {
    int i, j;
    char t[50];
    for (i = 0; i < p->n; i++) {
        for (j = i; j <= p->n; j++) {
            if (strcmp(p->d[i], p->d[j]) > 0) {
                strcpy(t,      p->d[i]);
                strcpy(p->d[i], p->d[j]);
                strcpy(p->d[j], t);
            }
        }
    }
}

int PecahAnak(CanBTree *x, int i) {
    int j;
    char mid[50];
    CanBTree *np1, *np3, *y;
    np3 = init();       
    np3->l = true;

    if (i == -1) {
		strcpy(mid, x->d[2]);   
        strcpy(x->d[2], "");
        x->n--;

        np1 = init();
        np1->l = false;
        x->l  = true;
		for (j = 3; j < 6; j++) {
            strcpy(np3->d[j - 3], x->d[j]);
            np3->CanAnakPointer[j - 3] = x->CanAnakPointer[j];
            np3->n++;
            strcpy(x->d[j], "");
            x->n--;
        }
		for (j = 0; j < 6; j++)
            x->CanAnakPointer[j] = NULL;
        strcpy(np1->d[0], mid);
        np1->CanAnakPointer[np1->n]     = x;
        np1->CanAnakPointer[np1->n + 1] = np3;
        np1->n++;
        r = np1;
    } else {
        y = x->CanAnakPointer[i];
        strcpy(mid, y->d[2]);
        strcpy(y->d[2], "");
        y->n--;
		for (j = 3; j < 6; j++) {
            strcpy(np3->d[j - 3], y->d[j]);
            np3->n++;
            strcpy(y->d[j], "");
            y->n--;
        }
        x->CanAnakPointer[i]     = y;
        x->CanAnakPointer[i + 1] = np3;
    }
    return 2; 
}
void Sisip(const char* a) {
    int i, t;
    x = r;

    if (x == NULL) {
        r = init();
        x = r;
    } else {
        if (x->l == true && x->n == 6) {
          
            t = PecahAnak(x, -1);
            x = r;
            for (i = 0; i < x->n; i++) {
                if (strcmp(a, x->d[i]) > 0 && strcmp(a, x->d[i + 1]) < 0) {
                    i++;
                    break;
                } else if (strcmp(a, x->d[0]) < 0) {
                    break;
                } else {
                    continue;
                }
            }
            x = x->CanAnakPointer[i];
        } else {
          
            while (x->l == false) {
                for (i = 0; i < x->n; i++) {
                    if (strcmp(a, x->d[i]) > 0 && strcmp(a, x->d[i + 1]) < 0) {
                        i++;
                        break;
                    } else if (strcmp(a, x->d[0]) < 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                if ((x->CanAnakPointer[i])->n == 6) {
					PecahAnak(x, i);
                    strcpy(x->d[x->n], x->d[t]);
                    x->n++;
                    continue;
                } else {
                    x = x->CanAnakPointer[i];
                }
            }
        }
    }

    strcpy(x->d[x->n], a);
    Urut(x);        
    x->n++;
}

int main() {
		const char* kata[] = {
        "Mangga",   "Apel",     "Jeruk",   "Pisang",  "Durian",
        "Semangka", "Melon",    "Anggur",  "Nanas",   "Pepaya",
        "Rambutan", "Salak",    "Jambu",   "Alpukat", "Belimbing"
    };
    int jumlah = 15;

    for (int i = 0; i < jumlah; i++)
        Sisip(kata[i]);

    cout << endl;
    cout << "HASIL PENGURUTAN MENGGUNAKAN BTREE" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    PohonB(r);
    cout << endl;

    return 0;
}