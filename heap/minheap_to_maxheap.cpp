#include <iostream>
#include <vector>
using namespace std;

class HeapConverter
{
public:
    // for max to min just reverse the conditions

    void heapifyDown(vector<int> &heap, int i, int n)
    {
        while (2 * i <= n)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= n && heap[left] > heap[largest])
                largest = left;
            if (right <= n && heap[right] > heap[largest])
                largest = right;

            if (largest != i)
            {
                swap(heap[i], heap[largest]);
                i = largest;
            }
            else
                break;
        }
    }

    // started from non-leaf node (here from n/2) to 1 and do heapify 
    void convertMinToMaxHeap(vector<int> &heap)
    {
        int n = heap.size() - 1; // 1-based indexing
        for (int i = n / 2; i >= 1; --i)
        {
            heapifyDown(heap, i, n);
        }
    }

    void printHeap(const vector<int> &heap)
    {
        for (int i = 1; i < heap.size(); ++i)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    // Example Min Heap (1-based): [dummy, 1, 3, 5, 7, 9, 8]
    vector<int> minHeap = {-1, 1, 3, 5, 7, 9, 8}; // -1 is dummy for 1-based indexing

    HeapConverter converter;
    cout << "Original Min Heap: ";
    converter.printHeap(minHeap);

    converter.convertMinToMaxHeap(minHeap);

    cout << "Converted Max Heap: ";
    converter.printHeap(minHeap);
}
