#include "main.h"
#include "Sorting.h"
#include "time.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
	// Allocating space for arrays
    int arr1[20000];
    int arr2[20000];
    int arr3[20000];

	// Declaring counters for three separated algorithms
    int compCount1;
    int moveCount1;

    int compCount2;
    int moveCount2;

    int compCount3;
    int moveCount3;
	// Elements for random array
    int index;

    for(int i = 0; i < 20000; i++){
        index = rand();

        arr1[i] = index;
        arr2[i] = index;
        arr3[i] = index;
    }
	// Initializing the arrays as sorting
    sorting s1;
    sorting s2;
    sorting s3;
    clock();
    s1.selectionSort(arr1, 20000, compCount1, moveCount1); // Using the first array for selection sort

    cout << clock();
    cout << "\nMoves for selection sort: ";
    cout << moveCount1;
    cout << "\nComparisons for selection sort: ";
    cout << compCount1;
    clock();
    s2.mergeSort(arr2, 20000, compCount2, moveCount2); // Using the first array for merge sort
    cout << "\n";
    cout << clock();
    cout << "\nMoves for merge sort: ";
    cout << moveCount2;
    cout << "\nComparisons for merge sort: ";
    cout << compCount2;
    clock();
    s3.quickSort(arr3, 20000, compCount3, moveCount3); // Using the first array for quick sort
    cout << "\n";
    cout << clock();
    cout << "\nMoves for quick sort: ";
    cout << moveCount3;
    cout << "\nComparisons for quick sort: ";
    cout << compCount3;
}
