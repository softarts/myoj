//
// Created by rui.zhou on 2/24/2019.
//
/*
 * 题目 给出一个grid，1表示可以走,0表示有障碍，9表示到达目的地，找出到达目的地需要的最少步数
 */
#include <codech/codech_def.h>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;

//
int removeObstacle(int numRows, int numColumns, int **lot)
{
    // WRITE YOUR CODE HERE
    // use BFS to search the path. use a queue to keep all the to be visited points,
    // array 'visited' to remember those visited points.
    // for each move, will push the current row,col,number of step into the queue
    // when it reachs the destination, update the minStep.
    if (numRows==0 || numColumns==0) return -1;
    using vt=pair<int,int>;
    using mytuple=tuple<int,int,int>;

    vector<vector<bool>> visited(numRows,vector<bool>(numColumns,false));
    vector<pair<int, int>> dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//left,right,down,up

    if (lot[0][0] == 9) return 1;
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
                if (lot[next_x][next_y] == 9) {
                    minStep=min(minStep,step+1);
                } else if (lot[next_x][next_y]==0) { //trench
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
// FUNCTION SIGNATURE ENDS

DEFINE_CODE_TEST(amazon_robot)
{
    // TODO 指针
    int **arr = new int*[3];
    for (int i=0;i<3;i++) {
        arr[i]=new int[3];
    }
    arr[0][0]=1;
    arr[0][1]=0;
    arr[0][2]=0;
    arr[1][0]=1;
    arr[1][1]=0;
    arr[1][2]=0;
    arr[2][0]=1;
    arr[2][1]=9;
    arr[2][2]=1;


    //int loc[3][2] = {{1,2},{3,4},{1,-1}};
    auto ret = removeObstacle(3,3,arr);
    cout<<ret;



}
