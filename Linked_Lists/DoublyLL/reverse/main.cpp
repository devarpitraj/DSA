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

// Recursive Approach
Node* reverseR(Node* head) {
    if(head == NULL || head -> next == NULL) {
        head -> prev = NULL;
        return head;
    } 
    
    Node* chotaHead = reverseR(head -> next);
    head -> next -> next = head;
    head -> prev = head -> next;
    head -> next = NULL;

    return chotaHead;
}

int main() {
    Node* head = NULL;

    insertAtPos(head, 10, 1);
    print(head);

    insertAtPos(head, 20, 1);
    insertAtPos(head, 30, 1);
    insertAtPos(head, 40, 1);
    insertAtPos(head, 50, 1);
    print(head);

    // Recursive Approach
    head = reverseR(head);
    print(head);

    while(head) {
        if(head -> prev == NULL) {
            std::cout << "NULL" << " ";
        } else 
            std::cout << head -> prev -> data << " ";
        head = head -> next;
    }
    std::cout << std::endl;

    return 0;
}