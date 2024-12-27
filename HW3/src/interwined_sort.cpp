#include <iostream>
#include <vector>
#include <linked_list.hpp> 
#include <graph.hpp> 
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sort.hpp>
#include <cmath>
#include <chrono>

#ifdef OPENCV
#include <opencv2/opencv.hpp>
#endif

bool verify(std::vector<ArrayValue> &array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1)
            continue;
        int j = i + 2;
        if (j >= n)
            break;
        if ((array[j].key < array[i].key) || (array[j].key == array[i].key && array[j].value < array[i].value))
            return false;
    }
    
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0)
            continue;
        int j = i + 2;
        if (j >= n)
            break;
        if ((array[j].key > array[i].key) || (array[j].key == array[i].key && array[j].value > array[i].value))
            return false;
    }

    return true;
}

bool testSort() {
    std::cout << "You are using " << sortAlgName << " algorithm" << std::endl;
    int n = 10;
    for (int k = 0; k < 6; ++k) {
        double avgTime = 0.0;
        std::cout << "[Test Case " << k + 1 << "]. Performing Testing " << sortAlgName << " on Array of " << n << " elements." << std::endl;
        int totalIter = 100;
        if (n == 1000000)
            totalIter = 10;
        for (int it = 0; it < 100; ++it) {
            std::vector<ArrayValue> array;
                for (int i = 0; i < n; ++i)
            array.push_back(ArrayValue(rand() % n, rand() % n)); 
            auto start = std::chrono::high_resolution_clock::now();
            sort(array, 0, n-1);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            avgTime += elapsed.count();
            if (verify(array) == false) {
                std::cout << "[Fail Test Case " << k + 1 << "]. Your " << sortAlgName <<  " Implementation Is Incorrect" << std::endl << std::endl;
                return false;
            }

        }
        n *= 10;
        std::cout << "[Pass Test Case " << k + 1 << "]. Average Running Time of Your " << sortAlgName <<  " Implementation Is " << std::fixed << std::setprecision (15) << avgTime/totalIter << " Seconds" << std::endl << std::endl;
    }
    return true;
}

int main(int argc, char **args) {
    
    std::cout << "Perform unit test on the sorting algorithm" << std::endl;
    if (testSort())
        std::cout << "Your sorting implementation is correct\n" << std::endl;
    else {
        std::cout << "Your sorting implementation is incorrect\n" << std::endl;
        return -1;
    }
    
}
