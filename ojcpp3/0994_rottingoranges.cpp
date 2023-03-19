/*
这题应该是一个BFS，用deque的题目，找出是否所有cell都覆盖了
//2:49-3:31 debug花了一些时间，实际上做的很快
只要考虑好边界条件就可以了
pair unpacking
*/
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int,int>> deq;        
        int m=grid.size();
        int n=grid[0].size();

        int totalFresh=0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[i].size();j++) {
                if (grid[i][j]==2) {
                    deq.push_back(pair(i,j));
                } else if (grid[i][j]==1) {
                    totalFresh++;
                }
            }
        }

        int steps=0;
        int dir[]={-1,0,1,0,-1};
        while (!deq.empty()) {
            //cout << "deq size "<<  deq.size() << endl;
            int sz = deq.size();
            bool changed=false;
            for (int i=0;i<sz;i++) {
                auto [x,y]=deq.front();
                deq.pop_front();
                for (int d=0;d<4;d++) {
                    int nx=x+dir[d],ny=y+dir[d+1];
                    if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
                    //cout << "checking "<< nx<<","<<ny<<endl;
                    if (grid[nx][ny]==1) {
                        grid[nx][ny]=2;
                        deq.push_back(pair(nx,ny));
                        //cout << nx<<","<<ny<<" rotting" <<endl;
                        totalFresh--;
                        changed=true;
                    }
                }
            }            
            if (changed) steps++;
            //cout << "steps "<<  steps << endl;
        }
        // 最后一步是清空deq而没有加入新的元素，所以需要steps-1
        return totalFresh==0?steps:-1;
    }
};