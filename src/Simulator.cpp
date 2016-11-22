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
	char label[1025];

	if(!(fp = fopen(utility.fileName, "r"))) {
		perror(utility.fileName);
		exit(-1);
	}

	Cache *cache;
	if(utility.cacheType == CacheType::DIRECT_MAPPED) {
		cache = new DirectMapped(utility.cacheSize, utility.blockSize);
	} else {
		cache = new Associativity(utility.nWay, utility.replacementAlgorithm, utility.cacheSize);
	}

	// Read file
	bool isSkipLabel = false;
	while (fgets(&buff[0], 1024, fp)) {
		sscanf(buff, "0x%lx", &addrTmp);
		if(!isSkipLabel) {
			sscanf(buff, "%s", label);
			isSkipLabel = true;
			continue;
		}
		sscanf(buff, "0x%lx", &addrTmp);
		cache->access(addrTmp);
	}

	printf("=====================\n");
	printf(" Cache Specification \n");
	printf("=====================\n");

	if(utility.cacheType == CacheType::DIRECT_MAPPED) {
		printf("Cache type: Direct mapped\n"
			   "Cache size: %lu bytes\n"
			   "Block size: %lu bytes\n\n",
			   utility.cacheSize,
			   utility.blockSize);
	} else {
		printf("Cache type: Associativity\n"
			   "Cache size: %lu bytes\n"
			   "N-way: %u bytes\n"
			   "Replacement algorithm: %s\n\n",
			   utility.cacheSize,
			   utility.nWay,
		   	   utility.replacementAlgorithm == ReplacementAlgorithm::ROUND_ROBIN ? "Round robin" : "Least recently used");
	}

	cache->printStatus();

	printf("\nAddress file: %s (%s)\n", label, utility.fileName);

	printf("\nHit: %ld\n"
		   "Miss: %ld\n"
		   "Miss Rate: %.4f\n", cache->getHit(), cache->getMiss(), (float)cache->getMiss() / (float)cache->getNAccess());

}
