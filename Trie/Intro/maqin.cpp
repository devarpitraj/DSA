#include<iostream>
#include<string>

class TrieNode {
    public:
        char ch;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            this -> ch = ch;
            for(int i = 0; i < 26; i++) children[i] = NULL;
            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, std::string word) {
            // base case
            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }

            // all chars are assumed to be uppercase
            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            } else { // absent
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            // recursive call
            insertUtil(child, word.substr(1));
        }

        void insert(std::string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, std::string word) {
            // base case
            if(word.length() == 0) {
                return root -> isTerminal;
            }

            int index = word[0] -'A';
            TrieNode* child;

            // present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            } else { // absent
                return false;
            }

            // recursive call
            return searchUtil(child, word.substr(1));
        }

        bool search(std::string word) {
            return searchUtil(root, word);
        }

        bool isEmpty(TrieNode* root) {
            for(int i = 0; i < 26; i++) {
                if(root -> children[i]) return false;
            }
            return true;
        }

        void removeUtil(TrieNode* root, std::string word) {
            // base case
            if(word.length() == 0) {
                if(root -> isTerminal) {
                    root -> isTerminal = false;
                    std::cout << "Deleted" << std::endl;
                }
                else {
                    std::cout << "Word Not found" << std::endl;
                }
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            } else {
                std::cout << "Word not found" << std::endl;
                return;
            }

            // recursive call
            removeUtil(child, word.substr(1));
        }

        void remove(std::string word) {
            removeUtil(root, word);
        }

        void printchildren(TrieNode* root) {
            for(int i = 0; i < 26; i++) {
                std::cout << char(i + 'A') << " : " << (root -> children[i]) << std::endl;
            }
        }
};

int main() {
    Trie* t = new Trie;

    t -> insert("ARM");
    t -> insert("ARE");
    t -> insert("TIME");

    std::cout << "Present or not " << t -> search("ARM") << std::endl;
    std::cout << "Present or not " << t -> search("ARMY") << std::endl;
    std::cout << "Present or not " << t -> search("TIM") << std::endl;
    std::cout << "Present or not " << t -> search("TIME") << std::endl;

    t -> remove("ARM");
    t -> remove("ARM");
    t -> remove("TIM");
    t -> remove("TIME");

    t -> insert("TIME");
    std::cout << "Present or not " << t -> search("TIME") << std::endl;
    t -> insert("TIM");
    std::cout << "Present or not " << t -> search("TIM") << std::endl;

    t -> remove("TIME");
    std::cout << "Present or not " << t -> search("TIME") << std::endl;
    std::cout << "Present or not " << t -> search("TIM") << std::endl;
    
    return 0;
}