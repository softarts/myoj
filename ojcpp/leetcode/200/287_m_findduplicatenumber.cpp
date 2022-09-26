//
// Created by Rui Zhou on 16/3/18.
//

/*
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 * find the duplicate one.

 Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3

Note:
You must not modify the array (assume the array is read only).  no sort
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

 medium
 N+1长度的数组，取值范围是N，所以必定有一个重复的字符，怎么找出来。
 要求只能使用O(1) space的话，就不可以用1hashtable
 复杂度  O(N^2)

 关键是让数组形成一个闭环，1 3 4 2 2如何形成cycle？
 如果仅以数值来连接，那需要一个hashmap来记住每一个数字的所在node,例如1 2 3 4 2,最后一个2的时候如何重新指向前面出现的2

 另一种思路:
 以每个位置的数值作为下一个node的index,例如1 2 3 4 2 那么就会变成[N0/1]->[N1/2]->[N2/3]->[N3/4]->[N4/2]->[N2/3],
 从而在3/4/2之间形成一个cycle.通过龟兔快慢指针可以在这个cycle上的某一点相遇

 接下来需要再来一次循环，确定原数组何处可以进入这个cycle.  //Floyd 算法？

 https://ask.julyedu.com/question/7299
 解释比较好
 环的检测从上面的解释理解起来应该没有问题。接下来我们来看一下如何确定环的起点，这也是Floyd解法的第二部分。
*方法是将慢指针（或快指针）移到链表起点，两者同时移动，每次移动一步，那么两者相遇的地方就是环的起点。

*这样做的道理在于。假设起点到环的起点距离为m，已经确定有环，环的周长为n，（第一次）相遇点距离环的起点的距离是k。
*那么当两者相遇时，慢指针移动的总距离为i，i = m + a * n + k，
*因为快指针移动速度为慢指针的两倍，那么快指针的移动距离为2i，2i = m + b * n + k。
*其中，a和b分别为慢指针和快指针在第一次相遇时转过的圈数。我们让两者相减（快减慢），那么有i = (b - a) * n。
*即i是圈长度的倍数。利用这个结论我们就可以理解Floyd解法为什么能确定环的起点。

*将一个指针移到链表起点，另一个指针不变，即距离链表起点为i处，两者同时移动，每次移动一步。
*当第一个指针前进了m，即到达环起点时，另一个指针距离链表起点为i + m。
*考虑到i为圈长度的倍数，可以理解为指针从链表起点出发，走到环起点，然后绕环转了几圈，所以第二个指针也必然在环的起点。
*即两者相遇点就是环的起点。
明白了 :i+m 为原先留在环里的指针的距离，i为环长度的倍数,m为起点到环的入口，真好吻合。


 */

#include <codech/codech_def.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        // find the entrance to the cycle
        //https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
        //如果有限状态机、迭代函数或者链表上存在环，那么在某个环上以不同速度前进的2个指针必定会在某个时刻相遇。同时显然地，
        // 如果从同一个起点(即使这个起点不在某个环上)同时开始以不同速度前进的2个指针最终相遇，那么可以判定存在一个环，
        // 且可以求出2者相遇处所在的环的起点与长度。

        //上述算法刚判断出存在环C时，显然t和h位于同一节点，设其为节点M。显然，仅需令h不动，而t不断推进，最终又会返回节点M，统计这一次t推进的步数，显然这就是环C的长度。
        //
        //为了求出环C的起点，只要令h仍均位于节点M，而令t返回起点节点S，此时h与t之间距为环C长度的整数倍。随后，
        // 同时让t和h往前推进，且保持二者的速度相同：t每前进1步，h前进1步。持续该过程直至t与h再一次相遇，
        // 设此次相遇时位于同一节点P，则节点P即为从节点S出发所到达的环C的第一个节点，即环C的一个起点。

        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};


DEFINE_CODE_TEST(287_m_findduplicatenumber)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,4,2};
        VERIFY_CASE(obj.findDuplicate(nums),2);
    }
    {
        vector<int> nums{1,2,3,4,4,5};
        VERIFY_CASE(obj.findDuplicate(nums),4);
    }
    {
        vector<int> nums{6,1,2,3,4,4,5};
        VERIFY_CASE(obj.findDuplicate(nums),4);
    }
    {
        vector<int> nums{6,1,4,3,4,4,5};
        VERIFY_CASE(obj.findDuplicate(nums),4);
    }

}
