#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};


ListNode* reverseList(ListNode* head);
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
ListNode* removeElements(ListNode* head, int val);
bool isValid(string s);
vector<vector<int>> levelOrder(TreeNode* root);
vector<int> preorderTraversal(TreeNode* root);
vector<int> inorderTraversal(TreeNode* root);
vector<int> postorderTraversal(TreeNode* root);
bool isSymmetric(TreeNode* root);
bool isSymmetric(TreeNode* root1, TreeNode* root2);


int main() {

    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2 = { 5,7 };
    ListNode x1 = ListNode(v1[0]);
    ListNode * start1 = &x1;
    ListNode x2 = ListNode(v2[0]);
    ListNode* start2=&x2;
    ListNode* curr=start1;

    
    for (int i = 1; i < v1.size(); i++)
    {
        ListNode* x = new ListNode(v1[i]);
        curr->next = x;
        curr = curr->next;

    }
    curr = start2;
    for (int i = 1; i < v2.size(); i++)
    {
        ListNode* x = new ListNode(v2[i]);
        curr->next = x;
        curr = curr->next;
    }

    //curr = mergeTwoLists(start1, start2);
    curr = reverseList(start1);
    cout << "l";// insert(v, 2);

	return 0;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    else if (list2 == nullptr) {
        return list1;
    }

    if (list1->val < list2->val) {
        ListNode* curr = list1->next;
        ListNode* prev = list1;

        if (curr != nullptr) {
            while (curr->next != nullptr) {
                if (curr->val < list2->val) {
                    prev = curr;
                    curr = curr->next;
                }
                else {
                    prev->next = list2;
                    list2 = list2->next;
                    prev->next->next = curr;
                    prev = prev->next;
                    if (list2 == nullptr) {
                        return list1;
                    }
                }
            }


            while (list2->next != nullptr) {
                if (curr->val < list2->val) {
                    prev = curr;
                    curr = curr->next;
                    break;
                }
                else {
                    prev->next = list2;
                    list2 = list2->next;
                    prev->next->next = curr;
                    prev = prev->next;
                    if (list2 == nullptr) {
                        return list1;
                    }
                }

            }
            if (curr != nullptr) {

                if (curr->val < list2->val) {
                    prev = curr;
                    curr = curr->next;

                }
                else {
                    prev->next = list2;
                    list2 = list2->next;
                    prev->next->next = curr;
                    prev = prev->next;
                    if (list2 == nullptr) {
                        return list1;
                    }
                }
            }
            prev->next = list2;
        }
        else {
            prev->next = list2;
        }


        return list1;

    }
    else {

        ListNode* curr = list2->next;
        ListNode* prev = list2;

        if (curr != nullptr) {
            while (curr->next != nullptr) {
                if (curr->val < list1->val) {
                    prev = curr;
                    curr = curr->next;
                }
                else {
                    prev->next = list1;
                    list1 = list1->next;
                    prev->next->next = curr;
                    prev = prev->next;
                    if (list1 == nullptr) {
                        return list2;
                    }
                }
            }


            while (list1->next != nullptr) {
                if (curr->val < list1->val) {
                    prev = curr;
                    curr = curr->next;
                    break;
                }
                else {
                    prev->next = list1;
                    list1 = list1->next;
                    prev->next->next = curr;
                    prev = prev->next;
                    if (list1 == nullptr) {
                        return list2;
                    }
                }

            }
            if (curr != nullptr) {
                if (curr->val < list1->val) {
                    prev = curr;
                    curr = curr->next;

                }
                else {
                    prev->next = list1;
                    list1 = list1->next;
                    prev->next->next = curr;
                    prev = prev->next;
                    if (list1 == nullptr) {
                        return list2;
                    }
                }
            }
            
            prev->next = list1;
        }
        else {
            prev->next = list1;
        }

        
        return list2;

    }

}

ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) {
        return head;
    }
    if (head->next == nullptr) {
        if (head->val == val) {
            return nullptr;
        }
        else {
            return head;
        }
    }
    ListNode* curr = head->next;
    ListNode* prev = head;
    while (curr != nullptr) {
        if (curr->val == val) {
            //if (curr->next != nullptr) {
                prev->next = curr->next;
                
                curr = curr->next;

            //}
            //else { break; }
            
        }
        else {
            prev = curr;
            curr = curr->next;
        }
        
    }

    if (head->val == val) {
        head = head->next;

    }
    return head;

}

ListNode* reverseList(ListNode* head) {
    stack<int> s;
    ListNode* start = head;
    while (head != nullptr) {
        s.push(head->val);
        head = head->next;
    }
    //ListNode* a = nullptr;
    //ListNode* b = new ListNode();
    ListNode* start2 = start;
    while (!s.empty()) {
        // int x = s.peek();
        start->val = (s.top());
        s.pop();
        start = start->next;
    }
    return start2;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> v;
    if (root == nullptr) {
        return v;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> temp;
        int size = q.size();
        for (int i = 0; i < size; i++) {

            temp.push_back(q.front()->val);

            if (q.front()->left != nullptr) {
                q.push(q.front()->left);
            }
            if (q.front()->right != nullptr) {
                q.push(q.front()->right);
            }
            q.pop();
        }
        v.push_back(temp);


    }
    return v;
}
bool isValid(string s) {
    stack<char> ss;
    char x;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            ss.push(s[i]);
        }
        else {
            if (ss.size()) {
                if (s[i] == ')' && ss.top() == '(') {
                    ss.pop();
                }
                else if (s[i] == ']' && ss.top() == '[') {
                    ss.pop();

                }
                else if (s[i] == '}' && ss.top() == '{') {
                    ss.pop();
                }
                else {
                    return 0;
                }
            }
            else { return 0; }
        }
    }
    if (ss.size()) {
        return 0;
    }
    else {
        return 1;
    }
}
vector<int> preorderTraversal(TreeNode* root) {
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
vector<int> inorderTraversal(TreeNode* root) {
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
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v1;
    vector<int> v2;
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }

    if (root->left != nullptr) {
        v1 = postorderTraversal(root->left);
        for (int i = 0; i < v1.size(); i++) {
            ans.push_back(v1[i]);
        }
    }
    if (root->right != nullptr) {
        v2 = postorderTraversal(root->right);
        for (int i = 0; i < v2.size(); i++) {
            ans.push_back(v2[i]);
        }
    }
    ans.push_back(root->val);
    return ans;
}
bool isSymmetric(TreeNode* root) {
    return isSymmetric(root->left, root->right);

}
bool isSymmetric(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return 1;
    }
    else if (root1 == nullptr) {
        return 0;
    }
    else if (root2 == nullptr) {
        return 0;
    }
    else {
        bool boo = 1;
        if (root1->left != nullptr && root2->right != nullptr) {
            boo = boo && root1->val == root2->val && isSymmetric(root1->left, root2->right);  //root1->left->val==root2->right->val;
        }
        else if (root1->left == nullptr && root2->right == nullptr) {
            boo = boo && root1->val == root2->val;
        }
        else {
            boo = 0;
        }
        if (root1->right != nullptr && root2->left != nullptr) {
            boo = boo && root1->val == root2->val && isSymmetric(root1->right, root2->left);  //root1->left->val==root2->right->val;
        }
        else if (root1->right == nullptr && root2->left == nullptr) {
            boo = boo && root1->val == root2->val;
        }
        else {
            boo = 0;
        }

        return boo;
    }
}


