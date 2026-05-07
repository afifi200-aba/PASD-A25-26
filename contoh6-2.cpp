#include <iostream>
using namespace std;

void merge(int arr[], int Kiri, int mid, int Kanan) {
    int n1 = mid - Kiri + 1;
    int n2 = Kanan - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[Kiri + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = Kiri;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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

void CetakData(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {85, 92, 78, 90, 88, 75,95};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "DATA SEBELUM diurutkan:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakData(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);
    cout << endl << endl;
    cout << "DATA SETELAH diurutkan:" << endl;
    CetakData(arr, arrSize);

    return 0;
}