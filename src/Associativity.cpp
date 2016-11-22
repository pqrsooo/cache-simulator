#include "Associativity.h"
#include "Cache.h"
#include "math.h"
#include <vector>
using namespace std;
#define BYTE_OFFSET 2
#define STARTING_AGE 0
#define DATA_SIZE 32

Associativity::Associativity(unsigned int nways, ReplacementAlgorithm replacementAlgo, unsigned long cacheSize ) {
    unsigned long entries = cacheSize/nways;
    this->nways = nways;
    this->age = STARTING_AGE;
    this->byteOffsetBit = BYTE_OFFSET;
    this->addressBit = log2(entries);
    this->tagBit = DATA_SIZE - BYTE_OFFSET - log2(entries);
    this->replacementAlgo = replacementAlgo;
    caches = vector<vector<CacheEntries>>(nways,vector<CacheEntries>(entries));

    switch (replacementAlgo)
    {
    case ReplacementAlgorithm::LEAST_RECENTLY_USED :
        break;
    case ReplacementAlgorithm::ROUND_ROBIN :
        this->roundIndex = new unsigned long[entries];
        break;
    default:
        break;
    }
}

void Associativity::access(unsigned long addr) {

}

void Associativity::tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *offset) {

}
