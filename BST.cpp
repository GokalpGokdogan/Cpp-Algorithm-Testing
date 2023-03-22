#pragma comment(linker, "/STACK:2000000")
#pragma comment(linker, "/HEAP:2000000")
#include "BST.h"
#include <queue>
#include <vector>
#include <iostream>
using namespace std;


void BST::insertItem(int key) {
    if (root==nullptr) {
        root = new BSTNode(key);
        return;
    }
    BSTNode* temp = insertItem(this->root, key);
    //temp = new BSTNode(key);
    //cout << key << endl;
}

BSTNode* BST::insertItem(BSTNode* curr, int key) {
    BSTNode* temp = new BSTNode(key);
    if (curr == nullptr) {
        curr = temp;
        return temp;
    }
    if (curr->val < key) {
        curr->right = insertItem(curr->right, key);
    }
    else {
        curr->left = insertItem(curr->left, key);
    }
    return curr;

}

void BST::printInorder() const
{
    int x = 0;
    int* arr = inorderTraversal(x);
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << endl;
    }
}

void BST::printPreorder() const
{
    int x = 0;
    int* arr = preorderTraversal(x);
    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << endl;
    }
}

BST::~BST()
{
    delete root;
    //cout << "lolbst" << endl;
}

BST& BST::operator=(const BST& Node)
{
    this->root = Node.root;
    return *this;
}

BST::BST(const BST& old)
{
    int size1;
    int* arr1 = old.preorderTraversal(size1);
    cout << "-----------\n";
    this->root = nullptr;
    for (int i = 0; i < size1; i++)
    {
        cout << arr1[i] << endl;
        this->insertItem(arr1[i]);
    }
    this->size = size1;
}

BST::BST()
{
    root = nullptr;
    size = 0;
}
//
void BST::deleteItem(int key) {
    BSTNode* temp = searchBST(key);
    //deleteNode(temp);
    if (temp->right == nullptr && temp->left == nullptr) {
        if (temp == root) {
            root = nullptr;
            delete temp;
        }
        else {

            BSTNode* prev = findPrev(root, temp);
            if (prev->left == temp) {
                prev->left = nullptr;

            }
            else {
                prev->right = nullptr;
            }
            delete temp;
        }
        
    }
    else {
        
        if (temp->right != nullptr && temp->left != nullptr) {
            //if (temp->val == 14661) {
              //  cout << endl;
            //}

            


            BSTNode* mostLeft = leftist(temp->right);
            BSTNode* prev = findPrev(root, mostLeft);
            
            



            BSTNode* xxx = mostLeft->right;
            if (mostLeft == temp->right) {
                mostLeft->left = temp->left;
                temp->left = nullptr;
                
            }
            else {
                prev->left = xxx;
                mostLeft->left = temp->left;
                temp->left = nullptr;
                mostLeft->right = temp->right;
                temp->right = nullptr;
                
            }
            
            if (temp != root) {
                BSTNode* prev2 = findPrev(root, temp);
                if (prev2->right == temp) {
                    prev2->right = mostLeft;
                }
                else {
                    prev2->left = mostLeft;
                }
            }
            else {
                root = mostLeft;
            }
            
            
            /*
            mostLeft->right = temp->right;
            mostLeft->left = temp->left;*/
            temp->right = nullptr;
            temp->left = nullptr;
            delete temp;

        }
        else {
            if (temp->right == nullptr) {
                if (temp == root) {
                    root = root->left;
                    temp->left = nullptr;

                }
                else {
                    BSTNode* prev2 = findPrev(root, temp);
                    if (prev2->right == temp) {
                        prev2->right = temp->left;
                    }
                    else {
                        prev2->left = temp->left;
                    }
                    temp->left = nullptr;
                    delete temp;
                }
                
            }
            else {

                if (temp == root) {
                    root = root->right;
                    temp->right = nullptr;

                }
                else {
                    BSTNode* prev2 = findPrev(root, temp);
                    if (prev2->right == temp) {
                        prev2->right = temp->right;
                    }
                    else {
                        prev2->left = temp->right;
                    }
                    temp->right = nullptr;
                    delete temp;
                }
                
            }
            
        }

        
    }
}


