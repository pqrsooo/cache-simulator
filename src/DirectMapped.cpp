#include <cmath>
#include "DirectMapped.h"

DirectMapped::DirectMapped(unsigned long cacheSize, unsigned long blockSize) {
	this->entrySize = cacheSize / blockSize;
	this->cache = vector<CacheEntry>(this->entrySize, CacheEntry((int)blockSize));
}

void DirectMapped::access(unsigned long addr) {

}

void DirectMapped::tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *offset) {

}
