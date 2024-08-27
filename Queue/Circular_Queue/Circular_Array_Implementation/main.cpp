#include<iostream>

class Cir_Que {
    public:
        int* arr;
        int front;
        int rear;
        int size;

        Cir_Que(int size) {
            this -> size = size;
            front = rear = -1;
            arr = new int[size];
        }

        void enqueue(int data) {
            if((rear + 1) % size == front) {
                std::cout << "Queue Overflow" << std::endl;
                return;
            }

            if(front == -1) front = rear = 0;
            else if(rear == size - 1 && front != 0) rear = 0;
            else rear++;

            arr[rear] = data;
        }

        void dequeue() {
            if(front == -1) {
                std::cout << "Queue Underflow" << std::endl;
                return;
            }

            if(front == rear) front = rear = -1;
            else if(front == size - 1) front = 0;
            else front++;
        }

        int give_front() {
            if(front == -1) return -1;
            return arr[front];
        }

        int back() {
            if(front == -1) return -1;
            return arr[rear];
        }
};

int main() {
    Cir_Que que(3);

    que.dequeue();

    que.enqueue(10);
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.enqueue(20);
    que.enqueue(30);
    std::cout << que.give_front() << std::endl;
    std::cout << que.back() << std::endl;

    que.enqueue(40);

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