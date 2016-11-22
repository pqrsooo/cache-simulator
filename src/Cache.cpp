#include "Cache.h"

Cache::Cache() {
	this->hit = 0;
	this->miss = 0;
	this->wordSize = 4;
}

long Cache::getHit() const {
	return this->hit;
}

long Cache::getMiss() const {
	return this->miss;
}
