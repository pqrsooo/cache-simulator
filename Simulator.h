#ifndef SIMULATOR_H_INCLUDED
#define SIMULATOR_H_INCLUDED

#define CACHE_SIZE 1024
#define INDEX_SIZE 256
#define BLOCK_SIZE 4
#define TAGLEN 22
#define INDEXLEN 8
#define OFFSETLEN 2
typedef unsigned char Byte;
typedef unsigned char bool;
typedef struct Cache{
    bool valid;
    bool dirty;
    unsigned long tag;
	Byte data[BLOCK_SIZE];
};

#endif // SIMULATOR_H_INCLUDED
