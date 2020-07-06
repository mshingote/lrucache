/*
Simple key, value lru cache implementation
*/

#ifndef _LRUCACHE_HPP_
#define _LRUCACHE_HPP_

#include <list>
#include <unordered_map>

namespace cache {
	using std::pair;
	using std::list;
	using std::unordered_map;

	template<typename key_t, typename value_t>
	class lru_cache {
	public:
		lru_cache(size_t max_size)
		{
			m_cache_max_limit = max_size;
		}
		void put(const key_t& key, const value_t& value) {
			auto it = m_cache_umap.find(key);
			if (it == m_cache_umap.end()) {
				if (m_cache_items.size() == m_cache_max_limit) {
					auto last = m_cache_items.back();
					m_cache_umap.erase(last.first);
					m_cache_items.pop_back();
				}
				m_cache_items.push_front({ key, value });
				m_cache_umap[key] = m_cache_items.begin();
			}
			else {
				__update(key, value);
			}
		}

		value_t get(const key_t& key) {
			auto it = m_cache_umap.find(key);
			if (it == m_cache_umap.end()) {
				throw std::range_error("Item not found");
			}
			const auto& itr = it->second;
			const auto value = (*itr).second;
			__update(key, value);
			return value;
		}
	private:
		void __update(const key_t& key, const value_t& value) {
			auto old = m_cache_umap[key];
			m_cache_items.erase(old);
			m_cache_items.push_front({ key, value });
			m_cache_umap[key] = m_cache_items.begin();
		}
	private:
		typedef typename pair< key_t, value_t > cache_items_t;
		typedef typename list< cache_items_t >::iterator cache_items_iterator_t;

		size_t m_cache_max_limit;
		list < cache_items_t > m_cache_items;
		unordered_map<key_t, cache_items_iterator_t> m_cache_umap;
	};
}

#endif // !_LRUCACHE_HPP_