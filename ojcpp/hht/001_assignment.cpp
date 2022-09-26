//
// Created by rui zhou on 30/01/19.
//
/*
 * https://github.com/zhedahht/CodingInterviewChinese2
 */
#include <codech/codech_def.h>

//mystring impl
//添加赋值运算符
//001 实现operator==()，需要考虑异常安全性,使用一个临时变量来swap ,临时变量可以随后释放空间
//
//参考实现一个字符串,
//一个空字符串至少长度为1,内容为\0,否则很多函数上实现不方便。具体参看CCI
//Std中如果传入一个nullptr作为字符串，会抛出异常。
//

#include <cstring>
#include <codech/codech_def.h>
#include <cassert>

using namespace std;

namespace HHT
{
    class CMyString
    {
    public:
//        CMyString():m_pData(new char[1]) {
//            m_pData[0]='\0';
//        }
        CMyString(char*pData=NULL):m_pData(nullptr){
            if (pData) {
                m_pData = new char[strlen(pData)+1];
                strcpy(m_pData, pData);
            } else { // std string not allow nullptr either
                throw string("nullptr string");// TODO new or value?
            }
        }

        CMyString(const CMyString &str) {
            int length = strlen(str.m_pData);
            m_pData = new char[length + 1];
            strcpy(m_pData, str.m_pData);
        }

        ~CMyString(){
            if (m_pData)
                delete m_pData;
        }

        void swap(CMyString &rhs)
        {
            std::swap(m_pData, rhs.m_pData);
        }

        const char* c_str() const
        {
            return m_pData;
        }
    private:
        char *m_pData;

    public:
        // not good impl /////////////////////////
//        CMyString& operator=(const CMyString&rhs)
//        {
//            if (this==&rhs)
//                return *this;
//            delete []m_pData;
//            m_pData = nullptr;
//            // if we get exception at the below line, the this status will be abnormal.
//            m_pData = new char[strlen(rhs.m_pData)+1];
//            strcpy(m_pData, rhs.m_pData);
//        }
        // better solution
        CMyString&operator=(const CMyString&rhs) {
            if (this!=&rhs) {
                CMyString tmp(rhs);
               this->swap(tmp);
            }

            return *this;
        }
    };
}

DEFINE_CODE_TEST(hht_string_impl)
{
    {
        HHT::CMyString str1((char*)"abc"),str2((char*)"def");
        str2=str1;
        VERIFY_CASE(strcmp(str2.c_str(),"abc"),0);
    }


}