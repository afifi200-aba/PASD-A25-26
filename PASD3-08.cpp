#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    string nama;
    int jumlah;

public:
    Stack(string n) {
        top = nullptr;
        nama = n;
        jumlah = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    
    void push(int nilai) {
        Node* newNode = new Node();
        newNode->data = nilai;
        newNode->next = top;
        top = newNode;
        jumlah++;
        cout << "[PUSH] " << nilai << " dimasukkan ke " << nama << endl;
    }

    
    int pop() {
        if (isEmpty()) {
            cout << "[ERROR] " << nama << " kosong! Tidak bisa POP." << endl;
            return -1;
        }
        Node* temp = top;
        int nilai = top->data;
        top = top->next;
        delete temp;
        jumlah--;
        cout << "[POP] " << nilai << " dikeluarkan dari " << nama << endl;
        return nilai;
    }

    
    int peek() {
        if (isEmpty()) {
            cout << "[ERROR] " << nama << " kosong!" << endl;
            return -1;
        }
        return top->data;
    }

    
    void tampilkan() {
        cout << "\n+------------------------+" << endl;
        cout << "|  " << nama;
        int pad = 22 - (int)nama.length();
        for (int i = 0; i < pad; i++) cout << " ";
        cout << "|" << endl;
        cout << "+------------------------+" << endl;

        if (isEmpty()) {
            cout << "|      [ KOSONG ]        |" << endl;
        } else {
            Node* curr = top;
            int pos = jumlah;
            while (curr != nullptr) {
                string angka = to_string(curr->data);
                cout << "|  [" << pos << "]  -->  " << angka;
                int sp = 13 - (int)angka.length();
                for (int i = 0; i < sp; i++) cout << " ";
                cout << "|" << endl;
                curr = curr->next;
                pos--;
            }
        }
        cout << "+------------------------+" << endl;
        cout << "  Jumlah elemen: " << jumlah << endl;
    }

    string getNama() { return nama; }
    int getJumlah() { return jumlah; }
};

int main() {
    Stack tumpukan1("Tumpukan 1");
    Stack tumpukan2("Tumpukan 2");
    Stack tumpukan3("Tumpukan 3");

    int pilihan, tumpPilih, nilai;

    cout << "============================================" << endl;
    cout << "   PROGRAM STACK - TUMPUKAN (LINKED LIST)  " << endl;
    cout << "            Nama File: PASD3-8.cpp         " << endl;
    cout << "============================================" << endl;

    
    cout << "\n[INFO] Mengisi Tumpukan 1 dengan data awal..." << endl;
    tumpukan1.push(3);
    tumpukan1.push(2);
    tumpukan1.push(1);

    cout << "\n=== KONDISI AWAL ===" << endl;
    tumpukan1.tampilkan();
    tumpukan2.tampilkan();
    tumpukan3.tampilkan();

    do {
        cout << "\n============================================" << endl;
        cout << "                   MENU                    " << endl;
        cout << "============================================" << endl;
        cout << "  1. PUSH  (Masukkan elemen ke tumpukan)   " << endl;
        cout << "  2. POP   (Keluarkan elemen dari tumpukan)" << endl;
        cout << "  3. PEEK  (Lihat elemen teratas)          " << endl;
        cout << "  4. TAMPILKAN semua tumpukan              " << endl;
        cout << "  0. KELUAR                                " << endl;
        cout << "============================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        Stack* target = nullptr;

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Pilih Tumpukan (1/2/3): ";
            cin >> tumpPilih;
            if      (tumpPilih == 1) target = &tumpukan1;
            else if (tumpPilih == 2) target = &tumpukan2;
            else if (tumpPilih == 3) target = &tumpukan3;
            else cout << "[ERROR] Tumpukan tidak valid!" << endl;
        }

        switch (pilihan) {
            case 1:
                if (target) {
                    cout << "Masukkan nilai: ";
                    cin >> nilai;
                    target->push(nilai);
                    target->tampilkan();
                }
                break;

            case 2:
                if (target) {
                    target->pop();
                    target->tampilkan();
                }
                break;

            case 3:
                if (target) {
                    int topVal = target->peek();
                    if (topVal != -1)
                        cout << "[PEEK] Elemen teratas " << target->getNama()
                             << ": " << topVal << endl;
                }
                break;

            case 4:
                cout << "\n=== ISI SEMUA TUMPUKAN ===" << endl;
                tumpukan1.tampilkan();
                tumpukan2.tampilkan();
                tumpukan3.tampilkan();
                break;

            case 0:
                cout << "\nProgram selesai. Sampai jumpa!\n" << endl;
                break;

            default:
                cout << "[ERROR] Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}