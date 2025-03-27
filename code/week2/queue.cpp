#include <iostream>


// 实现一个队列

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Queue {
    
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;


    public:
        Queue() : head(nullptr), tail(nullptr), size(0) {}

        ~Queue() {
            while(!isEmpty()){
                dequeue();
            }
        }
        // push the element
        void push(T val) {
            Node<T>* newNode = new Node<T>(val);
            if(isEmpty()){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

        // pop the element
        void pop() {
            if (isEmpty()) {
                std::cerr << "Queue is empty, cannot dequeue.\n";
                return;
            }
            Node<T>* temp = front;
            front = front->next;
            delete temp;
            size--;
    
            if (front == nullptr) { // 如果队列变空，rear 也要置空
                rear = nullptr;
            }
        }

        // get the front element
        T get front() {
            if(isEmpty()){
                throw std::runtime_error("Queue is empty");
            }
            return head->data;
        }


};
