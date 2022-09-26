/*
Implement interface Cache so that it:
  a) maintains internal cache of values of type V for keys of type K
  b) uses provided DataSource to fetch data from an external data source
  c) when get(K key) is called it first checks if we already have a cached value and returns it if we have.
     Otherwise obtain a value by calling DataSource::fetch, place it in the cache and return.

Additional requirements:
  d) Multithreading
    1) solution should be thread-safe
    2) when two threads are calling get() with the same argument at the same time and value is not available in the cache --
       only one thread should invoke DataSource::fetch, the other should wait until the value is available in the cache.
    3) when two threads invoke get() with different arguments at the same time -- both should be allowed to execute
       DataSource::fetch concurrently

2021
需求分析
如果key在cache中则返回
不在：
不同的key需要并发请求
相同的key只允许同一时间只有一个在请求，其他的线程需要等待结果

这个实现有些别扭，因为map不是threadsafe的，所以用了很多lock
因此这个实现算是较好的一个，假设MyHashMap是thread safe的
*/

#include <future>
#include <unordered_map>
#include <iostream>

using namespace std;

template<typename K, typename V>
class MyHashMap {
  private:
    unordered_map<K,V> m;
    std::mutex mu;
  public:
    bool count(K key) const{
      return m.count(key);
    }

    V get(K key) {
      std::lock_guard<std::mutex> lk(mu);
      return m[key];
    }

    void put(K key, V value) {
      std::lock_guard<std::mutex> lk(mu);
      m[key] = value;
    }

    template<typename Func>
    void submitFutureTask(K key, Func extcall) {
      std::lock_guard<std::mutex> lk(mu);
      m[key] = extcall();
    }

    template<typename U>
    bool getFutureResult(K key, U &value) {
      std::lock_guard<std::mutex> lk(mu);
      if (m[key].valid()) {
        value = m[key].get();
        return true;
      } else {
        return false;
      }
    }
};

template<typename K, typename V>
class ExtCall {
  private:
    MyHashMap<K,V> data;
    MyHashMap<K,future<V>> futs;
  public:
    template<typename Func>
    V computeIfAbsent(K key, Func extcall) {
      if (data.count(key)) {
        return data.get(key);
      } else {
        // submit task
        if (!futs.count(key)) {
          futs.submitFutureTask(key,extcall);
        }
        // get result
        V value;
        if (futs.template getFutureResult<V>(key, value)) {
          data.put(key,value);
        }

        return data.get(key);
      }
    }
};


int doExtCall() {
  return 123;
}


future<int> extCallProxy() {
  return std::async(std::launch::async, doExtCall);
}

template<typename K, typename V>
class CacheSystem {
  private:
    ExtCall<K,V> exts; 

  public:
    V  getData(K key) {
      return exts.computeIfAbsent(key, extCallProxy);
    }
};

int main() {
  CacheSystem<int,int> mycache;
  cout << mycache.getData(10) << endl;
  cout << mycache.getData(10) << endl;
}