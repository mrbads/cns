#include <stdio.h>
#include <stdlib.h>
#include "src/crypt.h"

int main(int argc, char *argv[]) {
  char *passwd = argv[1];
  // char *shadow = argv[2];
  FILE *file1 = fopen(passwd, "r");
  // FILE *file2 = fopen(shadow, "r");
  char line[256];
  char *token;
  char *array[7];
  int i = 0;
  // char *md5text;

  while (fgets(line, sizeof(line), file1) != NULL) {
    token = strtok(line, ":");
    while (token != NULL) {
      array[i++] = token;
      token = strtok(NULL, ":");
    }
    token = strtok(array[4]," ");
    printf("%s\n", token);
  }
  // passwd = fgets(line, sizeof(line), file1); //file to lines
  //
  // token = strtok(passwd, ":");  //separate on :
  // while (token != NULL) {
  //   array[i++] = token;
  //   token = strtok(NULL,":");
  // } //add tokens to array
  // token = strtok(array[4], " ");
  // printf("%s\n", token); //first name
  // shadow = fgets(line, sizeof(line), file2);
  //
  // printf("%s\n", shadow);
  // md5text = md5(token);
  // printf("%s\n", md5text);

  // free(md5text);
  fclose(file1);
  // fclose(file2);
  return 0;
}
