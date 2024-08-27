#include<iostream>

class Node {
    public:
        int data;
        Node* next;

        Node() {}

        Node(int data) {
            this -> data = data;
            next = NULL;
        }
};

class Stack : public Node {
    public:
        Node* top;
        Node* head;

        Stack() {
            top = NULL;
            head = NULL;
        }

        void push(int data) {
            Node* temp = new Node(data);
            if(top == NULL) top = head = temp;
            else {
                top -> next = temp;
                top = temp;
            }
        }

        void pop() {
            if(top == NULL) {
                std::cout << "Stack Underflow" << std::endl;
                return;
            } else {
                Node* temp = head;

                // deleting first node
                if(top == head) {
                    top = NULL;
                    delete temp;
                    return;
                }

                while(temp -> next != top) temp = temp -> next;

                Node* del = top;
                top = temp;
                delete del;
            }
        }

        int peek() {
            if(top == NULL) {
                std::cout << "Stack Underflow" << std::endl;
                return -1;
            }
            else {
                return top -> data;
            }
        }

        bool empty() {
            if(top == NULL) return 1;
            else return 0;
        }
};

int main() {
    Stack st;

    st.push(10);
    std::cout << st.peek() << std::endl;

    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    std::cout << st.peek() << std::endl;

    std::cout << std::boolalpha;
    std::cout << st.empty() << std::endl;

    st.pop();
    std::cout << st.peek() << std::endl;

    st.pop();
    std::cout << st.peek() << std::endl;
    st.pop();
    std::cout << st.peek() << std::endl;

    st.pop();
    std::cout << st.peek() << std::endl;

    st.pop();
    std::cout << st.peek() << std::endl;

    std::cout << st.empty() << std::endl;
    
    return 0;
}