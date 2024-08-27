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

void lvlOrderTraversal(Node* root) {
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            std::cout << std::endl;
            if(!q.empty()) q.push(NULL);
        } else {
            std::cout << temp -> data << " ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
}

Node* delete_node(Node* root, int key) {
    // base case
    if(root == NULL) return NULL;

    if(root -> data == key) {
        // 0 child
        if(!root -> left && !root -> right) {
            delete root;
            return NULL;
        }

        // 1 child

        // Left Child
        if(root -> left && !root -> right) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // Right Child
        if(!root -> left && root -> right) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 Child
        if(root -> left && root -> right) {
            // 1st way
            // int mini;
            // Node* temp = root -> right;
            // while(temp -> left) temp = temp -> left;
            // mini = temp -> data;

            // root -> data = mini;
            // root -> right = delete_node(root -> right, mini);

            // 2nd way
            int maxi;
            Node* temp = root -> left;
            while(temp -> right) temp = temp -> right;
            maxi = temp -> data;

            root -> data = maxi;
            root -> left = delete_node(root -> left, maxi);
        }
    }

    else if(root -> data > key) {
        root -> left = delete_node(root -> left, key);
    }

    else {
        root -> right = delete_node(root -> right, key);
    }

    return root;
}

int main() {
    Node* root = NULL;
    std::cout << "Enter values in BST : ";
    takeInput(root);
    lvlOrderTraversal(root);
    std::cout << std::endl;

    root = delete_node(root, 100);
    std::cout << std::endl;
    lvlOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}