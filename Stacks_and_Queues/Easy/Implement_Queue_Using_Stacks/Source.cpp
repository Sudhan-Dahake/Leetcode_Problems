#include <iostream>
#include <stack>

class MyQueue {
    std::stack<int> stack;
    std::stack<int> queue;

public:
    MyQueue() {

    }

    void push(int x) {
        this->stack.push(x);
    }

    int pop() {
        if (this->stack.empty() && this->queue.empty()) {
            return -1;
        }

        else if (this->queue.empty()) {
            while (!this->stack.empty()) {
                queue.push(this->stack.top());

                this->stack.pop();
            };
        }


        int element = this->queue.top();

        this->queue.pop();

        return element;
    }

    int peek() {
        if (this->stack.empty() && this->queue.empty()) {
            return -1;
        }

        else if (this->queue.empty()) {
            while (!this->stack.empty()) {
                this->queue.push(this->stack.top());

                this->stack.pop();
            };
        }


        return this->queue.top();
    }

    bool empty() {
        if (this->stack.empty() && this->queue.empty()) {
            return true;
        }

        return false;
    }
};


int main(void) {
 // * Your MyQueue object will be instantiated and called as such:
    MyQueue* obj = new MyQueue();
    obj->push(1);



    int param_2 = obj->pop();

    std::cout << param_2 << std::endl;




    int param_3 = obj->peek();

    std::cout << param_3 << std::endl;




    bool param_4 = obj->empty();

    return 0;
}

