#ifndef FS_H
#define FS_H


struct superblock 
{
  int num_inodes;
  int num_blocks;
  int size_blocks;
};

struct inode 
{
  int size;
  char name[8];
};

struct disk_block 
{
  int next_block_num;
  char data[512];
};

void create_fs(); // init new fs
void mount_fs();  // load a fs 
void sync_fs();   // write the fs


#endif
