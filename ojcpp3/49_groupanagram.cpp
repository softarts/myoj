/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for (auto &it:strs) {
            std:array<int,26> tmp{0};
            for (int i=0;i<it.length();i++) {
                tmp[it[i]-'a']++;
            }
            // for (int i=0;i<26;i++) {
            //     cout << tmp[i]<<" ";
            // }
            // cout <<endl;
            string key;
            transform(std::begin(tmp),std::end(tmp),
                    std::back_inserter(key),
                    [](int const &i) {
                        return i + '0';
                    });
            //cout << key <<","<<it<<endl;
            m[key].push_back(it);
        }
        for(auto el:m)  {
            ans.push_back(el.second);
        }
        return ans;
    }
};