#include<stdio.h>
void reverseArray(int*start, int*end){
    if(end<=start){return;}
    int tempStart = *start;
    *start = *end;
    *end = tempStart;
    reverseArray(start+1, end-1);
}

void printArr(int* start, int size){
    for(int i=0; i<size; i++){
        printf("%d ", *(start+i));
    }
    printf("\n");
}

int main(){
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};             //odd length
    int sizeArr1 = sizeof(arr1)/sizeof(int);
    printf("Original Array 1: ");
    printArr(arr1, sizeArr1);
    reverseArray(arr1, arr1+(sizeArr1-1));
    printf("Reversed Array 1: ");
    printArr(arr1, sizeArr1);

    int arr2[] = {5, 10, 15, 20, 25, 30};           //even leangth array
    int sizeArr2 = sizeof(arr2)/sizeof(int);
    printf("Original Array 2: ");
    printArr(arr2, sizeArr2);
    reverseArray(arr2, arr2+(sizeArr2-1));
    printf("Reversed Array 2: ");
    printArr(arr2, sizeArr2);


return 0;
}
