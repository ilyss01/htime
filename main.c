#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define XDG_CACHE

bool fileExist(const char *filename) {
  if (access(filename, F_OK) == 0) {
    return true; // File exists
  } else {
    return false; // File does not exist
  }
}

uint64_t delta(const time_t start, const time_t end) { return end - start; }

/* if file exists:
    read it's content
    find delta time
    print delta time
    remove file
   else
    make file
    write time into it
*/

int main(void) {
  FILE *file;
  time_t start_t;
  time_t end_t;
  uint64_t delta;
  char *file_path = getenv("XDG_CACHE_HOME");
  char file_name[] = "/htime";
  strcat(file_path, file_name);

  if (fileExist(file_path)) {
    time_t end_t = time(NULL);
    file = fopen("htime_time", "w+");
    if (!file) {
      perror("Couldn't open htime file");
      return 1;
    } else {
      fscanf(file, "%lu", &end_t);
      delta = end_t - start_t;
      printf("Delta: %lu\n", delta);

      fclose(file);

      remove(file_path);
      return 0;
    }
  } else {

    uint32_t read_res;
    start_t = time(NULL);
    file = fopen(file_path, "w+");

    printf("time: %lu\n", start_t);
    fprintf(file, "%lu", start_t);

    rewind(file);

    fscanf(file, "%lu", &end_t);
    printf("readed time: %lu\n", end_t);
    return 0;
  }
}
