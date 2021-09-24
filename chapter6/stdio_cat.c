#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
  int i;
  for (i = 1; i < argc; i++) {
    FILE *f;
    int c;

    // 返り値はfile descripter
    f = fopen(argv[i], "r");
    if (!f) {
      perror(argv[i]);
      exit(1);
    }
    // file descripterから読み込む。EOFが最後なので最後まで読み込むループ
    while((c = fgetc(f)) != EOF) {
      // putchar(c) = putc(c, stdout)
      if (putchar(c) < 0) exit(1);
    }
    fclose(f);
  }
  exit(0);
}