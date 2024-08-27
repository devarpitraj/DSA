#include<iostream>

class Stack {
    public:
        int* arr;
        int top;
        int size;
    
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if(top == size - 1) std::cout << "Stack Overflow" << std::endl;
        else {
            top++;
            arr[top] = data;
        }
    }

    void pop() {
        if(top == -1) std::cout << "Stack Underflow" << std::endl;
        else {
            top--;
        }
    }

    int peek() {
        if(top == -1) {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        }
        else return arr[top];
    }

    bool empty() {
        if(top == -1) return true;
        else return false;
    }
};

int main() {
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    std::cout << st.peek() << std::endl;
    std::cout << std::boolalpha;
    std::cout << st.empty() << std::endl;
    // std::cout << std::noboolalpha;
    
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    std::cout << st.peek() << std::endl;
    
    std::cout << st.empty() << std::endl;

    return 0;
}