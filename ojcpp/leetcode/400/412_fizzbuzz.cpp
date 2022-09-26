//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/fizz-buzz/description/
 * Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */

#include <codech/codech_def.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i=1;i<=n;i++) {
            string s = "";
            if (i % 3 ==0) {
                s+="Fizz";
            }
            if (i % 5==0) {
                s+="Buzz";
            }
            if (i % 3!=0 && i%5!=0) {
                s+=to_string(i);
            }
            //s+="\"";
            ret.push_back(std::move(s));
        }
        return ret;
    }
};

void printfizz(vector<string> &&ret) {
    for (auto &iter:ret) {
        cout << iter << endl;
    }
}

DEFINE_CODE_TEST(412_fizzbuzz)
{
    Solution obj;
    printfizz(obj.fizzBuzz(20));
}