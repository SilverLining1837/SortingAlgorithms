#include "findMin.h"
#include <iostream>
int main(){
    findMin m;
    int foo [11]= { 25,-5,80,16,11,78,9,20,28,15,16 };
    std::cout << m.findmin(foo, 11);

}
int findMin::findmin(int* arr, int size){
    if(size <= 1)
        return arr[0];
    else{
        return min(arr[0], findmin(arr+1, size-1));
    }
}
int findMin::min(int a, int b){
    return (a<b)?a:b;
}
