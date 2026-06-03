#include <iostream>
using namespace std;

typedef struct node *alamatnode;
typedef struct node {
    char INFO;
    alamatnode RIGHT;
    alamatnode LEFT;
} NODE;

typedef struct {
    NODE* root;
} TREE;

void BuatTree(char C, TREE *T) {
    NODE *Baru;
    Baru = new NODE;
    Baru->INFO  = C;
    Baru->RIGHT = NULL;
    Baru->LEFT  = NULL;
    (*T).root   = Baru;
}

void TambahKanan(char C, NODE *root) {
    if (root->RIGHT == NULL) {
        NODE *Baru = new NODE;
        Baru->INFO  = C;
        Baru->RIGHT = NULL;
        Baru->LEFT  = NULL;
        root->RIGHT = Baru;
    } else {
        cout << "Sub Tree Kanan telah diisi" << endl;
    }
}

void TambahKiri(char C, NODE *root) {
    if (root->LEFT == NULL) {
        NODE *Baru = new NODE;
        Baru->INFO  = C;
        Baru->RIGHT = NULL;
        Baru->LEFT  = NULL;
        root->LEFT  = Baru;
    } else {
        cout << "Sub Tree Kiri telah diisi" << endl;
    }
}

void CetakTreePreOrder(NODE *root) {
    if (root != NULL) {
        cout << root->INFO << endl;
        CetakTreePreOrder(root->LEFT);
        CetakTreePreOrder(root->RIGHT);
    }
}

void CetakTreeInOrder(NODE *root) {
    if (root != NULL) {
        CetakTreeInOrder(root->LEFT);
        cout << root->INFO << endl;
        CetakTreeInOrder(root->RIGHT);
    }
}

void CetakTreePostOrder(NODE *root) {
    if (root != NULL) {
        CetakTreePostOrder(root->LEFT);
        CetakTreePostOrder(root->RIGHT);
        cout << root->INFO << endl;
    }
}

int main() {
    TREE T;
    char rootData;
    int jumlahDaun;

    cout << "============================================" << endl;
    cout << "   BINARY TREE - Input dari User           " << endl;
    cout << "============================================" << endl;
    cout << "Masukkan data ROOT (1 karakter): ";
    cin  >> rootData;

    BuatTree(rootData, &T);
    cout << "Masukkan jumlah daun/leaf (maks 6): ";
    cin  >> jumlahDaun;
    if (jumlahDaun > 6) jumlahDaun = 6;
    char daun;
    NODE* level1[2] = {NULL, NULL};
    int filled = 0;

    for (int i = 0; i < jumlahDaun; i++) {
        cout << "Masukkan data daun ke-" << (i+1) << ": ";
        cin  >> daun;

        if (i == 0) {
            TambahKiri(daun, T.root);
            level1[0] = T.root->LEFT;
        } else if (i == 1) {
            TambahKanan(daun, T.root);
            level1[1] = T.root->RIGHT;
        } else if (i == 2 && level1[0] != NULL) {
            TambahKiri(daun, level1[0]);
        } else if (i == 3 && level1[0] != NULL) {
            TambahKanan(daun, level1[0]);
        } else if (i == 4 && level1[1] != NULL) {
            TambahKiri(daun, level1[1]);
        } else if (i == 5 && level1[1] != NULL) {
            TambahKanan(daun, level1[1]);
        }
    }

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~  PREORDER  ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakTreePreOrder(T.root);

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~  INORDER   ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakTreeInOrder(T.root);

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~  POSTORDER  ~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakTreePostOrder(T.root);

    return 0;
}