#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Merge Sort";

//merge function even though i thought i would get off easy by using the algorithms library merge function but it spat out more letters than i can read
void merge(std::vector<ArrayValue> &array, int l, int m, int r) {
    //getting left and right sides 
    //note to self: array [l...m] size is m-l +1 to take into account and give enough space, AND array[m+1...r] does NOT bc it already has the extra +1 from the last index into account
    int side1 = m - l + 1;
    int side2 = r - m;

    //tmp vectors
    std::vector<ArrayValue> leftArr(side1), rightArr(side2);

    //getting the respective data for each array
    for (int i = 0; i < side1; i++)
        leftArr[i] = array[l + i];

    for(int j = 0; j < side2; j++)
        rightArr[j] = array[m + 1 + j];

    //prepping vars for walk through
    int i = 0, j = 0;
    int k = l;

    //the act of merging 
    while (i < side1 && j < side2) {
        if( (leftArr[i].key < rightArr[j].key) || (leftArr[i].key == rightArr[j].key && leftArr[i].value < rightArr[j].value)) {
            array[k] = leftArr[i];
            i++;
        }
        else {
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //checking in case something was left behind
    while (i < side1) {
        array[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < side2) {
        array[k] = rightArr[j];
        j++;
        k++;
    }
}

void sort(std::vector<ArrayValue> &array, int l, int r) {
    //term. conds.
    if (l >= r)
        return;

    //mid point
    int m = (l + (r-1) ) / 2;

    //recursive calls to split into 2 arrays
    sort(array, l, m);
    sort(array, m+1, r);

    //making own merge
    merge(array, l, m, r);

    // //getting the info thru merge function given in algorithms library
    // merge(array[l], array[m], array[m+1], array[r], tmp.begin());
}