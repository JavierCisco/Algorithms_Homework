#include <sort.hpp>
#include <graph.hpp>

//extern
std::string sortAlgName = "Quick Sort";

void sort(std::vector<ArrayValue> &array, int l, int r) {
    //term conds.
    if (l >= r)
    	return;

    //choosing r (highest) for pivot
    int pivot = r;

    //partitioning blob
    int i = l - 1;    
    for (int j = l; j < r; j++) {
        if ( (array[j].key < array[pivot].key) || (array[j].key == array[pivot].key && array[j].value < array[pivot].value) ) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    // put pivot back
    std::swap(array[i+1], array[r]);
    pivot = i + 1;

    //recursive calls
    sort(array, l, pivot-1);
    sort(array, pivot+1, r);
}


