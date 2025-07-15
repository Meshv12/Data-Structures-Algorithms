#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 1 && heap[index] < heap[index / 2])
        {
            swap(heap[index], heap[index / 2]);
            index = index / 2;
        }
    }

    void heapifyDown(int index)
    {
        int n = heap.size() - 1; // Because index 0 is unused
        while (2 * index <= n)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            int smallest = index;

            if (left <= n && heap[left] < heap[smallest])
                smallest = left;
            if (right <= n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index)
            {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else
                break;
        }
    }

public:
    MinHeap()
    {
        heap.push_back(-1); // Dummy to make index 1-based
    }

    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMin()
    {
        if (heap.size() > 1)
            return heap[1];
        return -1; // or throw exception
    }

    void extractMin()
    {
        int n = heap.size() - 1;
        if (n == 0)
            return;

        heap[1] = heap[n];
        heap.pop_back();
        heapifyDown(1);
    }
};

int main()
{
    MinHeap pq;
    pq.insert(10);
    pq.insert(4);
    pq.insert(15);
    pq.insert(20);
    pq.insert(0);

    cout << "Min Element: " << pq.getMin() << endl;

    pq.extractMin();
}
