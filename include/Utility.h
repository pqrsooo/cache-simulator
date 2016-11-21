#ifndef UTILITY_H
#define UTILITY_H

#include "Cache.h"

class Utility {
private:

public:
	int cacheSize;
	CacheType cacheType;
	int blockSize;
	int nWay;
	ReplacementAlgorithm replacementAlgorithm;
	char *fileName;

	bool isSetFileName;

	Utility();
	void showUsage(char *programName);
	void tokenizeArgv(int argc, char *argv[]);
};

#endif
