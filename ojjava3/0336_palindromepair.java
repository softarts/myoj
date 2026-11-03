
/*
You are given a 0-indexed array of unique strings words.

A palindrome pair is a pair of integers (i, j) such that:

0 <= i, j < words.length,
i != j, and
words[i] + words[j] (the concatenation of the two strings) is a palindrome.
Return an array of all the palindrome pairs of words.

You must write an algorithm with O(sum of words[i].length) runtime complexity.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]
 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lowercase English letters.
最难的是要O(N)内作出判断
trie dict 字典树是个好东西，常见
写对很难 - 面试应该不会考
3种情况
a: 正好对称匹配完
b: trie里的长 - 这个需要保存palindromesuffix
c: trie里的短

 */

import java.util.*;

class Solution {
    private static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        // index
        int wordIndex = -1;
        List<Integer> palindromeSuffixes = new ArrayList<>(); // 记录经过此节点后，剩余部分是回文串的单词索引
    
    }
    private void insert(TrieNode root, String word, int index) {
        // 逆向插入trie tree
        TrieNode curr = root;
        for (int i=word.length()-1;i>=0;i--) {
            if (isPalindrome(word, 0, i)) {
                curr.palindromeSuffixes.add(index);
            }
            int c = word.charAt(i)-'a';
            if (curr.children[c] == null) {
                curr.children[c] = new TrieNode();
            }
            curr = curr.children[c];
            // // 修正：将回文判断放在走完之后的 curr 节点上
            // if (isPalindrome(word, 0, i)) {
            //     curr.palindromeSuffixes.add(index);
            // }
        }
        curr.wordIndex = index; // 先做简单匹配
        //["aba", "aba"]
        curr.palindromeSuffixes.add(index); // 单词完全匹配完，空后缀也是回文

    }

    private void search(TrieNode root, String word, int index, List<List<Integer>> answer) {
        TrieNode curr = root;
        for (int i = 0; i < word.length() && curr!=null; i++) {
            if (curr.wordIndex >= 0 && curr.wordIndex != index
                    && isPalindrome(word, i, word.length() - 1)) {
                answer.add(Arrays.asList(index, curr.wordIndex));
            }
            
            int c = word.charAt(i) - 'a';
            // if (curr.children[c] == null) {
            //     return;
            // }
            curr=curr.children[c];
        }

        // if (curr!=null && curr.wordIndex >= 0 && curr.wordIndex != index) {
        //     answer.add(Arrays.asList(index, curr.wordIndex));
        // }
        // 情况 C：Trie 中有比当前 word 更长的单词，且其在 Trie 中多出来的剩余部分是回文串
        if (curr!=null && curr.palindromeSuffixes.size()>0 ) {
            for (int j : curr.palindromeSuffixes) {
                if (j != index) {
                    answer.add(Arrays.asList(index, j));
                }
            }
        }
    }


    
    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left++) != s.charAt(right--)) {
                return false;
            }
        }
        return true;
    }


    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> answer = new ArrayList<>();
        TrieNode root = new TrieNode(); // global root
        for (int i=0; i< words.length; i++) {
            insert(root, words[i], i);
        }
        // debugTrie(root);

        // search
        for (int i=0; i<words.length; i++) {
            search(root, words[i], i , answer);
        }

        return answer;
    }





    private void debugTrie(TrieNode root) {
        System.out.println("Trie tree (words stored in reverse):");
        debugTrie(root, "", "root");
    }

    private void debugTrie(TrieNode node, String indent, String label) {
        System.out.println(indent + label
                + (node.wordIndex >= 0 ? " [wordIndex=" + node.wordIndex + "]" : "")
                + (node.palindromeSuffixes.isEmpty()? "":" [palindromeSuffixes=" + node.palindromeSuffixes + "]"));
        for (int i = 0; i < node.children.length; i++) {
            if (node.children[i] != null) {
                debugTrie(node.children[i], indent + "  ", String.valueOf((char) ('a' + i)));
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("测试情况B");
        Solution solution = new Solution();
        
        // 测试 LeetCode 336: 回文对
        String[] words = {"abcd", "dcba", "lls", "s", "sssll"};
        System.out.println("LeetCode 336 测试结果: " + solution.palindromePairs(words));
    }

}

//
class Solution2 {
    public static class Trie {
    int pos;
    Trie[] nodes;   // consider xyxabc. if current trie is 'a'. Then a.nodes has information. It means string after a is palindrome
    List<Integer> palins;
    public Trie() {
        pos = -1;
        nodes = new Trie[26];
        palins = new ArrayList<>();
    }
}

public static void add(Trie root, String word, int pos) {
    for (int i = word.length() - 1; i >= 0; i--) {
        char ch = word.charAt(i);
        if (isPalindrome(word, 0, i)) { // check if substring(0, i) is palindrome.
            root.palins.add(pos);
        }
        if (root.nodes[ch - 'a'] == null) {
            root.nodes[ch - 'a'] = new Trie();
        }
        root = root.nodes[ch - 'a'];
    }
    root.pos = pos; // if it is xyxcba. Until now, the node should be at x.
    root.palins.add(pos);
}

public static void search(Trie root, String[] words, int i, List<List<Integer>> ans) {
    int len = words[i].length();
    for (int j = 0; j < len && root != null; j++) {
        if (root.pos >= 0 && i != root.pos && isPalindrome(words[i], j, len - 1)) {
            ans.add(Arrays.asList(new Integer[] {i, root.pos}));
        }
        char ch = words[i].charAt(j);
        root = root.nodes[ch - 'a'];
    }
    if (root != null && root.palins.size() > 0) { // assume 'xyxabc' is in trie, now try 'cba'
        for (int j : root.palins) {
            if (j != i) {
                ans.add(Arrays.asList(new Integer[] {i, j}));
            }
        }
    }
}

public static List<List<Integer>> palindromePairs(String[] words) {
    List<List<Integer>> ans = new ArrayList<>();
    Trie trie = new Trie();
    for (int i = 0; i < words.length; i++) {
        add(trie, words[i], i);
    }
    for (int i = 0; i < words.length; i++) {
        search(trie, words, i, ans);
    }
    return ans;
}

public static boolean isPalindrome(String str, int i, int j) {
    while (i < j) {
        if (str.charAt(i++) != str.charAt(j--)) {
            return false;
        }
    }
    return true;
}
}