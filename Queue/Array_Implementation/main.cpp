#include<iostream>

class Queue {
    public:
        int front;
        int rear;
        int* arr;
        int size;

        Queue(int size) {
            this -> size = size;
            arr = new int[size];

            front = rear = -1;
        }

        void enqueue(int data) {
            if(rear == size - 1) {
                std::cout << "Queue Overflow" << std::endl;
                return;
            }

            if(front == -1) front++;

            rear++;
            arr[rear] = data;
        }

        void dequeue() {
            if(front == -1) {
                std::cout << "Queue Underflow" << std::endl;
                return;
            }

            front++;

            if(front > rear) front = rear = -1;
        }

        bool empty() {
            if(front == -1) return true;
            else return false;
        }

        int give_front() {
            if(empty()) return -1;
            return arr[front];
        }

        int back() {
            if(empty()) return -1;
            return arr[rear];
        }
};

int main() {
    Queue que(5);

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