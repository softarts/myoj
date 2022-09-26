// 2021-10-30

#include <codech/codech_def.h>
using namespace std;

// 做法类似lcxxx? 就是二分法，不过解得比较难看，不知道有没更好的算法

namespace {
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {        
        std::sort(cards.begin(), cards.end());
        do {
            // std::cout << "===========================" << '\n';
            // for (int x:cards) {
            //     cout << x << " ";
            // }
            // cout<<endl;
            vector<double> ans = helper(cards);
            for (double x:ans) {
                //cout << x << " ";
                if (abs(x-24)<0.00001) {
                    return true;
                }
            }
            cout<<endl;
        } while(std::next_permutation(cards.begin(), cards.end()));
        return false;
        
    }
    
    vector<double> helper(vector<int>& input) {
        // for (int x:input) {
        //     cout << x << " ";
        // }
        // cout<<endl;
        
        vector<double> ans;
        if (input.size()==1) {
            ans.push_back(input[0]);
            return ans;
        }
        
        for (int i=1;i<input.size();i++) {
            vector<int> a(input.begin(),input.begin()+i);
            vector<int> b(input.begin()+i,input.end());
            // cout<<"a= ";
            // for (int x:a) {
            //     cout << x << " ";
            // }
            // cout<<endl;
            // cout<<"b= ";
            // for (int x:b) {
            //     cout << x << " ";
            // }
            // cout<<endl;

            vector<double> left = helper(a);
            vector<double> right = helper(b);
            
            // cout<<"left= ";
            // for (int x:left) {
            //     cout << x << " ";
            // }
            // cout<<endl;
            // cout<<"right= ";
            // for (int x:right) {
            //     cout << x << " ";
            // }
            // cout<<endl;
            
            for (double x:left) {
                for (double y:right) {
                    ans.push_back(x-y);
                    ans.push_back(x+y);
                    ans.push_back(x*y);
                    if (y!=0) ans.push_back(x/y);
                }
            }
        }
        
        return ans;
    }
};
}