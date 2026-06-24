#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UKURAN_TABEL 11
#define PANJANG_KODE 10
#define PANJANG_NAMA 50

typedef struct {
    char kodeMK[PANJANG_KODE];
    char namaMK[PANJANG_NAMA];
    int terisi; /* 0 = kosong (NULL), 1 = terisi */
} SlotHash;

SlotHash tabelHash[UKURAN_TABEL];

/* ============================================================
 * Inisialisasi tabel hash -> semua slot dianggap kosong (NULL)
 * ============================================================ */
void inisialisasiTabel() {
    for (int i = 0; i < UKURAN_TABEL; i++) {
        tabelHash[i].terisi = 0;
        strcpy(tabelHash[i].kodeMK, "");
        strcpy(tabelHash[i].namaMK, "");
    }
}

/* ============================================================
 * Fungsi hash: mengubah KodeMK (contoh "IF101") menjadi angka,
 * lalu di-mod dengan ukuran tabel.
 * Cara ambil angka: jumlahkan nilai ASCII tiap karakter pada
 * KodeMK, supaya kode seperti "IF101" punya nilai numerik unik.
 * ============================================================ */
int fungsiHash(char *kodeMK) {
    long jumlah = 0;
    for (int i = 0; kodeMK[i] != '\0'; i++) {
        jumlah += (int) kodeMK[i];
    }
    return (int)(jumlah % UKURAN_TABEL);
}

/* ============================================================
 * INPUT DATA (Menu 1)
 * Menyimpan data ke tabel hash dengan linear probing
 * jika terjadi collision.
 * ============================================================ */
void inputData(char *kodeMK, char *namaMK) {
    int indeksAwal = fungsiHash(kodeMK);
    int indeks = indeksAwal;
    int hitungLangkah = 0;

    /* Cek apakah KodeMK sudah ada (hindari duplikat) */
    for (int i = 0; i < UKURAN_TABEL; i++) {
        if (tabelHash[i].terisi && strcmp(tabelHash[i].kodeMK, kodeMK) == 0) {
            printf("   [GAGAL] KodeMK %s sudah terdaftar di indeks %d.\n", kodeMK, i);
            return;
        }
    }

    /* Linear probing untuk mencari slot kosong */
    while (tabelHash[indeks].terisi == 1 && hitungLangkah < UKURAN_TABEL) {
        printf("   [COLLISION] Indeks %d terisi, mencoba indeks selanjutnya...\n", indeks);
        indeks = (indeks + 1) % UKURAN_TABEL;
        hitungLangkah++;
    }

    if (hitungLangkah >= UKURAN_TABEL) {
        printf("   [GAGAL] Tabel hash penuh, data %s tidak dapat disimpan.\n", kodeMK);
        return;
    }

    strcpy(tabelHash[indeks].kodeMK, kodeMK);
    strcpy(tabelHash[indeks].namaMK, namaMK);
    tabelHash[indeks].terisi = 1;

    printf("   [BERHASIL] KodeMK=%s, MK=%s -> hash awal=%d, tersimpan di indeks=%d\n",
           kodeMK, namaMK, indeksAwal, indeks);
}

/* ============================================================
 * DISPLAY DATA (Case 4)
 * Menampilkan seluruh isi tabel hash beserta indeksnya.
 * ============================================================ */
void tampilkanTabel() {
    printf("\n=================== ISI TABEL HASH ===================\n");
    printf("%-8s| %-10s| %-20s\n", "Indeks", "KodeMK", "Matakuliah");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < UKURAN_TABEL; i++) {
        if (tabelHash[i].terisi) {
            printf("%-8d| %-10s| %-20s\n", i, tabelHash[i].kodeMK, tabelHash[i].namaMK);
        } else {
            printf("%-8d| %-10s| %-20s\n", i, "-", "NULL");
        }
    }
    printf("=======================================================\n");
}

/* ============================================================
 * PENCARIAN DATA (Case 3)
 * Mencari satu KodeMK menggunakan fungsi hash + linear probing.
 * Mengembalikan indeks jika ditemukan, -1 jika tidak ditemukan.
 * ============================================================ */
int cariData(char *kodeMK) {
    int indeksAwal = fungsiHash(kodeMK);
    int indeks = indeksAwal;
    int hitungLangkah = 0;

    while (hitungLangkah < UKURAN_TABEL) {
        if (tabelHash[indeks].terisi && strcmp(tabelHash[indeks].kodeMK, kodeMK) == 0) {
            return indeks;
        }
        /* Jika slot kosong ditemukan, berarti data tidak ada di rantai probing ini */
        if (!tabelHash[indeks].terisi) {
            return -1;
        }
        indeks = (indeks + 1) % UKURAN_TABEL;
        hitungLangkah++;
    }
    return -1;
}

