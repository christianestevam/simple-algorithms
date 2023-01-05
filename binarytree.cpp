#include <iostream>
#include <vector>
#include <queue>

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
    void printLevelOrder() {
        if (root == NULL) {
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *current = q.front();
            cout << current->value << " ";
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
            q.pop();
        }
    }
};

int main() {
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.print();
    cout << endl;
    tree.printLevelOrder();
    cout << endl;
    return 0;
}