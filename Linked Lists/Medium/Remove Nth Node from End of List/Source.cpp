#include <iostream>

struct Node {
	int val;

	Node* next;
};


class RemoveNthNode {
public:
	Node* removeNthFromEnd(Node* head, int n) {
		if (!head) {
			return nullptr;
		}

		Node* fast = head;
		Node* slow = head;

		for (int i = 0; i < n; i++) {
			fast = fast->next;
		};


		if (!fast) {
			return head->next;
		};


		while (fast->next) {
			fast = fast->next;

			slow = slow->next;
		};


		Node* temp = slow->next->next;

		slow->next->next = nullptr;

		delete slow->next;

		slow->next = temp;

		temp = nullptr;



		return head;
	};
};