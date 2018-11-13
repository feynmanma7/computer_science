#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
}  Node;


struct Node* build_list(int arr[], int len) {
    if(len <= 0) return NULL;

    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for(int i = 0; i < len; i++) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->val = arr[i];
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = head;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }

    return head;
}


struct Node* add_node(struct Node* head, int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    
    if (head == NULL) return node;

    struct Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = node;
    return head;
}


struct Node* delete_node(struct Node* head, int val) {
    struct Node* node = head;

    /* node is the node to delete, pre is the node before node to delete. */
    struct Node* pre = NULL;
    while(node && node->val != val) {
        pre = node;
        node = node->next;
    }

    if (node == NULL) {
        // Not found
        printf("Val=%d is not found in the linked list!\n", val);
        return head;
    }

    if (node == head && pre == NULL) {
        head = head->next;
    } else {
        pre->next = node->next;
    }

    free(node);

    return head;
}


void print_list(struct Node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}


int main(void) {
    int arr[5] = {1, 3, 5, 7, 9};
    int len = 5;
    struct Node* head = build_list(arr, len);
    print_list(head);
    
    struct Node* head_2 = NULL;
    for (int i = 0; i < len; i++) {
        head_2 = add_node(head_2, arr[i]);
    }
    print_list(head_2);

    head = delete_node(head, 1);
    print_list(head);

    return 0;
}