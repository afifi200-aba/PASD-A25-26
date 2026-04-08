#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	int i;
	char *namaKu, NM[4]= {'A','F','I','F'};
	cout << "nama Ku " << endl;
	cout << "~~~~~~~~~~~~~~~~~"<< endl;
	for(i=0; i<4; i++)
	{
		namaKu = &NM[i];
		cout << " " << *namaKu << endl;
	}
	cin.get();
}