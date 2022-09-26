//
// Created by rui.zhou on 2/7/2019.
//
/*
 * Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
 */
#include <codech/codech_def.h>
using namespace std;

// 不太理想，不应该用额外的变量来保存全排列。
class Solution0 {
public:
    vector<int> numbers;
    vector<vector<int>> permutations;
    Solution0(vector<int> nums) {
        numbers = nums;
        do {
            permutations.push_back(nums);
        } while ( std::next_permutation(nums.begin(),nums.end()));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return numbers;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int idx = rand()% permutations.size();
        return permutations[idx];
    }
};

#include <random>
class Solution {
public:
    vector<int> numbers;
    Solution(vector<int> nums) {
        numbers = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return numbers;
    }

    // 从一个逐渐缩小的范围选出一个idx 与当前idx 交换，较难理解
    vector<int> shuffle0() {
        vector<int> array = numbers;
        // C++ swap is an in-place function
        for(int i = numbers.size(); i>0; i--){
            swap(array[rand()%i], array[i-1]);
        }
        return array;
    }

    vector<int> shuffle() {
        vector<int> array = numbers;
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator

        for(int i = 0; i < numbers.size();i++ ){
           std::uniform_int_distribution<> distr(i, numbers.size()-1);
           int idx = distr(eng);
           swap(array[idx], array[i]);
        }
        return array;
    }
};