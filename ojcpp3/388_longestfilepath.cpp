#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext". Note that the '\n' and '\t' are the new-line and tab characters.

Input: input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
Output: 20
Explanation: We have only one file, and the absolute path is "dir/subdir2/file.ext" of length 20.

codesignal dfs_longestpath
*/
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<vector<string>> layer;
        string s=input+'\n';
        string cur;
        int level=0;
        int ans=0;
    
        for (int i=0;i<s.length();i++) {
            
            switch (s[i]) {
                // cout << s[i] << "/f" << endl;    
                
                case '\n': {
                    // cout << "push " << cur << " to layer " << level << endl;
                    if (layer.size()<=level) {layer.push_back(vector<string>());}
                    layer[level].push_back(cur);
                    
                    // 是否当前为文件
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
};
