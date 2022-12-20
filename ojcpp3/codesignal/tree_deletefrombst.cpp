//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
/*
这个要求有些特殊，和lc450有点不一样，他要求删除节点后把left中的最rightmost节点拿出来作为root，实际上
lc450并不要求他作为root,而是把他的child拼上另一个子树就可以了
codesignal的难度更大一点
*/
#include "codesignal.h"
#include <vector>
#include <iostream>

using namespace std;


// 指针
// 如果要原地修改tree, 那么需要
// TreeNode ** node;
// *node = newnode;  // dereference， 把该内存的值替换成新的node的地址，从而指针的指针指向newnode


// 传进来的是*&t, 修改的是原始数据
void deleteFromBST(Tree<int>* &t, int q) {
    // 需要使用**确保修改的都是原始地址数据
    Tree<int>** s = &t;
    while (*s && (*s)->value != q) {
        s = q < (*s)->value ? &(*s)->left : &(*s)->right;
    }
    if (*s) {
        Tree<int>*& b = *s;  // 这里可以用*&
        if (b->left) {
            Tree<int>** r = &b->left; // 不能使用*&，必须使用**??
            cout << "bleft addr=" << &b->left<<endl;
            cout << "r addr=" << r<<endl;

            while ((*r)->right) {
                r = &(*r)->right;
            }
            Tree<int>* l = (*r)->left;  //rightmost节点的左子树，需要挂上其prev
            if (r != &b->left) {
                cout << "bleft2 addr=" << &b->left<<endl;
                cout << "r2 addr=" << r<<endl;
                (*r)->left = b->left;  // 新的rightmost节点的左子树接上目前的top左子树
                // r发生了变化,r跑到了指向node的指针所在的地址
                // bleft addr=0x557160eb7158
                // r addr=0x557160eb7158
                // bleft addr=0x557160eb7158
                // r addr=0x557160eb7180
            }
                
            (*r)->right = b->right; // 挂接上右子树
            b = *r;  // b=新的rightmost的节点
            *r = l;  // 这里rightmost节点替换成 L34, 因为是**，所以可以直接替换,如果是*， 则只是指针的复制
        } else {
            b = b->right;
        }
    }
}

//bad

void deleteFromBST(Tree<int>* &t, int q) {
    Tree<int>** s = &t;
    while (*s && (*s)->value != q) {
        s = q < (*s)->value ? &(*s)->left : &(*s)->right;
    }
    if (*s) {
        Tree<int>*& b = *s;
        if (b->left) {
            Tree<int>* &r = b->left;
            //cout << "init b->left=" << b->left->value<<endl;
            cout << "bleft addr=" << &b->left<<endl;
            cout << "r addr=" << &r<<endl;
            
            while ((r)->right) {
                r = (r)->right;
            }
            cout << "rightmost="<< r->value << " b->left=" << b->left->value<<endl;
            Tree<int>* l = (r)->left;
            cout << "bleft2 addr=" << &b->left<<endl;
            cout << "r2 addr=" << &r<<endl;
                
            if (r != b->left) { // 这里进不来，因为r &=b->left
                (r)->left = b->left;                
            }
            // 其所用的地址都不变，只是内容变了
            // bleft addr=0x5604821d7158
            // r addr=0x5604821d7158
            // bleft2 addr=0x5604821d7158
            // r2 addr=0x5604821d7158
            (r)->right = b->right;
            cout << r->value << "->left " << b->left->value << endl;
            cout << r->value << "->right " << b->right->value << endl;
            b = r;
            r = l;
        } else {
            b = b->right;
        }
    }
}


// good
int deleteMax(Tree<int>*& cur){
    if(cur->right==NULL){
        int max=cur->value;
        cur=cur->left;  //直接修改原指针了,ok
        return max;
    }
    return deleteMax(cur->right);
}

void deleteBSTNode(Tree<int>*& cur, int q){
    if(!cur)
        return;
    if(q>cur->value){
        deleteBSTNode(cur->right,q);
    }
    else if(q<cur->value){
        deleteBSTNode(cur->left,q);
    }
    else if(!cur->left && !cur->right){
            cur=NULL;
    }
    else if(!cur->left){
            cur=cur->right;
    }
    else if(cur->left){
        cur->value=deleteMax(cur->left);    
    }
    
}

void deleteFromBST(Tree<int>* &t, int q) {
    Tree<int>* s = t;
    while (s && (s)->value != q) {
        s = q < (s)->value ? (s)->left : (s)->right;
    }
    if (s) {
        Tree<int>* b = s;
        if (b->left) {
            Tree<int>* r = b->left;
            while ((r)->right) {
                r = (r)->right;
            }
            Tree<int>* l = (r)->left;
            if (r != b->left)
                (r)->left = b->left;
            (r)->right = b->right;
            b = r;
            r = l;
        } else {
            b = b->right;
        }
    }
}


Tree<int>* solution(Tree<int>* t, const std::vector<int>& queries) {
    for (const auto& q : queries) {
        Tree<int>** s = &t;
        while (*s && (*s)->value != q) {
            s = q < (*s)->value ? &(*s)->left : &(*s)->right;
        }
        if (*s) {
            Tree<int>*& b = *s;
            if (b->left) {
                Tree<int>** r = &b->left;
                while ((*r)->right) {
                    r = &(*r)->right;
                }
                Tree<int>* l = (*r)->left;
                if (r != &b->left)
                    (*r)->left = b->left;
                (*r)->right = b->right;
                b = *r;
                *r = l;
            } else {
                b = b->right;
            }
        }
    }
    return t;
}

