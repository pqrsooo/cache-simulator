#include <stdio.h>
#include <string.h>
#include "simulator.h"

long MISS;
long HIT;
struct Cache cache[INDEX_SIZE];
int init() {
	MISS=0;
	HIT=0;
	int i;
    for(i=0;i<INDEX_SIZE;i++){
        cache[i].valid=0;
        cache[i].tag=0;
        cache[i].dirty=0;
    }
}
int calAddr(unsigned long addr,unsigned long *tag,unsigned long *idx,unsigned long *offset) {
	unsigned long tmp;
	int i;
	*tag=addr>>(OFFSETLEN+INDEXLEN);
	tmp=0;
	for(i=0;i<INDEXLEN;i++) {
		tmp<<=1;
		tmp|=0x01;
	}
	*idx=addr>>OFFSETLEN & tmp;
	tmp=0;
	for(i=0;i<OFFSETLEN;i++) {
		tmp<<=1;
		tmp|=0x01;
	}
	*offset=addr & tmp;
}
int access(unsigned long addr){
    unsigned long offset;
	unsigned long tag;
	unsigned long idx;
    int i;
	int valid=0;
	calAddr(addr,&tag,&idx,&offset);
	if(cache[idx].tag==tag && cache[idx].valid){
        HIT++;
	}
	else{
        MISS++;
        cache[idx].valid=1;
        cache[idx].tag = tag;
	}

}
int main(int argc,char *argv[]){
    FILE *input;
    char buff[1025];
    unsigned long myaddr;
    if (argc<2) {
		fprintf(stderr,"Please specify address file\n");
		exit(-1);
	}
    input=fopen(argv[1],"r");
    //read file
    while (fgets(& buff[0],1024,input)) {
		sscanf(buff,"0x%x",&myaddr);
        access(myaddr);
    }
    printf("HIT:%7d MISS: %7d",HIT,MISS);

}