void pencarianData(char *kodeMK) {
    printf("\nMencari KodeMK: %s (hash awal = %d)\n", kodeMK, fungsiHash(kodeMK));
    int hasil = cariData(kodeMK);
    if (hasil != -1) {
        printf("   [DITEMUKAN] KodeMK=%s, Matakuliah=%s, pada indeks=%d\n",
               tabelHash[hasil].kodeMK, tabelHash[hasil].namaMK, hasil);
    } else {
        printf("   [TIDAK DITEMUKAN] Data dengan KodeMK %s tidak ada dalam tabel.\n", kodeMK);
    }
}

/* ============================================================
 * PENGHAPUSAN DATA (Case 2)
 * Menghapus data berdasarkan KodeMK, slot menjadi NULL kembali.
 * ============================================================ */
void hapusData(char *kodeMK) {
    int hasil = cariData(kodeMK);
    if (hasil != -1) {
        printf("   [BERHASIL] Data KodeMK=%s (%s) pada indeks %d telah dihapus.\n",
               tabelHash[hasil].kodeMK, tabelHash[hasil].namaMK, hasil);
        tabelHash[hasil].terisi = 0;
        strcpy(tabelHash[hasil].kodeMK, "");
        strcpy(tabelHash[hasil].namaMK, "");
    } else {
        printf("   [GAGAL] Data dengan KodeMK %s tidak ditemukan, tidak ada yang dihapus.\n", kodeMK);
    }
}

/* ============================================================
 * PENGOSONGAN TABEL (Case 5)
 * Mengosongkan seluruh isi tabel hash.
 * ============================================================ */
void kosongkanTabel() {
    inisialisasiTabel();
    printf("   [BERHASIL] Seluruh isi tabel hash telah dikosongkan (semua slot = NULL).\n");
}

/* ============================================================
 * Validasi: cek apakah tabel benar-benar kosong semua
 * ============================================================ */
int cekTabelKosong() {
    for (int i = 0; i < UKURAN_TABEL; i++) {
        if (tabelHash[i].terisi) return 0;
    }
    return 1;
}

/* ============================================================
 * Helper: bersihkan buffer input
 * ============================================================ */
void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ============================================================
 * MAIN PROGRAM - MENU
 * ============================================================ */
int main() {
    int pilihan;
    char kodeMK[PANJANG_KODE];
    char namaMK[PANJANG_NAMA];

    inisialisasiTabel();

    do {
        printf("\n================ MENU HASH TABLE (MATAKULIAH) ================\n");
        printf("1. Input Data\n");
        printf("2. Hapus Data\n");
        printf("3. Cari Data\n");
        printf("4. Tampilkan Seluruh Tabel Hash\n");
        printf("5. Kosongkan Tabel Hash\n");
        printf("X. Keluar Program\n");
        printf("================================================================\n");
        printf("Pilih menu: ");

        char inputMenu[10];
        scanf("%9s", inputMenu);
        bersihkanBuffer();

        if (toupper(inputMenu[0]) == 'X' && strlen(inputMenu) == 1) {
            pilihan = 0; /* kode internal untuk keluar */
        } else {
            pilihan = atoi(inputMenu);
        }

        switch (pilihan) {
            case 1: {
                printf("Masukkan KodeMK   : ");
                scanf("%9s", kodeMK);
                bersihkanBuffer();
                printf("Masukkan Matakuliah: ");
                fgets(namaMK, PANJANG_NAMA, stdin);
                namaMK[strcspn(namaMK, "\n")] = '\0'; /* hapus newline */
                inputData(kodeMK, namaMK);
                break;
            }
            case 2: {
                printf("Masukkan KodeMK yang akan dihapus: ");
                scanf("%9s", kodeMK);
                bersihkanBuffer();
                hapusData(kodeMK);
                break;
            }
            case 3: {
                printf("Masukkan KodeMK yang akan dicari: ");
                scanf("%9s", kodeMK);
                bersihkanBuffer();
                pencarianData(kodeMK);
                break;
            }
            case 4: {
                tampilkanTabel();
                break;
            }
            case 5: {
                kosongkanTabel();
                break;
            }
            case 0: {
                printf("\nProgram selesai. Terima kasih!\n");
                break;
            }
            default: {
                printf("   [INFO] Pilihan tidak valid, silakan coba lagi.\n");
                break;
            }
        }

    } while (pilihan != 0);

    return 0;
}