#ifndef UTILITY_H
#define UTILITY_H

#include "Cache.h"

class Utility {
private:

public:
	unsigned long cacheSize;
	CacheType cacheType;
	unsigned long blockSize;
	unsigned int nWay;
	ReplacementAlgorithm replacementAlgorithm;
	char *fileName;

	bool isSetFileName;

	Utility();
	void showUsage(char *programName);
	void tokenizeArgv(int argc, char *argv[]);
};

#endif
