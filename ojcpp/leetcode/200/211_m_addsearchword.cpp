//
// Created by rui zhou on 2019-09-13.
//

/*
 * Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
由于c++不像python那样弱类型，所以还是定义一个trieNode的结构为好

 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    struct TrieNode {
        TrieNode* childs[26] = {nullptr};
        bool leaf = false;
        TrieNode() {

        }
    };

    class WordDictionary {
    public:
        TrieNode root_;
        /** Initialize your data structure here. */
        WordDictionary() {

        }

        /** Adds a word into the data structure. */
        void addWord(string word) {
            TrieNode *currNode = &root_;
            for (auto ch : word) {
                int chi = ch-'a';
                if (currNode->childs[chi]==nullptr) {
                    currNode->childs[chi] = new TrieNode();
                }
                currNode = currNode->childs[chi];
            }
            currNode->leaf = true;
        }

        bool helper(int start, string &word, TrieNode *currNode) {
            if (start == word.length())
                return (currNode && currNode->leaf);

            char ch = word[start];
            if (ch == '.') {
                for (auto &&child : currNode->childs) {
                    if (child && helper(start+1, word, child))
                        return true;
                }
                return false;
            } else {
                int idx = ch - 'a';
                if (currNode->childs[idx]!=nullptr) {
                    return helper(start+1,word, currNode->childs[idx]);
                } else {
                    return false;
                }
            }

        }

        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
            TrieNode *currNode = &root_;
            return helper(0, word, &root_);

        }
    };

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
}


DEFINE_CODE_TEST(211_worddict)
{
    {
        WordDictionary obj;
        obj.addWord("bad");
        obj.addWord("dad");
        obj.addWord("mad");
        VERIFY_CASE(obj.search("pad"),false);
        VERIFY_CASE(obj.search("bad"),true);
        VERIFY_CASE(obj.search(".ad"),true);
        VERIFY_CASE(obj.search("b.."),true);
    }

    {
        //WordDictionary obj;
        //VERIFY_CASE(obj.search("pad"),false);
        //VERIFY_CASE(obj.search("bad"),true);
    }


}