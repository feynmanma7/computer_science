#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int start, int end) {
    
    if (start >= end) return start;
    
    int pivot = start - 1;
    int pivot_value = arr[end];
    
    for (int i = start; i <= end - 1; i++) {
        if (arr[i] <= pivot_value) {
            pivot ++;
            swap(&arr[pivot], &arr[i]);
        }
    }
    
    pivot ++;
    swap(&arr[pivot], &arr[end]);
    
    return pivot;
}


void quick_sort(int *arr, int start, int end) {
    // Ascend Order
    
    if (start >= end) return;
    
    int pivot = partition(arr, start, end);
    quick_sort(arr, start, pivot - 1);
    quick_sort(arr, pivot + 1, end);
}


void print_arr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void permulate(int *arr, int len, int start, int end) {
    if (start >= end) {
        print_arr(arr, len);
        return;
    }
    
    for (int i = start; i <= end; i++) {
        if (i != start && arr[i] == arr[start]) continue;
        
        swap(&arr[i], &arr[start]);
        quick_sort(arr, start+1, end);
        permulate(arr, len, start+1, end);
        swap(&arr[i], &arr[start]);
    }
}


int main(void) {
    
    int arr[] = {1, 1, 2, 3};
    int len = 4;
    
    int start = 0;
    int end = len - 1;
    
    permulate(arr, len, start, end);
    
    int buf[] = {1, 4, 3, 2, 9, 8, 7, 6, 5};
    quick_sort(buf, 0,  8);
    print_arr(buf, 9);
    
    return 0;
}

