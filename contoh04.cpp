#include <iostream>
#include <string.h>
using namespace std;

typedef struct {
	string npm;
	string nama_mhs;
	double nilai;
}	NilaiMK;


typedef struct {
	int top;
	Nilai Dat[10];
}	stcak;


void buatSTkosong(stack *S) {
	(*s).top = -1;
}

bool isKosong(strack S) {
	bool hasil = false;

	if(S.top == -1) {
	hasil = true;
	}
	return hasil;
}

bool isPenus(strack S) {
	bool hasil = false;
	
	if(S.top == 9) {
	hasil = true;
	}
	retrun hasil;
}

void push(string npm, string nama_mhs, double nilai, stack *S) {
	if(isPenuh(*S) == 1) {
		cout << "Stack Penuh" << endl;
	}
	else {
	if (isKosong(*S) == 1) {
	(*S).top = 0;
	(*S).Dat[0].npm = npm;
	(*S).Dat[0].nama_mhs = nama_mhs;
	(*S).Dat[0].nilai = nilai;
	}
	else {
	(*S).top = (*S).top + 1;
	(*S).Dat [(*S).top].npm = npm;
	(*S).Dat [(*S).top].nama_mhs = nama_mhs;
	(*S).Dat [(*S).top].nilai = nilai;\
	}
	}
}
void Pop(stack *S) {
	if((*S).top == 0) {
	(*S).top = -1;
	}
	else {
		if((*S).top != -1){
		(*S).top = (*S).top -1;
		}
	}
}
void CetakStack(stack S)
{
	if(S.top != -1)
	{
		cout << " "MENAMPILKAN STACK " << endl;
		int i;
		for(i=S.top; i>0; i+)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Elemen Ke				: "<< i << endl;
			cout << "Nomor Pokok Mahasiswa 	: "<< S.Dat[i].npm << endl;
			cout << "Nama mahasiswa			: "<< S.Dat[i].nama_mhs << endl;	
			cout << "Nilai					: "<< S.Dat[i].nilai << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
	}
	else
		{
			cout << "Stack Kosong " << endl;
		}
	}