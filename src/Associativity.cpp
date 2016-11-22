#include "Associativity.h"
#include "Cache.h"
#include "math.h"
#include <vector>
#include <cstdio>
using namespace std;
#define BYTE_OFFSET 2
#define STARTING_AGE 0
#define DATA_SIZE 32

Associativity::Associativity(unsigned int nways, ReplacementAlgorithm replacementAlgo, unsigned long cacheSize ) {
    unsigned long entries = cacheSize / (nways * this->wordSize);

    this->nways = nways;
    this->age = STARTING_AGE;
    this->byteOffsetLength = BYTE_OFFSET;
    this->indexLength = log2(entries);
    this->tagLength = DATA_SIZE - BYTE_OFFSET - log2(entries);
    this->replacementAlgo = replacementAlgo;
    caches = vector<vector<CacheEntries>>(nways,vector<CacheEntries>(entries));

    switch (replacementAlgo)
    {
    case ReplacementAlgorithm::LEAST_RECENTLY_USED :
        break;
    case ReplacementAlgorithm::ROUND_ROBIN :
        this->roundIndex = new unsigned int[entries];
        break;
    default:
        break;
    }
}

void Associativity::access(unsigned long addr) {
    unsigned long tag, index, byteOffset;
    this->tokenizeAddr(addr ,&tag, &index, &byteOffset);
    if(this->replacementAlgo == ReplacementAlgorithm::ROUND_ROBIN) {
        bool isHit = false;
        bool isInvalid = false;
        for(int way = 0 ; way < nways ; way++) {
            if(!caches[way][index].valid) {
                caches[way][index].tag = tag;
                caches[way][index].valid = true;
                isInvalid = true;
                break;
            } else if(caches[way][index].tag == tag && caches[way][index].valid) {
                isHit = true;
                break;
            }
        }
		if(!isHit && isInvalid) {
			++miss;
		} else if(!isHit) {
			unsigned long replaceWay = roundIndex[index];
			caches[replaceWay][index].tag = tag;
			roundIndex[index] = (roundIndex[index]+1)%nways;
			++miss;
		} else {
			++hit;
		}

    } else if (this->replacementAlgo == ReplacementAlgorithm::LEAST_RECENTLY_USED) {
       bool isHit = false;
       bool isInvalid = false;
       unsigned long minWay = 0;
	   ++age;
       for(int way = 0 ; way < nways ; way++) {
           if(!caches[way][index].valid) {
               caches[way][index].tag = tag;
               caches[way][index].valid = true;
               caches[way][index]._age = age;
               isInvalid = true;
               break;
           } else if(caches[way][index].tag == tag && caches[way][index].valid) {
               isHit = true;
               caches[way][index]._age = age;
               break;
           }
       }
       if(!isHit && isInvalid) {
           ++miss;
       } else if(!isHit) {
		   for(int way = 0 ; way < nways ; way++) {
	           if(caches[way][index]._age <  caches[minWay][index]._age) minWay = way;
		   }
           caches[minWay][index]._age = age;
           caches[minWay][index].tag = tag;
           ++miss;
       } else {
           ++hit;
       }
    } else {
        printf("Unknown Replacement Algorithm\n");
    }
	++this->nAccess;
}

void Associativity::tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *index, unsigned long *byteOffset) {
    unsigned long tmp;
    *tag = addr >> (this->byteOffsetLength + this->indexLength);
    tmp = 0;
    for(int i = 0 ; i < this->indexLength; i++) {
        tmp <<= 1;
        tmp |= 0x01;
    }
    *index = addr >> (this->byteOffsetLength) & tmp;
    tmp = 0;
    for(int i = 0 ; i < this->byteOffsetLength ; i++) {
        tmp <<= 1;
        tmp |= 0x01;
    }
    *byteOffset = addr & tmp;

}

void Associativity::printStatus() {
	printf("Entry size: %lu entries\n"
		   "Tag length: %lu bit(s)\n"
		   "Index length: %lu bit(s)\n"
		   "Byte offset length: %lu bit(s)\n",
		   caches.size(), tagLength, indexLength, byteOffsetLength);
}
