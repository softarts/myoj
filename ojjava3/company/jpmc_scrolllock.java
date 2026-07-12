/*
 * Scrolling Numbers
 * Programming challerge description:
 * You have been given a special kind of lock to open called a
 * "Scrolling Combination Lock" The lock has 9 keys numbered from 1 to 9.
 * Additionally, there are two numbers printed beow the keys suggesting a range
 * of values. To open the lock, you must enter all the numbers in the range that
 * are "Scatting Numbers"
 * 
 * A Scrolling Number is a number that has two characterisitics:
 * 
 * No digits repeat themselves.
 * All digits in the number "scroll" through themselves.
 * How To Scroll:
 * 
 * Beginning with the leftmost digit, take that digit's value D and move D
 * digits to the right. When scrolling, if the last digit of the number is
 * reached, wrap back to the leftmost digit as many times as needed to move to
 * total of D digits. After scrolling to a new digit, repeat the process using
 * the new digits's value for D.
 * 
 * A Scrolling Number will visit every digit exactly once and end at the
 * leftmost digit.
 * 
 * For example, consider the Scrolling Number 6231.
 * 
 * Start with the digit 6.
 * Advance 6 steps, wrapping around once, to the digit 3.
 * From 3 advance to 2, again wrapping around once
 * From 2 advance to 1
 * From 1 advance to 6 in a final wrap
 * Input:
 * The input is the range of integers to consider for the lock, expressed in the
 * format A, B
 * Each integer A and B is 1 <= A <= B <= 10000.
 * 
 * Output:
 * Print all Scrolling Numbers between A and B inclusive, each on a single line.
 * These are the combinations that will open the lock.
 * 
 * If there are no Scrolling Numbers between A and B print -1.
 * 
 * Test 1
 * Test Input
 * 100,500
 * 
 * Expected Output
 * 147
 * 174
 * 258
 * 285
 * 417
 * 471
 */

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Set;
import java.util.HashSet;

class Solution {
    public List<Integer> getScrollingNumber(int a, int b) {
        List<Integer> ans = new ArrayList<>();

        for (int i = a; i <= b; i++) {
            // Rule 1: No repeated digits

            String s = String.valueOf(i);
            Set<Character> seen = new HashSet<>();
            // rule 1 : no repeat digits
            for (char c : s.toCharArray()) {
                if (seen.contains(c))
                    continue;
                seen.add(c);
            }
            if (seen.size() != s.length()) {
                continue;
            }

            int count = s.length();
            int nextPos = 0;
            // rule 2: all visited
            boolean[] visited = new boolean[count];
            for (int j = 0; j < count; j++) {
                visited[nextPos] = true;
                int value = s.charAt(nextPos) - '0';
                nextPos = (nextPos + value) % count;

            }

            boolean visitedFlag = true;
            for (boolean v : visited) {
                if (!v) {
                    visitedFlag = false;
                    break;
                }
            }

            if (nextPos == 0 && visitedFlag) {
                ans.add(i);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int a = 100, b = 500;
        List<Integer> list = new Solution().getScrollingNumber(a, b);

        for (Integer num : list) {
            System.out.println(num);
        }
    }

}
