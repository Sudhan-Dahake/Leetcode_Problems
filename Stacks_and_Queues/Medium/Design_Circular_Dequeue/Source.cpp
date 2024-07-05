#include <iostream>
#include <memory>
#include <vector>

//class MyCircularDeque {
//    int* front_ptr;
//
//    int* last_ptr;
//
//    int front;
//
//    int last;
//
//    int capacity;
//
//    int size;
//
//public:
//    MyCircularDeque(int k) {
//        this->capacity = k;
//        this->size = 0;
//
//        this->front_ptr = new int[sizeof(int) * this->capacity];
//
//        memset(this->front_ptr, 0, (sizeof(int) * this->capacity));
//
//
//        this->last_ptr = this->front_ptr + (this->capacity - 1);
//
//
//        this->front = 0;
//
//        this->last = this->capacity - 1;
//    }
//
//    bool insertFront(int value) {
//        if (this->size == this->capacity) {
//            return false;
//        };
//
//        *(this->front_ptr + this->front) = value;
//
//        this->front = (this->front + 1) % this->capacity;
//
//        this->size++;
//
//        return true;
//    }
//
//    bool insertLast(int value) {
//        if (this->size == this->capacity) {
//            return false;
//        };
//
//
//        *(this->last_ptr + this->last - (this->capacity - 1)) = value;
//
//        this->last = (this->last - 1 + this->capacity) % this->capacity;
//
//        this->size++;
//
//        return true;
//    }
//
//    bool deleteFront() {
//        if (this->size == 0) {
//            return false;
//        };
//
//        if ((this->front - 1) == this->last) {
//            this->front = 0;
//        };
//
//        this->size--;
//
//        return true;
//    }
//
//    bool deleteLast() {
//        if (this->size == 0) {
//            return false;
//        };
//
//        if ((this->last + 1) == (this->front)) {
//            this->last = this->capacity - 1;
//        }
//
//        else {
//            this->last++;
//        };
//
//        this->size--;
//
//        return true;
//    }
//
//    int getFront() {
//        if (this->size == 0) {
//            return -1;
//        };
//
//        return *(this->front_ptr + front - 1);
//    }
//
//    int getRear() {
//        if (this->size == 0) {
//            return -1;
//        };
//
//        return *(this->last_ptr + last - (this->capacity - 2));
//    }
//
//    bool isEmpty() {
//        if (this->size == 0) {
//            return true;
//        };
//
//        return false;
//    }
//
//    bool isFull() {
//        if (this->size == this->capacity) {
//            return true;
//        };
//
//        return false;
//    }
//};



//class MyCircularDeque {
//private:
//    std::vector<int> buffer;
//    int cnt;
//    int k;
//    int front;
//    int rear;
//public:
//    /** Initialize your data structure here. Set the size of the deque to be k. */
//    MyCircularDeque(int k) : buffer(k, 0), cnt(0), k(k), front(k - 1), rear(0) {
//    }
//
//    /** Adds an item at the front of Deque. Return true if the operation is successful. */
//    bool insertFront(int value) {
//        if (cnt == k) {
//            return false;
//        }
//        buffer[front] = value;
//        front = (front - 1 + k) % k;
//        ++cnt;
//
//        return true;
//    }
//
//    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
//    bool insertLast(int value) {
//        if (cnt == k) {
//            return false;
//        }
//        buffer[rear] = value;
//        rear = (rear + 1) % k;
//        ++cnt;
//
//        return true;
//    }
//
//    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
//    bool deleteFront() {
//        if (cnt == 0) {
//            return false;
//        }
//        front = (front + 1) % k;
//        --cnt;
//
//        return true;
//    }
//
//    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
//    bool deleteLast() {
//        if (cnt == 0) {
//            return false;
//        }
//        rear = (rear - 1 + k) % k;
//        --cnt;
//
//        return true;
//    }
//
//    /** Get the front item from the deque. */
//    int getFront() {
//        if (cnt == 0) {
//            return -1;
//        }
//        return buffer[(front + 1) % k];
//    }
//
//    /** Get the last item from the deque. */
//    int getRear() {
//        if (cnt == 0) {
//            return -1;
//        }
//        return buffer[(rear - 1 + k) % k];
//    }
//
//    /** Checks whether the circular deque is empty or not. */
//    bool isEmpty() {
//        return cnt == 0;
//    }
//
//    /** Checks whether the circular deque is full or not. */
//    bool isFull() {
//        return cnt == k;
//    }
//};



class MyCircularDeque {
    int* front_ptr;

    int* last_ptr;

    int front;

    int last;

    int capacity;

    int size;

public:
    MyCircularDeque(int k) {
        this->capacity = k;
        this->size = 0;

        this->front_ptr = new int[sizeof(int) * this->capacity];

        memset(this->front_ptr, 0, (sizeof(int) * this->capacity));


        this->last_ptr = this->front_ptr + (this->capacity - 1);


        this->front = 0;

        this->last = this->capacity - 1;
    }

    bool insertFront(int value) {
        if (this->size == this->capacity) {
            return false;
        };

        *(this->front_ptr + this->front) = value;

        this->front = (this->front + 1) % this->capacity;

        this->size++;

        return true;
    }

    bool insertLast(int value) {
        if (this->size == this->capacity) {
            return false;
        };


        *(this->last_ptr + this->last - (this->capacity - 1)) = value;

        this->last = (this->last - 1 + this->capacity) % this->capacity;

        this->size++;

        return true;
    }

    bool deleteFront() {
        if (this->size == 0) {
            return false;
        };

        /*
                if ((this->front - 1) == this->last) {
                    this->front = 0;
                };
        */

        this->front = (this->front - 1 + this->capacity) % this->capacity;

        this->size--;

        return true;
    }

    bool deleteLast() {
        if (this->size == 0) {
            return false;
        };

        /*
        if ((this->last + 1) == (this->front)) {
            this->last = this->capacity - 1;
        }

        else {
            this->last++;
        }
        */

        this->last = (this->last + 1) % this->capacity;

        this->size--;

        return true;
    }

    int getFront() {
        if (this->size == 0) {
            return -1;
        };

        return *(this->front_ptr + ((front - 1 + this->capacity) % this->capacity));
    }

    int getRear() {
        if (this->size == 0) {
            return -1;
        };

        return *(this->last_ptr - ((this->capacity - 1) - ((this->last + 1) % this->capacity)));

        //return *(this->last_ptr + (((last - 1) + this->capacity) % this->capacity));
    }

    bool isEmpty() {
        if (this->size == 0) {
            return true;
        };

        return false;
    }

    bool isFull() {
        if (this->size == this->capacity) {
            return true;
        };

        return false;
    }
};




int main(void) {
    MyCircularDeque* obj = new MyCircularDeque(8);

    /*obj->insertLast(1);
    obj->insertLast(2);

    obj->insertFront(3);

    std::cout << obj->getRear() << std::endl;

    std::cout << obj->isFull() << std::endl;

    obj->deleteLast();

    obj->insertFront(4);

    std::cout << obj->getFront() << std::endl;*/


    obj->insertFront(5);

    std::cout << obj->getFront() << std::endl;

    obj->isEmpty();

    obj->deleteFront();

    obj->insertLast(3);

    std::cout << obj->getRear() << std::endl;


    obj->insertLast(7);

    obj->insertFront(7);

    obj->deleteLast();

    obj->insertLast(4);

    obj->isEmpty();

    
    return 0;
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */