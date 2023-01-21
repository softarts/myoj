#include <vector>
#include <string>
using namespace std;

/*
For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', 
your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.
从words中构造trienode，如果匹配继续检查下一个node，否则reset

[[["ab","ba","aaab","abab","baa"]],["a"],["a"],["a"],["a"],["a"],["b"],["a"],["b"],["a"],["b"],["b"],["b"],["a"],["b"],["a"],["b"],["b"],["b"],["b"],["a"],["b"],["a"],["b"],["a"],["a"],["a"],["b"],["a"],["a"],["a"]]

难点， 正向搜索有问题,例如有 aaac, aab, 输入:aaab,不匹配，但是aab可能匹配,如何在aaab不匹配的时候去尝试aab?
按照题意，需要做逆向搜索，保存一个buf，查找是否有匹配的suffix

a,a,a,a,a,b => ab || aaab
a,a,a,a =>此时无匹配，应该a=>root
*/

struct TrieNode {
    const char basec_ = 'a';
    TrieNode* childs[26] = {nullptr};
    bool leaf;
    TrieNode(bool isLeaf=false) {
        leaf=isLeaf;
    }

    TrieNode * add(char c, bool last=false) {
        auto i = c-basec_;
        if (!childs[i]) {
            childs[i]=new TrieNode(last);
        } else {
            if (last) childs[i]->leaf = last;
        } 
        return childs[i];
    }

    void insert(string word) {
        TrieNode*pnode=this;
        for (int i=0;i<word.length();i++) {
            pnode = pnode->add(word[i],(i==word.length()-1)?true:false);
        }
    }

    bool search(string word) {
        TrieNode*pnode=this;
        for (int i=0;i<word.length();i++) {
            int ch=word[i]-basec_;
            if (pnode) {
                pnode=pnode->childs[ch];
                if (pnode && pnode->leaf) return true;
                // cout << "find " << word[i] << " ";
            }   
            else {
                return false;
            }
                
        }
        return (pnode && pnode->leaf);
    }

    TrieNode* get(char c) {
        auto i = c-basec_;
        return (childs[i]);
    }
};

class StreamChecker {
public:
    TrieNode root;
    TrieNode* pNode_;
    string buffer_ = "";
    int maxLen_=INT_MIN;
    StreamChecker(vector<string>& words) {
        for (auto s:words) {
            TrieNode *pnode = &root;
            reverse(s.begin(),s.end());
            
            maxLen_ = max(maxLen_,int(s.length()));
            // cout << "add " << s << "," << maxLen_ << endl;
            pnode->insert(s);
        }
        pNode_ = &root;
    }

    bool query(char letter) {
        buffer_=letter+buffer_;
        if (maxLen_ < buffer_.length()) {
            buffer_ = buffer_.substr(0, maxLen_);
        }
        
        return pNode_->search(buffer_);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */