#include <iostream> 
#include <cstring> 
#define MAX 100 
using namespace std; 
struct afTransport { 
char afKotaAwal[20];    
char afKotaAkhir[20];   
int afJarak;            
char afSkip; 
}; 
struct afStack { 
char afKotaAwal[20]; 
char afKotaAkhir[20]; 
int afJrk; 
}; 
 
struct afTransport afBus[MAX]; 
struct afStack afBTStack[MAX]; 
 
int afBuspos  = 0; 
int afFindpos = 0; 
int afTos     = 0; 
 
void afSetup(); 
void afRoute(char *afKotaAkhir); 
void afInbus(const char *afKotaAwal, const char *afKotaAkhir, int afJarak); 
void afPush(char *afKotaAwal, char *afKotaAkhir, int afJrk); 
void afPop(char *afKotaAwal, char *afKotaAkhir, int *afJrk); 
void afIsbus(char *afKotaAwal, char *afKotaAkhir); 
int afFind(char *afKotaAwal, char *afAnyWhere); 
int afMatch(char *afKotaAwal, char *afKotaAkhir); 
 
int main() { 
    char afKotaAwal[20], afKotaAkhir[20]; 
    afSetup(); 
    cout<<"\nMasukkan Perjalanannya"<<endl; 
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl; 
    cout<<"Dari : "; 
 cin>>afKotaAwal; 
    cout<<"Ke   : ";  
 cin>>afKotaAkhir; 
    afIsbus(afKotaAwal, afKotaAkhir); 
    afRoute(afKotaAkhir); 
    cin.get(); 
    return 0; 
} 
 
void afSetup() { 
    afInbus("Jakarta", "Jogyakarta", 650); 
    afInbus("Jakarta", "Semarang", 450); 
    afInbus("Jakarta", "Malang", 850); 
    afInbus("Jogyakarta", "Malang", 300); 
    afInbus("Semarang", "Surabaya", 450); 
    afInbus("Semarang", "Jogyakarta", 75); 
    afInbus("Semarang", "Banyuwangi", 750); 
    afInbus("Malang", "Madiun", 250); 
    afInbus("Malang", "Nganjuk", 300); 
    afInbus("Malang", "Sidoardjo", 30); 
} 
 
void afInbus(const char *afKotaAwal, const char *afKotaAkhir, int afJarak) { 
    if (afBuspos < MAX) { 
        strcpy(afBus[afBuspos].afKotaAwal, afKotaAwal); 
        strcpy(afBus[afBuspos].afKotaAkhir, afKotaAkhir); 
        afBus[afBuspos].afJarak = afJarak; 
        afBus[afBuspos].afSkip = 0; 
        afBuspos++; 
    } else { 
        cout<<"Database penuh"<<endl; 
    } 
} 
 
void afIsbus(char *afKotaAwal, char *afKotaAkhir) { 
    int d, afJarak; 
    char afAnyWhere[20]; 
 
    if ((d = afMatch(afKotaAwal, afKotaAkhir))) { 
        afPush(afKotaAwal, afKotaAkhir, d); 
        return; 
    } 
    if ((afJarak = afFind(afKotaAwal, afAnyWhere))) { 
        afPush(afKotaAwal, afKotaAkhir, afJarak); 
        afIsbus(afAnyWhere, afKotaAkhir); 
    } else if (afTos > 0) { 
        afPop(afKotaAwal, afKotaAkhir, &afJarak); 
        afIsbus(afKotaAwal, afKotaAkhir); 
    } 
} 
 
int afMatch(char *afKotaAwal, char *afKotaAkhir) { 
    int t; 
    for (t = afBuspos - 1; t > -1; t--) { 
        if (!strcmp(afBus[t].afKotaAwal, afKotaAwal) && !strcmp(afBus[t].afKotaAkhir, 
afKotaAkhir)) 
            return afBus[t].afJarak; 
    } 
    return 0; 
} 
 
int afFind(char *afKotaAwal, char *afAnyWhere) { 
    afFindpos = 0; 
    while (afFindpos < afBuspos) { 
        if (!strcmp(afBus[afFindpos].afKotaAwal, afKotaAwal) && afBus[afFindpos].afSkip == 0) { 
            strcpy(afAnyWhere, afBus[afFindpos].afKotaAkhir); 
            afBus[afFindpos].afSkip = 1; 
            return afBus[afFindpos].afJarak; 
        } 
        afFindpos++; 
    } 
    return 0; 
} 
 
void afPush(char *afKotaAwal, char *afKotaAkhir, int afJrk) { 
    if (afTos < MAX) {                                  
        strcpy(afBTStack[afTos].afKotaAwal, afKotaAwal);       
        strcpy(afBTStack[afTos].afKotaAkhir, afKotaAkhir); 
        afBTStack[afTos].afJrk = afJrk;                         
        afTos++; 
    } else { 
        cout<<"Stack penuh !!!"<<endl; 
    } 
} 
 
void afPop(char *afKotaAwal, char *afKotaAkhir, int *afJrk) { 
    if (afTos > 0) {                                       
        afTos--; 
        strcpy(afKotaAwal, afBTStack[afTos].afKotaAwal); 
        strcpy(afKotaAkhir, afBTStack[afTos].afKotaAkhir); 
        *afJrk = afBTStack[afTos].afJrk;                     
    } else { 
        cout<<"Stack kosong !!!"<<endl; 
    } 
} 
 
void afRoute(char *afKotaAkhir) { 
    int afJrk, t; 
    afJrk = 0; 
    t = 0; 
    while (t < afTos) { 
        cout<<"\nTujuan : "<<afBTStack[t].afKotaAkhir<<endl; 
        afJrk += afBTStack[t].afJrk;   
        t++; 
    }  
    cout<<"afJarak Tempuh : "<<afJrk<<" Km"<<endl;         
} 