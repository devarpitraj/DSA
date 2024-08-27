#include<iostream>
#include<queue>

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

Node* buildTree(Node* root) {
    int n;
    std::cout << "Enter data for the current Node : ";
    std::cin >> n;

    if(n == -1) return NULL;

    root = new Node(n);

    std::cout << "Enter data to put in left of " << root -> data << std::endl;
    root -> left = buildTree(root -> left);

    std::cout << "Enter data to put in right of " << root -> data << std::endl;
    root -> right = buildTree(root -> right);

    return root;
}

void buildfromlvlorder(Node* &root) {
    std::queue<Node*> q;

    std::cout << "Enter data for current Node : ";
    int data;
    std::cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        std::cout << "Enter data for leftNode of " << temp -> data << " : ";
        int leftData;
        std::cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }
        
        std::cout << "Enter data for rightNode of " << temp -> data << " : ";
        int rightData;
        std::cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}

void lvlOrderTraversal(Node* root) {
    std::queue<Node*> q;
    q.push(root);

    q.push(NULL); // using seperator to print in levels

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

int main() {
    Node* root = NULL;

    buildfromlvlorder(root);
    lvlOrderTraversal(root);

    // root = buildTree(root);

    // lvlOrderTraversal(root);

    std::cout << "Inorder Traversal :";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal :";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal :";
    postorder(root);
    std::cout << std::endl;

    return 0;
}