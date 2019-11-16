#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  DIR *stream = opendir("."); // open current directory
  if (stream == NULL) {
    printf("errno: %s\n", strerror(errno));
  }
  struct dirent *file = readdir(stream);
  printf("Scanning current directory...\n\n");
  int size = 0;
  while (file != NULL) {
    struct stat file_info;
    int error = stat(file->d_name, &file_info);
    if (error == -1) {
      printf("errno: %s\n", strerror(errno));
    }
    // list the file, directory or not
    if (file->d_type == DT_DIR) {
      printf("\t%s\t(DIRECTORY)\n", file->d_name);
    } else {
      printf("\t%s\n", file->d_name);
    }
    // add to the total size
    size += file_info.st_size;
    file = readdir(stream);
  }
  printf("\nTotal directory size: %d Bytes\n", size);
  // list all files in directory
  // specify while files are directories
  // show total size of all regular files

}
