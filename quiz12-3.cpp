#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Fungsi BFS sekaligus menghitung jarak dari simpul awal
void BFS(vector<vector<int>> &graf, int start, vector<char> &namaSimpul) {
    int n = graf.size();
    vector<bool> visited(n, false);
    vector<int> jarak(n, -1); // -1 artinya belum/tidak terjangkau
    queue<int> q;

    visited[start] = true;
    jarak[start] = 0;
    q.push(start);

    cout << "\nHasil BFS :\n";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << namaSimpul[u] << " ";

        for (int v : graf[u]) {
            if (!visited[v]) {
                visited[v] = true;
                jarak[v] = jarak[u] + 1;
                q.push(v);
            }
        }
    }
    cout << endl;

    // Tampilkan jarak dari simpul awal ke setiap simpul
    cout << "\nJarak dari simpul " << namaSimpul[start] << " :\n\n";
    for (int i = 0; i < n; i++) {
        cout << namaSimpul[i] << " = ";
        if (jarak[i] == -1)
            cout << "Tidak Terjangkau" << endl;
        else
            cout << jarak[i] << endl;
    }
}

int main() {
    int n, e;
    cout << "Masukkan jumlah simpul : ";
    cin >> n;

    vector<char> namaSimpul(n);
    cout << "Masukkan nama simpul:\n";
    for (int i = 0; i < n; i++) {
        cin >> namaSimpul[i];
    }

    vector<vector<int>> graf(n);
    cout << "Masukkan jumlah hubungan (edge) : ";
    cin >> e;
    cout << "Masukkan hubungan antar simpul:\n";
    for (int i = 0; i < e; i++) {
        char a, b;
        cin >> a >> b;
        int u = -1, v = -1;
        for (int j = 0; j < n; j++) {
            if (namaSimpul[j] == a) u = j;
            if (namaSimpul[j] == b) v = j;
        }
        if (u != -1 && v != -1) {
            graf[u].push_back(v);
            graf[v].push_back(u); // graph tidak berarah
        }
    }

    char awal;
    cout << "Masukkan simpul awal : ";
    cin >> awal;
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (namaSimpul[i] == awal) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        cout << "Simpul tidak ditemukan!\n";
        return 0;
    }

    BFS(graf, start, namaSimpul);

    return 0;
}