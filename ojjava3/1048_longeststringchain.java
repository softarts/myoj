
/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


dp 的思路
 */
import java.util.*;

class Solution {
    public int longestStrChain(String[] words) {
        // 必须先排序, 按照长度而不是alphabetical
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        // Arrays.sort(words);
        Map<String, Integer> dp = new HashMap<>();
        int ans = 0;
        // 然后依序更新每个元素所在的dp
        for (String w : words) {
            dp.put(w, 1);
            for (int i = 0; i < w.length(); i++) {
                StringBuilder sb = new StringBuilder(w);
                sb.deleteCharAt(i);
                String prev = sb.toString();
                if (dp.containsKey(prev)) {
                    dp.put(w, Math.max(dp.get(w), dp.get(prev) + 1));
                }
            }
            ans = Math.max(ans, dp.get(w));
        }
        return ans;
    }
}