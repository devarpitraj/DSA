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

Node* divide(Node* &head, int k) {
    Node* temp = head;
    int cnt{};

    while(cnt++ < k) {
        temp = temp -> next;
    }
    Node* head2 = temp -> next;
    temp -> next = head;
    return head2;
}

int main() {
    Node* tail = NULL;
    insertAtPos(tail, 10, 1);
    insertAtPos(tail, 20, 1);
    insertAtPos(tail, 30, 1);
    insertAtPos(tail, 40, 1);
    insertAtPos(tail, 50, 1);
    print(tail);

    std::cout << tail -> next -> data << std::endl;

    int len = getLength(tail);
    int k = len / 2;

    Node* tail1 = tail -> next;

    Node* head2 = divide(tail -> next, k);
    int cnt{};

    Node* tail2 = head2;
    while(cnt++ < (len - k - 1) - 1) {
        tail2 = tail2 -> next;
    }
    tail2 -> next = head2;

    Node* temp = tail1;
    while(temp -> next != tail1) temp = temp -> next;
    tail1 = temp;
    
    print(tail1);
    std::cout << tail -> next -> data << std::endl;

    print(tail2);
    std::cout << tail2 -> next -> data << std::endl;

    return 0;
}