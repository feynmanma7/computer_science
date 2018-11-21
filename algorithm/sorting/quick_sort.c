#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int partition(int *arr, int start, int end) {
    /* return the partition place p,
     such that arr[start:p-1] <= arr[p], arr[p+1:end] > arr[p] */
    
    if (start >= end) return start;
    
    // The place for pivot value
    int pivot = start - 1;

    int pivot_value = arr[end];
    
    for (int i = start; i <= end - 1; i ++) {
        if (arr[i] <= pivot_value) {
            pivot ++;
            swap(&arr[i], &arr[pivot]);
        }
    }
    
    pivot++;
    swap(&arr[end], &arr[pivot]);
    
    return pivot;
}


void quick_sort(int *arr, int start, int end) {
    /* quick sort for arr,  [start, end], in ascend order */
    
    if (start >= end) return;
    
    int pivot = partition(arr, start, end);
    quick_sort(arr, start, pivot-1);
    quick_sort(arr, pivot+1, end);
}


void print_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}


int main(void) {
    int len = 9;
    int arr[] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
    
    int start = 0;
    int end = len - 1;
    
    print_array(arr, len);
    quick_sort(arr, start, end);
    print_array(arr, len);
    
    return 0;
}
