#include "sorting.h"
#include <algorithm>
#include <iostream>
sorting::sorting()
{

}

sorting::~sorting()
{
    //dtor
}

void sorting::mergeSort(int  *arr, int size,  int &compCount, int &moveCount){
    int first = 0;
    int last = size;
    mergeSort1(arr, first, last, compCount, moveCount);
}

void sorting::mergeSort1(int  *arr, int first, int last,  int &compCount, int &moveCount){
    compCount++; // Comparison for if
    if(first < last)
    {
        int mid = first + (last - first)/2; // Take the middle index of array
        moveCount += 4; // 4 arithmetic operations are done
        mergeSort1(arr, first, mid, compCount, moveCount); // First half of the array is gone to the recursion
        mergeSort1(arr, mid+1, last,compCount, moveCount); // Second half of the array is gone to the recursion
        merge(arr, first, mid, last, compCount, moveCount); // Merging sub arrays
    }
}

void sorting::merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount){
	// Initializing required variables
    int tempArray[last]; // Creating a temporary array
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    moveCount += 5;
    compCount += 3; // Comparisons on the while
    while((first1 <= last1) && (first2 <= last2)){
        compCount += 3; // If while loop is continuing, there is additional comparisons
        compCount++;	// Comparison for if
        if(arr[first1] <= arr[first2]){
            tempArray[index] = arr[first1]; // Merging two sub arrays
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
	// Moving the rest of elements after merging into the temporary array
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
    for(index = first; index <= last; index++){ // Moving the sorted array into the upper array.
        compCount += 1;
        arr[index] = tempArray[index];
        moveCount += 2;
    }
}

int sorting::partition(int *arr, int first, int last, int &compCount, int &moveCount)
{
    moveCount += 2;
    int pivot = arr[first]; // Selected the first element as pivot
    int pIndex = last; // Pivot index becomes the last index of the array
    moveCount += 2;
    compCount += 1;

    for(int i = last; i > first; i--){ // Partition algorithm which is told on the class
        compCount += 2;
        if(arr[i] >= pivot){
            std::swap(arr[i], arr[pIndex]);
            pIndex--;
            moveCount += 4;
        }
        moveCount += 1;
    }
    std::swap(arr[first], arr[pIndex]); // Swap the pivot into its right place
    moveCount += 3;
    return pIndex;
}

void sorting::quickSort(int *arr, int size, int &compCount, int &moveCount){
    int first = 0;
    int last = size;
    quickSort1(arr, first, last,  compCount, moveCount);
}

void sorting::quickSort1(int *arr, int first, int last, int &compCount, int &moveCount){
    compCount++;
    int pivotIndex;
    if(first < last){
        pivotIndex = partition(arr, first, last, compCount, moveCount); // Taking the right index of pivot
        moveCount += 3;
        quickSort1(arr, first, pivotIndex - 1,  compCount, moveCount); // Recursively sorting algorithm left and right of pivot
        quickSort1(arr, pivotIndex + 1, last,  compCount, moveCount);
    }
}

void sorting::selectionSort(int  *arr, int size, int &compCount, int &moveCount)
{
    moveCount += 2;
    compCount += 1;
    for(int last = size-1; last >=1; last--){ // Selection sort algorithm taken from the textbook
        compCount += 1;
        int largest = findIndexofLargest(arr, last+1, compCount, moveCount);
        std::swap(arr[largest], arr[last]);
        moveCount += 4;
    }
}


int sorting::findIndexofLargest(int *arr, int size,  int &compCount, int &moveCount){
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

