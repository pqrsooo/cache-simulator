#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "Utility.h"

Utility::Utility() {
	// Cache structure parameters (by default)
	this->cacheSize = 4 * (1 << 10);
	this->cacheType = CacheType::DIRECT_MAPPED;
	this->blockSize = 4;
	this->nWay = 2;
	this->replacementAlgorithm = ReplacementAlgorithm::LEAST_RECENTLY_USED;

	this->isSetFileName = false;
}

void Utility::showUsage(char *programName) {
	printf("Usage: %s [options] <path_to_address_file>\n\n"
	       "Options: \n"
	       "  -s, --size <cache_size>\t\tSet cache size (kilobyte)\n"
	       "  -sb, --size-b <cache_size>\t\tSet cache size (byte)\n"
	       "  -dm, --direct-mapped <block_size>?\tSet cache structure to a direct mapped with specific block size (4 by default)\n"
	       "  -as, --associativity <n_way>?\t\tSet cache structure to an associativity with specific n (2 by default)\n"
	       "  -lru, --least-recently-used\t\tSet least recently used as a replacement algorithm when --associativity option is triggered (default)\n"
	       "  -rr, --round-robin\t\t\tSet round robin as a replacement algorithm when --associativity option is triggered\n"
	       "  -h, --help\t\t\t\tShow this help message\n"
	       "Note that '?' after <argument> indicates that <argument> is optional\n", programName);
}

void Utility::tokenizeArgv(int argc, char *argv[]) {
	// Tokenize argv
	int argcCount = 1;
	while(argcCount < argc) {
		if(strcmp(argv[argcCount], "--size") == 0 || strcmp(argv[argcCount], "-s") == 0) {
			// Cache size (kilobyte)
			if(argcCount + 1 < argc) {
				this->cacheSize = atoi(argv[argcCount + 1]) * (1 << 10);
			} else {
				// Error
				fprintf(stderr, "%s option requires one argument\n", argv[argcCount]);
				exit(-1);
			}
			argcCount += 2;
		} else if(strcmp(argv[argcCount], "--size-b") == 0 || strcmp(argv[argcCount], "-sb") == 0) {
			// Cache size (byte)
			if(argcCount + 1 < argc) {
				this->cacheSize = atoi(argv[argcCount + 1]);
			} else {
				// Error
				fprintf(stderr, "%s option requires one argument\n", argv[argcCount]);
				exit(-1);
			}
			argcCount += 2;
		} else if(strcmp(argv[argcCount], "--direct-mapped") == 0 || strcmp(argv[argcCount], "-dm") == 0) {
			// Direct mapped
			this->cacheType = CacheType::DIRECT_MAPPED;
			if(argcCount + 1 < argc) {
				// Block size (Byte)
				this->blockSize = atoi(argv[argcCount + 1]);
				argcCount += 2;
			} else {
				// Optional
				argcCount += 1;
			}
		} else if(strcmp(argv[argcCount], "--associativity") == 0 || strcmp(argv[argcCount], "-as") == 0) {
			// Associativity
			this->cacheType = CacheType::ASSOCIATIVITY;
			if(argcCount + 1 < argc) {
				// n-way
				this->nWay = atoi(argv[argcCount + 1]);
				argcCount += 2;
			} else {
				// Optional
				argcCount += 1;
			}
		} else if(strcmp(argv[argcCount], "--round-robin") == 0 || strcmp(argv[argcCount], "-rr") == 0) {
			// Set round robin as a replacement algorithm when --associativity is triggered
			this->replacementAlgorithm = ReplacementAlgorithm::ROUND_ROBIN;
			argcCount += 1;
		} else if(strcmp(argv[argcCount], "--least-recently-used") == 0 || strcmp(argv[argcCount], "-lru") == 0) {
			// Set least recently used as a replacement algorithm when --associativity is triggered
			this->replacementAlgorithm = ReplacementAlgorithm::LEAST_RECENTLY_USED;
			argcCount += 1;
		} else if(strcmp(argv[argcCount], "--help") == 0 || strcmp(argv[argcCount], "-h") == 0) {
			// Show usage
			this->showUsage(argv[0]);
			exit(0);
			argcCount += 1;
		} else {
			// File name
			this->fileName = argv[argcCount];
			this->isSetFileName = true;
			argcCount += 1;
		}
	}
}
