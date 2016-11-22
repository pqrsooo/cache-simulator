#include <cmath>
#include <cstdio>
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
	unsigned long tag, index, blockOffset, byteOffset;
	this->tokenizeAddr(addr, &tag, &index, &blockOffset, &byteOffset);
	if(cache[index].tag == tag && cache[index].valid) {
		++this->hit;
	} else {
		++this->miss;
		this->cache[index].valid = true;
		this->cache[index].tag = tag;
	}
	++this->nAccess;
}

void DirectMapped::tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *index, unsigned long *blockOffset, unsigned long *byteOffset) {
	unsigned long tmp;
	*tag = addr >> (this->byteOffsetLength + this->blockOffsetLength + this->indexLength);
	tmp = 0;
	for(int i = 0; i < this->indexLength; i++) {
		tmp <<= 1;
		tmp |= 0x01;
	}
	*index = addr >> (this->byteOffsetLength + this->blockOffsetLength) & tmp;
	tmp = 0;
	for(int i = 0; i < this->blockOffsetLength; i++) {
		tmp <<= 1;
		tmp |= 0x01;
	}
	*blockOffset = addr >> (this->byteOffsetLength) & tmp;
	tmp = 0;
	for(int i = 0; i < this->byteOffsetLength; i++) {
		tmp <<= 1;
		tmp |= 0x01;
	}
	*byteOffset = addr & tmp;
}

void DirectMapped::printStatus() {
	printf("Entry Size: %lu\n"
		   "Tag Length: %u\n"
		   "Index Length: %u\n"
		   "Block Offset Length: %u\n"
		   "Byte Offset Length: %u\n",
		   entrySize, tagLength, indexLength, blockOffsetLength, byteOffsetLength);
}

unsigned long DirectMapped::getEntrySize() const {
	return this->entrySize;
}

unsigned int DirectMapped::getTagLength() const {
	return this->tagLength;
}

unsigned int DirectMapped::getIndexLength() const {
	return this->indexLength;
}

unsigned int DirectMapped::getBlockOffsetLength() const {
	return this->blockOffsetLength;
}

unsigned int DirectMapped::getByteOffsetLength() const {
	return this->byteOffsetLength;
}
