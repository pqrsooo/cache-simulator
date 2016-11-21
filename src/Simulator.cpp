#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "Utility.h"
#include "Cache.h"
#include "DirectMapped.h"
#include "Associativity.h"

int main(int argc, char *argv[]) {
	Utility utility;
	utility.tokenizeArgv(argc, argv);

	if(!utility.isSetFileName) {
		fprintf(stderr, "Please specify address file\n\n");
		// Show usage
		utility.showUsage(argv[0]);
		exit(-1);
	}

	FILE *fp;
	char buff[1025];
	unsigned long addrTemp;

	if(!(fp = fopen(utility.fileName, "r"))) {
		perror(utility.fileName);
		exit(-1);
	}

	// TODO: Initialize cache

	// Read file
	while (fgets(&buff[0], 1024, fp)) {
		sscanf(buff, "0x%lx", &addrTemp);

		// access(addrTemp);
	}

	// TODO: Print current cache structure

	// printf("Hit: %7d Miss: %7d\n", HIT, MISS);

}
