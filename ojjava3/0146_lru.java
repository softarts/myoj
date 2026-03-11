// least recent used cache

import java.util.LinkedHashMap;

class LRUCache {
    private LinkedHashMap<Integer, Integer> cache;

    private int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        cache = new LinkedHashMap<>();
    }

    public int get(int key) {
        if (cache.containsKey(key)) {
            var value = cache.get(key);
            cache.remove(key);
            cache.put(key, value);
            return value; // update the key to the most recent used
        }
        return -1;
    }

    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            cache.remove(key);
        } else if (capacity == cache.size()) {
            // head is the least recent used
            cache.remove(cache.keySet().iterator().next());
        }
        cache.put(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */