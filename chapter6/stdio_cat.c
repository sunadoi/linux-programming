#include <stdio.h>
#include <stdlib.h>

static void do_cat(FILE *f);

int
main(int argc, char *argv[])
{
  int i;
  if (argc == 1) {
    do_cat(stdin);
    exit(0);
  }

  for (i = 1; i < argc; i++) {
    FILE *f;

    // 返り値はfile descripter
    f = fopen(argv[i], "r");
    if (!f) {
      perror(argv[i]);
      exit(1);
    }
    do_cat(f);
    fclose(f);
  }
  exit(0);
}

static void
do_cat(FILE *f)
{
  int c;

  // file descripterから読み込む。EOFが最後なので最後まで読み込むループ
  while((c = fgetc(f)) != EOF) {
    // putchar(c) = putc(c, stdout)
    if (putchar(c) < 0) exit(1);
  }
}
