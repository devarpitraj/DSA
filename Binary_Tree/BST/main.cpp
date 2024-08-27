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

void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root -> left);
    std::cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node* root) {
    if(root == NULL) return;

    std::cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root) {
    if(root == NULL) return;

    postorder(root -> left);
    postorder(root -> right);
    std::cout << root -> data << " ";
}

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

int minVal(Node* root) {
    Node* curr = root;
    while(curr -> left) curr = curr -> left;
    return curr -> data;
}

int maxVal(Node* root) {
    Node* curr = root;
    while(curr -> right) curr = curr -> right;
    return curr -> data;
}

int main() {
    Node* root = NULL;

    std::cout << "Enter data in BST (end with -1) :-" << std::endl;
    takeInput(root);

    std::cout << "Level Order BST : " << std::endl;;
    lvlOrderTraversal(root);

    std::cout << "Inorder BST : ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Preorder BST : ";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Postorder BST : ";
    postorder(root);
    std::cout << std::endl;

    std::cout << "Minimum val in BST : " << minVal(root) << std::endl;
    std::cout << "Maximum val in BST : " << maxVal(root) << std::endl;

    return 0;
}