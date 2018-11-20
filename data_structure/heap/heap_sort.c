#include <stdio.h>
#include <stdlib.h>


unsigned int get_left_child_index(int i) {
    // Root start from 0
    return ((i + 1) << 1) - 1;
}

unsigned int get_right_child_index(int i) {
    // Root start from 0
    return (i + 1) << 1;
}

void max_heapify(int *heap, int len, int i) {
    // Root start from 0

    if (i < 0 || i >= len) return;

    int left_child_idx = get_left_child_index(i);
    int right_child_idx = get_right_child_index(i);

    int largest_idx = i;
    
    if ((left_child_idx > 0 && left_child_idx < len) && heap[left_child_idx] > heap[largest_idx]) {
        largest_idx = left_child_idx;
    }

    if ((right_child_idx > 0 && right_child_idx < len) && heap[right_child_idx] > heap[largest_idx]) {
        largest_idx = right_child_idx;
    }
    
    if (largest_idx != i) {
        // swap heap[i], heap[largest_idx]
        int tmp = heap[i];
        heap[i] = heap[largest_idx];
        heap[largest_idx] = tmp;

        max_heapify(heap, len, largest_idx);
    }

}

void print_heap(int *heap, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}


void build_max_heap(int *heap, int len) {
    // Root start from 0

    int num = 0;

    /* Bug: unsigned int i in for loop ... */
    for (int i = (len+1) / 2; i >= 0; i--) {
        max_heapify(heap, len, i);
    }
}


int main(void) {
    int len = 9;
    int heap[] = {1, 3, 5, 7, 9, 8, 6, 4, 2};

    build_max_heap(heap, len);
    print_heap(heap, len);

    return 0;
}