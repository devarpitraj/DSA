#include<iostream>
#include<queue>

void reverse(std::queue<int>& q) {
    if(q.empty()) return;

    int data = q.front();
    q.pop();

    reverse(q);

    q.push(data);
}

class Queue {
    public:
        std::queue<int> q;

        void push(int data) {
            reverse(q);
            q.push(data);
            reverse(q);
        }

        void pop() {
            if(empty()) {
                std::cout << "Underflow" << std::endl;
                return;
            }
            q.pop();
        }

        bool empty() {
            return q.empty();
        }

        int top() {
            return q.front();
        }
};

void print(Queue stack) {
    while(!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

int main() {
    Queue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    print(stack);

    stack.push(40);
    stack.push(50);
    stack.push(60);
    print(stack);

    stack.pop();
    print(stack);

    stack.pop();
    print(stack);

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    
    stack.pop();

    return 0;
}