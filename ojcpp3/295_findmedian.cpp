#include <iostream>
#include <set>
using namespace std;
/*
能够找到数据流的median
原本的做法是使用2个priority_queue(最大，最小堆)
有没有更好的做法?
使用map ==> 这说明 mid 跟的是元素本身,插入后并没有失效

*/
class MedianFinder {
public:
        MedianFinder() {
        mid = m.begin();
    }
    
    void addNum(int num) {
        m.insert(num);       // 先插入再调整
        if (mid==m.end()) {
            mid=m.begin();
        } else {
            if (*mid>num) {
                left++;
                if (left-right>=1) {
                    mid--;  // 在mid前面多一个元素
                    left--;right++;
                }                
            } else {
                right++;
                if (right-left>=2) {
                    mid++;  // 在mid前面多一个元素
                    left++;right--;
                }
            }
        }
    }
    
    double findMedian() {
        if (m.size()%2==0) {
            return (*mid+*next(mid,1))/2.0;
        } else {
            return *mid;
        }
    }
private:
    multiset<int> m;
    multiset<int>::iterator mid;
    int left=0,right=0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */