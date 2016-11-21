#ifndef ASSOCIATIVITY_H
#define ASSOCIATIVITY_H

#include "Cache.h"

class Associativity : public Cache {
private:


public:
	Associativity();
	void access(unsigned long addr);
	void tokenizeAddr(unsigned long addr, unsigned long *tag, unsigned long *idx, unsigned long *offset);
};

#endif
