#include<iostream>
#include<stack>

void pushAtBottom(std::stack<int>&, int);

class Stack {
    public:
        std::stack<int> st;

        void push(int data) {
            pushAtBottom(st, data);
        }

        void pop() {
            if(empty()) {
                std::cout << "Underflow" << std::endl;
                return;
            }
            st.pop();
        }

        bool empty() {
            return st.empty();
        }

        int front() {
            return st.top();
        }
};

void pushAtBottom(std::stack<int>& st, int data) {
    if(st.empty()) {
        st.push(data);
        return;
    }

    int num = st.top();
    st.pop();

    pushAtBottom(st, data);

    st.push(num);
}

void print(Stack st) {
    while(!st.empty()) {
        std::cout << st.front() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    print(st);

    st.pop();
    print(st);

    st.pop();
    st.pop();
    st.pop();

    // st.pop();

    return 0;
}