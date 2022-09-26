#include <iostream>
#include <atomic>

using namespace std;

template<typename T>
class SharedPtr {
private:
    T* ptr_;
    atomic_int* count_;

public:
    explicit SharedPtr(T*ptr) {
        ptr_ = ptr;
        count_ = (atomic_int*)malloc(sizeof(atomic_int));
        *count_ = 1;
        cout << "ctor count:" << count_->load()<<endl;
    }

    // SharedPtr(SharedPtr<T> &sptr){
    //     ptr_ = sptr.ptr_;
    //     ref_count = sptr.ref_count;
    //     ++*ref_count;
    // }
};

class A{
    int x=5;
};

int main() {
    SharedPtr<A> sptr(new A());
    return 0;
}