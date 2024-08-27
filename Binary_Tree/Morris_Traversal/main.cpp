#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

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

void print(Node* root) {
    std::cout << root -> data << " ";
}

Node* findPred(Node* root) {
    Node* curr = root;
    curr = curr -> left;
    while(curr -> right != NULL && curr -> right != root) {
        curr = curr -> right;
    }
    return curr;
}

void morrisTraversalInorder(Node* root) {
    Node* curr = root;

    while(curr != NULL) {
        if(curr -> left == NULL) {
            print(curr);
            curr = curr -> right;
        }

        else {
            Node* pred = findPred(curr);

            if(pred -> right == NULL) {
                pred -> right = curr;
                curr = curr -> left;
            } else {
                pred -> right = NULL;
                print(curr);
                curr = curr -> right;
            }
        }
    }
}

void Improper_morrisTraversalPreorder(Node* root) {
    Node* curr = root;

    while(curr != NULL) {
        print(curr);
        if(curr -> left == NULL) {
            curr = curr -> right;
        }

        else {
            Node* pred = findPred(curr);

            if(pred -> right == NULL) {
                pred -> right = curr -> right;
                curr = curr -> left;
            } else {
                pred -> right = NULL;
                curr = curr -> right;
            }
        }
    }
}

Node* findPredforPost(Node* root) {
    Node* curr = root;
    curr = curr -> right;
    while(curr -> left != NULL && curr -> left != root) {
        curr = curr -> left;
    }
    return curr;
}

std::vector<int> morrisTraversalPostorder(Node* root) {
    std::vector<int> ans;
    Node* curr = root;

    while(curr != NULL) {
        if(curr -> right == NULL) {
            ans.push_back(curr -> data);
            curr = curr -> left;
        }

        else {
            Node* pred = findPredforPost(curr);

            if(pred -> left == NULL) {
                ans.push_back(curr -> data);
                pred -> left = curr;
                curr = curr -> right;
            } else {
                pred -> left = NULL;
                curr = curr -> left;
            }
        }
    }

    std::reverse(ans.begin(), ans.end());

    return ans;
}

void morrisTraversalPreorder(Node* root) {
    Node* curr = root;

    while(curr != NULL) {
        if(curr -> left == NULL) {
            print(curr);
            curr = curr -> right;
        } else {
            Node* pred = findPred(curr);

            if(pred -> right == curr) {
                pred -> right = NULL;
                curr = curr -> right;
            } else {
                print(curr);
                pred -> right = curr;
                curr = curr -> left;
            }
        }
    }
}

int main() {
    Node* root = NULL;
    buildfromlvlorder(root);
    std::cout << std::endl;

    std::cout << "Inorder : ";
    morrisTraversalInorder(root);
    std::cout << std:: endl;

    std::cout << "Postorder : ";
    std::vector<int> ans = morrisTraversalPostorder(root);
    for(auto i : ans) std::cout << i << " ";
    std::cout << std:: endl;

    // std::cout << "Preorder : ";
    // Improper_morrisTraversalPreorder(root);
    // std::cout << std:: endl;
    // warning : pre-order traversal changed links

    std::cout << "Preorder : ";
    morrisTraversalPreorder(root);
    std::cout << std:: endl;

    return 0;
}