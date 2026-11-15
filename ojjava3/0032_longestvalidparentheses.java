/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0

使用stack,然后计算栈顶的index和当前的index的差距，就是最大长度
 */

import java.util.*;
import java.Math.*;
class Solution {
    public int longestValidParentheses(String s) {
        int answer = 0;
        record Pair<K, V>(K key, V value) {}
        Deque<Pair<Character, Integer>> stack = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            if (!stack.isEmpty()) {
                if (s.charAt(i)==')') {
                    Pair<Character, Integer> item =  stack.peek();
                    if (item.key() == '(') {
                        stack.pop();
                        int curIdx = stack.isEmpty()?-1:stack.peek().value();
                        int curLen = i - curIdx;
                        answer = Math.max(answer, i - curIdx);
                    } else {
                        stack.push(new Pair<>(s.charAt(i), i));
                    }
                } else {
                    stack.push(new Pair<>(s.charAt(i), i));
                }
            } else {
                stack.push(new Pair<>(s.charAt(i), i));
            }
        }
        return answer;
    }
}
