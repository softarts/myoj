#include <type_traits>
#include <iostream>
using namespace std;

template <typename T, typename = int>
struct HasX : std::false_type { };

template <typename T>
struct HasX <T, decltype((void) T::x, 0)> : std::true_type { };
struct A { int x; };
struct B { int y; };
// 是否有x,利用SFINAE
void hasx() {
    cout << "A has x:" << boolalpha << (HasX<A>::value == true) << endl;
    cout << "B has x:" << boolalpha << (HasX<B>::value == true) << endl;
}


// factorial in compile time
template <unsigned int n>
constexpr unsigned int factorial() {
    //cout << "in constexpr" << endl; // not a compile time
    if constexpr (n > 1)
        return n * factorial<n - 1>();
    else
        return 1;
}


void test_factorial() {
    constexpr int n=factorial<5>();
    cout << "factorial:" << n << endl;
}

int main() {
    //hasx();
    test_factorial();
    return 0;
}