#ifndef CACHE_H
#define CACHE_H

// Enum declaration
enum CacheType {
	DIRECT_MAPPED,
	ASSOCIATIVITY
};
enum ReplacementAlgorithm {
	LEAST_RECENTLY_USED,
	ROUND_ROBIN
};

class Cache {
private:
	int hit, miss;

public:
	Cache();
	void access(unsigned long addr);
	void tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *offset);
};

#endif
