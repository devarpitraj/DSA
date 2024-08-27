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

class Cir_Queue {
    public:
        Node* front;
        Node* rear;

        Cir_Queue() {
            front = rear = NULL;
        }

        bool empty() {
            if(front == NULL) return true;
            else return false;
        }

        void enqueue(int data) {
            Node* temp = new Node(data);
            if(empty()) {
                front = rear = temp;
                rear -> next = temp;
            }
            else {
                temp -> next = rear -> next;
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
            if(front -> next == front) { // single element
                front = rear = NULL;
            } else {
                front = front -> next;
                rear -> next = front;
            }
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
    Cir_Queue que;

    que.dequeue();

    que.enqueue(10);
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.enqueue(20);
    que.enqueue(30);
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    // que.enqueue(40);

    que.dequeue();
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.enqueue(40);
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.dequeue();
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.dequeue();
    que.dequeue();
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    return 0;
}