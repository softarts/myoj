//
// Created by Rui Zhou on 14/3/18.
//

/*
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 * Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

 medium?
 like quantcast interview
 */


#include <codech/codech_def.h>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }

        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq;
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};


DEFINE_CODE_TEST(347_topk_frequent_element)
{
    Solution obj;
    {
        vector<int> nums{1,1,1,2,2,3};
        VERIFY_CASE(PRINT_VEC(obj.topKFrequent(nums, 2)),"1 2");
    }
    {
        vector<int> nums{1,2,2};
        VERIFY_CASE(PRINT_VEC(obj.topKFrequent(nums, 2)),"1 2");
    }
}