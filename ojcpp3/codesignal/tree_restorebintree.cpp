#include <vector>
#include "codesignal.h"
using namespace std;


pair<vector<int>,vector<int>> getNewInorder(int parent, vector<int> inorder) {
    auto parentPos = find(inorder.begin(), inorder.end(), parent);
    return pair(
        vector<int>(inorder.begin(),parentPos),
        vector<int>(parentPos+1,inorder.end())
    );
}


Tree<int>* createTree(vector<int> inorder, vector<int> preorder) {
    if (preorder.empty()) return nullptr;
    auto parent=preorder[0];
    
    auto [leftInorder,rightInorder]= getNewInorder(parent, inorder);
    vector<int> leftPreorder;
    vector<int> rightPreorder;
    if (!leftInorder.empty()) {
        int left = leftInorder[0];
        auto leftPos = find(preorder.begin()+1, inorder.end(), left);
        copy(preorder.begin()+1, leftPos+1, back_inserter(leftPreorder)); 
        copy(leftPos+1, preorder.end(), back_inserter(rightPreorder));
    } else {
        copy(preorder.begin()+1, preorder.end(), back_inserter(rightPreorder));
    }

    Tree<int> *node = new Tree<int>(parent);
    node->left=createTree(leftInorder,leftPreorder);
    node->left=createTree(rightInorder, rightPreorder);
    return node;
}

   

Tree<int> * solution(vector<int> inorder, vector<int> preorder) {
    return createTree(inorder, preorder);
}


{
    "value": 1,
    "left": {
        "value": 2,
        "left": {
            "value": 4,
            "left": null,
            "right": null
        },
        "right": null
    },
    "right": {
        "value": 3,
        "left": {
            "value": 5,
            "left": null,
            "right": null
        },
        "right": {
            "value": 6,
            "left": null,
            "right": null
        }
    }
}

{
    "value": -99999,
    "left": {
        "value": -100000,
        "left": null,
        "right": null
    },
    "right": {
        "value": -99998,
        "left": null,
        "right": null
    }
}


-100000 -99999 -99998  preorder >>> -99999 -100000 -99998 
-100000  preorder >>> -99998 
-99998  preorder >>> 5 6 33 0 2 22027 0 0 0 0 33 0 -99999 -100000 -99998 0 3 6 33 0 -100000 -99999 -99998 0 0 0 33 0 -99999 -100000 -99998 