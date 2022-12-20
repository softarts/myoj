#include <string>
#include <vector>
#include <numeric>
#include <iterator>
#include <iostream>
using namespace std;
/*
找出最长的文件系统路径
这题并不难，就是烦
*/

int solution(string fileSystem) {
    vector<vector<string>> layer;
    string s=fileSystem+'\f';
    string cur;
    int level=0;
    int ans=0;
  
    for (int i=0;i<s.length();i++) {
        
        switch (s[i]) {
            cout << s[i] << "/f" << endl;    
            
            case '\f': {
                // cout << "push " << cur << " to layer " << level << endl;
                if (layer.size()<=level) {layer.push_back(vector<string>());}
                layer[level].push_back(cur);
                
                auto pos = cur.find('.');
                if (pos!=string::npos && cur.substr(pos).length()>1) {
                    int curLen = 0;
                    for (int i=0;i<=level;i++) {
                        curLen+=layer[i].back().length();
                        // cout << "cur len " << curLen << endl;
                    }
                    ans=max(ans,curLen+level);
                    // cout << "max len= " << ans << endl;    
                }
                
                level=0;
                cur="";
                break;
            }
            
            case '\t':
                level++;
            break;
        
            default:
                cur+=s[i];
                break;
        }
        
    }
    return ans;
}

int main() {
    int actual = solution("user\f\tpictures\f\tdocuments\f\t\tnotes.txt");
    return 0;

}

