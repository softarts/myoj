//
// Created by rui zhou on 2019-10-06.
//

/*
 * 输入一个正数s，打印所有和为S的连续正数序列，例如
 * 15 = 1+2+3+4+5 = 4+5+6 = 7+8,输出3个连续序列

 思路
先从小的开始加，一但超过了，就把最小的减掉
 */


#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        vector <vector<int>> FindContinuousSequence(int sum) {
            vector<vector<int>> ret;
            int cursum = 1;
            int begin=1,end=1;
            while ((cursum!=sum || begin<=end) && end <= (sum+1)/2) {
                if (cursum+end+1 < sum) {
                    end++;
                    cursum+=end;
                } else if (cursum+end+1 > sum) {
                    cursum-=begin;
                    begin+=1;
                } else {
                    vector<int> ans;
                    for (int i=begin;i<=end+1;i++) {
                        ans.push_back(i);
                    }
                    ret.emplace_back(ans);
                    cursum-=begin;
                    begin+=1;
                }
            }
            return ret;
        }

    };
}

DEFINE_CODE_TEST(041_continuous_seq)
{
    Solution obj;
    {
        vector<vector<int>> exp{{1,2,3,4,5},{4,5,6},{7,8}};
        VERIFY_CASE(VERIFY_VV(obj.FindContinuousSequence(15),exp),true);
    }

}


