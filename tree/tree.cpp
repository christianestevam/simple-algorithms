#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    Node(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node *root;
    Tree() {
        root = NULL;
    }
    void insert(int value) {
        if (root == NULL) {
            root = new Node(value);
        } else {
            Node *current = root;
            while (true) {
                if (value < current->value) {
                    if (current->left == NULL) {
                        current->left = new Node(value);
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = new Node(value);
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }
    void print() {
        print(root);
    }
    void print(Node *node) {
        if (node != NULL) {
            print(node->left);
            cout << node->value << " ";
            print(node->right);
        }
    }
};

int main() {
    Tree tree;
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(5);
    tree.insert(4);
    tree.print();
    cout << endl;
    return 0;
}