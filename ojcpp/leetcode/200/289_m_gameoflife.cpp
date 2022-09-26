//
// Created by rui.zhou on 9/25/2019.
//

/*
 * According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 不使用额外空间，怎么修改,使用位操作
 static bool live(int **board, int boardSize, int *boardColSize, int x, int y) {
        return x >= 0 && x < boardSize && y >= 0 && y < *boardColSize && board[x][y];
}

static int live_neighbours(int **board, int boardSize, int *boardColSize, int x, int y) {
    int count = 0;
    for (int x_offset = -1; x_offset <= 1; x_offset++) {
            for (int y_offset = -1; y_offset <= 1; y_offset++) {
                    count += live(board, boardSize, boardColSize, x + x_offset, y + y_offset);
            }
    }
    return count - board[x][y];
}

 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        int checkNeighbours(vector<vector<int>>& board, int i,int j, int row_size, int col_size) {
            int count = 0;
            for (int x=-1;x<=1;x++) {
                for (int y=-1;y<=1;y++) {
                    if (y==0 && x==0) continue;
                    count+= (i+y>=0 && i+y<row_size && j+x>=0 && j+x<col_size  && (board[i+y][j+x] & 0x1));
                }
            }
            return count;
        }
//        Any live cell with fewer than two live neighbors dies, as if caused by under-population.
//        Any live cell with two or three live neighbors lives on to the next generation.
//        Any live cell with more than three live neighbors dies, as if by over-population..
//        Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

        void gameOfLife(vector<vector<int>>& board) {
            if (board.empty()) return;
            int row_size = board.size();
            int col_size = board[0].size();
            for (int i=0;i<row_size;i++) {
                for (int j=0;j<col_size;j++) {
                    int live = checkNeighbours(board,i,j,row_size,col_size);
                    if ((board[i][j]&0x1)==1 && (live<2 || live>3)) {
                        board[i][j] = 1&board[i][j]; //dead
                    } else if ((board[i][j]&0x1)==1 && (live==2 || live==3)) {
                        board[i][j] = 2|board[i][j];  //live
                    } else if ((board[i][j]&0x1)==0 && live==3) {
                        board[i][j] = 2|board[i][j];  //live
                    }
                }
            }

            for (int i=0;i<row_size;i++) {
                for (int j=0;j<col_size;j++) {
                    board[i][j] = (board[i][j]&0x2)>>1;
                }
            }
        }
    };
}

DEFINE_CODE_TEST(289_gameoflife)
{
    Solution obj;
    {
//        Input:
//        [
//        [0,1,0],
//        [0,0,1],
//        [1,1,1],
//        [0,0,0]
//        ]
//        Output:
//        [
//        [0,0,0],
//        [1,0,1],
//        [0,1,1],
//        [0,1,0]
//        ]

        vector<vector<int>> m{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
        obj.gameOfLife(m);
        vector<vector<int>> exp{{0,0,0},{1,0,1},{0,1,1},{0,0,0}};
        //cout << PRINT_VVEC(move(m)) << endl;
        VERIFY_CASE(VERIFY_VV(move(m),exp, false),true);
    }
}
