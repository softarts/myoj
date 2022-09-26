#include <codech/codech_def.h>
using namespace std;

/*
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
1.空格相等
2.左边的空格比右边多
3.每行总长度=maxwidth

这个主要是步骤比较复杂, 在想什么是最好的办法

*/
namespace {
    class Solution {
    public:        
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> ans;
            vector<string> line;
            int lineLen = 0;
            string str = "";
            for (int j=0;j<words.size();j++) {
                auto word = words[j];
                if (str.length()+word.length() < maxWidth) {
                    line.emplace_back(word);
                    lineLen+=word.length();
                    str+=word;
                    str+=" ";
                } else if (str.length()+word.length() == maxWidth) {
                    str+=word;
                    ans.emplace_back(str);
                    line.clear();
                    lineLen = 0;
                    str="";
                } else { // 超出长度，需要重新调整空格    
                    //这个调整比较麻烦,需要考虑两种条件                
                    str="";
                    int spaces = maxWidth - lineLen;
                    int n = line.size()-1;
                    if (n>0) {
                        int x = spaces/n;
                        int y = spaces%n;
                        for (int i=0;i<line.size();i++) {
                            str+=line[i];
                            if (i!=n) {
                                str+=string(x+(i<y?1:0),' ');
                            }
                        }
                    } else {
                        str+=line[0];
                        str+=string(spaces,' ');
                    }
                    
                    ans.emplace_back(str);
                    str="";
                    line.clear();
                    lineLen=0;
                    j--;
                }
            }
            if(!str.empty()) {
                if(str.size() < maxWidth)
                    str += string(maxWidth - str.size(), ' ');
                ans.push_back(str);
            }

            return ans;
        }

    };
}