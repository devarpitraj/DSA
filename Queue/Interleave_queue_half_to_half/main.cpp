#include<iostream>
#include<queue>
#include<stack>

void print(std::queue<int> q) {
    while(!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    int half = (q.size() / 2);

    // using queue
    // std::queue<int> temp;

    // while(half--) {
    //     int val = q.front();
    //     q.pop();

    //     temp.push(val);
    // }

    // while(!temp.empty()) {
    //     int val = temp.front();
    //     temp.pop();
    //     q.push(val);

    //     val = q.front();
    //     q.pop();
    //     q.push(val);
    // }

    // if(q.size() & 1) {
    //     int val = q.front();
    //     q.pop();
    //     q.push(val);
    // }
    // print(q);

    // using stack
    std::stack<int> temp;
    int i{};

    // half is in stack (reverse order)
    // stack : 1 2 3
    // queue : 4 5 6
    while(i++ < half) {
        int val = q.front();
        q.pop();
        temp.push(val);
    }

    // push in queue 
    // stack : empty
    // queue : 4 5 6 3 2 1
    while(!temp.empty()) {
        int val = temp.top();
        temp.pop();
        q.push(val);
    }

    // move half of queue to back of queue
    // stack : empty
    // queue : 3 2 1 4 5 6
    i = 0;
    while(i++ < half) {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // move half of queue to stack (correct order)
    // stack : 3 2 1
    // queue : 4 5 6
    i = 0;
    while(i++ < half) {
        int val = q.front();
        q.pop();
        temp.push(val);
    }

    // interleave stack and queue
    // queue : 1 4 2 5 3 6
    while(!temp.empty()) {
        int val = temp.top();
        temp.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }
    print(q);

    return 0;
}