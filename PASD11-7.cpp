#include <iostream>
using namespace std;

class BinaryHeap {
    private:
        const static int MAX_N = 15;
        int heap[MAX_N];
        int N;
    public:
        BinaryHeap() {
            N = 0;
        }
        static int root(int i) {
            return (i - 1)/2;
        }
        static int KIRI(int i) {
            return 2*i + 1;
        }
        static int KANAN(int i) {
            return 2*i + 2;
        }

        static void tukar(int *x, int *y) {
            int temp = *x;
            *x = *y;
            *y = temp;
        }

        void sisip(int data) {
            if (N >= MAX_N) {
                cout<<"HEAP TREE kondisi PENUH dan Tidak bisa di SISIP kan"<<endl;
                return;
            }
            heap[N] = data;
            N = N + 1;
            int i = N - 1;
            while (i != 0 && heap[BinaryHeap::root(i)] < heap[i]) {
                BinaryHeap::tukar(&heap[BinaryHeap::root(i)], &heap[i]);
                i = BinaryHeap::root(i);
            }
        }

        void maxHeapify(int i) {
            int left = BinaryHeap::KIRI(i);
            int right = BinaryHeap::KANAN(i);
            int largest = i;
            if (left <= N && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right <= N && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != i) {
                int temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;
                maxHeapify(largest);
            }
        }

        int getMax() {
            return heap[0];
        }

        int extractMax() {
            int maxItem = heap[0];
            heap[0] = heap[N - 1];
            N = N - 1;
            maxHeapify(0);
            return maxItem;
        }

        void cetakHeap() {
            for (int i = 0; i < N; i++) {
                cout<< heap[i] << " ";  
            }
            cout<<endl;
        }
}; 

int main() {
    BinaryHeap heap;

    cout << "=== Program Binary Max Heap ===" << endl;

    heap.sisip(10);
    heap.sisip(20);
    heap.sisip(5);
    heap.sisip(30);
    heap.sisip(15);

    cout << "Isi Heap setelah insert: ";
    heap.cetakHeap();

    cout << "Nilai Maksimum: " << heap.getMax() << endl;

    cout << "Extract Max: " << heap.extractMax() << endl;

    cout << "Isi Heap setelah extractMax: ";
    heap.cetakHeap();

    return 0;
}