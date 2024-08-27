#include<iostream>
#include<vector>
#include<queue>

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            right = left = NULL;
        }
};

Node* buildTree(std::vector<int> in, int s, int e) {
    if(s > e) return NULL;

    int mid = s + (e - s) / 2;
    Node* root = new Node(in[mid]);

    root -> left = buildTree(in, s, mid - 1);
    root -> right = buildTree(in, mid + 1, e);

    return root;
}

void lvlOrdertraversal(Node* root) {
    std::queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            std::cout << std::endl;
            if(!q.empty()) q.push(NULL);
        } else {
            std::cout << front -> data << " ";
            if(front -> left) q.push(front -> left);
            if(front -> right) q.push(front -> right);
        }
    }
}

void inorder(Node* root, std::vector<int>& in) {
    if(root == NULL) return;

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

void flattenBST(Node* root, Node* &head) {
    if(root == NULL) return;

    flattenBST(root -> right, head);

    root -> right = head;
    head = root;

    flattenBST(root -> left, head);
    root -> left = NULL;
}

int countNodes(Node* head) {
    int n{};
    Node* temp = head;
    while(temp != NULL) {
        n = n + 1;
        temp = temp -> right;
    }
    return n;
}

Node* sortedLLtoBST(Node* head, int s, int e) {
        if (s > e)
        return NULL;

        int mid = (s + e) / 2;
        Node* leftNode = sortedLLtoBST(head, s, mid - 1);
        Node* root = new Node(head->data);
        root->left = leftNode;
        if (head->right != NULL) {
            head->data = head->right->data;
            head->right = head->right->right;
        }
        root->right = sortedLLtoBST(head, mid + 1, e);
        return root;
}

int main() {
    std::vector<int> in;
    std::cout << "Enter inorder for a BST (End with -1) : ";

    int data;
    std::cin >> data;
    while(data != -1) {
        in.push_back(data);
        std::cin >> data;
    }

    Node* root = NULL;
    root = buildTree(in, 0, in.size() - 1);

    lvlOrdertraversal(root);

    Node* head = NULL;
    flattenBST(root, head);

    // lvlOrdertraversal(head);

    // std::cout << "No. of Nodes = " << countNodes(head) << std::endl;

    // std::vector<int> inord;
    // inorder(head, inord);
    // for(auto i : inord) std::cout << i << " ";
    // std::cout << std::endl;

    Node* temp = sortedLLtoBST(head, 0, countNodes(head) - 1);

    std::vector<int> out;
    inorder(temp, out);
    for(auto i : out) std::cout << i << " ";
    std::cout << std::endl;
    // std::cout << "No. of Nodes = " << countNodes(temp) << std::endl;

    return 0;
}