#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int pilihan04;

    cout << "=======================================" << endl;
    cout << "   PROGRAM GERAK 1 DIMENSI (GLBB)     " << endl;
    cout << "   NPM: 4525210004                    " << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Pilihan Menu:" << endl;
    cout << "1. Menghitung Waktu Tempuh" << endl;
    cout << "   (masukan: kecepatan awal, percepatan, kecepatan akhir)" << endl;
    cout << "2. Menghitung Kecepatan Awal" << endl;
    cout << "   (masukan: kecepatan akhir, percepatan, waktu tempuh)" << endl;
    cout << "3. Menghitung Percepatan" << endl;
    cout << "   (masukan: kecepatan awal, waktu tempuh, kecepatan akhir)" << endl;
    cout << endl;
    cout << "Masukkan pilihan (1/2/3): ";
    cin >> pilihan04;
    cout << endl;

    if (pilihan04 == 1) {
		double v0_04, a04, vt04, t04;

        cout << "--- Menghitung Waktu Tempuh ---" << endl;
        cout << "Masukkan kecepatan awal (v0) [m/s] : ";
        cin >> v0_04;
        cout << "Masukkan percepatan (a)     [m/s2] : ";
        cin >> a04;
        cout << "Masukkan kecepatan akhir (vt) [m/s]: ";
        cin >> vt04;

        if (a04 == 0) {
            cout << endl;
            cout << "[ERROR] Percepatan tidak boleh 0 untuk menghitung waktu tempuh!" << endl;
        } else {
            t04 = (vt04 - v0_04) / a04;
            cout << endl;
            cout << "=======================================" << endl;
            cout << "HASIL:" << endl;
            cout << "Kecepatan Awal (v0) = " << v0_04 << " m/s" << endl;
            cout << "Percepatan (a)      = " << a04   << " m/s2" << endl;
            cout << "Kecepatan Akhir(vt) = " << vt04  << " m/s" << endl;
            cout << "---------------------------------------" << endl;
            cout << "Waktu Tempuh (t)    = " << t04   << " s" << endl;
            cout << "=======================================" << endl;
        }

    } else if (pilihan04 == 2) {
       double vt04, a04, t04, v0_04;

        cout << "--- Menghitung Kecepatan Awal ---" << endl;
        cout << "Masukkan kecepatan akhir (vt) [m/s]: ";
        cin >> vt04;
        cout << "Masukkan percepatan (a)     [m/s2] : ";
        cin >> a04;
        cout << "Masukkan waktu tempuh (t)   [s]    : ";
        cin >> t04;

        v0_04 = vt04 - (a04 * t04);

        cout << endl;
        cout << "=======================================" << endl;
        cout << "HASIL:" << endl;
        cout << "Kecepatan Akhir (vt)= " << vt04  << " m/s" << endl;
        cout << "Percepatan (a)      = " << a04   << " m/s2" << endl;
        cout << "Waktu Tempuh (t)    = " << t04   << " s" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Kecepatan Awal (v0) = " << v0_04 << " m/s" << endl;
        cout << "=======================================" << endl;

    } else if (pilihan04 == 3) {
        double v0_04, t04, vt04, a04;

        cout << "--- Menghitung Percepatan ---" << endl;
        cout << "Masukkan kecepatan awal (v0) [m/s] : ";
        cin >> v0_04;
        cout << "Masukkan waktu tempuh (t)    [s]   : ";
        cin >> t04;
        cout << "Masukkan kecepatan akhir (vt) [m/s]: ";
        cin >> vt04;

        if (t04 == 0) {
            cout << endl;
            cout << "[ERROR] Waktu tempuh tidak boleh 0 untuk menghitung percepatan!" << endl;
        } else {
            a04 = (vt04 - v0_04) / t04;
            cout << endl;
            cout << "=======================================" << endl;
            cout << "HASIL:" << endl;
            cout << "Kecepatan Awal (v0) = " << v0_04 << " m/s" << endl;
            cout << "Waktu Tempuh (t)    = " << t04   << " s" << endl;
            cout << "Kecepatan Akhir(vt) = " << vt04  << " m/s" << endl;
            cout << "---------------------------------------" << endl;
            cout << "Percepatan (a)      = " << a04   << " m/s2" << endl;
            cout << "=======================================" << endl;
        }

    } else {
        cout << "[ERROR] Pilihan tidak valid! Masukkan angka 1, 2, atau 3." << endl;
    }

    cout << endl;
    return 0;
}