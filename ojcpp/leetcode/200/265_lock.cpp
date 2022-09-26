/*
Given a 0-indexed integer array nums, return the smallest index i of nums such that i mod 10 == nums[i], or -1 if such index does not exist.

x mod y denotes the remainder when x is divided by y.

 

Example 1:

Input: nums = [0,1,2]
Output: 0
Explanation: 
i=0: 0 mod 10 = 0 == nums[0].
i=1: 1 mod 10 = 1 == nums[1].
i=2: 2 mod 10 = 2 == nums[2].
All indices have i mod 10 == nums[i], so we return the smallest index 0.
Example 2:

Input: nums = [4,3,2,1]
Output: 2
Explanation: 
i=0: 0 mod 10 = 0 != nums[0].
i=1: 1 mod 10 = 1 != nums[1].
i=2: 2 mod 10 = 2 == nums[2].
i=3: 3 mod 10 = 3 != nums[3].
2 is the only index which has i mod 10 == nums[i].
Example 3:

Input: nums = [1,2,3,4,5,6,7,8,9,0]
Output: -1
Explanation: No index satisfies i mod 10 == nums[i].
Example 4:

Input: nums = [2,1,3,5,2]
Output: 1
Explanation: 1 is the only index with i mod 10 == nums[i].
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 9
*/
// class Solution {
// public:
//     int smallestEqual(vector<int>& nums) {
//         int ans = INT_MAX;
//         for (int i=0;i<nums.size();i++) {
//             if (i%10 == nums[i]) {
//                 ans = min(ans, i);
//             }
//         }
//         return ans==INT_MAX?-1:ans;
//     }
// };

/*
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
Example 4:


Input: head = [2,3,3,2]
Output: [-1,-1]
Explanation: There are no critical points in [2,3,3,2].
 

Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105
*/
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         int mind=INT_MAX,maxd=INT_MIN,prevPos=-1,curPos=0;
//         ListNode* prev=nullptr;
//         while (head) {
//             if (prev && head->next) {
//             if (head->val<prev->val && head->val<head->next->val) {
//                 if (prevPos==-1) {
//                     prevPos=curPos;
//                 } else {
//                     maxd = max(maxd,curPos-prevPos);
//                     prevPos=curPos;
//                 }
                
//             }
//             if (head->val<prev->val && head->val<head->next->val) {
//                 if (prevPos==-1) {
//                     prevPos=curPos;
//                 } else {
//                     mind = min(mind,curPos-prevPos);
//                     prevPos=curPos;
//                 }
//             }

//             }
//             curPos++;
//             head=head->next;
//         }
//         return vector<int>{mind, maxd};
//     }
// };

/*
You are given a 0-indexed integer array nums containing distinct numbers, an integer start, and an integer goal. There is an integer x that is initially set to start, and you want to perform operations on x such that it is converted to goal. You can perform the following operation repeatedly on the number x:

If 0 <= x <= 1000, then for any index i in the array (0 <= i < nums.length), you can set x to any of the following:

x + nums[i]
x - nums[i]
x ^ nums[i] (bitwise-XOR)
Note that you can use each nums[i] any number of times in any order. Operations that set x to be out of the range 0 <= x <= 1000 are valid, but no more operations can be done afterward.

Return the minimum number of operations needed to convert x = start into goal, and -1 if it is not possible.

 

Example 1:

Input: nums = [1,3], start = 6, goal = 4
Output: 2
Explanation:
We can go from 6 → 7 → 4 with the following 2 operations.
- 6 ^ 1 = 7
- 7 ^ 3 = 4
Example 2:

Input: nums = [2,4,12], start = 2, goal = 12
Output: 2
Explanation:
We can go from 2 → 14 → 12 with the following 2 operations.
- 2 + 12 = 14
- 14 - 2 = 12
Example 3:

Input: nums = [3,5,7], start = 0, goal = -4
Output: 2
Explanation:
We can go from 0 → 3 → -4 with the following 2 operations. 
- 0 + 3 = 3
- 3 - 7 = -4
Note that the last operation sets x out of the range 0 <= x <= 1000, which is valid.
Example 4:

Input: nums = [2,8,16], start = 0, goal = 1
Output: -1
Explanation:
There is no way to convert 0 into 1.
Example 5:

Input: nums = [1], start = 0, goal = 3
Output: 3
Explanation: 
We can go from 0 → 1 → 2 → 3 with the following 3 operations. 
- 0 + 1 = 1 
- 1 + 1 = 2
- 2 + 1 = 3
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i], goal <= 109
0 <= start <= 1000
start != goal
All the integers in nums are distinct.
*/
// class Solution {
// public:
//     int minimumOperations(vector<int>& nums, int start, int goal) {
        
