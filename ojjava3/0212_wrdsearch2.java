
/*
m x n 的棋盘，每个单元格由 'a' 到 'z' 的字母组成
wordDict 里的单词都是由小写字母组成
你可以从任意一个单元格开始在棋盘上搜索
每次搜索时，把单元格里的字母当成单词的首字母
然后往上下左右四个方向移动，把当前路径上的字母连起来
如果连起来的路径正好是 wordDict 里的一个单词，就算找到了

同一个cell不能在一个word用两次

这显然是DFS
你这个问题其实就是 LeetCode 212 Word Search II（不是 214 😅，214 是最短回文串）。题意：在棋盘上搜索字典里的单词，不能重复使用同一个 cell。典型解法就是 DFS + Trie，因为直接对每个单词做 DFS 会超时。

*/
class Solution {
    public List<String> findWords(char[][] board, String[] words) {

    }

    public void dfs(char[][] board, int i, int j, String word) {

    }
}
