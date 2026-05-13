#include <iostream>
using namespace std;

class MergeSort {
private:
    int *arr;
    int arrSize;

    void merge(int arr[], int Kiri, int mid, int Kanan) {
        int n1 = mid - Kiri + 1;
        int n2 = Kanan - mid;

        int L[n1], R[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[Kiri + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = Kiri;

        
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int arr[], int Kiri, int Kanan) {
        if (Kiri < Kanan) {
            int mid = Kiri + (Kanan - Kiri) / 2;
            mergeSort(arr, Kiri, mid);
            mergeSort(arr, mid + 1, Kanan);
            merge(arr, Kiri, mid, Kanan);
        }
    }

public:
    MergeSort(int size) {
        arrSize = size;
        arr = new int[arrSize];
    }

    ~MergeSort() {
        delete[] arr;
    }

    void inputData() {
        cout << "Masukkan " << arrSize << " data:" << endl;
        cout << "-------------------------------" << endl;
        for (int i = 0; i < arrSize; i++) {
            cout << "Data ke-" << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    void sort() {
        mergeSort(arr, 0, arrSize - 1);
    }

    void CetakData() {
        for (int i = 0; i < arrSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "  MERGE SORT - CLASS  " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    MergeSort ms(n);
    ms.inputData();

    cout << endl;
    cout << "DATA SEBELUM diurutkan:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    ms.CetakData();

    ms.sort();

    cout << endl;
    cout << "DATA SETELAH diurutkan (Descending):" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    ms.CetakData();

    return 0;
}