//     }
// };


/**
 * An original string, consisting of lowercase English letters, can be encoded by the following steps:

Arbitrarily split it into a sequence of some number of non-empty substrings.
Arbitrarily choose some elements (possibly none) of the sequence, and replace each with its length (as a numeric string).
Concatenate the sequence as the encoded string.
For example, one way to encode an original string "abcdefghijklmnop" might be:

Split it as a sequence: ["ab", "cdefghijklmn", "o", "p"].
Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes ["ab", "12", "1", "p"].
Concatenate the elements of the sequence to get the encoded string: "ab121p".
Given two encoded strings s1 and s2, consisting of lowercase English letters and digits 1-9 (inclusive), return true if there exists an original string that could be encoded as both s1 and s2. Otherwise, return false.

Note: The test cases are generated such that the number of consecutive digits in s1 and s2 does not exceed 3.

 

Example 1:

Input: s1 = "internationalization", s2 = "i18n"
Output: true
Explanation: It is possible that "internationalization" was the original string.
- "internationalization" 
  -> Split:       ["internationalization"]
  -> Do not replace any element
  -> Concatenate:  "internationalization", which is s1.
- "internationalization"
  -> Split:       ["i", "nternationalizatio", "n"]
  -> Replace:     ["i", "18",                 "n"]
  -> Concatenate:  "i18n", which is s2
Example 2:

Input: s1 = "l123e", s2 = "44"
Output: true
Explanation: It is possible that "leetcode" was the original string.
- "leetcode" 
  -> Split:      ["l", "e", "et", "cod", "e"]
  -> Replace:    ["l", "1", "2",  "3",   "e"]
  -> Concatenate: "l123e", which is s1.
- "leetcode" 
  -> Split:      ["leet", "code"]
  -> Replace:    ["4",    "4"]
  -> Concatenate: "44", which is s2.
Example 3:

Input: s1 = "a5b", s2 = "c5b"
Output: false
Explanation: It is impossible.
- The original string encoded as s1 must start with the letter 'a'.
- The original string encoded as s2 must start with the letter 'c'.
Example 4:

Input: s1 = "112s", s2 = "g841"
Output: true
Explanation: It is possible that "gaaaaaaaaaaaas" was the original string
- "gaaaaaaaaaaaas"
  -> Split:      ["g", "aaaaaaaaaaaa", "s"]
  -> Replace:    ["1", "12",           "s"]
  -> Concatenate: "112s", which is s1.
- "gaaaaaaaaaaaas"
  -> Split:      ["g", "aaaaaaaa", "aaaa", "s"]
  -> Replace:    ["g", "8",        "4",    "1"]
  -> Concatenate: "g841", which is s2.
Example 5:

Input: s1 = "ab", s2 = "a2"
Output: false
Explanation: It is impossible.
- The original string encoded as s1 has two letters.
- The original string encoded as s2 has three letters.
 

Constraints:

1 <= s1.length, s2.length <= 40
s1 and s2 consist of digits 1-9 (inclusive), and lowercase English letters only.
The number of consecutive digits in s1 and s2 does not exceed 3. 
 * */

// class Solution {
// public:
//     bool possiblyEquals(string s1, string s2) {
        
//     }
// };