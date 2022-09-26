#include <codech/codech_def.h>
using namespace std;

// 代码有点长，但是也没什么致命缺点，就是退出时还要处理一次不太理想
namespace {
    class Solution {
    public:
        int compress(vector<char>& chars) {
            if (chars.empty()) return 0;
            
            int w=1;
            int r = 1;
            int len = chars.size();
            int count = 1;
            while (r<len) {
                if (chars[r]==chars[r-1]) {
                    count++;
                } else {
                    if (count>1) {
                        addCount(chars,w,count);
                        //chars[w++] = '0'+count;        
                    }
                    chars[w++] = chars[r];
                    count=1;
                }
                r++;
            }       
            if (count>1) {
                // chars[w++] = '0'+count;      
                addCount(chars,w,count);
            }
            return w;
        }
        
        void addCount(vector<char>& chars, int &w, int count) {
            if (count <10) {
                chars[w++] = '0' + count;        
            } else {
                string sc = to_string(count);
                for (int i=0;i<sc.length();i++) {
                    chars[w++] = sc[i];
                }
            }
        }
    };

}