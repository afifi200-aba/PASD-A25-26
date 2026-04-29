#include <iostream>
#include <stack>
#include <string>
using namespace std;


void tampilStack(stack<string> s) {
    if (s.empty()) {
        cout << "Stack kosong!" << endl;
        return;
    }

    string arr[100];
    int n = 0;

    while (!s.empty()) {
        arr[n] = s.top();
        s.pop();
        n++;
    }

    cout << "Isi Stack (atas ke bawah): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Isi Stack (bawah ke atas): ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "       PROGRAM STACK - PASD3-6.cpp     " << endl;
    cout << "========================================" << endl;

   
    stack<string> stackAwal;
    stackAwal.push("A");
    stackAwal.push("B");
    stackAwal.push("C");

    cout << "\nStack Awal:" << endl;
    tampilStack(stackAwal);

    
    cout << "\n----------------------------------------" << endl;
    cout << "a. Masukkan D setelah A:" << endl;
    cout << "----------------------------------------" << endl;

    stack<string> stackA = stackAwal;
    stack<string> tempA;

    while (stackA.top() != "A") {
        tempA.push(stackA.top());
        stackA.pop();
    }
    stackA.push("D");
    while (!tempA.empty()) {
        stackA.push(tempA.top());
        tempA.pop();
    }

    tampilStack(stackA);

    
    cout << "\n----------------------------------------" << endl;
    cout << "b. Masukkan E setelah B:" << endl;
    cout << "----------------------------------------" << endl;

    stack<string> stackB = stackAwal;
    stack<string> tempB;

    while (stackB.top() != "B") {
        tempB.push(stackB.top());
        stackB.pop();
    }
    stackB.push("E");
    while (!tempB.empty()) {
        stackB.push(tempB.top());
        tempB.pop();
    }

    tampilStack(stackB);

    
    cout << "\n----------------------------------------" << endl;
    cout << "c. Masukkan F paling bawah (A,B,C hilang):" << endl;
    cout << "----------------------------------------" << endl;

    stack<string> stackC;
    stackC.push("F");

    tampilStack(stackC);

   
    cout << "\n----------------------------------------" << endl;
    cout << "d. Masukkan F paling bawah (A,B,C masih ada):" << endl;
    cout << "----------------------------------------" << endl;

    stack<string> stackD = stackAwal;
    stack<string> tempD;

    while (!stackD.empty()) {
        tempD.push(stackD.top());
        stackD.pop();
    }
    stackD.push("F");
    while (!tempD.empty()) {
        stackD.push(tempD.top());
        tempD.pop();
    }

    tampilStack(stackD);

    cout << "\n========================================" << endl;
    cout << "           PROGRAM SELESAI             " << endl;
    cout << "========================================" << endl;

    return 0;
}