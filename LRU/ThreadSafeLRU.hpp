#include <iostream>
#include <unordered_map>
#include <list>
#include <mutex>
#include <shared_mutex> // C++17
#include <optional>

// 线程安全的 LRU 缓存
template <typename Key, typename Value>
class ThreadSafeLRUCache {
private:
   size_t capacity; // 缓存容量
   std::list<std::pair<Key, Value>> cacheList; // 双向链表存储键值对
   std::unordered_map<Key, typenamestd::list<std::pair<Key, Value>>::iterator> cacheMap; // 哈希表
   mutablestd::shared_mutex mutex; // 共享锁

   void moveToFront(typename std::list<std::pair<Key, Value>>::iterator it) {
        cacheList.splice(cacheList.begin(), cacheList, it); // 将当前节点移动到链表头部
    }

public:
   explicit ThreadSafeLRUCache(size_t cap) : capacity(cap) {}

   // 获取缓存值
   std::optional<Value> get(const Key& key) {
       std::shared_lock lock(mutex); // 共享锁
       auto it = cacheMap.find(key);
       if (it == cacheMap.end()) {
           returnstd::nullopt; // 未命中
        }
        moveToFront(it->second); // 更新使用顺序
       return it->second->second;
    }

   // 插入或更新缓存
   void put(const Key& key, const Value& value) {
       std::unique_lock lock(mutex); // 独占锁
       auto it = cacheMap.find(key);
       if (it != cacheMap.end()) {
            it->second->second = value;
            moveToFront(it->second);
        } else {
           if (cacheList.size() == capacity) {
               auto& node = cacheList.back();
                cacheMap.erase(node.first); // 从哈希表移除
                cacheList.pop_back(); // 移除链表尾部节点
            }
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }

   // 删除缓存中的键
   void erase(const Key& key) {
       std::unique_lock lock(mutex); // 独占锁
       auto it = cacheMap.find(key);
       if (it != cacheMap.end()) {
            cacheList.erase(it->second);
            cacheMap.erase(it);
        }
    }

   // 显示缓存内容（调试用）
   void display() const {
       std::shared_lock lock(mutex); // 共享锁
       for (constauto& [key, value] : cacheList) {
           std::cout << key << ":" << value << " ";
        }
       std::cout << std::endl;
    }
};

int main() {
   ThreadSafeLRUCache<int, std::string> cache(3); // 容量为3的LRU缓存

    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");

    cache.display(); // 输出: 3:three 2:two 1:one

    cache.get(2); // 访问键2
    cache.display(); // 输出: 2:two 3:three 1:one

    cache.put(4, "four"); // 插入键4，淘汰键1
    cache.display(); // 输出: 4:four 2:two 3:three

    cache.erase(3); // 删除键3
    cache.display(); // 输出: 4:four 2:two

   return 0;
}