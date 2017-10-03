#ifndef MERGESORT_H
#define MERGESORT_H


class MergeSort
{
    public:
        MergeSort(int  *arr, int size, int &compCount, int &moveCount);
        virtual ~MergeSort();
    protected:
    private:
        void mergeSort(int  *arr, int first, int last,  int &compCount, int &moveCount);
        void merge(int theArray[], int first, int mid, int last,  int &compCount, int &moveCount);
};

#endif // MERGESORT_H
