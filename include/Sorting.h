#ifndef SORTING_H
#define SORTING_H


class sorting
{
    public:
        sorting();
        virtual ~sorting();
        void mergeSort(int  *arr, int size,  int &compCount, int &moveCount);
        void quickSort(int *arr, int size, int &compCount, int &moveCount);
        void selectionSort(int  *arr, int size, int &compCount, int &moveCount);
    protected:
    private:
        void mergeSort1(int *arr, int first, int last, int &compCount, int &moveCount);
        void quickSort1(int *arr, int first, int last, int &compCount, int &moveCount);
        void merge(int *arr, int first, int mid, int last,  int &compCount, int &moveCount);
        int partition(int *arr, int first, int last, int &compCount, int &moveCount);
        int findIndexofLargest(int *arr, int size,  int &compCount, int &moveCount);

        int first;
        int last;
};

#endif // SORTING_H
