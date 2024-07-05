#include <iostream>
#include <vector>
#include <tuple>

class MinStack {
	std::vector<std::tuple<int, int>> stack;

	int minVal;

public:
	MinStack() {
		this->minVal = INT_MAX;
	};


	void push(int val) {
		if (minVal > val) {
			this->minVal = val;
		}

		stack.push_back(std::make_tuple(val, minVal));
	};


	void pop() {
		if (stack.size() == 0) {
			return;
		}

		else if (stack.size() == 1) {
			this->minVal = INT_MAX;
		}

		else {
			this->minVal = std::get<1>(stack[stack.size() - 2]);
		};


		stack.pop_back();
	};


	int top() {
		return std::get<0>(stack[stack.size() - 1]);
	};


	int getMin() {
		return this->minVal;
	};
};












//struct Stack {
//    Stack* prevPtr;
//    int value;
//    int minValue;
//    Stack* nextPtr;
//};
//
//class MinStack {
//    int minVal;
//
//    Stack* head;
//    Stack* tail;
//
//    unsigned int size;
//
//public:
//    MinStack() {
//        this->minVal = INT_MAX;
//
//        this->head = nullptr;
//        this->tail = nullptr;
//
//        this->size = 0;
//    }
//
//    void push(int val) {
//        if (this->minVal > val) {
//            this->minVal = val;
//        }
//
//        if (this->size == 0) {
//            this->head = new Stack[sizeof(Stack)];
//
//            memset(this->head, 0, sizeof(Stack));
//
//            this->tail = this->head;
//
//            this->head->nextPtr = nullptr;
//            this->tail->prevPtr = nullptr;
//        }
//
//        else {
//            this->tail->nextPtr = new Stack[sizeof(Stack)];
//
//            memset(this->tail->nextPtr, 0, sizeof(Stack));
//
//            this->tail->nextPtr->nextPtr = nullptr;
//
//            this->tail->nextPtr->prevPtr = this->tail;
//
//            this->tail = this->tail->nextPtr;
//        }
//
//
//        this->tail->minValue = this->minVal;
//        this->tail->value = val;
//
//
//        this->size++;
//    }
//
//    void pop() {
//        if (this->size == 0) {
//            return;
//        }
//
//
//        Stack* temp = this->tail;
//
//        this->tail = temp->prevPtr;
//
//        if (this->size != 1) {
//            this->tail->nextPtr = nullptr;
//        }
//
//        temp->prevPtr = nullptr;
//
//        delete[] temp;
//        temp = nullptr;
//
//
//
//        this->size--;
//
//
//        if (this->size == 0) {
//            this->minVal = INT_MAX;
//        }
//
//        else {
//            this->minVal = this->tail->minValue;
//        }
//    }
//
//    int top() {
//        return this->tail->value;
//    }
//
//    int getMin() {
//        return this->tail->minValue;
//    }
//};
//
///**
// * Your MinStack object will be instantiated and called as such:
// * MinStack* obj = new MinStack();
// * obj->push(val);
// * obj->pop();
// * int param_3 = obj->top();
// * int param_4 = obj->getMin();
// */