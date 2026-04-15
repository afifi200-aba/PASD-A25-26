#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
	string nim;
	string nama;
	float quiz, uts, uas, na;
	string index;
};

string isiIndex(float na) {
	if (na <= 44.99) return "E";
	else if (na <= 55.99) return "D";
	else if (na <= 59.99) return "C";
	else if (na <= 63.99) return "C+";
	else if (na <= 67.99) return "B-";
	else if (na <= 71.99) return "B";
	else if (na <= 75.99) return "B+";
	else if (na <= 79.99) return "A-";
	else return "A";
}

int main() {
	int n;
	cout << "Masukkan jumlah mahasiswa: ";
	cin >> n;

	Mahasiswa *mhs = new Mahasiswa[n];

	for (int i = 0; i < n; i++) {
		Mahasiswa *p = &mhs[i];

		cout << "\nPengisian Data Mahasiswa Ke-" << i + 1 << endl;
		cout << "NIM        : ";
		cin >> p->nim;
		cout << "NAMA       : ";
		cin.ignore();
		getline(cin, p->nama);
		cout << "Nilai QUIZ : ";
		cin >> p->quiz;
		cout << "Nilai UTS  : ";
		cin >> p->uts;
		cout << "Nilai UAS  : ";
		cin >> p->uas;

		p->na = (p->quiz + p->uts + p->uas) / 3;
		p->index = isiIndex(p->na);
	}

	cout << "\nData yang telah dimasukan adalah :" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "| NIM\t| NAMA\t\t| QUIS\t| UTS\t| UAS\t| NA\t| INDEX |" << endl;
	cout << "-------------------------------------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		Mahasiswa *p = &mhs[i];
		cout << "| " << p->nim
		     << "\t| " << p->nama
		     << "\t| " << p->quiz
		     << "\t| " << p->uts
		     << "\t| " << p->uas
		     << "\t| " << p->na
		     << "\t| " << p->index
		     << "\t|" << endl;
	}

	cout << "-------------------------------------------------------------" << endl;

	delete[] mhs;
	cin.get();
}