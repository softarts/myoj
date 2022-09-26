//
// Created by rui zhou on 07/05/19.
//

//所有奇数放在前面，偶数放在后面
#include <codech/codech_def.h>
#include <functional>

using namespace CODECH;
using namespace std;

namespace {
    class Solution {
    public:
        void reorderOddEven(vector<int> &arr) {
            std::function<bool(int)> pred = [](int x) {
                return x%2==0;
            };

            int start=0,end=arr.size()-1;
            while (start<end) {
                while (!pred(arr[start])) start++;
                while (pred(arr[end])) end--;
                if (start<end) {
                    swap(arr[start],arr[end]);
                }
            }
        }
    };
}



DEFINE_CODE_TEST(hht_014_oddeven)
{
    Solution obj;
    {
        vector<int> arr{1,2,3,4,5};
        obj.reorderOddEven(arr);
        VERIFY_CASE(PRINT_VEC(move(arr)),"1 5 3 4 2");
    }
}