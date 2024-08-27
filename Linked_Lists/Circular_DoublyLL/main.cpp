#include<iostream>

class Node {
    public:
        Node* prev;
        int data;
        Node* next;

        Node(int data) {
            this -> data = data;
            prev = NULL;
            next = NULL;
        }
};

void print(Node* tail) {
    Node* temp = tail -> next;

    do{
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != tail -> next);
    std::cout << std::endl;
}

int getLength(Node* tail) {
    Node* temp = tail -> next;
    int len{};

    do{
        len++;
        temp = temp -> next;
    }while(temp != tail -> next);
    
    return len;
}

void insertAtPos(Node* &tail, int data, int pos) {
    Node* temp = new Node(data);

    // empty list
    if(tail == NULL) {
        tail = temp;
        temp -> prev = temp;
        temp -> next = temp;
        return;
    }

    // inserting at first
    if(pos == 1) {
        temp -> next = tail -> next;
        tail -> next -> prev = temp;
        temp -> prev = temp;
        tail -> next = temp;
        return;
    }

    int cnt{1};
    Node* bef = tail -> next;
    while(cnt < pos - 1) {
        cnt++;
        bef = bef -> next;
    }
    temp -> next = bef -> next;
    temp -> prev = bef;
    bef -> next -> prev = temp;
    bef -> next = temp;
    if(bef == tail) {
        tail = temp;
    }
}

void deleteAtPos(Node* &tail, int pos) {
    //empty list
    if(tail == NULL) {
        std::cout << "Empty list" << std::endl;
        return;
    }
        
    // single node list
    if(getLength(tail) == 1) {
        tail -> next = tail -> prev = NULL;
        tail = NULL;
        return;
    }

    // (>= 2) node list
    if(pos == 1) {
        Node* temp = tail -> next;
        tail -> next = temp -> next;
        temp -> next -> prev = tail; 
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }
    else {
        int cnt{1};
        Node* bef = tail -> next;
        while(cnt < pos - 1) {
            cnt++;
            bef = bef -> next;
        }
        Node* temp = bef -> next;
        if(bef -> next == tail) tail = bef;
        bef -> next = temp -> next;
        temp -> next -> prev = bef;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }
}

int main() {
    Node* tail = NULL;

    insertAtPos(tail, 10, 1);
    print(tail);

    insertAtPos(tail, 20, 1);
    insertAtPos(tail, 30, 1);
    insertAtPos(tail, 40, 1);
    print(tail);

    std::cout << "Length of list = " << getLength(tail) << std::endl;

    insertAtPos(tail, 90, getLength(tail) + 1);
    print(tail);

    insertAtPos(tail, 100, getLength(tail) + 1);
    insertAtPos(tail, 110, getLength(tail) + 1);
    print(tail);

    insertAtPos(tail, 17, 3);
    print(tail);

    insertAtPos(tail, 63, 6);
    insertAtPos(tail, 52, 5);
    print(tail);

    deleteAtPos(tail, 1);
    print(tail);

    deleteAtPos(tail, getLength(tail));
    print(tail);

    deleteAtPos(tail, 4);
    print(tail);

    return 0;

}