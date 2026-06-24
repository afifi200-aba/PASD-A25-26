#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

const int HASHSIZE = 100; // Contoh batas slot memori
struct HashData {
    char kode[50];
    char nama[100];
};
HashData* hashTable[HASHSIZE]; 
// ------------------------------------------------------------------------

// FUNGSI PENDUKUNG (Menghitung jumlah huruf)
int characterAmount(char array[]){
    int jumlah=0;
    for(int i=0; array[i]!='\0'; i++)
        jumlah++;
    return jumlah;
}

// FUNGSI PENDUKUNG (Mengecek apakah loker kosong)
bool isIndexEmpty(int rec){
    if(hashTable[rec] == NULL)
        return true;
    else
        return false;
}

// =========================================================================
// 1.INTI RUMUS HASHING-NYA! (FUNGSI HASH)
// Di sinilah Kode MK diubah menjadi nomor loker (indeks)
// =========================================================================
int hashFunction(HashData *array){
    int value = 0, rec, n;
    
    n = characterAmount(array->kode); 
    
    // TAHAP 1: Menjumlahkan kode ASCII dari setiap huruf Kode MK
    for(int i=0; i<n; i++)
        value += array->kode[i];
        
    // TAHAP 2: Di-Modulo (sisa bagi) dengan total loker (HASHSIZE)
    rec = value % HASHSIZE; 
    
    return rec; // Nilai 'rec' inilah nomor alamat lokernya!
}


// =========================================================================
// 2. IMPLEMENTASI HASHING SAAT MENYIMPAN DATA (INSERT)
// =========================================================================
void insert(HashData *array){
    int rec;
    
    // Program memanggil rumus Hashing untuk minta nomor loker
    rec = hashFunction(array); 
    
    // PENERAPAN UTAMA: Data langsung dimasukkan ke loker nomor 'rec'
    // TANPA TABRAKAN HANDLING (Langsung tiban kalau ada isi sebelumnya)
    hashTable[rec] = array; 
    
    cout<<"Input successfully!"<<endl;
    cout<<"Data disimpan pada record indeks "<<rec<<endl;
    cin.get();
}


// Fungsi tambahan untuk mencocokkan huruf saat mencari
int searchingProcess(HashData *cari, int rec){
    int m, n, j = 0;
    bool equal = true;
    if(isIndexEmpty(rec) == false){
        n = characterAmount(cari->kode);
        m = characterAmount(hashTable[rec]->kode);
        if(n == m){
            while((equal == true) && (cari->kode[j] != '\0')){
                if(tolower(cari->kode[j]) != tolower(hashTable[rec]->kode[j]))
                    equal = false;
                j++;
            }
            if(equal == true)
                return rec;
            else
                return -1;
        }
        else
            return -1;
    }
    else {
        return -1;
        cin.get();
    }
}


// =========================================================================
// 3. IMPLEMENTASI HASHING SAAT MENCARI DATA (SEARCHING)
// =========================================================================
void searching(HashData *cari){
    int rec;
    
    // PENERAPAN: Alih-alih mencari dari loker 0 sampai ujung,
    // program menghitung ulang Kode MK-nya untuk tahu datanya nyangkut di loker mana!
    rec = hashFunction(cari); 
    
    rec = searchingProcess(cari, rec);
    if(rec >= 0){
        cout<<"Data ditemukan pada record indeks "<<rec<<endl;
        cout<<"Isi data : "<<endl;
        cout<<"=> KodeMK      : "<<hashTable[rec]->kode<<endl;
        cout<<"=> Matakuliah  : "<<hashTable[rec]->nama<<endl;
    }
    else {
        cout<<"Maaf! Data tidak ditemukan."<<endl;
        cin.get();
    }
}


// =========================================================================
// 4. IMPLEMENTASI HASHING SAAT MENGHAPUS DATA (DELETING)
// =========================================================================
void deleting(HashData *hapus){
    int rec;
    
    // PENERAPAN: Sama seperti cari, hitung dulu lokernya di mana
    rec = hashFunction(hapus); 
    
    rec = searchingProcess(hapus, rec);
    if(rec >= 0){
        cout<<"Data :"<<endl;
        cout<<"  => KodeMK      : "<<hashTable[rec]->kode<<endl;
        cout<<"  => MataKuliah  : "<<hashTable[rec]->nama<<endl;
        cout<<"terhapus!"<<endl;
        
        // Langsung buang isi lokernya menjadi KOSONG (NULL)
        hashTable[rec] = NULL; 
    }
    else {
        cout<<"Maaf! Data tidak ditemukan!"<<endl;
        cin.get();
    }
}


// Menampilkan seluruh isi tabel/loker yang tidak kosong
void DisplayTable(){
    cout<<"\n";
    cout<<"|===================================================|"<<endl;
    cout<<"| Indeks |    KODEMK    |       Nama Mata Kuliah    |"<<endl;
    cout<<"|===================================================|"<<endl;
    for(int i = 0; i < HASHSIZE; i++)
    {
        if(isIndexEmpty(i) == false)
            cout<<setw(6)<<i<<"      "<<hashTable[i]->kode<<"\t     "<<hashTable[i]->nama<<endl;
    }
    cin.get();
}

// Mengosongkan seluruh memori
void Clear(){
    for(int i = 0; i < HASHSIZE; i++)
        hashTable[i] = NULL;
}


// PROGRAM UTAMA / MENU
int main(){
    char ulang = 'Y', menu;
    do{
        system("cls"); // atau system("clear") di Linux/Mac
        
        puts("        PROSES HASH TABLE        ");
        puts("");
        puts("1. Input");
        puts("2. Delete");
        puts("3. Find");
        puts("4. Display");
        puts("5. Clear");
        puts("x. Keluar");
        puts("");
        cout<<"Menu pilihan Anda : "; cin>>menu;
        
        switch(menu){
            case '1' :
                HashData *array;
                array = new HashData;
                puts("");
                cout<<"KodeMK        : "; cin>>array->kode;
                cout<<"Matakuliah    : "; cin>>array->nama;
                cout<<endl;
                insert(array); break;
            case '2' :
                HashData *hapus;
                hapus = new HashData;
                cout<<"Hapus Matakuliah(KodeMK) : "; cin>>hapus->kode;
                deleting(hapus); 
				// --- TAMBAHKAN DUA BARIS INI ---
                cout << endl;
                system("pause"); 
                // -------------------------------
				break;
            case '3' :
                HashData *cari;
                cari = new HashData;
                cout<<"Cari MataKuliah (KodeMK) : "; cin>>cari->kode;
                searching(cari); 
				// --- TAMBAHKAN DUA BARIS INI ---
                cout << endl;
                system("pause"); 
                // -------------------------------
				break;
            case '4' :
                DisplayTable(); break;
            case '5' :
                Clear();
                puts("Tabel hash telah dikosongkan."); 
				// --- TAMBAHKAN DUA BARIS INI ---
                cout << endl;
                system("pause"); 
                // -------------------------------
				break;
            case 'x' :
            case 'X' :
                ulang = 'T'; break;
            default :
                puts("Pilihan diluar Menu yang tersedia!"); break;
        }
        cin.get();
    }
    while(toupper(ulang) == 'Y');
    
    return 0;
}