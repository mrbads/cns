#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <crypt.h>

int main(int argc, char const *argv[]) {
  const char *passwd = argv[1];
  const char *shadow = argv[2];
  FILE *file1 = fopen(passwd, "r");
  FILE *file2 = fopen(shadow, "r");
  char line[256];
  char line2[256];
  char *array[7];
  char *array2[7];
  char *token;
  char *token2;
  char *name;
  char salt[] = "$1$2X$fffff";
  const char *const seedchars = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *hash;
  int i = 0;
  int x = 0;

  while (1) {
    //get userid and first name
    if (fgets(line, sizeof(line), file1) == NULL) break; {
      token = strtok(line, ":");
      printf("%s: ", token );
      while (token != NULL) {
        array[i++] = token;
        token = strtok(NULL, ":");
      }
      name = strtok(array[4], " ");
      printf("%s\n", name);
    }
    i = 0;
    //get the hashed password
    if (fgets(line2, sizeof(line2), file2) == NULL) break; {
      token2 = strtok(line2, ":");
      while (token2 != NULL) {
        array2[x++] = token2;
        token2 = strtok(NULL, ":");
      }
      printf("%s\n", array2[1]);
    }
    x = 0;

    hash = crypt(name,salt);
    printf("%s\n", hash);
    // compare hashed password to hashed first name
    // score = strcmp(hashed_name, hashed_passwd);
    // if (score = 0) {
    //   printf("%s: %s", token, name);
    // }
    // // compare hashed password to hashed password top 250
    // score = strcmp(hashed_top, hashed_passwd);
    // if (score = 0) {
    //   printf("%s: %s", token, top);
    // }
  }
  fclose(file1);
  fclose(file2);

  return 0;
}
