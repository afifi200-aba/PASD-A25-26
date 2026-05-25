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
    Baru -> INFO = C;
    Baru -> RIGHT = NULL;
    Baru -> LEFT = NULL;
    (*T).root = Baru;
}

//04. Deklarasi prosedur menambahkan simpul/node pada sisi kanan Tree
void TambahKanan(char C, NODE *root) {
    if(root -> RIGHT == NULL) {
        //Apabila sub tree kanan kosong
        NODE *Baru;
        Baru = new NODE;
        Baru -> INFO = C;
        Baru -> RIGHT = NULL;
        Baru -> LEFT = NULL;
        root -> RIGHT = Baru;
    }
    else
        cout << "Sub Tree Kanan telah diisi" << endl;
}

//05. Deklarasi prosedur menambahkan simpul/node pada sisi kiri Tree
void TambahKiri(char C, NODE *root) {
    if(root -> LEFT == NULL) {
        //Apabila sub tree kiri kosong
        NODE *Baru;
        Baru = new NODE;
        Baru -> INFO = C;
        Baru -> RIGHT = NULL;
        Baru -> LEFT = NULL;
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
//12. Deklarasi prosedur meng-copy biner satu ke biner lainnya
void CopyTree(NODE *root1, NODE **root2) {
    if(root1 != NULL) {
        (*root2) = new NODE;
        (*root2) -> INFO = root1 -> INFO;
        if(root1 -> LEFT != NULL) {
            CopyTree(root1 -> LEFT, &(*root2) -> LEFT);
        }
        if(root1 -> RIGHT != NULL) {
            CopyTree(root1 -> RIGHT, &(*root2) -> RIGHT);
        }
    }
}

//13. Deklarasi mengembalikan nilai true apabila 2 buah tree biner merupakan tree biner yang sama
bool isEqual(NODE *root1, NODE *root2) {
    bool Hasil = true;
    if((root1 == NULL) && (root2 != NULL)) {
        //Jika node tree 1 dan tree 2 sama
        if(root1 -> INFO != root2 -> INFO) {
            //Jika node tree 1 dan tree 2 tidak sama
            Hasil = false;
        }
        else {
            //Telusuri simpul selanjutnya
            isEqual(root1 -> LEFT, root2 -> LEFT);
            isEqual(root1 -> RIGHT, root2 -> RIGHT);
        }
    }
    else {
        if((root1 != NULL) || (root2 != NULL)) {
            Hasil = false;
        }
    }
    return Hasil;
}

//14. Menu Utama
int main() {
    TREE T;
    BuatTree('R', &T);
    TambahKiri('S', T.root);
    TambahKanan('U', T.root);
    TambahKiri('V', T.root -> LEFT);
    TambahKanan('W', T.root -> LEFT);
    TambahKiri('Y', T.root -> RIGHT);
    TambahKanan('Z', T.root -> RIGHT);

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~  PREORDER   ~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
    CetakTreePreOrder(T.root);
    cout << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~~  INORDER    ~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
    CetakTreeInOrder(T.root);
    cout << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " ~~~~~  POSTORDER   ~~~~~~ " << endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
    CetakTreePostOrder(T.root);
    cout << endl;
}