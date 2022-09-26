//
// Created by rui.zhou on 2/22/2019.
//

#include "algo_common.h"

using namespace std;

namespace CODECH {
    // depreciated, create tree per layer
    /*TreeNode* CREATE_TREENODE(int idx, const std::vector<int> &list)
    {
        size_t len = list.size();
        if (idx <(int) len)
        {
            int val = list[idx];
            if (val != null)
            {
                TreeNode*node = new TreeNode(list[idx]);
                node->left = CREATE_TREENODE(idx * 2 + 1, list);
                node->right = CREATE_TREENODE(idx * 2 + 2, list);
                return node;
            }
            return nullptr;
        }
        else
        {
            return nullptr;
        }
    }*/
    //create tree from a list
    TreeNode* CREATE_TREENODE(const std::vector<int> &list)
    {
        TreeNode *root = new TreeNode(list[0]);
        std::deque<TreeNode*> toDo{root};

        int idx = 0;
        while (!toDo.empty()) {
            TreeNode *parent = toDo.front();
            toDo.pop_front();

            idx++;
            if (idx<list.size()) {
                int v1 = list[idx];
                if (v1 != null) {
                    parent->left = new TreeNode(v1);
                    toDo.push_back(parent->left);
                } else {
                    parent->left = nullptr;
                }
            } else {
                break;
            }

            idx++;
            if (idx<list.size()) {
                int v2 = list[idx];
                if (v2 != null) {
                    parent->right = new TreeNode(v2);
                    toDo.push_back(parent->right);
                } else {
                    parent->right = nullptr;
                }
            } else {
                break;
            }
        }
        return root;
    }


//    TreeNode* LCREATE_TREENODE(const std::vector<int> &list)
//    {
//        TreeNode *root = new TreeNode(list[0]);
//        std::deque<TreeNode*> toDo{root};
//
//        for (size_t i=0; i < list.size(); i++) {
//            TreeNode *parent = toDo.front();
//            toDo.pop_front();
//            int idx = i * 2 + 1;
//            if (idx<(int)list.size()) {
//                int v1 = list[idx];
//                if (v1 != null) {
//                    parent->left = new TreeNode(v1);
//                    toDo.push_back(parent->left);
//                } else {
//                    parent->left = nullptr;
//                }
//            }
//
//            idx++;
//            if (idx < (int)list.size()) {
//                int v2 = list[idx];
//                if (v2 != null) {
//                    parent->right = new TreeNode(v2);
//                    toDo.push_back(parent->right);
//                } else {
//                    parent->right = nullptr;
//                }
//            }
//        }
//        return root;
//    }
    TreeNode* LCREATE_TREENODE(const std::vector<int> &list)
    {
        TreeNode *root = new TreeNode(list[0]);
        std::deque<TreeNode*> toDo{root};

        //for (size_t i=0; i < list.size(); i++) {
        int idx = 0;
        while (!toDo.empty()) {
            TreeNode *parent = toDo.front();
            toDo.pop_front();
            idx++;
            int v1 = list[idx];
            if (v1 != null) {
                parent->left = new TreeNode(v1);
                toDo.push_back(parent->left);
            } else {
                parent->left = nullptr;
            }


            idx++;
            int v2 = list[idx];
            if (v2 != null) {
                parent->right = new TreeNode(v2);
                toDo.push_back(parent->right);
            } else {
                parent->right = nullptr;
            }

        }
        return root;
    }
    // node data first


    void DO_TREE_PREORDER(TreeNode*root,std::stringstream &ss)
    {
        if (root)
        {
            ss  << root->val << " ";
            DO_TREE_PREORDER(root->left,ss);
            DO_TREE_PREORDER(root->right,ss);
        } else {
            //std::cout << " null ";
        }
    }

    std::string TREE_PREORDER(TreeNode*root)
    {
        std::stringstream ss;
        DO_TREE_PREORDER(root,ss);
        return trim(ss.str());

    }


    std::string TREE_BYLEVEL(TreeNode*root) {
        std::deque<TreeNode*> toDo{root};
        std::stringstream ss;
        while (!toDo.empty()) {
            TreeNode *node = toDo.front();
            toDo.pop_front();
            if (node) {
                ss << node->val <<",";
                toDo.push_back(node->left);
                toDo.push_back(node->right);
            } else {
                ss << "null,";
            }
        }
        return ss.str();
    }
    TreeNode* FIND_NODE(TreeNode *root, int val) {
        std::deque<TreeNode*> toDo{root};
        while (!toDo.empty()) {
            TreeNode *node = toDo.front();
            toDo.pop_front();
            if (node) {
                if (node->val == val)
                    return node;
                toDo.push_back(node->left);
                toDo.push_back(node->right);
            }
        }
        return nullptr;
    }

    // ==================================
    // ListNode

