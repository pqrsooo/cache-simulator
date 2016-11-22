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

            if(!isHit && isInvalid) {
                ++miss;
            } else if(!isHit) {
                unsigned long replaceIndex = roundIndex[index++];
                caches[replaceIndex][index].tag = tag;
                ++miss;
            } else {
                ++hit;
            }
        }
        
    } else if (this->replacementAlgo == ReplacementAlgorithm::LEAST_RECENTLY_USED) {
       
       
    } else {
        printf("Unknown Replacement Algorithm\n");
    }
}

void Associativity::tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *byteOffset) {
    usigned long tmp;
    *tag = addr >> (this->byteOffsetLength + this->indexLength);
    tmp = 0;
    for(int i = 0 ; i < this->indexLength; i++) {
        tmp <<= 1;
        tmp |= 0x01;
    }
    *index = addr >> (this->byteOffsetLengths) & tmp;
    tmp = 0;
    for(int i = 0 ; i < this->byteOffsetLength ; i++) {
        tmp <<= 1;
        tmp |= 0x01;
    }
    *byteOffset = addr & tmp;

}
