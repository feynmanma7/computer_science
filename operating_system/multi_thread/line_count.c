#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char *input_file_name = "input.txt";

long file_size = 0;
long num_line = 0;
int num_thread = 4;
long num_char_per_thread = 0;

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

int main(void) {

    FILE *fin = fopen(input_file_name, "r");
    
    num_thread = 10;
    
    if (fin == NULL) {
        printf("No such file!");
        return -1;
    }
    
    fseek(fin, 0L, SEEK_END);
    file_size = ftell(fin);
    printf("file_size=%ld\n", file_size);
    
    num_char_per_thread = file_size / num_thread;
    
    printf("num_char_per_thread=%ld\n", num_char_per_thread);
    

    pthread_t *pt = (pthread_t *)malloc(num_thread * sizeof(pthread_t));
    
    int i;
    for (i = 0; i < num_thread; i++) {
        pthread_create(&pt[i], NULL, count_lines_thread, (void *)i);
    }
    
    for (i = 0; i < num_thread; i++) {
        pthread_join(pt[i], NULL);
    }
    
    fclose(fin);
   
    printf("Total line number is %ld\n", num_line);
    
    return 0;
}

