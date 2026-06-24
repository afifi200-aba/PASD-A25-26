#include <iostream>
using namespace std;

int main() {
    double L, v;

    cout << "=================================================" << endl;
    cout << " PROGRAM PERHITUNGAN FREKUENSI HARMONIK PIPA ORGANA" << endl;
    cout << "=================================================" << endl;

    cout << "Masukkan panjang pipa (L) dalam meter      : "; cin >> L;
    cout << "Masukkan cepat rambat gelombang (v) dalam m/s : "; cin >> v;

    cout << fixed;
    cout.precision(2);
    cout << "--- a. Pipa Organa Terbuka ---" << endl;
    cout << "Rumus: fn = n * v / (2L)" << endl;
    for (int n = 1; n <= 4; n++) {
        double f = (n * v) / (2.0 * L);
        cout << "Frekuensi harmonik ke-" << n << " (f" << n << ") = " << f << " Hz" << endl;
    }

    cout << "--- b. Pipa Organa Tertutup ---" << endl;
    cout << "Rumus: fn = (2n-1) * v / (4L)" << endl;
    for (int n = 1; n <= 4; n++) {
        double f = ((2 * n - 1) * v) / (4.0 * L);
        cout << "Frekuensi harmonik ke-" << n << " (f" << n << ") = " << f << " Hz" << endl;
    }

    cout << "=================================================" << endl;

    return 0;
}