#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

typedef struct Node Node;

Node* build_list(int arr[], int len) {
    if(len <= 0) return NULL;

    Node* head = NULL;
    Node* tail = NULL;
    
    for(int i = 0; i < len; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
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


Node* add_node(Node* head, int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    
    if (head == NULL) return node;

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = node;
    return head;
}


Node* delete_node(Node* head, int val) {
    Node* node = head;

    /* node is the node to delete, pre is the node before node to delete. */
    Node* pre = NULL;
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


void print_list(Node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}


int main(void) {
    int arr[5] = {1, 3, 5, 7, 9};
    int len = 5;
    Node* head = build_list(arr, len);
    print_list(head);
    
    Node* head_2 = NULL;
    for (int i = 0; i < len; i++) {
        head_2 = add_node(head_2, arr[i]);
    }
    print_list(head_2);

    head = delete_node(head, 1);
    print_list(head);

    return 0;
}