#include <stdio.h>
#include <stdlib.h>

static void do_wc(FILE *f);

int main(int argc, char *argv[])
{
  int i;
  if (argc < 2) {
    fprintf(stderr, "%s: file name not given\n", argv[0]);
    exit(1);
  }
  for (i = 1; i < argc; i++) {
    FILE *f;

    f = fopen(argv[i], "r");
    if (!f) {
      perror(argv[i]);
      exit(1);
    }
    do_wc(f);
    fclose(f);
  }
  exit(0);
}

#define BUFFER_SIZE 2048

static void
do_wc(FILE *f)
{
  // 最終行の文を最初にカウントしておく
  unsigned long count = 1;
  int c;

  while((c = fgetc(f)) != EOF) {
    if (c == '\n') {
      count++;
    }
  }
  printf("%lu\n", count);
}
