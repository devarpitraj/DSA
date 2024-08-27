#include<iostream>

class Node {
    public:
        int data;
        Node* next;
    
        // constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

int main() {
    Node* n1 = new Node(10);
    std::cout << n1 -> data << std::endl;
    std::cout << n1 -> next << std::endl;

    return 0;
}