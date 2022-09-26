#ifndef CODE_DEF_H_
#define CODE_DEF_H_

#include <string>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <queue>
#include <stack>
#include <iostream>
#include <iterator>
#include <climits>
#include <memory>
#include <type_traits>  // result _of?
//#include "codech_util.h"
#include "algo_common.h"
#include <algorithm>
#include <cstring>

#define DECL_CODE_TEST(x) \
        using namespace std; \
        static void CC_##x();


#define REG_CODE_TEST(x)  \
        DECL_CODE_TEST(x);\
        class Reg##x { \
        public:\
            Reg##x(){CODECH::CodeChMgr::getInstance().registerTest(__FILE__, string(#x), CC_##x);} \
        };\
        static Reg##x obj_##x##_obj;

#define DEFINE_CODE_TEST(x) \
        REG_CODE_TEST(x);\
        void CC_##x()          

//#define COUT \
//    CODECH::CodeChMgr::stream()

//#define RUN_CASE(x,exp) \
//	CODECH::CodeChMgr::runCase(#x, boost::any(x), boost::any(exp));

#define VERIFY_CASE(x,exp) \
	CODECH::CodeChMgr::runCase(#x, x, exp);

#define RUN_CASE_PRINT(x) \
    CODECH::CodeChMgr::runPrintCase(#x, x);

#define TIMER(x,loop) \
    { \
        auto t_start = std::chrono::high_resolution_clock::now();\
        for (int i=0;i<loop;i++) {\
        x;}\
        auto t_end = std::chrono::high_resolution_clock::now();\
        std::cout << std::fixed << std::setprecision(2) << "Wall clock time passed: " << std::chrono::duration<double, std::milli>(t_end - t_start).count() << " ms\n";\
    }

#define COMP_TIMER(x,y) \
    { \
        TIMER(x,1); \
        TIMER(y,1); \
    }


namespace CODECH
{   
    using TYPE_CODETEST_FUNC = std::function < void() >;

    class CodeTimer
    {
    public:
        CodeTimer();
        ~CodeTimer();
        std::clock_t c_start;
    };

	struct TestObj
	{
		TYPE_CODETEST_FUNC cppFunc_;
		std::string pythonFileName_;
		std::string cppFileName_;
        std::string testName_;
		TestObj() :cppFunc_(nullptr), pythonFileName_(""), cppFileName_(""), testName_("") {}
	};

    inline std::ostream & operator<<(std::ostream &s, std::nullptr_t) {
        return s << static_cast<void *>(nullptr);
    }

    class CodeChMgr
    {
    public:
        static CodeChMgr& getInstance()
        {
            static CodeChMgr instance;
            return instance;
        }

        static std::ostream & stream() { return std::cout; }

		//static void runCase(std::string desc, boost::any actual, boost::any exp);

        template<typename F, typename E>
        static void runCase(std::string desc, F actual, E e){
            //std::result_of<F()>::type actual;// = f();

            bool ret = (actual == e);
            std::cout << desc << ":" << (ret?"PASSED":"FAILED") << std::endl;

            if (!ret) {
                std::cout << "EXP:" << e << ",ACTUAL:" << actual << std::endl;
            }
        };

        static void runPrintCase(std::string desc, std::string result)
        {
            std::cout << desc << ":" << result << std::endl;
        }

        CodeChMgr();
        
        void registerTest(std::string fileName, std::string testName, TYPE_CODETEST_FUNC func);
        void listTest();
        void runTest(); 
        void __runTest(int nId);
        
    protected:
        
        void __registerPythonTest(std::string testName);
    protected:
        // std::unordered_map<std::string, TYPE_CODETEST_FUNC> allTests_;
        // std::unordered_map<int, std::string> allTestIds_;
		std::vector<TestObj> allTests_;
        int curIdx_;
    };
}
#endif
