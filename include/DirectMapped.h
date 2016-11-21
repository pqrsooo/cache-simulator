#ifndef DIRECT_MAPPED_H
#define DIRECT_MAPPED_H

#include "Cache.h"

class DirectMapped : public Cache {
private:

public:
	DirectMapped();
	void access(unsigned long addr);
	void tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *offset);
};

#endif
