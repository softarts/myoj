//
// Created by rui zhou on 18/03/18.
//

/*
 * 800
 * https://leetcode.com/contest/weekly-contest-76/problems/similar-rgb-color/
 *
 * In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a shorthand color "#RGB" that is most similar to #ABCDEF.

Example 1:
Input: color = "#09f166"
Output: "#1e6"
Explanation:
The similarity is -(09 - 11)^2 -(f1 - ee)^2 - (66 - 66)^2 = -2^2 - 3^2 - 0^2 = -13.
This is the lowest among any shorthand color.
Note:

color is a string of length 7.
color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
Any answer which has the same similarity as the best answer will be accepted.
All inputs and outputs should use lowercase letters.

 */
#include <codech/codech_def.h>
#include <iostream>
#include <sstream>
//#include <cstdlib>
//#include <stdlib.h>


using namespace std;


class Solution {
public:
    string similarRGB(string color) {
        int r = (int)strtol(string(color,1,2).c_str(), NULL, 16);
        int g = (int)strtol(string(color,3,2).c_str(), NULL, 16);
        int b = (int)strtol(string(color,5,2).c_str(), NULL, 16);


        string r1 = findstr(r);
        string g1 = findstr(g);
        string b1 = findstr(b);
        return "#"+r1+g1+b1;
    }

    string findstr(int val) {
        std::stringstream sstream;
        sstream << std::hex << std::setfill('0') << std::setw(2) <<find(val);
        return sstream.str();
    }

    int find(int val) {
        int f1 = val >>4;
        int f2 = val & 0xf;
        if (f1==f2) {
            return val;
        } else if (f1 > f2){
            int c1 = f1<<4 | f1;
            int c2 = (f1-1) << 4 | (f1-1);
            return (abs(c1-val) > abs(c2-val))?c2:c1;
        } else {
            int c1 = f1<<4 | f1;
            int c2 = (f1+1) << 4 | (f1+1);
            return (abs(c1-val) > abs(c2-val))?c2:c1;
        }
    }
};


DEFINE_CODE_TEST(c_800_similarrgb)
{
    Solution obj;
    VERIFY_CASE(obj.similarRGB("#09f166"),"#11ee66");
    VERIFY_CASE(obj.similarRGB("#11f166"),"#11ee66");
    VERIFY_CASE(obj.similarRGB("#12f1f1"),"#11eeee");
    VERIFY_CASE(obj.similarRGB("#1c9e03"),"#229900");

}

