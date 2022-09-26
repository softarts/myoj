/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[3,4], cnt(4)=2, cnt(3)=3

2021-05-07   

(list)
[1]---list<1,2,3>
[3]---list<4,5,6>
原本打算使用linkedlist的，但实际上hashmap也可以，因为只需要记住mincount
*/


#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;


namespace {
    struct DataNode {        
        int key=0,value=0,count=0;
        list<int>::const_iterator it; // point to list中的位置
    };


    class LFUCache {
    public:
        unordered_map<int,list<int>> countsMap;
        unordered_map<int, DataNode> cache;
        int minCount = 0;
        int cap;

        LFUCache(int capacity) {
            cap = capacity;
        }
        

        void change(DataNode &node) {
            int curCount = node.count;
            int newCount = ++node.count;
            countsMap[curCount].erase(node.it);
            if (countsMap[curCount].empty() && curCount == minCount) {
                countsMap.erase(curCount);
                minCount = newCount;
            }
            countsMap[newCount].push_front(node.key);
            node.it = countsMap[newCount].cbegin();
        }

        int get(int key) {
            auto iter = cache.find(key);
            if (iter != cache.end()) {  // found            
                change(iter->second);
                return iter->second.value;                
            } else {
                return -1;
            }
        }
    
        void put(int key, int value) {
            if (cap==0) return;
            auto it = cache.find(key);
            if (it!=cache.end()) {
                it->second.value = value;
                change(it->second);
                return;
            }
            if (cache.size()==cap) {
                const int keyDelete = countsMap[minCount].back();
                countsMap[minCount].pop_back();
                cache.erase(keyDelete);
            }
            const int count = 1;
            minCount = count;
            countsMap[count].push_front(key);
            cache[key] = {key,value,count,countsMap[count].cbegin()};

        }
    };

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
}
