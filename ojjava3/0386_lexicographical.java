// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

// Example 1:

// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
// Example 2:

// Input: n = 2
// Output: [1,2]

// Constraints:

// 1 <= n <= 5 * 104
// 花费50分钟...

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    // slow
    public List<Integer> lexicalOrder0(int n) {
        List<String> list = new ArrayList();
        for (int i = 1; i <= n; i++) {
            list.add(String.valueOf(i));
        }
        Collections.sort(list);
        List<Integer> res = new ArrayList();
        for (String s : list) {
            res.add(Integer.valueOf(s));
        }
        return res;
    }

    // fast
    private void sub(List<Integer> ans, int start, int k, int n) {
        if (start > n) {
            return;
        }
        for (int i = start; i < start + k; i++) {
            if (i <= n) {
                ans.add(i);
                sub(ans, start * 10, k * 10, n);
            }
        }
        sub(ans, start * 10, k * 10, n);
    }

    public List<Integer> lexicalOrder1(int n) {
        List<Integer> ans = new ArrayList();
        for (int i = 1; i <= 9; i++) {
            sub(ans, i, 1, n);
        }
        return ans;
    }

    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList();
        int curr = 1;
        for (int i = 1; i <= n; i++) {
            ans.add(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                if (curr % 10 == 9 || cur + 1 > n) {
                    curr /= 10;
                }
                curr++;
            }
        }
        return ans;
    }

    public List<Integer> lexicalOrder2(int n) {
        List<Integer> result = new ArrayList<>(n);
        int curr = 1;
        for (int i = 0; i < n; i++) {
            result.add(curr);
            if (curr * 10 <= n) {
                // go deeper (append 0)
                curr *= 10;
            } else {
                // move to next
                // 199 => 1 => 2
                // 109 => 10 => 11
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                curr++;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int n = 130;
        List<Integer> list = new Solution().lexicalOrder1(n);

        for (Integer num : list) {
            System.out.println(num);
        }
    }
}