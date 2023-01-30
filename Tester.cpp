#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

int main() {

    vector<int> v1 = { 1,2,4};
    vector<int> v2 = { 1,3,4 };
    ListNode x1 = ListNode(v1[0]);
    ListNode * start1 = &x1;
    ListNode x2 = ListNode(v2[0]);
    ListNode* start2=&x2;
    ListNode* curr=start1;

    
    for (int i = 1; i < v1.size(); i++)
    {
        ListNode x = ListNode(v1[i]);
        curr->next = &x;
        curr = curr->next;

    }
    curr = start2;
    for (int i = 1; i < v2.size(); i++)
    {
        ListNode x = ListNode(v2[i]);
        curr->next = &x;
        curr = curr->next;
    }

    curr = mergeTwoLists(start1, start2);
    
    //cout << insert(v, 2);

	return 0;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    else if (list2 == nullptr) {
        return list2;
    }

    if (list1->val < list2->val) {
        ListNode* curr = list1->next;
        ListNode* prev = list1;

        while (curr->next != nullptr) {
            if (curr->val < list2->val) {
                prev = curr;
                curr = curr->next;
            }
            else {
                prev->next = list2;
                list2 = list2->next;
                prev->next = curr;
                prev = prev->next;
                if (list2 == nullptr) {
                    return list1;
                }
            }
        }
        while (curr != nullptr) {
            if (curr->val < list2->val) {
                prev = curr;
                curr = curr->next;
                break;
            }
            else {
                prev->next = list2;
                list2 = list2->next;
                prev->next = curr;
                prev = prev->next;
                if (list2 == nullptr) {
                    return list1;
                }
            }

        }
        curr->next = list2;
        return list1;

    }
    else {

        ListNode* curr = list2->next;
        ListNode* prev = list2;

        while (curr->next != nullptr) {
            if (curr->val < list2->val) {
                prev = curr;
                curr = curr->next;
            }
            else {
                prev->next = list2;
                list2 = list2->next;
                prev->next = curr;
                prev = prev->next;
                if (list2 == nullptr) {
                    return list1;
                }
            }
        }

        while (curr != nullptr) {
            if (curr->val < list1->val) {
                prev = curr;
                //curr = curr->next;
                break;
            }
            else {
                prev->next = list1;
                list1 = list1->next;
                prev->next = curr;
                prev = prev->next;
                if (list1 == nullptr) {
                    return list2;
                }
            }

        }
        curr->next = list1;
        return list2;

    }





}