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
ListNode* removeElements(ListNode* head, int val);
int main() {

    vector<int> v1 = { 1,2,6,3,4,5,6 };
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
    curr = removeElements(start1, 6);
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

















    //ListNode* res = head;
    //ListNode* r;// = res;
    //if (head == nullptr) {
    //    return head;
    //}
    //int i = 0;
    //while (head->next != nullptr) {
    //    if (head->val != val) {
    //        ListNode*  r = new ListNode(head->val);
    //        if (i == 0) {
    //            res = r;
    //            i++;
    //        }
    //        r = r->next;
    //        

    //    }
    //    head = head->next;
    //}
    //if (head->val != val) {
    //    r = new ListNode(head->val);
    //}
    //return res;



}

