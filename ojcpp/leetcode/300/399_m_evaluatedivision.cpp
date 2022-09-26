//
// Created by rui.zhou on 2019/9/19.
//

/*
 * Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].


The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

给出一系列的除法表达式，然后求表达式的值
转化为用graph来表示，例如 a/b; e/f, b/e ,值作为edge的值,双向
求值的时候对graph进行遍历，求出dividend和divisor之间的edge的值的乘积
 */

#include <codech/codech_def.h>

using namespace std;
using namespace CODECH;

namespace {


    class Solution {
    public:
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            using edge_t = unordered_map<string, double>;
            unordered_map<string, edge_t> m;

            for (int i=0;i<equations.size();i++) {
                vector<string> &pr = equations[i];
                string dividend = pr[0];
                string divisor = pr[1];
                double val = values[i];
                m[dividend][divisor] = val;
                m[divisor][dividend] = 1/val;
            }

            vector<double> ans;

            auto calc = [&](auto dividend,auto divisor) {
                unordered_set<string> visited;
                std::deque<pair<string,double>> todo{{dividend,1.0}};
                while (!todo.empty()) {
                    auto &pr = todo.front();
                    string &name = pr.first;
                    double val = pr.second;
                    todo.pop_front();
                    visited.emplace(name);

                    for (auto &&it:m[name]) {
                        if (it.first == divisor) {
                            return it.second*val;
                        }
                        if (!visited.count(it.first)) {
                            todo.emplace_back(it.first, it.second*val);
                        }
                    }
                }
                return -1.0;
            };


            for (auto &&it: queries) {
                string dividend = it[0];
                string divisor = it[1];

                if (m.count(dividend) ==0 || m.count(divisor)==0) {
                    ans.emplace_back(-1.0);
                } else {
                    ans.emplace_back(calc(dividend, divisor));
                }
            }
            return ans;
        }
    };
}


DEFINE_CODE_TEST(399_m_evaluatedivision)
{
    {
        Solution obj;
        vector<vector<string>> equations = {{"a","b"},{"e","f"},{"b","e"}};
        vector<double> values = {2.0, 0.5,0.5};
        vector<vector<string>> queries = {{"a","e"}};
        VERIFY_CASE(VERIFY_VEC(obj.calcEquation(equations, values, queries),{1.0}), true);

    }

    {
        Solution obj;
        vector<vector<string>> equations = {{"a","b"},{"b","c"}};
        vector<double> values = {2.0, 3.0};
        vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
        VERIFY_CASE(VERIFY_VEC(obj.calcEquation(equations, values, queries),{6.0,0.5,-1.0,1.0,-1.0}), true);

    }


}