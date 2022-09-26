//https://www.justsoftwaresolutions.co.uk/threading/implementing-a-thread-safe-queue-using-condition-variables.html

#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

template<typename T>
class SafeQueue {
private:
    std::mutex mu;
    std::condition_variable cv;
    deque<T> deq_;
public:
    void wait_and_pop(T &value) {
        std::lock_guard lk(m);
        cv.wait(lk,[this](){return !deq_.empty();});
        value = deq_.front();
        deq_.pop();
    }

    void push(const T &obj) {
        std::lock_guard lk(m);
        deq_.push_back(obj);
    }

    T& front() {
        std::lock_guard lk(m);
        return deq_.front();
    }

    void pop()
    {
        std::lock_guard lk(m);
        deq_.pop();
    }
};