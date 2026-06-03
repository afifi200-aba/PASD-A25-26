#include <iostream>
#include <cmath>
using namespace std;

const double g04 = 9.8; // m/s2

int main() {
    int pilihan04;
    double v0_04, sudut04;

    cout << "=======================================" << endl;
    cout << "  PROGRAM GERAK 2 DIMENSI (PARABOLA)  " << endl;
    cout << "  NPM: 4525210004                     " << endl;
    cout << "=======================================" << endl;
	cout << "Masukkan kecepatan awal (v0) [m/s]   : "; cin >> v0_04;
    cout << "Masukkan sudut lempar peluru  [derajat]: "; cin >> sudut04;
    cout << endl;

    double sudutRad04 = sudut04 * M_PI / 180.0;
    double vx04 = v0_04 * cos(sudutRad04);
    double vy04 = v0_04 * sin(sudutRad04);

    cout << "Pilihan Menu:" << endl;
    cout << "1. Menghitung Kecepatan Awal Arah X dan Arah Y" << endl;
    cout << "2. Menghitung Tinggi Maksimum Benda" << endl;
    cout << "3. Menghitung Jarak Maksimum Benda" << endl;
    cout << endl;
    cout << "Masukkan pilihan (1/2/3): "; cin >> pilihan04;
    cout << endl;

    if (pilihan04 == 1) {
        cout << "--- Kecepatan Awal Arah X dan Arah Y ---" << endl;
        cout << endl;
        cout << "=======================================" << endl;
        cout << "HASIL:" << endl;
        cout << "Kecepatan Awal (v0)   = " << v0_04    << " m/s"     << endl;
        cout << "Sudut Lempar          = " << sudut04  << " derajat" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Kecepatan Arah X (vx) = " << vx04    << " m/s"     << endl;
        cout << "Kecepatan Arah Y (vy) = " << vy04    << " m/s"     << endl;
        cout << "=======================================" << endl;

    } else if (pilihan04 == 2) {
       double H04 = (vy04 * vy04) / (2.0 * g04);

        cout << "--- Menghitung Tinggi Maksimum ---" << endl;
        cout << endl;
        cout << "=======================================" << endl;
        cout << "HASIL:" << endl;
        cout << "Kecepatan Awal (v0)   = " << v0_04   << " m/s"     << endl;
        cout << "Sudut Lempar          = " << sudut04 << " derajat" << endl;
        cout << "Kecepatan Arah Y (vy) = " << vy04   << " m/s"     << endl;
        cout << "Gravitasi (g)         = " << g04    << " m/s2"    << endl;
        cout << "---------------------------------------" << endl;
        cout << "Tinggi Maksimum (H)   = " << H04    << " m"       << endl;
        cout << "=======================================" << endl;

    } else if (pilihan04 == 3) {
		double R04 = (v0_04 * v0_04 * sin(2.0 * sudutRad04)) / g04;

        cout << "--- Menghitung Jarak Maksimum ---" << endl;
        cout << endl;
        cout << "=======================================" << endl;
        cout << "HASIL:" << endl;
        cout << "Kecepatan Awal (v0)   = " << v0_04   << " m/s"     << endl;
        cout << "Sudut Lempar          = " << sudut04 << " derajat" << endl;
        cout << "Gravitasi (g)         = " << g04    << " m/s2"    << endl;
        cout << "---------------------------------------" << endl;
        cout << "Jarak Maksimum (R)    = " << R04    << " m"       << endl;
        cout << "=======================================" << endl;

    } else {
        cout << "[ERROR] Pilihan tidak valid! Masukkan angka 1, 2, atau 3." << endl;
    }

    cout << endl;
    return 0;
}