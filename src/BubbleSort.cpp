#include "BubbleSort.h"
#include <algorithm>
BubbleSort::BubbleSort(int theArray[], int n)
{
    bool sorted = false;
    int pass = 1;
    while(!sorted && (pass < n)){
        sorted = true;
        for(int index = 0; index < n - pass; index++){
            int nextIndex = index + 1;
            if(theArray[index] > theArray[nextIndex]){
                std::swap(theArray[index], theArray[nextIndex]);
                sorted = false;
            }
        }

        pass++;
    }
}

BubbleSort::~BubbleSort()
{
    //dtor
}
