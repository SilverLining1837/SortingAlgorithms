#include "MergeSort.h"

MergeSort::MergeSort(int  *arr, int size, int &compCount, int &moveCount)
{   int first = 0;
    int last = size;
    moveCount += 2;
    mergeSort(arr, first, last, compCount, moveCount);
}

MergeSort::~MergeSort()
{
    //dtor
}

void MergeSort::mergeSort(int  *arr, int first, int last,  int &compCount, int &moveCount){
    compCount++;
    if(first < last){
        int mid = first + (last - first)/2;
        moveCount++;
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid+1, last,compCount, moveCount);
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void MergeSort::merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount){
    int tempArray[last];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    moveCount += 5;
    compCount += 3;
    while((first1 <= last1) && (first2 <= last2)){
        compCount += 3;
        compCount++;
        if(arr[first1] <= arr[first2]){
            tempArray[index] = arr[first1];
            first1++;
            moveCount += 2;
        }
        else{
            tempArray[index] = arr[first2];
            first2++;
            moveCount += 2;
        }
        index++;
        moveCount += 1;
    }
    compCount += 1;
    while(first1 <= last1){
        compCount += 1;
        tempArray[index] = arr[first1];
        first1++;
        index++;
        moveCount += 3;
    }
     compCount += 1;
     while(first2 <= last1){
        compCount += 1;
        tempArray[index] = arr[first2];
        first2++;
        index++;
        moveCount += 3;
    }
    moveCount += 2;
    compCount += 1;
    for(index = first; index <= last; index++){
        compCount += 1;
        arr[index] = arr[index];
        moveCount += 2;
    }
}
