#include <vector>
#include <string>
#include <iostream>
using namespace std;
/*
一个dfs的变种，还是要注意dir, x,y的边界条件，并不难
下面这个实现TLE，能调整的地方,使用trie，在每一个cell的时候直接明确是否命中
*/
class Solution0 {
public:
    int m=0;
    int n=0;    
    int dir[5]={-1,0,1,0,-1};
    // TLE???
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.empty() || words.empty()) {
            return ans;
        }
        m=board.size();
        n=board[0].size();
        for (auto &w:words) {
            vector<vector<bool>> visited(12,vector<bool>(12,false));
            //cout << "search " << w << endl;
            auto loop=[&]() {
                for (int i=0;i<m;i++) {
                    for (int j=0;j<n;j++) {
                        if (helper(i,j,0,w,board,visited)) {
                            return true;
                        }
                    }
                }
                return false;
            };

            if (loop()) {
                ans.push_back(w);    
            }        
        }
        return ans;
    }

    bool helper(int i, int j, int pos, string &word, vector<vector<char>>& board, vector<vector<bool>> &visited) {
        if (pos==word.length()) return true;        
        if (i>=0 && i<m && j>=0 && j<n && !visited[i][j] && board[i][j]==word[pos]) {
            //cout << "found "<< i <<","<<j<<"="<< board[i][j] << endl;
            visited[i][j] = true;
            for (int d=0;d<4;d++) {
                int nr=i+dir[d];
                int nc=j+dir[d+1];
                if (helper(nr,nc,pos+1,word,board,visited)) {
                    return true;
                }
            }
            visited[i][j] = false;
        }
        return false;
    }
};



class Solution {
public:
    class Node {
    public:
        bool isEnd;
        Node* charList[26];

        Node() {
            for (int i = 0; i < 26; ++ i) charList[i] = NULL;
            isEnd = false;
        }

    };

    int visisted[13][13];

    bool dfs(vector<vector<char>>& board, Node* trieRoot, int i, int j, vector<string>& res, string& s) {

        if (trieRoot->isEnd) {
            res.push_back(s);
            trieRoot->isEnd = false;
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || trieRoot->charList[board[i][j] - 'a'] == NULL || visisted[i][j]) return false;
        visisted[i][j] = 1;
        s.push_back(board[i][j]);
        if (
            dfs(board, trieRoot->charList[board[i][j] - 'a'], i + 1, j, res, s) ||
            dfs(board, trieRoot->charList[board[i][j] - 'a'], i - 1, j, res, s) ||
            dfs(board, trieRoot->charList[board[i][j] - 'a'], i, j - 1, res, s) ||
            dfs(board, trieRoot->charList[board[i][j] - 'a'], i, j + 1, res, s)) return true;
        s.pop_back();
        visisted[i][j] = 0;
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        vector<string> res;
        Node* trieRoot = new Node();
        for (const string& s : words) {
            Node* p = trieRoot;
            for (char c : s) {
                if (p->charList[c - 'a'] == NULL) p->charList[c - 'a'] = new Node();
                p = p->charList[c - 'a'];
            }
            p->isEnd = true;
        }
        for (int i = 0; i < board.size(); ++ i) {
            for (int j = 0; j < board[i].size(); ++ j) {
                string s = "";
                dfs(board, trieRoot, i, j, res, s);
            }
        }
        return res;

    }
};

int main() {
    Solution obj;
    vector<vector<char>> board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words={"oath","pea","eat","rain"};
    auto ans=obj.findWords(board, words);
    for (auto &s:ans){
        cout<<s<<endl;
    }
    return 0;
}