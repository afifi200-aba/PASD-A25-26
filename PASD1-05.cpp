#include <iostream>
#include <string>
using namespace std;

struct afif {
    string NIK;
    string Nama;
    string Alamat;
    int TahunLahir;
    string JenisKelamin;
    string Agama;
    string StatusPerkawinan;
    string Pekerjaan;
    string Kewarganegaraan;
    string MasaBerlaku;
};

int main() {
    afif dataAfif;

    cout << "=== INPUT DATA KTP ===" << endl;
    cout << "NIK              : "; cin>> dataAfif.NIK;
    cout << "Nama             : "; cin>> dataAfif.Nama;
    cout << "Alamat           : "; cin>> dataAfif.Alamat;
    cout << "Tahun Lahir      : "; cin>> dataAfif.TahunLahir;
    cout << "Jenis Kelamin    : "; cin>> dataAfif.JenisKelamin;
    cout << "Agama            : "; cin>> dataAfif.Agama;
    cout << "Status Perkawinan: "; cin>> dataAfif.StatusPerkawinan;
    cout << "Pekerjaan        : "; cin>> dataAfif.Pekerjaan;
    cout << "Kewarganegaraan  : "; cin>> dataAfif.Kewarganegaraan;
    cout << "Masa Berlaku     : "; cin>> dataAfif.MasaBerlaku;

    cout << endl;
    cout << "========================================" << endl;
    cout << "     KARTU TANDA PENDUDUK (KTP)         " << endl;
    cout << "========================================" << endl;
    cout << "NIK              : " << dataAfif.NIK              << endl;
    cout << "Nama             : " << dataAfif.Nama             << endl;
    cout << "Alamat           : " << dataAfif.Alamat           << endl;
    cout << "Tahun Lahir      : " << dataAfif.TahunLahir       << endl;
    cout << "Jenis Kelamin    : " << dataAfif.JenisKelamin     << endl;
    cout << "Agama            : " << dataAfif.Agama            << endl;
    cout << "Status Perkawinan: " << dataAfif.StatusPerkawinan << endl;
    cout << "Pekerjaan        : " << dataAfif.Pekerjaan        << endl;
    cout << "Kewarganegaraan  : " << dataAfif.Kewarganegaraan  << endl;
    cout << "Masa Berlaku     : " << dataAfif.MasaBerlaku      << endl;
    cout << "========================================" << endl;

    cin.get();
}