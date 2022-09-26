#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

/*
参考了C++ STL 2.0 书 19章
*/

template <typename T>
class MyAlloc {
  public:
    typedef T value_type;
    // MyAlloc() noexcept = default;
    // template <class U>
    // MyAlloc (const MyAlloc<U>&) noexcept {};

    T * allocate(std::size_t num) {
      cout << "allocate " << num <<endl;
      return static_cast<T*>(::operator new(num*sizeof(T)));
    }

    void deallocate(T* p, std::size_t num) {
      cout << "deallocate " << num <<endl;
      ::operator delete(p);
    }
};


// return that all specializations of this allocator are interchangeable
template <class T1, class T2>
bool operator== (const MyAlloc<T1>&,
                const MyAlloc<T2>&) throw() {
    return true;
}
template <class T1, class T2>
bool operator!= (const MyAlloc<T1>&,
                const MyAlloc<T2>&) throw() {
    return false;
}

// =========================================================
#include <stdio.h>
#include <sys/mman.h>

template <typename T>
  class MmapAlloc {
    private:      
    public:
      typedef T value_type;
      T * allocate(std::size_t num) {
        cout << "allocate " << num <<endl;
        T *ptr = (T*)mmap(NULL, num * sizeof(T), PROT_READ|PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS, 0,0);
        if (ptr == MAP_FAILED) {
          throw bad_alloc();
        }
        return ptr;
      }

      void deallocate(T* p, std::size_t num) {
        cout << "deallocate " << num <<endl;
        if (0!=munmap(p, num*sizeof(T))) {
          throw std::runtime_error("dealloc");
        }
      }
  };


  // return that all specializations of this allocator are interchangeable
  // template <class T1, class T2>
  // bool operator== (const MmapAlloc<T1>&,
  //                 const MmapAlloc<T2>&) throw() {
  //     return true;
  // }
  // template <class T1, class T2>
  // bool operator!= (const MmapAlloc<T1>&,
  //                 const MmapAlloc<T2>&) throw() {
  //     return false;
  // }

void test1() {
  vector<int, MyAlloc<int>> v;
  for (int i=0;i<10;i++) {
    v.push_back(10);
  }
  
  cout << v[0] << endl;
}

void test2() {
  vector<int, MmapAlloc<int>> v;
  for (int i=0;i<10;i++) {
    v.push_back(10);
  }
  
  cout << v[0] << endl;
}

int main() {
  test2();
  return 0;
}