    ListNode * CREATE_LIST(int size)
    {
        ListNode *head = nullptr;
        ListNode *cur = nullptr;
        for (int i =1;i <= size; i++)
        {
            ListNode *pNode = new ListNode(i);
            if (head==nullptr)
            {
                head = pNode;cur = head;
            }
            else
            {
                cur->next = pNode; cur = pNode;
            }
        }
        return head;

    }
    ListNode * CREATE_LIST(std::vector<int> &&vec)
    {
        ListNode *head = nullptr;
        ListNode *cur = nullptr;
        size_t size = vec.size();
        for (size_t i =1;i <= size; i++)
        {
            ListNode *pNode = new ListNode(vec[i-1]);
            if (head==nullptr)
            {
                head = pNode;cur = head;
            }
            else
            {
                cur->next = pNode; cur = pNode;
            }
        }
        return head;

    }

    ListNode* FIND_LISTNODE(ListNode* head,int val)
    {
        std::unordered_set<ListNode*> sets;
        while (head)
        {
            auto iter = sets.find(head);
            if (iter==sets.end())
            {
                sets.insert(head);
                if (head->val == val)
                    return head;
                head = head->next;
            }
            else
            {
                // prevent a circle linked list
                return nullptr;
            }
        }
        return nullptr;
    }

    std::string PRINT_LIST(ListNode *head)
    {
        std::unordered_set<ListNode*> sets;
        std::stringstream ss;
        while (head)
        {
            auto iter = sets.find(head);
            if (iter==sets.end())
            {
                sets.insert(head);
                ss << head->val;
                head = head->next;
                if (head)
                    ss << " ";
            }
            else
            {
                // prevent a circle linked list
                break;
            }
        }
        return ss.str();
    }

    // array ========================================
    std::string PRINT_VEC(std::vector<int> &&vec) {
        std::stringstream ss;
        for (size_t i=0; i< vec.size(); i++) {
            ss << vec[i];
            if (i != vec.size()-1)
                ss << " ";
        }
        return ss.str();
    }

    std::string PRINT_VVEC(std::vector<std::vector<int>> &&m) {
        std::stringstream ss;
        for (auto &row : m){
            for (auto &v : row) {
                ss << v << " ";
            }
            //TODOss << ",";
        }
        return trim(ss.str());
    }

    bool VERIFY_VVECINT(std::vector<std::vector<int>> &&m, std::vector<std::vector<int>> &n) {
        vector<int> a,b;
        for (auto &row : m){
            for (auto &v : row) {
                a.emplace_back(v);
            }
        }
        for (auto &row : n){
            for (auto &v : row) {
                b.emplace_back(v);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }

    std::string PRINT_STRVEC(std::vector<std::string>  &&m) {
        std::stringstream ss;
        for (auto &v : m) {
            ss << v << " ";
        }
        return ss.str();
    }

    // matrix =============================================
    std::string PRINT_MATRIX(std::vector<std::vector<int>> &m) {
        std::stringstream ss;
        for (auto &row : m){
            for (auto &v : row) {
                ss << v << " ";
            }
        }
        return trim(ss.str());
    }

    // graph =================================================
    UndirectedGraphNode* CREATE_GRAPH(vector<vector<int>> &adjList) {
        // first one is the node val;
        UndirectedGraphNode*node = nullptr;
        unordered_map<int, UndirectedGraphNode*> map;
        for (auto &&vec: adjList) {
            if (vec.empty())
                continue;
            int label = vec[0];
            node = map[label];
            if (node==nullptr) {
                node = new UndirectedGraphNode(label);
                map[label] = node;
            }
            for (int i=1;i<vec.size();i++) {
                int adj = vec[i];
                auto adjNode = map[adj];
                if (adjNode==nullptr) {
                    adjNode = new UndirectedGraphNode(adj);
                    map[adj] = adjNode;
                }
                node->neighbors.push_back(adjNode);
            }
        }
        return node;
    }

    string GRAPH_BFS(UndirectedGraphNode *node) {
        unordered_set<int> visited;
        std::stringstream ss;
        std::deque<UndirectedGraphNode*> todo{node};
        while (!todo.empty()) {
            UndirectedGraphNode *ugn = todo.front();
            todo.pop_front();
            if (!ugn) continue;
            int nodeLabel = ugn->val;


            if (visited.find(nodeLabel) != visited.end()) {
                continue;
            }
            visited.emplace(nodeLabel);
            ss << "#"<<nodeLabel;
            if (!ugn->neighbors.empty()) ss << ",";

            for (int i=0;i<ugn->neighbors.size();i++) {
                ss << ugn->neighbors[i]->val;
                todo.emplace_back(ugn->neighbors[i]);
                if (i!=ugn->neighbors.size()-1) {
                    ss<<",";
                }
            }
        }
        return trim(ss.str());

    }

}