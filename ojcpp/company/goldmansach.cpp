//
// Created by rui zhou on 2019-11-27.
//

#include <codech/codech_def.h>
using namespace std;

// 找出第一个不重复的字符串
namespace {
    char findFirst(const string input)
    {
        // TODO: implement the solution here
        unordered_map<char,int> m;
        for (auto &it:input) {
            m[it]+=1;
        }

        for (auto &it:input) {
            if (m[it] == 1) {
                return it;
            }
        }
        return 0;
    }

/**
 * bool doTestsPass()
 * Returns true if all tests pass. Otherwise returns false.
 */
    bool doTestsPass()
    {
        // todo: implement more tests, please
        // feel free to make testing more elegant
        bool result = true;
        result &= findFirst("apple") == 'a';
        result &= findFirst("racecars") == 'e';
        result &= findFirst("ababdc") == 'd';
        //additional test
        result &= findFirst("") == 0;
        result &= findFirst("aaa") == 0;
        return result;
    }

    // test2
    // 找出平均分最高的，返回


}

DEFINE_CODE_TEST(gs_test)
{
    VERIFY_CASE(doTestsPass(),true);
}
