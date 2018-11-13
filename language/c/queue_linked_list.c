#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Queue {
    /*
    Wrong: Node* front, rear;
    Right: Node *front, *rear;
    */
    Node *front, *rear;     
} Queue; 

void enqueue(Queue *queue, int val);
int dequeue(Queue *queue);
void print_queue(Queue *queue);
void build_queue(Queue *queue, int arr[], int len);


void print_queue(Queue *queue) {
    Node *node = queue->front;
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int dequeue(Queue *queue) {
    if (queue->front == NULL) return -1;

    Node *node = queue->front;
    queue->front = node->next;

    int val = node->val;
    free(node);

    return val;
}

void enqueue(Queue *queue, int val) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (queue->rear == NULL) {        
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

void build_queue(Queue *queue, int arr[], int len) {
    for (int i = 0; i < len; i++) {
       enqueue(queue, arr[i]);
    }
}

int main(void) {

    int arr[] = {1, 3, 5, 7, 9};
    int len = 5;

    Queue *queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    build_queue(queue, arr, len);
    print_queue(queue);

    dequeue(queue);
    print_queue(queue);

    return 0;
}