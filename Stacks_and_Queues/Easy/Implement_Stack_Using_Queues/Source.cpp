#include <iostream>
#include <queue>

class MyStack {
    std::queue<int> queue;

public:
    MyStack() {

    }

    void push(int x) {
        queue.push(x);

        for (int i = 0; i < (queue.size() - 1); i++) {
            queue.push(queue.front());

            queue.pop();
        };
    }

    int pop() {
        int element = queue.front();

        queue.pop();

        return element;
    }

    int top() {
        return queue.front();
    }

    bool empty() {
        return queue.empty();
    }
};


int main(void) {
    MyStack* obj = new MyStack();
    
    obj->push(1);
    obj->push(2);
    obj->push(3);

    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();

    return 0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */