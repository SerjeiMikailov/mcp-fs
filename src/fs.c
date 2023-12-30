#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fs.h"

struct superblock sb;
struct inode *inodes;
struct disk_block *dbs;

void create_fs()
{
  sb.num_inodes = 10;
  sb.num_blocks = 100;
  sb.size_blocks = sizeof(struct disk_block);

  int i;

  inodes = malloc(sizeof(struct inode) * sb.num_inodes);
  for (i = 0; i < sb.num_inodes; i++)
  {
    inodes[i].size = -1;
    strcpy(inodes[i].name, "emptyfile");
  }

  dbs = malloc(sizeof(struct disk_block) * sb.num_blocks);
  for (i = 0; i < sb.num_blocks; i++)
  {
    dbs[i].next_block_num = -1;
  }
}

void sync_fs()
{
  FILE *file;
  file = fopen("fs_data", "w+");
  
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  // superblock
  fwrite(&sb, sizeof(struct superblock), 1, file);

  // write inodes
  int i;
  for (i = 0; i < sb.num_inodes; i++)
  {
    fwrite(&(inodes[i]), sizeof(struct inode), 1, file);
  }

  // write disk blocks
  for (i = 0; i < sb.num_blocks; i++)
  {
    dbs[i].next_block_num = -1;
    fwrite(&(dbs[i]), sizeof(struct disk_block), 1, file);
  }

  fclose(file);
}

