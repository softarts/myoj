//
// Created by rui zhou on 09/05/19.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

// 解法太cool了
namespace {
    class Solution {
    public:
        vector<int> findAppearOnce(const vector<int> &arr) {
            int result=0;
            for (auto &it:arr) {
                result^=it;
            }
            //找出为1的bit
            int bit=0;
            for (;bit<32;bit++) {
                if (result&1) {
                    break;
                }
            }

            int num1=0,num2=0;
            for (auto &it:arr) {
                int num=it;
                if (num>>bit & 1) {
                    num1^=it;
                } else {
                    num2^=it;
                }
            }
            return {num1,num2};
        }
    };
}



DEFINE_CODE_TEST(hht_030_appear_once)
{
    Solution obj;
    {
        VERIFY_CASE(PRINT_VEC(obj.findAppearOnce({1,2,3,3,4,4,5,5})),"1 2");
    }
}
