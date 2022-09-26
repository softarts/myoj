//
// Created by rui.zhou on 2/5/2019.
//

/* DRW
 * Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

这是DRW曾经面试过的题目,并不是很特别, 要求insert / remove 都是O(1)，并且能随机返回一个element
 使用hashtable达到insert / remove O(1)，同时使用vector来记下 index-nums映射，
 每插入一个元素，从vector得到一个新的index，插入到vector末尾
 每删除一个元素,得到index,去vector中删除对应元素，为了不影响vector layout,需要把末尾的元素来swap



 */

#include <codech/codech_def.h>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> numsToIndex;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (numsToIndex.find(val) != numsToIndex.end())
            return false;

        nums.push_back(val);
        numsToIndex[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (numsToIndex.find(val) == numsToIndex.end())
            return false;
        //这里挺巧妙的，把最后一个数字和待删除数字互换，然后删除最后一个数字
        int indexToDelete = numsToIndex[val];
        nums[indexToDelete] = nums[nums.size() -1]; // 等于最后一个元素
        numsToIndex[nums[indexToDelete]] = indexToDelete; // update hashtable
        nums.resize(nums.size() - 1);  // 相当于删除最后一个元素.
        // If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
        numsToIndex.erase(val); // 删除hashtable中的元素

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0];
        int index = rand() % (nums.size());

        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */



DEFINE_CODE_TEST(380_insertdeleterandom)
{
    RandomizedSet obj;
    VERIFY_CASE(obj.insert(1),true);
    VERIFY_CASE(obj.getRandom(),1);
    VERIFY_CASE(obj.remove(1),true);
}
