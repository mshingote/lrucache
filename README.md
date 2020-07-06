# lrucache
Simple  C++ based LRU (Least Recently Used) cache 

```
/*
Cache with maximum size limit of 10
*/

cache::lru_cache<int, int> cache(10);

cache.put(1, 1);
cache.put(2, 2);

const auto& from_cache = cache.get(2)

```

```
lrucache
├─ lrucache
│  ├─ lrucache.filters
│  ├─ lrucache.hpp (cache logic)
│  ├─ lrucache.vcxproj (vs2019 project file)
│  └─ main.cpp (How to use cache)
├─ lrucache.sln (vs2019 solution file)
└─ README.md

```