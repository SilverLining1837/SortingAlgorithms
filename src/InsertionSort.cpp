#include "InsertionSort.h"
InsertionSort::InsertionSort(int theArray[], int n)
{
    for(int unsorted = 1; unsorted < n; unsorted++){
        int nextItem = theArray[unsorted];
        int loc = unsorted;

        while((loc > 0) && theArray[loc-1] > nextItem){
            theArray[loc] = theArray [loc-1];
            loc--;
        }
        theArray[loc] = nextItem;
    }
}

InsertionSort::~InsertionSort()
{
    //dtor
}
