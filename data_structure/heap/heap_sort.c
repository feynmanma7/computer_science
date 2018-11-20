#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

unsigned int get_left_child_index(int i) {
    // Root starts from 0
    return ((i + 1) << 1) - 1;
}

unsigned int get_right_child_index(int i) {
    // Root starts from 0
    return (i + 1) << 1;
}

void max_heapify(int *heap, int size, int i) {
    // Root starts from 0

    if (i < 0 || i >= size) return;

    int left_child_idx = get_left_child_index(i);
    int right_child_idx = get_right_child_index(i);

    int largest_idx = i;
    
    if ((left_child_idx > 0 && left_child_idx < size) && heap[left_child_idx] > heap[largest_idx]) {
        largest_idx = left_child_idx;
    }

    if ((right_child_idx > 0 && right_child_idx < size) && heap[right_child_idx] > heap[largest_idx]) {
        largest_idx = right_child_idx;
    }
    
    if (largest_idx != i) {
        // swap heap[i], heap[largest_idx]
       swap(&heap[i], &heap[largest_idx]);

       max_heapify(heap, size, largest_idx);
    }

}

void print_heap(int *heap, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}


void build_max_heap(int *heap, int len) {
    // Root starts from 0

    int num = 0;

    /* Bug: unsigned int i in for loop ... */
    for (int i = (len+1) / 2; i >= 0; i--) {
        max_heapify(heap, len, i);
    }
}

void heap_sort(int *heap, int len) {

    build_max_heap(heap, len);

    int heap_size = len;

    // Root starts from 0.
    for (int i = len - 1; i >= 1; i--) {
        swap(&heap[0], &heap[i]);

        heap_size --;
        max_heapify(heap, heap_size, 0);        
    }
}

void top_small_K(int *arr, int len, int K) {

    int heap[K];
    for (int i = 0; i < K; i++) {
        heap[i] = arr[i];
    }

    build_max_heap(heap, K);

    for(int i = K; i < len; i++) {
        if (heap[0] > arr[i]) {
            heap[0] = arr[i];
            max_heapify(heap, K, 0);
        }
    }

    print_heap(heap, K);
}

int main(void) {
    int len = 9;
    int heap[] = {1, 3, 5, 7, 9, 8, 6, 4, 2};

    //build_max_heap(heap, len);

    heap_sort(heap, len);
    print_heap(heap, len);

    int K = 2;
    top_small_K(heap, len, K);

    return 0;
}