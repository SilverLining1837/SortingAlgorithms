#include "SelectionSort.h"
#include <algorithm>
SelectionSort::SelectionSort(int  *arr, int size, int &compCount, int &moveCount)
{
    moveCount += 2;
    compCount += 1;
    for(int last = size-1; last >=1; last--){
        compCount += 1;
        int largest = findIndexofLargest(arr, last+1, compCount, moveCount);
        std::swap(arr[largest], arr[last]);
        moveCount += 5;
    }
}

SelectionSort::~SelectionSort()
{
    //dtor
}

int SelectionSort::findIndexofLargest(const int *arr, int size,  int &compCount, int &moveCount){
    moveCount += 1;
    int indexSoFar = 0;

    moveCount += 2;
    compCount += 1;
    for(int currentIndex = 1; currentIndex < size; currentIndex++){
        compCount += 2;
        if(arr[currentIndex] > arr [indexSoFar]){
            moveCount += 1;
            indexSoFar = currentIndex;
        }
        moveCount += 1;
    }
    return indexSoFar;
}
