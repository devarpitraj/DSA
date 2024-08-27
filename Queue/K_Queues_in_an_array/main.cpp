#include<iostream>

class KQueue {
    public:
        int* arr;
        int* front;
        int* rear;
        int* next;
        int freeSpot;

        KQueue(int size, int k) {
            arr = new int[size];
            next = new int[size];
            front = new int[k];
            rear = new int[k];
            freeSpot = 0;

            for(int i = 0; i < size; i++) next[i] = i + 1;
            next[size - 1] = -1;

            for(int i = 0; i < k; i++) {
                front[i] = rear[i] = -1;
            }
        }

        void push(int data, int q) {
            // overflow check
            if(freeSpot == -1) {
                std::cout << "Queue Overflow" << std::endl;
                return;
            }

            // find index where to push
            int index = freeSpot;

            // update freeSpot
            freeSpot = next[index];

            // first ele or else
            if(front[q - 1] == -1) {
                //update front array
                front[q - 1] = index;
            } else {
                // link new ele to prev ele
                next[rear[q - 1]] = index;
            }

            // make next of index = -1 since it is last in queue
            next[index] = -1;

            // update rear array
            rear[q - 1] = index;

            // assign the value in array
            arr[index] = data;
        }

        int pop(int q) {
            // underflow condition
            if(front[q - 1] == -1) {
                std::cout << "Queue Underflow" << std::endl;
                return -1;
            }

            // find index to pop
            int index = front[q - 1];

            // update front array
            front[q - 1] = next[index];

            // update next[index] to freeSpot
            // and move freeSpot to index
            // so the newly available space
            // can be used
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];
        }
};

int main() {
    KQueue que(5, 3);

    que.push(10, 1);
    que.push(20, 2);
    que.push(40, 2);
    que.push(30, 3);
    que.push(60, 3);

    std::cout << que.pop(1) << std::endl;

    que.push(90, 3);

    // std::cout << que.pop(1) << std::endl;

    std::cout << que.pop(2) << std::endl;
    std::cout << que.pop(3) << std::endl;
    std::cout << que.pop(3) << std::endl;
    std::cout << que.pop(2) << std::endl;
    
    std::cout << que.pop(3) << std::endl;
    // std::cout << que.pop(2) << std::endl;

    // std::cout << que.pop(3) << std::endl;
  
    return 0;
}