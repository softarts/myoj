#include <vector>
#include <unordered_set>
using namespace std;
/*
hard
组合的套路，不要使用递归，直接往当前已有vector中加
*/
int solution(vector<int> coins, vector<int> quantity) {    
    unordered_set<int> m{0};
    
    // auto debug=[](unordered_set<int> &v) {
    //     cout << " ";
    //     for (auto &el:v) {
    //         cout<<el<<" ";
    //     }
    //     cout << endl;
    // };
    for (int j=0;j<quantity.size();j++) {   
        vector<int> tmp(m.begin(),m.end());             
        for (int i=0;i<tmp.size();i++) {                    
            for (int k=1;k<=quantity[j];k++) {
                m.insert(tmp[i]+k*coins[j]);         
            }
        }
    }  
    
    return m.size()-1;
    
}


