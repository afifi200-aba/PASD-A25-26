//TUGAS BESAR ALGORITMA DAN PEMROGRAMAN KELAS A - SI PENJUALAN TOKO BAJU
/*-Selection/seleksi
  -Repetation/Pengulangan 
  -Array
  -Fungction
  -String/file
  -Selection Sort (Asceding)	menggunakan inputan 
 */
  /*
	Nama		: Afif Abdaha 
	Npm			: 4525210004
	NO. Tugas	: 1
*/

#include <iostream>
#include <string>
#define n 5
using namespace std;

// Deklarasi variabel 
int A[n] = {150000, 90000, 180000, 15000, 120000};

//function judul
void judul() {
    cout << "        SELAMAT DATANG DI TOKO BAJU        " << endl;
    cout << endl;
}
// function ucapan
void ucapan() {
    cout << "Terima Kasih" << endl;
}

int main() {
    judul();

    cout << "======================================" << endl;
    cout << "     DAFTAR HARGA PAKAIAN     " << endl;
    cout << "======================================" << endl;
    cout << endl;
    for (int d = 0; d < n; d++) {
        cout << A[d] << "    ";
    }
    cout << endl;

    // Selection sort
    for (int b = 1; b < n; b++) {
        int d = b;
        int c = A[d];
        while (d > 0 && A[d - 1] > c) {
            A[d] = A[d - 1];
            d--;
        }
        A[d] = c;
    }

    cout << endl;
    cout << "=======================================================" << endl;
    cout << "    Daftar Harga Barang Dari Yang Paling Murah    " << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    for (int d = 0; d < n; d++) {
        cout << A[d] << "    ";
    }
    cout << endl;

    cout << endl;
    cout << "==========================================" << endl;
    cout << "            TOKO BAJU            " << endl;
    cout << "==========================================" << endl;
    cout << "1 | Belanja" << endl;
    cout << "2 | Klaim voucher Akhir Tahun 2025" << endl;
    cout << "3 | Keluar" << endl;
    cout << "==========================================" << endl;
    cout << "Pilih Yang Mana? (1/2/3): "; //sequnce tampilkan teks
    int pilih; //Deklarasi Variabel
    cin >> pilih; //sequnce inputan
    cout << endl;

	//if Selection
    if (pilih == 1) {
        cout << "|===========================================================|" << endl;
        cout << "                    Daftar Nama Pakaian                     |" << endl;
        cout << "|===========================================================|" << endl;
        cout << "|                                                           |" << endl;
        cout << "|            Nama Barang            |        Harga         |" << endl;
        cout << "|                                                           |" << endl;
        cout << "|===========================================================|" << endl;
        cout << "|                                                           |" << endl;
        cout << "|    1. Baju Anak Anak            |     Rp. 150.000       |" << endl;
        cout << "|    2. Baju Tidur                |     Rp.  90.000       |" << endl;
        cout << "|    3. Baju Dewasa                |     Rp. 180.000       |" << endl;
        cout << "|    4. Baju Training              |     Rp.  15.000       |" << endl;
        cout << "|    5. Baju Bola                  |     Rp. 120.000       |" << endl;
        cout << "|===========================================================|" << endl;
        cout << endl;
        cout << "Pilih kode barang (1-5): ";
        int kode;
        cin >> kode;
        cout << "Jumlah barang yang dibeli: ";
        int kuan;
        cin >> kuan;

        float hrg, tot, potongan, spot, byr, kbl;
        switch (kode) {
            case 1:
                cout << "\nBaju Anak Anak" << endl;
                hrg = 150000;
                tot = hrg * kuan;
                potongan = tot * 10 / 100;
                spot = tot - potongan;
                cout << "Bayar: ";
                cin >> byr;
                kbl = byr - spot;
                break;
            case 2:
                cout << "\nBaju Tidur" << endl;
                hrg = 90000;
                tot = hrg * kuan;
                potongan = tot * 5 / 100;
                spot = tot - potongan;
                cout << "Bayar: ";
                cin >> byr;
                kbl = byr - spot;
                break;
            case 3:
                cout << "\nBaju Dewasa" << endl;
                hrg = 180000;
                tot = hrg * kuan;
                potongan = tot * 10 / 100;
                spot = tot - potongan;
                cout << "Bayar: ";
                cin >> byr;
                kbl = byr - spot;
                break;
            case 4:
                cout << "\nBaju Training" << endl;
                hrg = 15000;
                tot = hrg * kuan;
                potongan = tot * 5 / 100;
                spot = tot - potongan;
                cout << "Bayar: ";
                cin >> byr;
                kbl = byr - spot;
                break;
            case 5:
                cout << "\nBaju Bola" << endl;
                hrg = 120000;
                tot = hrg * kuan;
                potongan = tot * 5 / 100;  
                spot = tot - potongan;
                cout << "Bayar: ";
                cin >> byr;
                kbl = byr - spot;
                break;
            default:
                cout << "Kode yang Anda masukkan tidak tersedia." << endl;
        }

        cout << endl;
        cout << "===================================================" << endl;
        cout << "Harga                     | Rp.     = " << tot << endl;
        cout << "Potongan                  | Rp.     = " << potongan << endl;
        cout << "Harga Sesudah Potongan    | Rp.     = " << spot << endl;
        cout << "Bayar                     | Rp.     = " << byr << endl;
        cout << "Kembalian                 | Rp.     = " << kbl << endl;

        // Array 
        const int data = 3;
        int a[data] = {3, 2, 1};
        cout << endl;
        cout << "===================================================" << endl;
        cout << "SELAMAT ANDA MENDAPATKAN VOUCHER AKHIR TAHUN !!!" << endl;
        cout << "            SILAKAN TUNGGU                      " << endl;
        cout << "        VOUCHER SEDANG DIPROSES                 " << endl;
        cout << "===================================================" << endl;
        cout << endl;
        for (int i = 0; i < data; i++) {
            cout << "    " << a[i] << endl;
        }
        cout << endl;

        // String 
        string data1 = "Tukar Voucher Akhir Tahun Ini di Toko Baju Jaya";
        string data2 = "            Voucher Hanya Berlaku Hari Ini            ";
        cout << "===============================================================" << endl;
        cout << "                    VOUCHER AKHIR TAHUN 2025                  " << endl;
        cout << "===============================================================" << endl;
        cout << endl;
        cout << "    " << data1 << endl;
        cout << "    " << data2 << endl;

        // Repetation/Pengulangan 
        int f = 1;
        while (f > 0) {
            cout << endl;
            ucapan();
            f--;
        }
    } else if (pilih == 2) {
        cout << "Voucher Tidak Bisa Diklaim" << endl;
        cout << "ANDA HARUS BERBELANJA DAHULU" << endl;
        cout << endl;
    } else if (pilih == 3) {
        cout << "Terima Kasih" << endl;
        cout << endl;
    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    cin.get();
}