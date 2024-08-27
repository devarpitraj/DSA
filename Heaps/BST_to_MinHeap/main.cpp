#include<iostream>
#include<vector>
#include<queue>

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            data = d;
            left = right = NULL;
        }
};

void completeBST(Node* &root) {
    root = new Node(4);

    root -> left = new Node(2);
    root -> right = new Node(6);

    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);

    root -> right -> left = new Node(5);
    root -> right -> right = new Node(7);
}

void inorder(Node* root, std::vector<int>& in) {
    if(root == NULL) return;

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

void buildHeapfromPreorder(std::vector<int> in, Node* &root, int& index) {
    if(root == NULL) return;

    root -> data = in[index++];

    buildHeapfromPreorder(in, root -> left, index);

    buildHeapfromPreorder(in, root -> right, index);
}

void preorder(Node* root, std::vector<int>& pre) {
    if(root == NULL) return;

    pre.push_back(root -> data);
    preorder(root -> left, pre);
    preorder(root -> right, pre);
}

int main() {
    // given :- complete BST
    Node* root = NULL;
    completeBST(root);

    std::vector<int> inBST;
    inorder(root, inBST);

    std::cout << "Inorder of BST : ";
    for(auto i : inBST) std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> preBST;
    preorder(root, preBST);

    std::cout << "Preorder of BST : ";
    for(auto i : preBST) std::cout << i << " ";
    std::cout << std::endl;

    // this inorder is preorder for the heap
    // thus buildTree from preorder
    int index = 0;
    buildHeapfromPreorder(inBST, root, index);

    std::vector<int> preHeap;
    preorder(root, preHeap);

    std::cout << "Preorder of MinHeap : ";
    for(auto i : preHeap) std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> inHeap;
    inorder(root, inHeap);

    std::cout << "Inorder of MinHeap : ";
    for(auto i : inHeap) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}