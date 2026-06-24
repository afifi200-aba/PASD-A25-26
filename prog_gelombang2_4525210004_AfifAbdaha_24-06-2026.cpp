#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double A, f, lambda, x, t, phi0;
    const double PI = 3.14159265358979323846;

    cout << "=================================================" << endl;
    cout << " PROGRAM PERHITUNGAN SIMPANGAN GELOMBANG Y(x,t)" << endl;
    cout << "=================================================" << endl;
    cout << "Persamaan: y(x,t) = A * cos(w*t - k*x + phi0)" << endl << endl;

    cout << "Masukkan Amplitudo (A)                         : "; cin >> A;
    cout << "Masukkan Frekuensi gelombang (f) dalam Hz      : "; cin >> f;
    cout << "Masukkan Panjang gelombang (lambda) dalam meter: "; cin >> lambda;
    cout << "Masukkan Jarak titik gelombang (x) dalam meter : "; cin >> x;
    cout << "Masukkan Waktu terjadinya simpangan (t) detik  : "; cin >> t;
    cout << "Masukkan Fasa nol (phi0) dalam radian          : "; cin >> phi0;

    double omega = 2.0 * PI * f;
    double k     = 2.0 * PI / lambda;

    double y = A * cos(omega * t - k * x + phi0);

    cout << fixed;
    cout.precision(4);

    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Frekuensi sudut (omega) = " << omega << " rad/s" << endl;
    cout << "Bilangan gelombang (k)  = " << k << " rad/m" << endl;
    cout << "Simpangan y(x,t)        = " << y << endl;

    cout << "=================================================" << endl;

    return 0;
}