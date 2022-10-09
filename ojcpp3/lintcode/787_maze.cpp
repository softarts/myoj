// amazon
// lc490m,499h,505m
/*
在迷宫中有一个球，里面有空的空间和墙壁。球可以通过滚上，下，左或右移动，
但它不会停止滚动直到撞到墙上。当球停止时，它可以选择下一个方向。

给定球的起始位置，目的地和迷宫，确定球是否可以停在终点。

迷宫由二维数组表示。1表示墙和0表示空的空间。你可以假设迷宫的边界都是墙。开始和目标坐标用行和列索引表示。
*/
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int numRows=maze.size();
        int numColumns=maze[0].size();
        if (numRows==0 || numColumns==0) return false;
        
        using vt=pair<int,int>;
        using mytuple=tuple<int,int,int>;

        vector<vector<bool>> visited(numRows,vector<bool>(numColumns,false));
        vector<pair<int, int>> dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//left,right,down,up

        //if (lot[0][0] == 9) return 1;
        if (start == destination) return true;
        
        std::queue<mytuple> q;
        q.push({0,0,0});
        visited[0][0] = true;
        int minStep = INT_MAX;
        int x,y,step;

        while (!q.empty())  {
            std::tie(x, y, step) = q.front();
            q.pop();
            for (int i=0;i<4;i++) {
                int next_x = x + dx[i].first;
                int next_y = y + dx[i].second;
                if (next_x >= 0 && next_x < numRows && next_y >= 0 && next_y < numColumns) {
                    if (maze[next_x][next_y] == 9) {
                        minStep=min(minStep,step+1);
                    } else if (maze[next_x][next_y]==0) { //trench
                        continue;
                    }
                    if(!visited[next_x][next_y]){
                        visited[next_x][next_y] = true;
                        q.push({next_x, next_y,step+1});
                    }
                }
            }
        }
        return minStep==INT_MAX?-1:minStep;
        }
};