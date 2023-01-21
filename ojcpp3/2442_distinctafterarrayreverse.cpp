#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> m;
        auto myrev = [](int n) {
            long ans; // 注意long,有时候overflow
            while (n>0) {
                ans=ans*10+n%10;
                n=n/10;
            }
            return ans;
        };

        for (auto i:nums) {
            m.insert(i);
            m.insert(myrev(i));
        }        
        return m.size();
    }
};