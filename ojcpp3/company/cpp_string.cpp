#include <iostream>
#include <vector>
using namespace std;

class MyString {
    private:
        char *data_ = nullptr;
    public:
        // 基本的ctor, dtor, assignment, copy ctor

        MyString():data_(new char[1]) {
            *data_='\0';
        }
        ~MyString() {
            cout << "dtor" << endl;
            delete [] data_;
        }

        MyString(const char* str)
        : data_(new char[strlen(str)+1]) {
            strcpy(data_, str);
        }

        MyString(const MyString &rhs)
        : data_(new char[rhs.size()+1]) {
            strcpy(data_, rhs.c_str());
        }

        // assignment
        MyString& operator=(MyString rhs) {
            swap(rhs); // rhs is temp object, will be deleted in dtor
            return *this;
        }


        size_t size() const {
            return strlen(data_);
        }

        const char * c_str() const {
            return data_;
        }

        void swap(MyString &rhs) {
            std::swap(data_, rhs.data_);
        }

        // move ctor

        // C++11 move ctor
        MyString(MyString&& rhs)
        :data_(rhs.data_)  {
            cout << "move ctor" <<endl;
            rhs.data_ = nullptr;
        }
};


int main() {
    MyString s;
    MyString s0("abc");
    
    MyString s1="efg";
    MyString s2=s1;
    MyString s3(s1);
    s2=s0;
    
    vector<MyString> v;
    v.push_back("e1");
    v.push_back("e2");
    
    cout << s.c_str() << endl;
    cout << s0.c_str() << endl;
    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << s3.c_str() << endl;

    cout << "----------------------------------" << endl;
    for (auto &it:v) {
        cout << it.c_str() << endl;
    }

*/
    return 0;


}