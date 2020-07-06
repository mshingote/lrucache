// LRUCache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

#include "lrucache.hpp"

using namespace cache;

void put_test()
{
	lru_cache<int, int> cache(10);

	for (int i = 0; i < 100; ++i) {
		cache.put(i, i);
		//std::cout << cache.get(i) << "\n";
		std::cout << "-------------\n";
	}
}

int main()
{
	put_test();
	return 0;
}