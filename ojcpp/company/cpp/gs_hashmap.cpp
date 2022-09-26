#include <codech/codech_def.h>
#include <list>
using namespace std;

namespace {
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
    private:
        const int cap_ = 1000;
        using value_t = pair<K,V>;
        vector<list<pair<K,V>>> buckets_;
    };
}

DEFINE_CODE_TEST(gs_hashmap)
{
    MyHashMap<int,int> m;
    m[1]=1;
    m[1]=10;
    cout << m[1]<<endl;
}