#pragma once
class BSTNode
{
private:
    
public:
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(BSTNode &node);
    BSTNode() : val(0), left(nullptr), right(nullptr) {}
    BSTNode(int x) : val(x), left(nullptr), right(nullptr) {}
    BSTNode(int x, BSTNode* left, BSTNode* right) : val(x), left(left), right(right) {}
    int getVal();
    BSTNode* getLeft();
    BSTNode* getRight();
    BSTNode& operator=(const BSTNode& Node);

    ~BSTNode();
};

