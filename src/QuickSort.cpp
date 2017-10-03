#include "QuickSort.h"
#include <algorithm>
QuickSort::QuickSort(int  *arr, int size, int &compCount, int &moveCount)
{
    moveCount += 2;
    int first = 0;
    int last = size;
    quickSort(arr, first, last, compCount, moveCount);
}

QuickSort::~QuickSort()
{
    //dtor
}
int QuickSort::partition(int *arr, int first, int last, int &compCount, int &moveCount)
{
    moveCount += 2;
    int pivot = arr[first];
    int pIndex = arr[last];
    moveCount += 2;
    compCount += 1;
    for(int i = last; i > first; i--){
        compCount += 2;
        if(arr[i] <= pivot){
            std::swap(arr[i], arr[pIndex]);
            pIndex--;
            moveCount += 4;
        }
        moveCount += 1;
    }
    std::swap(arr[pIndex], arr[first]);
    moveCount += 1;
    return pIndex;
}

void QuickSort::quickSort(int *arr, int first, int last, int &compCount, int &moveCount){
    int pivotIndex = partition(arr, first, last, compCount, moveCount);
    moveCount += 1;
    quickSort(arr, first, pivotIndex - 1,  compCount, moveCount);
    quickSort(arr, pivotIndex + 1, last,  compCount, moveCount);
}
