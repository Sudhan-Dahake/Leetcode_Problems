#include <iostream>

struct Node {
	int val;

	Node* next;
};

class ReverseLinkedList {
public:
	Node* reverseList(Node* head) {
		if (head->next == nullptr) {
			return head;
		};


		Node* temp = reverseList(head->next);

		head->next->next = head;

		head->next = nullptr;


		return temp;
	};
};