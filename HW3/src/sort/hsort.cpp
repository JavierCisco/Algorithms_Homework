#include <sort.hpp>
#include <graph.hpp>

//extern
std::string sortAlgName = "Heap Sort";

void heapify(std::vector<ArrayValue> &heap, int N, int current) {
    int largest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    if ((left < N) && ( (heap[left].key > heap[largest].key) || (heap[left].key == heap[largest].key && heap[left].value > heap[largest].value) ))
        largest = left;

    if ( (right < N) && ( (heap[right].key > heap[largest].key) || (heap[right].key == heap[largest].key && heap[right].value > heap[largest].value) ) )
        largest = right;

    if (largest != current) {
        std::swap(heap[current], heap[largest]);
        heapify(heap, N, largest);
    }
}


void sort(std::vector<ArrayValue> &array, int l, int r) {

    int n = r - l + 1;
    std::vector<ArrayValue> heap(n-1);

    //walking the new vector to input the array into it in the needed indexes
    // note to self: (in case i forget) i-l leads to 0...n-1, just remember the algebra you did with n, same amount of iterations happen. so you dont have to use tmpL again (embaressing) 
    for (int i = l; i <= r; i++) {
        heap[i-l] = array[i];
    }

    // the magic stuffs
    for (int i = (n/2)-1; i >= 0; i--) {
        heapify(heap, n, i);
    }

    for (int i = n-1; i >= 0; i--) {
        std::swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }

    //same as the first thing but in reverse lol
    for (int i = l; i <= r; i++) {
        array[i] = heap[i-l];
    }
}
