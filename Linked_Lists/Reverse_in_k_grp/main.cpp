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

int getlength(Node* head) {
    int len{};
    while(head) {
        len++;
        head = head -> next;
    }
    return len;
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

Node* reverse(Node* head, int k, int times) {
    if(times > 0) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        int cnt{};

        while(cnt++ < k) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head -> next = reverse(next, k, times - 1);

        return prev;
    } else {
        return head;
    }
}


int main() {
    Node* head = NULL;
    insertAtPos(head, 10, 1);
    insertAtPos(head, 20, 1);
    insertAtPos(head, 30, 1);
    insertAtPos(head, 40, 1);
    insertAtPos(head, 50, 1);
    insertAtPos(head, 60, 1);
    print(head);

    std::cout << getlength(head) << std::endl;

    int k = 2;
    int len = getlength(head);
    int times = len / k;

    head = reverse(head, k, times);
    print(head);

    return 0;
}