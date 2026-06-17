#include<iostream>
#include<string>
using namespace std;

class BTreeNode {
    char *Kunci;   
    int  t;        
    BTreeNode **C; 
    int  n;        
    bool leaf;     

public:
    BTreeNode(int _t, bool _leaf);

    void traverse();
    BTreeNode* search(char k);
    void SisipTdkPenuh(char k);
    void splitAnak(int i, BTreeNode *y);

    friend class BTree;
};

class BTree {
    BTreeNode *root;
    int t;

public:
    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    void traverse() {
        if (root != NULL) root->traverse();
    }

    BTreeNode* search(char k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    void Sisip(char k);
};

BTreeNode::BTreeNode(int t1, bool leaf1) {
    t    = t1;
    leaf = leaf1;
    Kunci = new char[2 * t - 1];
    C     = new BTreeNode*[2 * t];
    n     = 0;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << Kunci[i];
    }
    if (leaf == false)
        C[i]->traverse();
}

BTreeNode* BTreeNode::search(char k) {
    int i = 0;
    while (i < n && k > Kunci[i])
        i++;
    if (Kunci[i] == k)
        return this;
    if (leaf == true)
        return NULL;
    return C[i]->search(k);
}

void BTree::Sisip(char k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->Kunci[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitAnak(0, root);
            int i = 0;
            if (s->Kunci[0] < k)
                i++;
            s->C[i]->SisipTdkPenuh(k);
            root = s;
        } else {
            root->SisipTdkPenuh(k);
        }
    }
}

void BTreeNode::SisipTdkPenuh(char k) {
    int i = n - 1;
    if (leaf == true) {
        while (i >= 0 && Kunci[i] > k) {
            Kunci[i + 1] = Kunci[i];
            i--;
        }
        Kunci[i + 1] = k;
        n = n + 1;
    } else {
        while (i >= 0 && Kunci[i] > k)
            i--;
        if (C[i + 1]->n == 2 * t - 1) {
            splitAnak(i + 1, C[i + 1]);
            if (Kunci[i + 1] < k)
                i++;
        }
        C[i + 1]->SisipTdkPenuh(k);
    }
}

void BTreeNode::splitAnak(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->Kunci[j] = y->Kunci[j + t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];
    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        Kunci[j + 1] = Kunci[j];
    Kunci[i] = y->Kunci[t - 1];

    n = n + 1;
}

int main() {
    int  jumlah;
    char huruf;
    char cariHuruf;

    cout << "=====================================" << endl;
    cout << "  BTREE - DATA HURUF DENGAN INPUTAN  " << endl;
    cout << "        (PASD10-04 - Contoh 1)        " << endl;
    cout << "=====================================" << endl;

    BTree t(3); 

    cout << "\nMasukkan jumlah huruf yang akan diinput: ";
    cin >> jumlah;

    cout << "\nMasukkan huruf satu per satu:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "  Huruf ke-" << (i + 1) << " = ";
        cin >> huruf;
        t.Sisip(huruf);
    }

    cout << "\n-------------------------------------" << endl;
    cout << "  Pohon dengan menggunakan B-TREE    " << endl;
    cout << "  ------------ m = 3 -------------- " << endl;
    cout << "-------------------------------------" << endl;
    t.traverse();
    cout << endl;

    cout << "\nMasukkan huruf yang ingin dicari: ";
    cin >> cariHuruf;
    (t.search(cariHuruf) != NULL)
        ? cout << "Huruf yang dicari '" << cariHuruf << "' = Ditemukan" << endl
        : cout << "Huruf yang dicari '" << cariHuruf << "' = Tidak Ditemukan" << endl;

    return 0;
}