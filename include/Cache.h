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
protected:
	long hit, miss;

public:
	Cache();
	virtual void access(unsigned long addr) = 0;

	long getHit() const;
	long getMiss() const;
};

#endif
