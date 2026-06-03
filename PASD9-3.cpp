#include <iostream>
#include <string>
using namespace std;

struct NODE {
    string INFO;
    NODE*  LEFT;
    NODE*  RIGHT;
};

struct TREE {
    NODE* root;
};

NODE* buatNode(string data) {
    NODE* n   = new NODE;
    n->INFO   = data;
    n->LEFT   = NULL;
    n->RIGHT  = NULL;
    return n;
}

void inisialisasi(TREE &T) {
    T.root = NULL;
}

void preOrder(NODE* root) {
    if (root != NULL) {
        cout << "  " << root->INFO << endl;
        preOrder(root->LEFT);
        preOrder(root->RIGHT);
    }
}

void inOrder(NODE* root) {
    if (root != NULL) {
        inOrder(root->LEFT);
        cout << "  " << root->INFO << endl;
        inOrder(root->RIGHT);
    }
}

void postOrder(NODE* root) {
    if (root != NULL) {
        postOrder(root->LEFT);
        postOrder(root->RIGHT);
        cout << "  " << root->INFO << endl;
    }
}

void tampilkanSemua(TREE &T) {
    cout << "  --------------------------------" << endl;
    cout << "  PreOrder   : " << endl;
    preOrder(T.root);
    cout << "  --------------------------------" << endl;
    cout << "  InOrder    : " << endl;
    inOrder(T.root);
    cout << "  --------------------------------" << endl;
    cout << "  PostOrder  : " << endl;
    postOrder(T.root);
    cout << "  --------------------------------" << endl;
}

NODE* cariNode(NODE* root, string target) {
    if (root == NULL) return NULL;
    if (root->INFO == target) return root;
    NODE* hasil = cariNode(root->LEFT, target);
    if (hasil != NULL) return hasil;
    return cariNode(root->RIGHT, target);
}

void gantiNode(NODE* root, string lama, string baru) {
    NODE* target = cariNode(root, lama);
    if (target != NULL) {
        cout << "  >> Menghapus \"" << lama << "\" dan memasukkan \""
             << baru << "\"" << endl;
        target->INFO = baru;
    } else {
        cout << "  >> Node \"" << lama << "\" tidak ditemukan!" << endl;
    }
}

void bangunTreeAwal(TREE &T) {
 
    T.root              = buatNode("Maemo");
    T.root->LEFT        = buatNode("Symbian");
    T.root->RIGHT       = buatNode("Mac");
    T.root->LEFT->LEFT  = buatNode("Windows");
    T.root->LEFT->RIGHT = buatNode("Iphone");
    T.root->RIGHT->LEFT = buatNode("IOS");
}

int main() {
    TREE T;
    inisialisasi(T);
    bangunTreeAwal(T);

    cout << "============================================" << endl;
    cout << "  BINARY TREE - String Data                " << endl;
    cout << "  Maemo, Symbian, Mac, Windows, Iphone, IOS" << endl;
    cout << "============================================" << endl;

    cout << "\n[TREE AWAL]" << endl;
    tampilkanSemua(T);

    cout << "n[a] Memasukkan \"Iphone 5\" setelah menghapus \"Iphone\"" << endl;
    gantiNode(T.root, "Iphone", "Iphone 5");
    tampilkanSemua(T);

    cout << "n[b] Menambahkan \"Windows Phone\" setelah menghapus \"Windows\"" << endl;
    gantiNode(T.root, "Windows", "Windows Phone");
    tampilkanSemua(T);

    cout << "n[c] Menambahkan \"SnowLeopard\" setelah menghapus \"Mac\"" << endl;
    gantiNode(T.root, "Mac", "SnowLeopard");
    tampilkanSemua(T);

    cout << "n[d] Menambahkan \"Symbian Belle\" setelah menghapus \"Symbian\"" << endl;
    gantiNode(T.root, "Symbian", "Symbian Belle");
    tampilkanSemua(T);

    cout << "n[e] Menambahkan \"Maemo 4\" sebagai node paling awal (root baru)" << endl;
    cout << "  >> Membuat root baru \"Maemo 4\", tree lama menjadi subtree kanan" << endl;
    NODE* rootBaru   = buatNode("Maemo 4");
    rootBaru->RIGHT  = T.root;  
    T.root           = rootBaru;
    tampilkanSemua(T);

    return 0;
}