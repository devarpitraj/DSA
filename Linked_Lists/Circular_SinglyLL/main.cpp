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

void print(Node* tail) {
    if(tail == NULL) {
        std::cout << "Empty List" << std::endl;
        return;
    }

    Node* temp = tail -> next;

    do {
        std::cout << temp -> data << " ";
        temp = temp -> next;
    } while(temp != tail -> next);
    std::cout << std:: endl;
}

int getLength(Node* tail) {
    Node* temp = tail -> next;
    int len{};
    
    do {
        len++;
        temp = temp -> next;
    } while(temp != tail -> next);

    return len;
}

void insertAtPos(Node* &tail, int data, int pos) {
    Node* temp = new Node(data);

    // empty list
    if(tail == NULL) {
        // Node* temp = new Node(data);
        tail = temp;
        tail -> next = tail;
        return;
    }

    // insert at first
    int cnt{1};
    if(cnt == pos) {
        // Node* temp = new Node(data);
        temp -> next = tail -> next;
        tail -> next = temp;
        return;
    }

    // Node* temp = new Node(data);
    Node* prev = tail -> next;
    while(cnt < pos - 1) {
        cnt++;
        prev = prev -> next;
    }
    // insert at last
    if(prev == tail) {
        temp -> next = tail -> next;
        tail -> next = temp;
        tail = temp;
    } else {
        temp -> next = prev -> next;
        prev -> next = temp;
    }
}

void deleteAtPos(Node* &tail, int pos) {
    int cnt{1};
    Node* prev = tail -> next;

    if(cnt == pos) {
        if(getLength(tail) == 1) {
            tail -> next == NULL;
            tail = NULL;
        } else {
            Node* temp = tail -> next;
            tail -> next = temp -> next;
            temp -> next = NULL;
            delete temp;
        }
        return;
    }

    while(cnt < pos - 1) {
        cnt++;
        prev = prev -> next;
    }

    Node* temp = prev -> next;
    if(prev -> next == tail) tail = prev;
    prev -> next = temp -> next;
    temp -> next = NULL;
    // if(prev -> next == tail) tail = prev;
    delete temp;
}

int main() {
    Node* tail = NULL;

    insertAtPos(tail, 10, 1);
    print(tail);

    insertAtPos(tail, 20, 1);
    insertAtPos(tail, 30, 1);
    print(tail);

    std::cout << "Length of list = " << getLength(tail) << std::endl;

    insertAtPos(tail, 50, getLength(tail) + 1);
    print(tail);

    insertAtPos(tail, 60, getLength(tail) + 1);
    insertAtPos(tail, 70, getLength(tail) + 1);
    print(tail);

    insertAtPos(tail, 24, 5);
    print(tail);

    insertAtPos(tail, 27, 3);
    insertAtPos(tail, 16, 3);
    print(tail);

    deleteAtPos(tail, 1);
    print(tail);

    deleteAtPos(tail, 3);
    print(tail);

    deleteAtPos(tail, getLength(tail));
    print(tail);

    deleteAtPos(tail, getLength(tail));
    deleteAtPos(tail, getLength(tail));
    print(tail);

    std::cout << std::endl;

    Node* tail2 = NULL;
    print(tail2);

    insertAtPos(tail2, 91, 1);
    print(tail2);

    deleteAtPos(tail2, 1);
    print(tail2);

    return 0;
}