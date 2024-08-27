#include<iostream>

class Node {
    public:
        Node* prev;
        int data;
        Node* next;

        Node(int data) {
            this -> prev = NULL;
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

int getLength(Node* head) {
    Node* temp = head;
    int len{};

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

    return len;
}

void insertAtPos(Node* &head, int data, int pos) {
    Node* temp = new Node(data);
    int cnt{1};

    // empty list
    if(head == NULL) {
        Node* temp = new Node(data);
        head = temp;
        return;
    }

    // inserting at first pos
    if(cnt == pos) {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
        return;
    }

    Node* before = head;
    while(cnt < pos - 1) {
        cnt++;
        before = before -> next;
    }

    // inserting at last pos
    if(before -> next == NULL) {
        temp -> prev = before;
        before -> next = temp;
    }
    else {
        temp -> next = before -> next;
        before -> next -> prev = temp;
        temp -> prev = before;
        before -> next = temp;
    }
    
}

void deleteAtPos(Node* &head, int pos) {
    Node* before = head;
    int cnt{1};

    // deleting first node
    if(cnt == pos) {
        Node* temp = head;
        head = head -> next;

        temp -> prev = NULL;
        temp -> next = NULL;
        delete temp;

        return;
    }

    while(cnt < pos - 1) {
        cnt++;
        before = before -> next;
    }

    // deleting last node
    if(before -> next -> next == NULL) {
        Node* temp = before -> next;
        before -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    } 

    else {
        Node* temp = before -> next;

        before -> next = temp -> next;
        temp -> next -> prev = before;

        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }
}

int main() {
    Node* head = NULL;
    print(head);
    insertAtPos(head, 10, 1);
    print(head);

    int length = getLength(head);
    std::cout << "Length of list = " << length << std::endl;

    std::cout << std::endl;

    // inserting at start
    insertAtPos(head, 20, 1);
    print(head);

    insertAtPos(head, 30, 1);
    insertAtPos(head, 40, 1);
    print(head);

    // inserting at end
    insertAtPos(head, 17, getLength(head) + 1);
    print(head);

    insertAtPos(head, 19, getLength(head) + 1);
    insertAtPos(head, 21, getLength(head) + 1);
    print(head);

    //inserting at particulat pos
    insertAtPos(head, 80, 3);
    print(head);

    insertAtPos(head, 90, 5);
    insertAtPos(head, 100, 7);
    print(head);

    std::cout << std::endl;

    // deleting fisrt node
    deleteAtPos(head, 1);
    print(head);

    // deleting last node
    deleteAtPos(head, getLength(head));
    print(head);

    // deleting any pos
    deleteAtPos(head, 4);
    print(head);

    return 0;
}