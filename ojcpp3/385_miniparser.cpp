#include <vector>
#include <string>
using namespace std;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
   // Constructor initializes an empty nested list.
    NestedInteger(){};

     // Constructor initializes a single integer.
     NestedInteger(int value){};

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni){};

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

/*
Input: s = "[123,[456,[789]]]"
Output: [123,[456,[789]]]
这题有点像autodesk考过的flat 341
*/
#include <ctype.h>
#include <stack>

// passed
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ni;
        stack<NestedInteger> sta({ni});
        for (int i=0;i<s.length();i++) {
            char ch=s[i];
            if (s[i]=='[') { // it is list                
                sta.push(NestedInteger());                
            } else if (isdigit(ch) || ch=='-') {
                long num = 0;
                int sign=+1;
                if (ch=='-') {sign=-1;i++;} // 处理-
                while (i<s.length() && isdigit(s[i])) {                    
                    num=num*10+s[i]-'0';
                    i++;
                }
                i--;
                sta.top().add(NestedInteger(num*sign));                
            } else if (s[i]==']') { 
                auto ni = sta.top();sta.pop();
                sta.top().add(ni);
            }
        }
        return sta.top().getList()[0];
    }
        
};