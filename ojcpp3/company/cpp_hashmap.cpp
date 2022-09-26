#include <iostream>
#include <list>
#include <vector>
using namespace std;

//  goldman sachs 面试题, 话说这个考得并不多,做得有点复杂
template<class K,class V>
class MyHashMap {
public:
    MyHashMap() {
        buckets_.resize(cap_);
    }
    V& operator[](const K &key) {
        int idx = std::hash<K>{}(key)%cap_;
        auto &lst = buckets_[idx];
        auto it = find_if(lst.begin(),lst.end(),[&](const auto &it){return it.first==key;});            
        if (it==lst.end()) {
            lst.push_front(make_pair(key,V()));
            return lst.begin()->second;
        } else {
            return it->second;
        }
    }
    void insert(K key, V value) {
        int idx = getHash(key);
        auto &lst = buckets_[idx];
        auto it = find_if(lst.begin(),lst.end(),[&](const auto &it){return it.first==key;});            
        if (it==lst.end()) {
            lst.push_front(make_pair(key,value));
        } else {
            it->second = value;
        }
    }
private:
    const int cap_ = 1000;
    using value_t = pair<K,V>;
    vector<list<pair<K,V>>> buckets_;
private:
    int getHash(K key) {
      int idx = std::hash<K>{}(key)%cap_;
      return idx;
    }
};

int main() {
    MyHashMap<int,int> m;
    m[1]=1;
    m[1]=10;
    cout << m[1]<<endl;
    m.insert(2,4);
    cout << m[2]<<endl;
}
