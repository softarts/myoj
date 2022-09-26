//
// Created by rui zhou on 07/05/19.
//

#include <codech/codech_def.h>
#include <algorithm>
#include <type_traits>
using namespace std;
//LC 155 easy
namespace {
    template<typename T>
    class Stack {
    public:
        void push(const T& el) {
            if (m_stack.empty()) {
                m_min = el;
            } else {
                m_min = m_stack.top();
            }
            m_stack.push(el);
            m_stack.push(std::min(m_min, el));
        }

        void pop(T & el) {
            if (!m_stack.empty()) {
                m_min = m_stack.top();m_stack.pop();
                el = m_stack.top();m_stack.pop();
                if (el>m_min) {
                    T min2 = m_stack.top();m_stack.pop();
                    m_stack.push(std::min(m_min,min2));
                }
            }
        }

        T min() {
            if (!m_stack.empty()) {
                m_min = m_stack.top();
                return m_min;
            }
            return T();
        }
    private:
        stack<T> m_stack;
        T m_min;
    };
}


DEFINE_CODE_TEST(021_minstack)
{
    {
        Stack<int> st;
        st.push(6);st.push(5),st.push(4);
        VERIFY_CASE(st.min(),4);VERIFY_CASE(st.min(),4);VERIFY_CASE(st.min(),4);
        int x;
        st.pop(x);VERIFY_CASE(st.min(),5);
        st.pop(x);VERIFY_CASE(st.min(),6);
        st.push(7);st.push(8);st.push(9);  //6,7,8,9
        st.pop(x);VERIFY_CASE(st.min(),6);
        st.pop(x);VERIFY_CASE(st.min(),6);
        st.pop(x);VERIFY_CASE(st.min(),6);
    }
}