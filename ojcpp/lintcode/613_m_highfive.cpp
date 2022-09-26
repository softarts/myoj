//
// Created by rui.zhou on 2/27/2019.
//

/* amazon locked
 * [LintCode] 613 High Five 解题报告
Description
There are two properties in the node student id and scores, to ensure that each student will have
at least 5 points, find the average of 5 highest scores for each person.

Example
Given results = [[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],[1,61]]

Return

 */


class Record {
public:
    int id, score;
    Record(int id, int score) {
        this->id = id;
        this->score = score;
    }
};

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record> &results) {
        unordered_map<int, priority_queue<int>> scores;
        for (auto &iter:results) {
            auto &pq = scores[iter.id];
            pq.push(iter.score);
            if (pq.size()>5) {
                pq.pop();
            }
        }

        map<int,double> map;
        for (auto &iter:scores) {
            auto &pq = iter.second;
            int sum = 0;
            while (!pq.empty()) {
                sum+=pq.top();
                pq.pop();
            }
            map[iter.first]=sum/5.0;
        }
        return map;
    }
};
// Write your code here
DEFINE_CODE_TEST(lint_613_highfive)
{
    Solution obj;
    {
        vector<Record> nums{{1,91},{1,92},{2,93},{2,99},{2,98},{2,97},{1,60},{1,58},{2,100},{1,61}};
        auto map=obj.highFive(nums);
        for (auto &iter:map) {
            cout << iter.first << " " << iter.second <<endl;
        }
    }
}