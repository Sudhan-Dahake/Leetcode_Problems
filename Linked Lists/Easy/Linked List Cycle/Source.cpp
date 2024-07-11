#include <iostream>

struct Node {
	int val;

	Node* next;
};

class LinkedListCycle {
public:
	bool hasCycle(Node* head) {
		Node* fast = head;
		Node* slow = head;

		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow) {
				return true;
			};
		};


		return false;
	};
};


int main(void) {
	Node* head = nullptr;


	Node* a = new Node[sizeof(Node)];
	memset(a, 0, sizeof(Node));

	Node* b = new Node[sizeof(Node)];
	memset(b, 0, sizeof(Node));

	Node* c = new Node[sizeof(Node)];
	memset(c, 0, sizeof(Node));

	Node* d = new Node[sizeof(Node)];
	memset(d, 0, sizeof(Node));



	a->val = 3;
	b->val = 2;
	c->val = 0;
	d->val = -4;


	a->next = b;
	b->next = c;
	c->next = d;
	d->next = b;


	head = a;


	LinkedListCycle llc;

	std::cout << llc.hasCycle(head) << std::endl;
	
	return 0;
}