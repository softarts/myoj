/*
2457. Minimum Addition to Make Integer Beautiful
User Accepted:4315
User Tried:6825
Total Accepted:4483
Total Submissions:16195
Difficulty:Medium
You are given two positive integers n and target.

An integer is considered beautiful if the sum of its digits is less than or equal to target.

Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.

即补一个什么数能让它变成beautiful number
16 -> 6, 补 4
467 -> 6 补33
11:24->
看到long 必须注意溢出，使用long
*/


class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {        
        long ans = 0;
        auto isBeautiful = [&](long m) {
            int sum = 0;            
            while (m>0) {
                sum+=m%10;
                m=m/10;
            }
            return (sum<=target);
        };
        
        long tens=1;
        while (!isBeautiful(n)) {
            ans = (10 - n % 10)*tens+ans;
            n=n/10+1;
            tens*=10;
        }

        return ans;        
    }
};