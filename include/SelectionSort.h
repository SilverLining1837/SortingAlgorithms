#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H


class SelectionSort
{
    public:
        SelectionSort(int  *arr, int size, int &compCount, int &moveCount);
        virtual ~SelectionSort();
    protected:
    private:
        int findIndexofLargest(const int *arr, int size,  int &compCount, int &moveCount);
};

#endif // SELECTIONSORT_H
