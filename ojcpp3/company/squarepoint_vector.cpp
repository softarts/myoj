/*
awscommunitybuilders@amazon.coms
实现vector,member_variable 的命名方式,copy assignment,ctor, exception 等
*/
#include <iostream>
using namespace std;

template<typename T>
class MyVector {
  private:
    T * arr=nullptr;
    int cap = 1;
    int current = 0;
  public:
    // ctor
    MyVector() {
      arr = new T[cap];
    }
    // dtor
    ~MyVector() {
      cout << "dtor arr=" << arr << endl;
      delete [] arr;
    }

    // 绑定临时变量
    void push_back(const T &obj) {
      if (current == cap) {
        T* temp = new T[2 * cap];
        for (int i = 0; i < cap; i++) {
            temp[i] = arr[i];
        }
        delete [] arr;
        cap *= 2;
        arr =temp;
      }
      arr[current++] = obj;
    }

    T& operator[](int index) {
      if (index < cap) {
        return arr[index];
      } else {
        throw std::out_of_range("out of range");
      }
    }

    int size() const {
      return current;
    }

    void print() {
      cout << "print size=" << size() << ",cap="<<cap << endl;
      for (int i = 0; i < size(); i++) {
        cout << arr[i] <<" ";
      }
      cout << endl;
    }
    // additional ==================================
    // copy ctor
    MyVector(const MyVector &v) {
      cout << "ctor size=" << v.size() << endl;
      arr = new T[v.size()];
      MyVector &m=const_cast<MyVector&>(v);

      for (int i=0;i<m.size();i++) {
        cout << i<<"=" << m[i] << endl;
        arr[i]=m[i];
      }
      current = v.size();
      cap = current;
    }

    // copy assignment
    // 应该改写为 pass y value MyVector &operator=(MyVector obj) {
    MyVector &operator=(const MyVector &obj) {
      obj.print();
      cout << "tmp" << endl;
      MyVector tmp(obj);
      cout << "swap" << endl;
      std::swap(this->arr, tmp.arr);
      std::swap(this->current, tmp.current);
      std::swap(this->cap, tmp.cap);
      this->print();
      return *this;
    }
};


int main() {
  cout << "push"<<endl;
  MyVector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);
  v.push_back(50);
  v[4]=60;
  v.print();
  // for (int i=0;i<v.size();i++) {
  //   cout<<v[i]<<" ";
  // }

  cout << "ctor"<<endl;
  MyVector<int> v1(v);
  v1.print();

  cout << "assignment"<<endl;
  MyVector<int> v2 = v1;
  v2.print();
  // cout<<v[10]<<" ";  //out_of_range

  return 0;
}