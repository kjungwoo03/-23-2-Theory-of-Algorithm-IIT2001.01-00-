#include <stdio.h>
#include <string.h>

// structure to store comparision/exchange num
typedef struct COMP_EXC_COUNT {
  int compCount;
  int exchCount;
} COMP_EXC_COUNT;

// function to swap two components of array
void swap(int *a, int *b);

// function to implement bubble sorting algorithm
COMP_EXC_COUNT bubbleSort(int array[], int n);

// function to print all components of array to check sorting is done well
void printArray(int array[], int size);

int main() {
    int data[] = {5, 10, 2, 30, 6, 4, 15, 7};  // question
    // int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // sorted
    // int data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  // reversed
    //int data[] = {1, 2, 4, 3, 6, 5, 7, 10, 8, 9};  // nearly sorted

    // calculate the size of data array
    int size = sizeof(data) / sizeof(data[0]);

    // print the array before sorting
    printf("Before Sorting : ");
    printArray(data, size);
    // printf("\n");
    
    // sorting the array using bubble sort
    COMP_EXC_COUNT stepCount = bubbleSort(data, size);

    // print the array after sorting
    printf("After Sorting : ");
    printArray(data, size);
    
    // print the comparision/exchange number
    printf("Comparision Num : %d\n", stepCount.compCount);
    printf("Exchange Num : %d\n", stepCount.exchCount);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

COMP_EXC_COUNT bubbleSort(int array[], int n) {
    // for i = 1:n,
    //     swapped = false
    //     for j = n:i+1,
    //         if a[j] < a[j-1],
    //             swap a[j,j-1]
    //             swapped = true
    //     → 불변: a[1..i]는 최종 정렬되어 있음
    //     break if not swapped
    // end

    COMP_EXC_COUNT stepCount = {0, 0};
    // printf("%d\n",  stepCount.compCount);
    // printf("%d\n", stepCount.exchCount);
    
    // 구현 시작 -->
    for(int i = 0; i < n; i++) {
        int swapped = 1;
        for(int j = n - 1; j > i; j--) {
            stepCount.compCount++;
            if(array[j - 1] > array[j]) {
                swap(&array[j - 1], &array[j]);
                swapped = 0;
                stepCount.exchCount++;
            }
        }
        printArray(array, n);
        printf("Comparision Num: %d\n", stepCount.compCount);
        printf("Exchange Num: %d\n", stepCount.exchCount);
        printf("\n");

        if(swapped == 1) {
            break;
        }
    }
    
    // <-- 구현 종료

    return stepCount;
}

void printArray(int array[], int size) {
    for(int i = 0; i < size; ++i) {
        // printf("Now i is %d\n", i);
        printf("%d  ", array[i]);
    }
    printf("\n");
}
