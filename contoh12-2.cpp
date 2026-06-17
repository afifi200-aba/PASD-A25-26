#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Variabel global
int a[100][100];  
int q[100];       
int visited[100]; 
int n;            
int f = 0;        
int r = -1;       

// Fungsi Utama Algoritma BFS 
void bfs(int v) {
    for (int i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            visited[i] = 1; 
            q[++r] = i;     
        }
    }
    if (f <= r) {
        bfs(q[f++]); 
    }
}

int main() {
    int v; 
    
    cout << "=== PROGRAM BFS INTERAKTIF ===" << endl;
    cout << "Masukkan Jumlah Vertex/Node: "; cin >> n; 

    for (int i = 1; i <= n; i++) {
        q[i] = 0;       
        visited[i] = 0; 
    }

    cout << "\n--- Masukkan Data Matriks [" << n << "x" << n << "] ---" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "Input Baris " << i << ", Kolom " << j << " (0 atau 1): ";
            cin >> a[i][j]; 
        }
    }

    cout << "\nMasukkan Vertex Awal Penelusuran: "; cin >> v; 
    

    visited[v] = 1; 
    q[++r] = v;     
    f++;            

    bfs(v); 

    cout << "\nNode Yang Dapat Dicapai: ";
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << i << " "; 
        }
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            cout << "\nBFS - Tidak Semua Node Dapat Dijangkau";
            break; 
        }
    }

    cout << endl;
    return 0;
}