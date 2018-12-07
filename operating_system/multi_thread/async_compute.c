#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_LEN 100

/*
Create many threads, a thread_pool will be used in the future.
*/


char *input_file_name = "input.txt";

long file_size = 0;
long num_line = 0;
int num_thread = 4;
long num_char_per_thread = 0;

long sum = 0;


typedef struct Args_Struct {
    int thread_id;
    char ch;
} args_struct;


void *count_lines_thread(void *id) {
    
    FILE *fin = fopen(input_file_name, "r");
    
    if (fin == NULL) return NULL;
    
    long thread_id = id;
    
    fseek(fin, file_size / num_thread * thread_id, SEEK_SET);

    long cur_num_char = 0;
    
    char ch;
    
    long cur_num_line = 0;
    
    while ((ch = getc(fin)) != EOF) {
        cur_num_char++;
        
        if (ch == '\n') cur_num_line++;
        
        if (thread_id < num_thread - 1 &&
            cur_num_char >= num_char_per_thread) break;
    }
    
    num_line += cur_num_line;
    
    printf("id=%ld, cur_num_line=%ld\n", thread_id, cur_num_line);
    
    return NULL;
}

void *compute_sum_thread(void *arguments) {
    
    args_struct *args = (args_struct *) arguments;
    
    int thread_id = args->thread_id;
    char ch = args->ch;
    
    if ('0' < ch && ch < '9') {
        sum += ((ch - '0') * thread_id);
    }
    
    return NULL;
}


int main(void) {

    FILE *fin = fopen(input_file_name, "r");
    
    if (fin == NULL) {
        printf("No such file!\n");
        return -1;
    }
    
    char ch;
    
    sum = 0;
    
    int coff = 0;
    for (int i = 0; i < num_thread; i++) {
        coff += i;
    }
    
    printf("coff=%d\n", coff);
    
    char word[MAX_LEN];
    
    while ((ch = getc(fin)) != EOF) {
        
        if ('0' < ch && ch < '9') {
            sum += ((ch - '0') * coff);
        }
    }
    
    printf("Total sum, single thread = %d\n", sum);
    

    fseek(fin, 0L, SEEK_SET);
    
    sum = 0;
    pthread_t *pt = (pthread_t *)malloc(num_thread * sizeof(pthread_t));
    
    while ((ch = getc(fin)) != EOF) {
        
        for(int i = 0; i < num_thread; i++) {
            args_struct *args = (args_struct *)malloc(sizeof(args_struct));
            
            args->thread_id = i;
            args->ch = ch;
            
            pthread_create(&pt[i], NULL, compute_sum_thread, (void *)args);
            
            pthread_join(pt[i], NULL);
            
            free(args);
        }
        
    }
    
    printf("Total sum, multi threads = %d\n", sum);
    
    fclose(fin);
    
    return 0;
}

