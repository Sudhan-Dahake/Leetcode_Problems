#include <iostream>

struct ListNode {
    int val;

    ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }

        else if (!list2) {
            return list1;
        };

        if (list1->val >= list2->val) {
            list2->next = mergeTwoLists(list1, list2->next);

            return list2;
        }

        else {
            list1->next = mergeTwoLists(list1->next, list2);

            return list1;
        };
    }
};


int main(void) {
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;

    ListNode* a1 = new ListNode[sizeof(ListNode)];
    memset(a1, 0, sizeof(ListNode));

    ListNode* b1 = new ListNode[sizeof(ListNode)];
    memset(b1, 0, sizeof(ListNode));

    ListNode* c1 = new ListNode[sizeof(ListNode)];
    memset(c1, 0, sizeof(ListNode));


    a1->val = 1;
    b1->val = 2;
    c1->val = 4;

    a1->next = b1;
    b1->next = c1;
    c1->next = nullptr;




    ListNode* a2 = new ListNode[sizeof(ListNode)];
    memset(a2, 0, sizeof(ListNode));

    ListNode* b2 = new ListNode[sizeof(ListNode)];
    memset(b2, 0, sizeof(ListNode));

    ListNode* c2 = new ListNode[sizeof(ListNode)];
    memset(c2, 0, sizeof(ListNode));


    a2->val = 1;
    b2->val = 3;
    c2->val = 4;

    a2->next = b2;
    b2->next = c2;
    c2->next = nullptr;


    list1 = a1;
    list2 = a2;


    Solution s;

    ListNode* head =  s.mergeTwoLists(list1, list2);

    ListNode* temp = head;

    while (temp != nullptr) {
        std::cout << temp->val << std::endl;

        temp = temp->next;
    };
    
    return 0;
};