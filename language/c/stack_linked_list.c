#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node ;

Node* build_stack(int arr[], int len);
Node* push_stack(Node* top,  int val);
void print_stack(Node* top);
Node* pop_stack(Node* top);


Node* build_stack(int arr[], int len) {

    Node* top = NULL;
    for (int i = 0; i < len; i++) {
        top = push_stack(top, arr[i]);
    }

    return top;
}


Node* push_stack(Node* top,  int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (top == NULL) {
        top = node;
    } else {
        node->next = top;
        top = node;
    }

    return top;
}

void print_stack(Node* top) {
    
    int val = 0;

    while(top) {
        printf("%d ", top->val);
        top = pop_stack(top);
    }

    printf("\n");
}


Node* pop_stack(Node* top) {
    if (top == NULL) {
        return top;
    } else {
        Node* node = top;
        top = node->next;
        
        free(node);
        return top;
    }
}


int main(void) {
    int arr[] = {1, 3, 5, 7, 9};
    int len = 5;

    Node* top = build_stack(arr, len);
    print_stack(top);
}