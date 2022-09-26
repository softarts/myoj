#include <codech/codech_def.h>
using namespace std;

// 这个很简单啊
//lc642, grasshooper也考过
namespace {
    class MovingAverage {
    public:
        deque<int> deq;
        long sum=0; //overflow
        int cap;
        /*
        * @param size: An integer
        */MovingAverage(int size) {
            cap = size;
        }

        /*
        * @param val: An integer
        * @return:  
        */
        double next(int val) {
            if (deq.size()==cap) {
                int item = deq.front();
                deq.pop_front();
                sum=sum-item+val;
                deq.push_back(val);
                return double(sum)/double(deq.size());
            } else {
                deq.push_back(val);
                sum+=val;
                return double(sum)/double(deq.size());
            }
        }
    };
}