#include<iostream>

class Node {
    public:
        Node* prev;
        int data;
        Node* next;

        Node(int data) {
            prev = next = NULL;
            this -> data = data;
        }
};

class Deque {
    public:
        Node* front;
        Node* rear;

        Deque() {
            front = rear = NULL;
        }

        bool isEmpty() {
            if(front == NULL) return true;
            else return false;
        }

        void push_front(int data) {
            Node* temp = new Node(data);

            if(isEmpty()) {
                front = rear = temp;    
                return;
            }

            temp -> next = front;
            front -> prev = temp;
            front = temp;
        }

        void push_back(int data) {
            Node* temp = new Node(data);

            if(isEmpty()) {
                front = rear = temp;
                return;
            }

            rear -> next = temp;
            temp -> prev = rear;
            rear = temp;
        }

        void pop_front() {
            if(isEmpty()) {
                std::cout << "Queue underflow" << std::endl;
                return;
            }

            if(front == rear) front = rear = NULL;
            else {
                Node* temp = front;
                front = front -> next;
                front -> prev = NULL;
                temp -> next = NULL;
                delete temp;
            }
        }

        void pop_back() {
            if(isEmpty()) {
                std::cout << "Queue underflow" << std::endl;
                return;
            }

            if(front == rear) front = rear = NULL;
            else {
                Node* temp = rear;
                rear = rear -> prev;
                rear -> next = NULL;
                temp -> prev = NULL;
                delete temp;
            }
        }

        int give_front() {
            if(isEmpty()) return -1;
            else return front -> data;
        }

        int give_back() {
            if(isEmpty()) return -1;
            else return rear -> data;
        }
};

int main() {
    Deque deq;

    std::cout << deq.give_front() << std::endl;
    std::cout << deq.give_back() << std::endl;

    deq.pop_back();
    deq.pop_front();

    deq.push_back(20);
    deq.push_front(10);
    std::cout << deq.give_front() << std::endl;
    std::cout << deq.give_back() << std::endl;

    deq.push_back(30);
    std::cout << deq.give_front() << std::endl;
    std::cout << deq.give_back() << std::endl;

    // deq.push_front(100);
    // deq.push_back(200);

    deq.pop_front();
    std::cout << deq.give_front() << std::endl;
    std::cout << deq.give_back() << std::endl;

    deq.pop_back();
    std::cout << deq.give_front() << std::endl;
    std::cout << deq.give_back() << std::endl;

    deq.pop_back();
    std::cout << deq.give_front() << std::endl;
    std::cout << deq.give_back() << std::endl;

    deq.pop_back();
    deq.pop_front();

    return 0;
}