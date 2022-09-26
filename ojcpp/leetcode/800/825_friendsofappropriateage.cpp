//
// Created by rui zhou on 29/04/18.
//

/*
 * https://leetcode.com/contest/weekly-contest-82/problems/friends-of-appropriate-ages/
 * Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.

Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

How many total friend requests are made?

Example 1:

Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.
Example 2:

Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
Example 3:

Input: [20,30,100,110,120]
Output:
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 */

#include <codech/codech_def.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        if (ages.size() <=1)
            return 0;

        sort(ages.begin(),ages.end());
        for (auto iter:ages) {
            cout << iter <<" ";
        }
        cout <<endl;
        int total = 0;
        int prev = INT_MIN;
        for (auto iter = ages.begin(); iter!=ages.end(); ++iter) {
            int b = *iter;
            if (prev == INT_MIN) {
                prev = b;
            } else if (b==prev) {
                total +=1;
            } else {
                prev = b;
            }

            int a1 = max(b+1,(b-7)*2);  // < a1 ok
            auto ui = std::lower_bound(iter, ages.end(), a1);

            for (auto ni = iter;ni!=ui;++ni) {
                cout << *ni << " ";
            }

            int count = std::max(long(0),long(std::distance(iter, ui) -1));
            total += count;
            cout<<","<< a1 <<","<<count <<"," << total <<endl;
        }
        return total;
    }
};


DEFINE_CODE_TEST(825_friends_ofappropriate_age)
{
    Solution obj;


    {
        vector<int> ages{73,106,39,6,26,15,30,100,71,35,46,112,6,60,110};
        VERIFY_CASE(obj.numFriendRequests(ages),29);
    }


//    {
//        vector<int> ages{16,17,18};
//        VERIFY_CASE(obj.numFriendRequests(ages),2);
//    }
//
//    {
//        vector<int> ages{16,17};
//        VERIFY_CASE(obj.numFriendRequests(ages),1);
//    }
//    {
//        vector<int> ages{16,16};
//        VERIFY_CASE(obj.numFriendRequests(ages),2);
//    }
//    {
//        vector<int> ages{16,17,18};
//        VERIFY_CASE(obj.numFriendRequests(ages),2);
//    }
//    {
//        vector<int> ages{20,30,100,110,120};
//        VERIFY_CASE(obj.numFriendRequests(ages),3);
//    }

}
