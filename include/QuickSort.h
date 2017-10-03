#ifndef QUICKSORT_H
#define QUICKSORT_H


class QuickSort
{
    public:
        QuickSort(int  *arr, int size, int &compCount, int &moveCount);
        virtual ~QuickSort();
    protected:
    private:
        int partition(int *arr, int first, int last, int &compCount, int &moveCount);
        void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
};

#endif // QUICKSORT_H
