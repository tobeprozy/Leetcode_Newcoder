#include<iostream>
#include<vector>
using namespace std;



#include<iostream>
#include<vector>
using namespace std;

class MyCircularQueue {
private:
    int front;                 // 头指针
    int rear;                  // 尾指针
    int capacity;              // 循环队列容量
    vector<int> elements;      // 保存元素的容器

public:
    MyCircularQueue(int k) : front(0), rear(0), capacity(k + 1), elements(vector<int>(capacity)) {

    }
    
    bool enQueue(int value) {
        if (isFull()) return false;    // 先判断循环队列有没有满
        // 放入元素
        elements[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;   
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return elements[front]; 
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return elements[(rear - 1 + capacity) % capacity]; 
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return front == (rear + 1) % capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    int k = 3;
    MyCircularQueue* obj = new MyCircularQueue(k);
    bool r1 = obj->enQueue(1);
    bool r2 = obj->enQueue(2);
    bool r3 = obj->enQueue(3);
    bool r4 = obj->enQueue(4);
    int a1 = obj->Rear();
    bool r5 = obj->isFull();
    bool r6 = obj->deQueue();
    bool r7 = obj->enQueue(4);
    int a2 = obj->Rear();
    return 0;
}