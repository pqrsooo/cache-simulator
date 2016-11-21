#include <cmath>
#include "DirectMapped.h"

DirectMapped::DirectMapped(unsigned long cacheSize, unsigned long blockSize) {
	unsigned long entrySize = cacheSize / blockSize;
	this->entrySize = entrySize;
	this->cache = vector<CacheEntry>(entrySize, CacheEntry((int)blockSize));

	unsigned int byteOffsetLength = log2(this->wordSize);
	unsigned int blockOffsetLength = log2(blockSize / this->wordSize);
	unsigned int indexLength = log2(entrySize);
	this->byteOffsetLength = byteOffsetLength;
	this->blockOffsetLength = blockOffsetLength;
	this->indexLength = indexLength;
	this->tagLength = 8 * this->wordSize - byteOffsetLength - blockOffsetLength - indexLength;
}

void DirectMapped::access(unsigned long addr) {

}

void DirectMapped::tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *offset) {

}

void DirectMapped::printStatus() {
	printf("Entry Size: %lu\n"
		   "Tag Length: %u\n"
		   "Index Length: %u\n"
		   "Block Offset Length: %u\n"
		   "Byte Offset Length: %u\n",
		   entrySize, tagLength, indexLength, blockOffsetLength, byteOffsetLength);
}
