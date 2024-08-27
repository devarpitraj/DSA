#include<iostream>
#include<queue>

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

void insertInBST(Node* &root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return;
    }

    if(data > root -> data) insertInBST(root -> right, data);
    if(data < root -> data) insertInBST(root -> left, data);
}

void takeInput(Node* &root) {
    int data;
    std::cin >> data;

    while(data != -1) {
        insertInBST(root, data);
        std::cin >> data;
    }
}

void inorder_pred_and_succ(Node* root, Node* &pred, Node* &succ, int key) {
    // base case
    if(root == NULL) return;

    // if key is at root
    if(root -> data == key) {

        // maximum in left-subtree is the predecessor
        if(root -> left != NULL) {
            Node* temp = root -> left;
            while(temp -> right) temp -> right;

            pred = temp;
        }

        // minimum in right-subtree is the successor
        if(root -> right != NULL) {
            Node* temp = root -> right;
            while(temp -> left) temp = temp -> left;

            succ = temp;
        }
    }

    // if key is < root -> data
    else if(key < root -> data) {
        succ = root;
        inorder_pred_and_succ(root -> left, pred, succ, key);
    }

    else {
        pred = root;
        inorder_pred_and_succ(root -> right, pred, succ, key);
    }
}

int main() {
    Node* root = NULL;
    std::cout << "Enter values: ";
    takeInput(root);

    int key;
    std::cout << "Enter key ";
    std::cin >> key;

    Node* pred = NULL;
    Node* succ = NULL;

    inorder_pred_and_succ(root, pred, succ, key);

    std::cout << "Inorder Predecessor of " << key << " is : " << ((pred == NULL) ? -1 : pred -> data) << std::endl;
    std::cout << "Inorder Successor of " << key << " is : " << ((succ == NULL) ? -1 : succ -> data) << std::endl;

    return 0;
}
