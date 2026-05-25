#include <iostream>
using namespace std;

//01. Deklarasi struktur simpul/node
typedef struct node *alamatnode;
typedef struct node {
    char INFO;
    alamatnode RIGHT;
    alamatnode LEFT;
} NODE;

//02. Deklarasi Tree ke simpul/node awal - root
typedef struct {
    NODE* root;
} TREE;

//03. Deklarasi prosedur membuat Tree
void BuatTree(char C, TREE *T) {
    NODE *Baru;
    Baru = new NODE;
    Baru -> INFO  = C;
    Baru -> RIGHT = NULL;
    Baru -> LEFT  = NULL;
    (*T).root = Baru;
}

//04. Deklarasi prosedur menambahkan simpul/node pada sisi kanan Tree
void TambahKanan(char C, NODE *root) {
    if(root -> RIGHT == NULL) {
        NODE *Baru;
        Baru = new NODE;
        Baru -> INFO  = C;
        Baru -> RIGHT = NULL;
        Baru -> LEFT  = NULL;
        root -> RIGHT = Baru;
    }
    else
        cout << "Sub Tree Kanan telah diisi" << endl;
}

//05. Deklarasi prosedur menambahkan simpul/node pada sisi kiri Tree
void TambahKiri(char C, NODE *root) {
    if(root -> LEFT == NULL) {
        NODE *Baru;
        Baru = new NODE;
        Baru -> INFO  = C;
        Baru -> RIGHT = NULL;
        Baru -> LEFT  = NULL;
        root -> LEFT = Baru;
    }
    else
        cout << "Sub Tree Kiri telah diisi" << endl;
}

//06. Deklarasi prosedur mencetak tree secara PreOrder
void CetakTreePreOrder(NODE *root) {
    if(root != NULL) {
        cout << root -> INFO << endl;
        CetakTreePreOrder(root -> LEFT);
        CetakTreePreOrder(root -> RIGHT);
    }
}

//07. Deklarasi prosedur mencetak tree secara InOrder
void CetakTreeInOrder(NODE *root) {
    if(root != NULL) {
        CetakTreeInOrder(root -> LEFT);
        cout << root -> INFO << endl;
        CetakTreeInOrder(root -> RIGHT);
    }
}

//08. Deklarasi prosedur mencetak tree secara PostOrder
void CetakTreePostOrder(NODE *root) {
    if(root != NULL) {
        CetakTreePostOrder(root -> LEFT);
        CetakTreePostOrder(root -> RIGHT);
        cout << root -> INFO << endl;
    }
}

//09. Deklarasi prosedur menghapus semua simpul/node
void HapusSemua(NODE *root) {
    if(root != NULL) {
        HapusSemua(root -> LEFT);
        HapusSemua(root -> RIGHT);
        delete root;
    }
}

//10. Deklarasi prosedur menghapus simpul/node pada sisi kanan Tree
void HapusKanan(NODE *root) {
    if(root -> RIGHT != NULL) {
        HapusSemua(root -> RIGHT);
        root -> RIGHT = NULL;
    }
}

//11. Deklarasi prosedur menghapus simpul/node pada sisi kiri Tree
void HapusKiri(NODE *root) {
    if(root -> LEFT != NULL) {
        HapusSemua(root -> LEFT);
        root -> LEFT = NULL;
    }
}

//12. Deklarasi prosedur meng-copy biner satu ke biner lainnya
void CopyTree(NODE *root1, NODE **root2) {
    if(root1 != NULL) {
        (*root2) = new NODE;
        (*root2) -> INFO  = root1 -> INFO;
        (*root2) -> LEFT  = NULL;
        (*root2) -> RIGHT = NULL;
        if(root1 -> LEFT != NULL) {
            CopyTree(root1 -> LEFT,  &(*root2) -> LEFT);
        }
        if(root1 -> RIGHT != NULL) {
            CopyTree(root1 -> RIGHT, &(*root2) -> RIGHT);
        }
    }
}

//13. Deklarasi mengembalikan nilai true apabila 2 buah tree biner merupakan tree biner yang sama
bool isEqual(NODE *root1, NODE *root2) {
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;
    if(root1 -> INFO != root2 -> INFO) return false;
    return isEqual(root1 -> LEFT,  root2 -> LEFT) &&
           isEqual(root1 -> RIGHT, root2 -> RIGHT);
}

//14. Menu Utama
int main() {
    TREE Tree1;
    BuatTree('X', &Tree1);
    TambahKiri ('Y', Tree1.root);
    TambahKanan('Z', Tree1.root);
    TREE Tree2;
    Tree2.root = NULL;
    CopyTree(Tree1.root, &Tree2.root);
    cout << "Tahap 1: Pengecekan Awal" << endl;
    if(isEqual(Tree1.root, Tree2.root))
        cout << "--> Tree1 dan Tree2 adalah SAMA." << endl;
    else
        cout << "--> Tree1 dan Tree2 BERBEDA." << endl;
    cout << endl;
    cout << "Menambahkan 'W' ke kiri 'Y' pada Tree1..." << endl;
    TambahKiri('W', Tree1.root -> LEFT);  
    cout << endl;
    cout << "Tahap 2: Pengecekan Setelah Modifikasi" << endl;
    if(isEqual(Tree1.root, Tree2.root))
        cout << "--> Tree1 dan Tree2 adalah SAMA." << endl;
    else
        cout << "--> Tree1 dan Tree2 BERBEDA." << endl;

    return 0;
}