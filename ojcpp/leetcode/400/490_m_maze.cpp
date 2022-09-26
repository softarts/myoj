//
// Created by rui.zhou on 2/24/2019.
//

/* Lock
 *
 * 给个array,其中只有一格是9，其他格子是0或1，0表示此路不通，1表示可以走，
 * 判断从（0,0) 点开始上下左右移动能否找到这个是9的格子
 * Maze : 这题折腾了我好久啊！之前没时间把所有题都做一遍（地里的面经已经几乎涵盖了题库了），然后就没做这题，觉得不会遇到……

这题呢，用故事性强一点的说法就是，一只可怜的饥饿的小老鼠在一个N乘以N的迷宫里面（其实就一个二维数组……），它从（0，0）点开始出发，要寻找奶酪来吃（似乎是它闻到有奶酪的味了？）。

然后呢，这个二维数组表示的迷宫里面，1是路，0是墙（如果没记错的话，大家还是认真看看这个），值为9的地方是终点！

题目给出的就是这个二维数组，问你小老鼠最后能不能吃到奶酪（到达9）呢？能的话就返回true，不(e)能(si)的话就返回false。

我留意到了之前做过这个题的楼主提醒，老鼠在（0，0）开始，然后要测（0，0）就是终点（==9）的情况， 多么坑的一个corner case。

然后我就很欢(ku)乐(bi)地开始写了。但是！楼主这题花了30多分钟才写完，原因如下：

倒霉1： 楼主之前各种训练shortest time job first, round robin， 然后各种需要递归迭代的题通通很弱……于是这题就花了很长的时间。

倒霉2： 楼主的网络连接不给力，10分钟之内断了3次，重复登录3次，幸运的是都登录回去了。每次登出都得等2分钟来登回去。（现在想想我应该利用这个登出的时间把题妥妥的做完在登入啊！！）

倒霉3： 楼主没想到起点为0（墙）的情况是直接返回不能(false)的！那时候我已经被网络不佳给搞得特别慌了，就剩12分钟了，心里想着这回惨了，简单题都过不了。
 然后楼主一个不小心点到“test case”那个tab。（注意不是你的test case运行的情况，而是OA给出来的两个示例test case）
 然后那里就有一个起点为墙返回为false…… 然后楼主立即马上迅速地加上了这条才过了的。

 * There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
https://blog.csdn.net/magicbean2/article/details/78706612

 Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2) ->3,1?

Output: false
Explanation: There is no way for the ball to stop at the destination.
Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.


 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution0 {
    public:
        bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
            if (maze.empty() || maze[0].empty() || start.empty() || destination.empty()) return false;
            // 使用一个queue来记录需要尝试的点
            //使用visited来记录已经访问过的点


            using vt=pair<int,int>;
    //        auto my_hash = [](const vt& foo) {
    //            return std::hash<int>()((foo.first<<16)^(foo.second));
    //        };
    //        auto my_eq = [](const vt&a, const vt &b) { return a.first==b.first && a.second==b.second;};
    //        std::unordered_set<vt,decltype(my_hash), decltype(my_eq)> visited(0, my_hash, my_eq);
            int row = maze.size();
            int col = maze[0].size();
            vector<vector<bool>> visited(row,vector<bool>(col,false));
            vector<pair<int, int>> dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//left,right,down,up

            if (start[0]==destination[0] && start[1]==destination[1]) return true;
            std::queue<vt> q;
            q.push({start[0],start[1]});
            visited[start[0]][start[1]] = true;
            while (!q.empty())  {
                auto &pt=q.front();
                q.pop();
                for (int i=0;i<4;i++) {
                    int next_x = pt.first + dx[i].first;
                    int next_y = pt.second + dx[i].second;
                    if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col) {
                        if (next_x == destination[0] && next_y==destination[1])
                            return true;
                        if (maze[next_x][next_y]==1) continue;
                        if(!visited[next_x][next_y]){
                            visited[next_x][next_y] = true;
                            q.push({next_x, next_y});
                            cout << next_x << " " << next_y <<endl;
                        }
                    }
                }
            }
            return false;
        }
    };

    // lintcode 787 感觉和lc有点不一样，球不会停止滚动直到撞上墙？
    class Solution {
    public:
        /**
         * @param maze: the maze
         * @param start: the start
         * @param destination: the destination
         * @return: whether the ball could stop at the destination
         */
        bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
            // write your code here
        }
    };
}



DEFINE_CODE_TEST(490_maze)
{
    Solution obj;
    {
//        0 0 1 0 0
//        0 0 0 0 0
//        0 0 0 1 0
//        1 1 0 1 1
//        0 0 0 0 0
        vector<vector<int>> m{{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
        vector<int> start{0,4}; vector<int> destination{4,4};
        VERIFY_CASE(obj.hasPath(m, start, destination),true);
    }
    {
        vector<vector<int>> m{{0,0,1,0,0},{0,0,1,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
        vector<int> start{0,4}; vector<int> destination{3,2};
        VERIFY_CASE(obj.hasPath(m, start, destination),false);
    }

}
