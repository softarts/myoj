#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

namespace ubi1{
    class Solution {
    public:
        int averageValue(vector<int>& nums) {
            int sum=0;
            int count=0;
            for (auto &item:nums) {
                if (item%3==0 && item%2==0) {
                    sum+=item;
                    count++;
                }
            }
            return count!=0?sum/count:0;
        }
    };
}

namespace ubi2 {
    class Solution {
    public:
        vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
            vector<vector<string>> ans;
            unordered_map<string,long> totalScores;

            unordered_map<string,long> creatorVideoScore;
            unordered_map<string,string> creatorVideo;
            for (int i=0;i<creators.size();i++) {
                totalScores[creators[i]]+=views[i];

                if (views[i]>creatorVideoScore[creators[i]] || creatorVideoScore[creators[i]]==0) {
                    creatorVideoScore[creators[i]]=views[i];
                    creatorVideo[creators[i]]=ids[i];
                } else if (views[i]==creatorVideoScore[creators[i]]) {
                    if (ids[i]<=creatorVideo[creators[i]]) {
                        creatorVideo[creators[i]]=ids[i];
                    }
                }
            }

            long maxScore=-1;
            string creator;
            for (auto &iter:totalScores) {
                if (iter.second>maxScore) {
                    creator=iter.first;
                    maxScore=iter.second;
                }
            }

            for (auto &iter:totalScores) {
                if (iter.second==maxScore) {
                    creator=iter.first;
                    ans.push_back(
                        {creator,creatorVideo[creator]}
                    );
                }
            }
            return ans;
        }
    };
}


namespace ubi3 {
    class Solution {
    public:
        long long makeIntegerBeautiful(long long n, int target) {
            
        }
    };  
}

#include "../common.h"
#include <iostream>

namespace ubi4 {
    class Solution {
    public:
        unordered_map<int,int> memo;
        unordered_map<int,TreeNode*> subtree;
        unordered_map<int,bool> m;
        int flag=false;
        vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
            vector<int>ans;
            flag=true;
            dfs(root,0,0);
            
            for (int i=0;i<queries.size();i++) {
                auto node=subtree[queries[i]];
                helper(node,false);
                int depth=0;
                for (auto &iter:memo) {
                    if (!m[iter.first]) continue;
                    depth=max(depth,iter.second);
                    cout<<depth<<endl;
                    ans.push_back(depth);
                }
                for (auto &iter:m) {
                    iter.second=true;
                }
            }
            return ans;
        }

        int dfs(TreeNode* node, int target,int layer) {
            if (node==nullptr) return layer;
            if (node->val==target && flag==false) return layer;

            int left=dfs(node->left,target,layer+1);
            int right=dfs(node->right,target,layer+1);

            int ret=max(left,right);
            memo[node->val]=layer;
            subtree[node->val]=node;
            cout<<node->val<<","<<layer<<endl;
            m[node->val]=true;
            return max(left,right);
        }


        void helper(TreeNode* node, bool flag) {
            if (node==nullptr) return;
            helper(node->left,flag);
            helper(node->right,flag);
            m[node->val]=flag;
        }







            // for (int i=0;i<queries.size();i++) {
            //     int depth = dfs(root, queries[i],0)-1;
            //     //cout<<depth<<endl;
            //     ans.push_back(depth);
            // }
            // return ans;
        // int dfs0(TreeNode* node, int target) {
        //     if (node==nullptr) return 0;
        //     if (node->val==target && flag==false) return 0;

        //     int left=1+dfs(node->left,target);
        //     int right=1+dfs(node->right,target);
        //     int ret=max(left,right);
        //     memo[node->val]=ret;
        //     cout<<node->val<<","<<ret<<endl;
        //     return max(left,right);
        // }
    };
}