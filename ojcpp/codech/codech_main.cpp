#include <iostream>
#include <iomanip>  // hex,dec
#include "codech_def.h"

//#include <boost/lexical_cast.hpp>
//#include <boost/filesystem.hpp>

using namespace std;

namespace CODECH
{
    CodeTimer::CodeTimer()
    {
       c_start = std::clock();
    }

    CodeTimer::~CodeTimer()
    {

    }

    static int getTestType(string testName)
    {
        size_t pos = testName.find_last_of(".");
        if (pos != std::string::npos)
        {
            //pos1;
            if (testName.substr(pos) == ".cpp")
                return 0;
            else if(testName.substr(pos) == ".py")
                return 1;
        }
        return 0;
    }



    static void runPython(string testName)
    {
        string cmd = "python " + testName;
        system(cmd.c_str());
    }

    CodeChMgr::CodeChMgr()
    : curIdx_(0)
    {}


	//void CodeChMgr::runCase(std::string desc, boost::any actual, boost::any exp)
	//{
	//	/*std::cout << desc << ":" << (ret ? "PASSED" : "FAILED") << std::endl;
	//	*/
	//	string strRet;
	//	string strExp;
	//	bool flag = false;
	//	if (actual.type() == typeid(string)) {
	//		strRet = boost::lexical_cast<string>(boost::any_cast<string>(actual));
	//		strExp = boost::lexical_cast<string>(boost::any_cast<string>(exp));			
	//	}	
	//	else if (actual.type() == typeid(int)) {
	//		strRet = boost::lexical_cast<string>(boost::any_cast<int>(actual));
	//		strExp = boost::lexical_cast<string>(boost::any_cast<int>(exp));
	//	}
	//	flag = (strRet == strExp);

	//	cout << desc << ":" << (flag?"PASSED":"FAILED") << endl;
	//	if (!flag)
	//	{
	//		cout << "EXP:" << strExp << ",ACTUAL:" << strRet << endl;
	//	}
	//}



    void CodeChMgr::registerTest(std::string fileName, std::string testName, TYPE_CODETEST_FUNC func)
    {   
		TestObj t;
		t.cppFileName_ = fileName;
        t.testName_ = testName;
		t.cppFunc_ = func;
		allTests_.push_back(t);

        // allTests_[testName] = func;
        // allTestIds_[curIdx_++] = testName;
        //__registerPythonTest(fileName);
    }

   // void CodeChMgr::__registerPythonTest(std::string fileName)
   // {
   //     // replace ".cpp" with ".py"		
   //     size_t pos = fileName.find_last_of(".");
   //     if (pos!=std::string::npos)
   //     {
   //         //pos1;
			//fileName.replace(pos, 4, ".py");
   //         if (boost::filesystem::exists(fileName))
   //         {
   //             // add to python test suite.
			//	TestObj t;
			//	t.pythonFileName_ = fileName;
			//	allTests_.push_back(t);
   //             // allTests_[testName] = nullptr;
   //             // allTestIds_[curIdx_++] = testName;
   //         }            
   //     }
   // }

    void CodeChMgr::listTest()
    {        
		int idx = 0;
		cout.fill('.');
		for (auto &iter : allTests_)
		{
			if (iter.cppFileName_!="")
				//std::cout << setw(5) << left << idx++ << "\t" << iter.testName_  << "\t" << iter.cppFileName_ << std::endl;
                std::cout << setw(5) << left << idx++ << "\t" << std::setw(35) << iter.testName_ << "\t" << iter.cppFileName_ << std::endl;
			else if (iter.pythonFileName_ != "")
				std::cout << setw(5) << left << idx++ << "\t" << std::setw(20) << "python" << "\t"  << iter.pythonFileName_ << std::endl;
		}		
    }

    void CodeChMgr::runTest()
    {
        int testId;
        cout << "\nInput test ID:" << std::endl;
        cin >> testId;  
		__runTest(testId);

    }

	void CodeChMgr::__runTest(int nId)
	{
		if (nId >= allTests_.size())
		{
			std::cout << "Test not found - " << nId << std::endl;
			return;
		}

		TestObj &t = allTests_[nId];
		string name = (t.cppFileName_ != "" ? t.cppFileName_ : t.pythonFileName_);
		std::cout << "Running test:" << name << std::endl;

		int type = getTestType(name);
		if (type == 0)
			t.cppFunc_();
		else if (type == 1)
		{
			runPython(name);
		}
	}
}

int main(int argc, char**argv)
{
    CODECH::CodeChMgr &pac = CODECH::CodeChMgr::getInstance();
    if (argc>1)
    {
        int tid = strtol(argv[1], NULL, 10);
        pac.__runTest(tid);
    }
    else
    {
        pac.listTest();
        pac.runTest();
        //system("pause");
    }
    
    
}