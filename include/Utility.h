#ifndef UTILITY_H
#define UTILITY_H

#include "Cache.h"

class Utility {
private:

public:
	// Cache structure parameters (by default)
	int cacheSize = 4;
	CacheType cacheType = CacheType::DIRECT_MAPPED;
	int blockSize = 4;
	int nWay = 2;
	ReplacementAlgorithm replacementAlgorithm = ReplacementAlgorithm::LEAST_RECENTLY_USED;
	char *fileName;

	bool isSetFileName = false;

	Utility();
	void showUsage(char *programName);
	void tokenizeArgv(int argc, char *argv[]);
};

#endif
