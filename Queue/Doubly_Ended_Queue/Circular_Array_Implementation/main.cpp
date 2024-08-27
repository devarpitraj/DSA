#include<iostream>

class Deque {
    public:
        int front;
        int rear;
        int* arr;
        int size;

        Deque(int size) {
            this -> size = size;
            arr = new int[size];
            front = rear = -1;
        }

        bool isEmpty() {
            if(front == -1) return 1;
            else return 0;
        }

        bool isFull() {
            if((rear + 1) % size == front) return 1;
            else return 0;
        }

        void push_front(int data) {
            if(isFull()) {
                std::cout << "Queue Overflow" << std::endl;
                return;
            }

            if(isEmpty()) front = rear = 0;
            else if(front == 0 && !isFull()) front = size - 1;
            else front--;

            arr[front] = data;
        }

        void push_back(int data) {
            if(isFull()) {
                std::cout << "Queue Overflow" << std::endl;
                return;
            }

            if(isEmpty()) front = rear = 0;
            else if(rear == size - 1 && !isFull()) rear = 0;
            else rear++;

            arr[rear] = data;
        }

        void pop_front() {
            if(isEmpty()) {
                std::cout << "Queue Underflow" << std::endl;
                return;
            }

            if(front == rear) front = rear = -1;
            else if(front == size - 1) front = 0;
            else front++;
        }

        void pop_back() {
            if(isEmpty()) {
                std::cout << "Queue Underflow" << std::endl;
                return;
            }

            if(front == rear) front = rear = -1;
            else if(rear == 0) rear = size - 1;
            else rear--;
        }

        int give_front() {
            if(isEmpty()) {
                return -1;
            }
            else return arr[front];
        }

        int give_back() {
            if(isEmpty()) {
                return -1;
            }
            else return arr[rear];
        }
};

int main() {
    Deque deq(3);

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

    deq.push_front(100);
    deq.push_back(200);

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