#include <stdio.h>
#include "Fs.h"

int main()
{
  create_fs();
  sync_fs();
  printf("Done");
}