//void BST::deleteNode(BSTNode*& del) {
//    int replacementItem;
//    if (del->left == nullptr && del->right == nullptr) {
//        delete del;
//        del = nullptr;
//    }
//    else if (del->left ==nullptr) {
//        BSTNode* x = del;
//        del = del->right;
//        x->right = nullptr;
//        delete x;
//    }
//    else if (del->right == nullptr) {
//        BSTNode* x = del;
//        del = del->left;
//        x->left = nullptr;
//        delete x;
//    }
//    else {
//
//        processLeftmost(del->right, replacementItem);
//        del->val = replacementItem;
//
//        /*BSTNode* x = leftist(del->right);
//        if (x == del) {
//            del = del->right;
//            del->right = nullptr;
//            delete x;
//        }
//        else {
//            BSTNode* prev = findPrev(root,x);
//            BSTNode* left = leftist(del->right);
//            
//
//            x = del;
//            
//        }
//        */
//    }
//}
//void BST::processLeftmost(BSTNode*& nodePtr,
//    int& treeItem) {
//
//    if (nodePtr->left == NULL) {
//        treeItem = nodePtr->val;
//        BSTNode* delPtr = nodePtr;
//        nodePtr = nodePtr->right;
//        delPtr->right = NULL; // defense
//        delete delPtr;
//    }
//    else
//        processLeftmost(nodePtr->left, treeItem);
//}
//


int* BST::inorderTraversal(int& length) const{
    vector<int> v = inorderTraversal(root);
    length = v.size();
    int* arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = v[i];
    }/*
    cout << "-----------\n";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }*/
    return arr;
}


int* BST::preorderTraversal(int& length) const {
    vector<int> v = preorderTraversal(root);
    length = v.size();
    int* arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = v[i];
    }/*
    cout << "-----------\n";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }*/
    return arr;
}
vector<int> BST::preorderTraversal(BSTNode* root)const {
    vector<int> v1;
    vector<int> v2;
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }
    ans.push_back(root->val);
    if (root->left != nullptr) {
        v1 = preorderTraversal(root->left);
        for (int i = 0; i < v1.size(); i++) {
            ans.push_back(v1[i]);
        }
    }
    if (root->right != nullptr) {
        v2 = preorderTraversal(root->right);
        for (int i = 0; i < v2.size(); i++) {
            ans.push_back(v2[i]);
        }
    }
    return ans;
}
vector<int> BST::inorderTraversal(BSTNode* root)const {
    vector<int> v1;
    vector<int> v2;
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }

    if (root->left != nullptr) {
        v1 = inorderTraversal(root->left);
        for (int i = 0; i < v1.size(); i++) {
            ans.push_back(v1[i]);
        }
    }

    ans.push_back(root->val);

    if (root->right != nullptr) {
        v2 = inorderTraversal(root->right);
        for (int i = 0; i < v2.size(); i++) {
            ans.push_back(v2[i]);
        }
    }
    return ans;
}

BSTNode* BST::searchBST(int val) {
    //cout << "----------\n";
    return searchBST(root, val);
}


BSTNode* BST::findPrev(BSTNode* root, BSTNode* leftist) {



    if (root == nullptr) {
        return nullptr;
    }
    if (root->left != nullptr) {
        if (root->left->val == leftist->val) {
            return root;
        }
    }
    if (root->right != nullptr) {
        if (root->right->val == leftist->val) {
            return root;
        }
    }
    if (root->val < leftist->val) {
        return findPrev(root->right, leftist);
    }
    else {
        return findPrev(root->left, leftist);

    }
}

BSTNode* BST::searchBST(BSTNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }
    //cout << root->val << endl;
    if (root->val == val) {
        return root;
    }
    else if (root->val < val) {
        return searchBST(root->right, val);
    }
    else {
        return searchBST(root->left, val);

    }
    
    /*
    queue<BSTNode*> q;
    q.push(root);
    while (!q.empty()) {
        
        if (q.front()->val == val) {
            return q.front();
        }
        else {
            if (q.front()->left != nullptr) {
                q.push(q.front()->left);
            }
            if (q.front()->right != nullptr) {
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
    return nullptr;
    */


}

BSTNode* BST::leftist(BSTNode* root) {
    if (root->left == nullptr) {
        return root;
    }
    return leftist(root->left);
}
bool BST::hasSequence(int* seq, int length){
    int size;
    int* arr = inorderTraversal(size);
    int i = 0;
    for (; i < size; i++)
    {
        if (arr[i] == seq[0]) {
            break;
        }
        else if (arr[i] < seq[0]) {
            i += i / 2;
        }
        else {
            i = i / 2;
        }


    }
    int a = 0;
    for (int j = i; j < size; j++)
    {
        if (arr[j] == seq[a]) {
            a++;
        }
        else {
            if (arr[j] < seq[length - 1]) {
                break;
            }
        }

       

    }
    if (length == a) {
        return true;
    }
    
    return false;
}
