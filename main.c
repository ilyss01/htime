#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* access() */
int main(void) {
    FILE* file;
    time_t start_t;
    time_t end_t;
    uint32_t read_res;
    start_t = time(NULL);
    file = fopen("htime_time", "w+");

    printf("time: %lu\n", start_t);
    fprintf(file, "%lu", start_t);

    rewind(file);

    fscanf(file, "%lu", &end_t);
    printf("readed time: %lu\n", (unsigned long)end_t);
}
