
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

import java.util.*;

class Solution {
    int m, n;
    // int[][] visited; // 用二维数组标记访问过的格子

    static class Node {
        // boolean isEnd;
        Node[] children = new Node[26];
        String word;
    }

    public List<String> findWords(char[][] board, String[] words) {
        m = board.length;
        n = board[0].length;

        // build trie
        Node trieRoot = new Node();
        for (String w : words) {
            Node p = trieRoot;
            for (char c : w.toCharArray()) {
                if (p.children[c - 'a'] == null) {
                    p.children[c - 'a'] = new Node();
                }
                p = p.children[c - 'a'];
            }
            // p.isEnd = true;
            p.word = w;
        }

        // loop
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, trieRoot, ans);
            }
        }
        return ans;
    }

    public void dfs(char[][] board, int i, int j, Node node, List<String> ans) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        char c = board[i][j];
        if (c == '#' || node.children[c - 'a'] == null)
            return; // not match
        node = node.children[c - 'a'];

        if (node.word != null) { // it hit the end
            ans.add(node.word);
            node.word = null; // 防止重复选择同一个词

        }

        // 不再需要检查trie node是否到了 end
        // if (trieRoot.isEnd){
        // ans.add(sb.toString());
        // trieRoot.isEnd = false;
        // }

        board[i][j] = '#';
        dfs(board, i + 1, j, node, ans);
        dfs(board, i - 1, j, node, ans);
        dfs(board, i, j + 1, node, ans);
        dfs(board, i, j - 1, node, ans);
        board[i][j] = c; // 回溯恢复
    }
}
