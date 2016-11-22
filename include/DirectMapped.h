#ifndef DIRECT_MAPPED_H
#define DIRECT_MAPPED_H

#include <vector>
#include "Cache.h"

using namespace std;

class DirectMapped : public Cache {
private:
	typedef unsigned char Byte;
	class CacheEntry {
		friend class DirectMapped;
	protected:
		bool valid;
		bool dirty;
		unsigned long tag;
		vector<Byte> data;
	public:
		CacheEntry(int blockSize) {
			this->valid = false;
			this->dirty = false;
			this->tag = 0;
			this->data = vector<Byte>(blockSize);
		}
	};
	vector<CacheEntry> cache;
	unsigned long entrySize;
	unsigned int tagLength, indexLength, blockOffsetLength, byteOffsetLength;

public:
	DirectMapped(unsigned long cacheSize, unsigned long blockSize);
	void access(unsigned long addr);
	void tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *index, unsigned long *blockOffset, unsigned long *byteOffset);
	void printStatus();

	unsigned long getEntrySize() const;
	unsigned int getTagLength() const;
	unsigned int getIndexLength() const;
	unsigned int getBlockOffsetLength() const;
	unsigned int getByteOffsetLength() const;
};

#endif
