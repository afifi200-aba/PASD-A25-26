#include<string.h>
#include<iostream>
using namespace std;

class BubbleSort
{
    private:
        int data[10], data2[10];
        int n;

    public:
        void tukar(int a, int b)
        {
            int t;
            t = data[b];
            data[b] = data[a];
            data[a] = t;
        }

        void Input()
        {
            cout << "Masukkan jumlah data = "; cin >> n;
            cout << "--------------------------------------" << endl;
            for(int i = 0; i < n; i++)
            {
                cout << "Masukkan data ke-" << (i+1) << " = "; cin >> data[i];
                data2[i] = data[i];
            }
            cout << endl;
        }

        void Tampil()
        {
            for(int i = 0; i < n; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }

        void bubble_sort()
        {
            for(int i = 1; i < n; i++)
            {
                for(int j = n-1; j >= i; j--)
                {
                    
                    if(data[j] > data[j-1]) tukar(j, j-1);
                }
                Tampil();
            }
            cout << endl;
        }
};

int main()
{
    BubbleSort bs;

    cout << "*--------------------------------------*" << endl;
    cout << "* Selamat datang di aplikasi          *" << endl;
    cout << "* Bubble Sort Ascending (Class)       *" << endl;
    cout << "*--------------------------------------*" << endl;
    bs.Input();
    cout << "Proses Bubble Sort........." << endl;
    cout << "--------------------------------------" << endl;
    bs.Tampil();
    bs.bubble_sort();
    cout << "--------------------------------------" << endl;
    cout << " TERIMA KASIH " << endl;
    cout << "--------------------------------------" << endl;
    cin.get();
}