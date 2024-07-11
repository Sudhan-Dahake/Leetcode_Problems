#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryover = 0;

        ListNode* list1 = l1;
        ListNode* list2 = l2;

        ListNode* dummy = new ListNode(0);

        ListNode* tail = dummy;

        while (list1 || list2 || carryover) {
            int digit1 = (list1) ? list1->val : 0;

            int digit2 = (list2) ? list2->val : 0;

            int sum = digit1 + digit2 + carryover;



            carryover = sum / 10;

            sum = sum % 10;



            ListNode* newNode = new ListNode(sum);

            tail->next = newNode;

            tail = tail->next;



            list1 = (list1) ? list1->next : nullptr;

            list2 = (list2) ? list2->next : nullptr;
        };

        ListNode* result = dummy->next;

        dummy->next = nullptr;

        delete dummy;

        return result;
    };
};