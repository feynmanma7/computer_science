#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node; 

typedef struct Hash {
    struct Node *list[MAX];
} Hash; 

void build_hash(Hash *hash, int arr[][2], int len) {

    for (int i = 0; i < MAX; i++) { 
        //hash->list[i] = malloc(sizeof(Node));
        //hash->list[i]->key = -1;

        hash->list[i] = NULL;
    }

   for (int i = 0; i < len; i++) {
        int key = arr[i][0];
        int value = arr[i][1];

        Node *node = malloc(sizeof(Node));
        node->key = key;
        node->value = value;
        node->next = NULL;

        hash->list[key] = node;
   }
}

int get_value(Hash* hash, int key) {
        
    if (key > 0 && key < MAX && hash->list[key] != NULL) {
        return hash->list[key]->value;
    }

    return -1;
}

int main(void) {

    int arr[][2] = {{1, 3}, {2, 5}, {3, 7}, {4, 2}, {5, 4}};

    int len = 5;

    Hash *hash = malloc(sizeof(Hash));

    build_hash(hash, arr, len);

    for (int i = 0; i < 10; i++) {
        int value = get_value(hash, i);
        printf("key=%d, value=%d\n", i, value);
    }


    return 0;
}
