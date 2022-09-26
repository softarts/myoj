//
// Created by rui zhou on 10/05/19.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    bool isSort(vector<string> &arr,vector<char> order) {

        // c,b,a -> c=3,b=2,a=1
        // ["cc", "cb", "bc", "ac"] -> [33,32,23,13]
        // check
        // ["cc", "bcc"] => true
        // -> 330,233
        // ["cc","ccc"]-> true,
        // 334,333/

        // ["aaaaaaaaaaaaaaaaaaaaa", "aab"]
        // ["aa", "aaa"] => true
        // ["aaa", "aa"] => false

//        unordered_map<char,int> map;
//        int order=1;
//        for (auto &ch:order) {
//            map[ch] =order++;
//        }
//        //assume arr is not empty
//        auto prev = arr[0];
//        auto comp = [](string &a,string &b) {
//            int l=min(a.length(),b.length())
//            for (int i=0;i<l;i++) {
//                if (map[a[i]]<map[b[i]])
//                    return true;
//                else if (map[a[i]]>map[b[i]])
//                    return false;
//            }
//
//            if (b.length()<a.length())
//                return false;
//            else
//                return true;
//        }
//
//        for (int i=1;i<arr.size();i++) {
//            if (!comp(prev,arr[i]))
//                return false;
//        }
//        return true;

        return true;
    }
}

