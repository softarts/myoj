//
// Created by rui.zhou on 9/26/2019.
//

/*
 * Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,4,6].


 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    /**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

    class NestedInteger {
    public:
        bool isInteger() const {return true;}
        int getInteger() const {return 0;}
        const vector<NestedInteger> &getList() const {return vector<NestedInteger>(0);}
    };

    // 思路
    // [[[1]] 怎么解决？[[[1,2,3]]],如果item是一个nested iter的时候怎么处理？
    // 能否使用额外空间，stack？
    // time O(N), space O(N)
    class NestedIterator {
    public:
        vector<int> arr;
        int idx = 0;
        void flatten(const vector<NestedInteger> &nestedList) {
            for (int i=0;i<nestedList.size();i++) {
                if (nestedList[i].isInteger()) {
                    arr.emplace_back(nestedList[i].getInteger());
                } else {
                    flatten(nestedList[i].getList());
                }
            }
        }

        NestedIterator(vector<NestedInteger> &nestedList) {
            flatten(nestedList);
        }

        int next() {
            return arr[idx++];
        }

        bool hasNext() {
            return idx < arr.size();
        }
    };
    //TODO 不使用额外空间?


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
}