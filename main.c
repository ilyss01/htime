#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

bool fileExist(const char* filename) {
  return (access(filename, F_OK) == 0);
}

time_t delta(const time_t start, const time_t end) { return (end - start); }

/* if file exists:
    read it's content
    find delta time
    print delta time
    remove file
   else
    make file
    write time into it
*/

int main(int argc, char** argv) {
  /* TODO: argv implementation, more functions */
  /* TODO: fix time bug */
  FILE* file;
  time_t start_t;
  time_t end_t;

  char* file_path = getenv("XDG_CACHE_HOME");
  char file_name[] = "/htime";
  strcat(file_path, file_name);
  
  if (fileExist(file_path)) {
  /* file exists, need to print the difference start and end and to remove the file */
    time_t end_t = time(NULL);
    file = fopen("htime_time", "w+");
    if (!file) {
      perror("Couldn't open htime file");
      return 1;
    } else {
      fscanf(file, "%lu", &start_t);
      printf("Delta: %lu\n", end_t - start_t);

      fclose(file);
      remove(file_path);
      return 0;
    }
  } else {
    /* file doesn't exist, need to create it and write time in there */
    file = fopen(file_path, "w+");
    if (!file) {
      perror("Couldn't create htime file");
      return 1;
    } else {
      fprintf(file, "%lu", time(NULL));
      printf("Created htime file");
      return 0;
    }
  }
}
