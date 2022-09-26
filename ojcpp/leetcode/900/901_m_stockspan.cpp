//
// Created by rui zhou on 2019-10-06.
//

/*
 * Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].



Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation:
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.


Note:

Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
There will be at most 10000 calls to StockSpanner.next per test case.
There will be at most 150000 calls to StockSpanner.next across all test cases.
The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.

 这道题和sliding window的题很像 lc239
 使用一个sliding window (deque/stack)来保存

 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    // 使用stack,但是速度并没有快很多
    class StockSpanner0 {
    public:    
        stack<pair<int,int>> st;
        int today = 0;
        StockSpanner0() {
            // queue.push_back(0);
            // arr.push_back(INT_MAX);
            st.push(make_pair(0,INT_MAX));
        }
        
        int next(int price) {
            today++;
            if (price >= st.top().second) {
                while (st.top().second <= price) {
                    st.pop();
                }
            }
            int span = today - st.top().first;
            st.push(make_pair(today,price));
            return span;
        }
    };
    class StockSpanner {
    public:
        vector<int>  arr;
        deque<int>  queue;
        
        StockSpanner() {
            queue.push_back(0);
            arr.push_back(INT_MAX);
        }
        
        int next(int price) {
            arr.push_back(price);
            int today = arr.size() - 1;
            
            if (price >= arr[queue.back()]) {
                while (arr[queue.back()] <= price) {
                    queue.pop_back();
                }
            }
            int span = today - queue.back();
            queue.push_back(today);
            return span;
        }
    };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
}

