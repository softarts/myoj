#include <codech/codech_def.h>
using namespace std;

//这题没那么难，就是先从左到右保证顺序，然后再从右到左
namespace {
    class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int> arr(ratings.size(),1);
            for (int i=1;i<ratings.size();i++) {
                if (ratings[i]>ratings[i-1]) {
                    arr[i]=arr[i-1]+1;
                } 
                cout<<i<<"="<<arr[i]<<",";
            }
            
            cout<<endl;
            for (int i=ratings.size()-2;i>=0;i--) {
                if (ratings[i]>ratings[i+1] && (arr[i]<=arr[i+1])) {
                    arr[i]=arr[i+1]+1;
                } 
                cout<<i<<"="<<arr[i]<<",";
            }
            int ans = accumulate(begin(arr),end(arr),0);
            return ans;
        }
    }; 
}


DEFINE_CODE_TEST(135_candy)
{
    Solution obj;
    {
        vector<int> nums{1,0,2};
        VERIFY_CASE(obj.candy(nums),5);    
    }
    {
        vector<int> nums{1,3,4,5,2};
        VERIFY_CASE(obj.candy(nums),11);    
    }
    {
        vector<int> nums{1,2,2};
        VERIFY_CASE(obj.candy(nums),4);    
    }

}