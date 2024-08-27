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

void print(Node* &head) {
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

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);

    tail -> next = temp;
    tail = temp;
}

void insertAtPos(Node* &head, int data, int pos) {
    Node* temp = new Node(data);

    // insert at start
    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* prev = head;
    int cnt{1};
    while(cnt != pos - 1) {
        cnt++;
        prev = prev -> next;

        // invalid position
        if(prev == NULL) {
            std::cerr << "Invalid Position" << std::endl;
            return;
        }

        // insert at last position
        // if(prev -> next == NULL) {
        //     insertAtTail(tail, data);
        //     // pass the tail arg also
        //     return;
        // }
    }

    temp -> next = prev -> next;
    prev -> next = temp;
}

void deleteAtPos(Node* &head, int pos) {
    Node* prev = head;
    int cnt{1};

    // deleting first pos
    if(cnt == pos) {
        Node* temp = head;
        head = head -> next;

        temp -> next = NULL;
        delete temp;
        return;
    }

    while(cnt < pos - 1) {
        cnt++;
        prev = prev -> next;
    }

    Node* temp = prev -> next;
    prev -> next = temp -> next;

    temp -> next = NULL;
    delete temp;
}

int main() {
    Node* n1 = new Node(10);

    Node* head = n1;
    Node* tail = head;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
    insertAtHead(head, 20);
    print(head);

    insertAtTail(tail, 19);
    print(head);

    insertAtTail(tail, 25);
    insertAtTail(tail, 27);
    print(head);

    insertAtPos(head, 170, 3);
    print(head);

    insertAtPos(head, 200, 5);
    print(head);

    //invalid position
    insertAtPos(head, 1290, 70);

    insertAtPos(head, 400, 1);
    print(head);

    std::cout << std::endl;

    deleteAtPos(head, 3);
    print(head);

    // deleting last pos
    deleteAtPos(head, 9);
    print(head);

    //deleting first pos
    deleteAtPos(head, 1);
    print(head);

    return 0;
}