#include<iostream>

class Node {
    public:
        int data;
        Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;
}

void insertAtHead(Node* &head, int data) {
    // reference of head is needed because
    // we want to add at the same address
    // if we passed by value then a copy would be
    // created and node will be added at that position

    Node* temp = new Node(data);

    temp -> next = head;
    head = temp;
}

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

int main() {
    Node* head = new Node(10);

    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    print(head);

    Node* mid = findMid(head);
    std::cout << mid -> data << std::endl;

    insertAtHead(head, 50);
    print(head);

    mid = findMid(head);
    std::cout << mid -> data << std::endl;

    return 0;
}