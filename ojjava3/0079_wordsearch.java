
/*
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
 */
class Solution {
    String search;

    public boolean exist(char[][] board, String word) {
        int m=board.length;
        int n=board[0].length;
        search = word;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (dfs())
            }
        }
    }

    private void dfs(nt row, int col, int pos, char[][] board, ) {

    }
}