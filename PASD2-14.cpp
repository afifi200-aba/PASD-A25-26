#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class Stack {
private:
    string data[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

   
    void push(string item) {
        if (isFull()) {
            cout << "Stack penuh!" << endl;
        } else {
            data[++top] = item;
        }
    }

   
    string pop() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return "";
        }
        return data[top--];
    }

    
    string peek() {
        if (isEmpty()) return "";
        return data[top];
    }

    int getTop() { return top; }

   
    void tampilkan() {
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return;
        }
        cout << "Isi Stack (atas -> bawah):" << endl;
        cout << string(30, '-') << endl;
        for (int i = top; i >= 0; i--) {
            cout << "| " << data[i] << endl;
        }
        cout << string(30, '-') << endl;
        cout << endl;
    }

   
    void insertAt(int pos, string item) {
        if (isFull()) {
            cout << "Stack penuh!" << endl;
            return;
        }
  
        for (int i = top; i >= pos; i--) {
            data[i + 1] = data[i];
        }
        data[pos] = item;
        top++;
    }

  
    int findIndex(string item) {
        for (int i = 0; i <= top; i++) {
            if (data[i] == item) return i;
        }
        return -1;
    }
};

int main() {
    Stack s;

  
    cout << "======================================" << endl;
    cout << "   PROGRAM STACK - DATA OS" << endl;
    cout << "======================================" << endl;

    s.push("Iphone");
    s.push("Windows");
    s.push("Mac");
    s.push("Symbian");
    s.push("Maemo");

    cout << "\n[Stack Awal]" << endl;
    s.tampilkan();

   
    cout << "a. Memasukkan 'Iphone 5' di atas 'Iphone'" << endl;
    int idxIphone = s.findIndex("Iphone");
    s.insertAt(idxIphone + 1, "Iphone 5");
    s.tampilkan();

   
    cout << "b. Menambahkan 'Windows Phone' di atas 'Windows'" << endl;
    int idxWin = s.findIndex("Windows");
    s.insertAt(idxWin + 1, "Windows Phone");
    s.tampilkan();

   
    cout << "c. Menambahkan 'SnowLeopard' setelah 'Mac'" << endl;
    int idxMac = s.findIndex("Mac");
    s.insertAt(idxMac + 1, "SnowLeopard");
    s.tampilkan();

    
    cout << "d. Menambahkan 'Symbian Belle' setelah 'Symbian'" << endl;
    int idxSymbian = s.findIndex("Symbian");
    s.insertAt(idxSymbian + 1, "Symbian Belle");
    s.tampilkan();

   
    cout << "e. Menambahkan 'Maemo 4' paling bawah" << endl;
    s.insertAt(0, "Maemo 4");
    s.tampilkan();

    return 0;
}