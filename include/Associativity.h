#ifndef ASSOCIATIVITY_H
#define ASSOCIATIVITY_H

#include "Cache.h"
#include <vector>
using namespace std;
class Associativity : public Cache {
protected:
	class CacheEntries {
		friend class Associativity;
		protected:
			typedef unsigned char Byte;
			bool valid;
			bool dirty;
			unsigned long tag;
			unsigned long _age;
			Byte data;

		public:
			CacheEntries() {
				this->valid = false;
				this->dirty = false;
				this->_age = 0;
			}
	};

protected:
		unsigned int nways;
		unsigned long age;
		unsigned long byteOffsetLength;
		unsigned long indexLength;
		unsigned long tagLength;
		unsigned int *roundIndex;
		ReplacementAlgorithm replacementAlgo;
		vector<vector<CacheEntries>> caches;

public:
	Associativity(unsigned int nways, ReplacementAlgorithm replacementAlgo, unsigned long cacheSize);
	void access(unsigned long addr);
	void tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *offset);
	void printStatus();
};

#endif
