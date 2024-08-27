#include<iostream>

class Node{
    public:
        int data;
        Node* next;

        Node(int data) {
            this -> data = data;
            next = NULL;
        }
};

class Queue{
    public:
        Node* front;
        Node* rear;

        Queue() {
            front = rear = NULL;
        }

        bool empty() {
            if(front == NULL) return true;
            else return false;
        }

        void enqueue(int data) {
            Node* temp = new Node(data);
            if(empty()) front = rear = temp;
            else {
                rear -> next = temp;
                rear = temp;
            }
        }

        void dequeue() {
            if(empty()) {
                std::cout << "Queue Underflow" << std::endl;
                return;
            }
            Node* temp = front;
            front = front -> next;
            delete temp;
        }

        int give_front() {
            if(empty()) return -1;
            return front -> data;
        }

        int back() {
            if(empty()) return -1;
            return rear -> data;
        }
};

int main() {
    Queue que;

    que.dequeue();

    que.enqueue(10);
    que.enqueue(20);
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.enqueue(30);
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.enqueue(40);
    que.enqueue(50);

    // que.enqueue(60);

    que.dequeue();
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.dequeue();
    que.dequeue();

    que.dequeue();
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.dequeue();
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    std::cout << std::boolalpha;
    std::cout << que.empty() << std::endl;
    que.enqueue(100);
    std::cout << que.empty() << std::endl;

    return 0;
}