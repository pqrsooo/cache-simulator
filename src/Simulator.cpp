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
	unsigned long addrTmp;

	if(!(fp = fopen(utility.fileName, "r"))) {
		perror(utility.fileName);
		exit(-1);
	}

	// TODO: Initialize cache
	Cache *cache;
	if(utility.cacheType == CacheType::DIRECT_MAPPED) {
		cache = new DirectMapped(utility.cacheSize, utility.blockSize);
	} else {
		cache = new Associativity(utility.nWay, utility.replacementAlgorithm, utility.cacheSize);
	}

	cache->printStatus();

	// Read file
	bool isSkipFileName = false;
	int maxNPrint = 5;
	while (fgets(&buff[0], 1024, fp)) {
		sscanf(buff, "0x%lx", &addrTmp);
		if(!isSkipFileName) {
			isSkipFileName = true;
			continue;
		}
		if(maxNPrint-- > 0) {
			printf("%lx\n", addrTmp);
		}
		cache->access(addrTmp);
	}

	// TODO: Print current cache structure

	printf("\nHit: ld\n"
		   "Miss: ld\n"
		   "Miss Rate: %.4f\n", cache->getHit(), cache->getMiss(), (float)cache->getMiss() / (float)cache->getNAccess());

}
