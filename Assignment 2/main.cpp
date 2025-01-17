#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Height of Node
int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Find the difference in height between left and right sub-trees
int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Update the height after balancing
void updateHeight(Node* node) {
    if (node == nullptr)
        return;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right Rotate
Node* rightRotate(Node* root) {
    Node* temp1 = root->left;
    Node* temp2 = temp1->right;

    temp1->right = root;
    root->left = temp2;

    updateHeight(root);
    updateHeight(temp1);

    return temp1;
}

// Left Rotate
Node* leftRotate(Node* root) {
    Node* temp1 = root->right;
    Node* temp2 = temp1->left;

    temp1->left = root;
    root->right = temp2;

    updateHeight(root);
    updateHeight(temp1);

    return temp1;
}

// Insertion
Node* insert(Node* root, int key) {
    if (root == nullptr) //If it's empty, create a new one
        return new Node{key, nullptr, nullptr, 1}; 

    if (key < root->key) //Go left side for lesser
        root->left = insert(root->left, key);
    else if (key > root->key) //Go right side for more
        root->right = insert(root->right, key);
    else
        return root;

    // Update height after insertion
    updateHeight(root);

    // Check the balance in case rotations are required
    int balance = getBalanceFactor(root);

    // Left Heavy (LL or LR)
    if (balance > 1) {
        if (key < root->left->key) {
            return rightRotate(root); // LL
        } else {
            root->left = leftRotate(root->left);
            return rightRotate(root); // LR
        }
    }

    // Right Heavy (RR or RL)
    if (balance < -1) {
        if (key > root->right->key) {
            return leftRotate(root); // RR
        } else {
            root->right = rightRotate(root->right);
            return leftRotate(root); // RL
        }
    }

    return root;
}

// Max value for inserting after deletion
Node* findMaxValueNode(Node* root) {
    Node* current = root;
    while (current->right != nullptr)
        current = current->right;
    return current;
}

// Deletion
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Case when there is one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        } else {
            Node* temp = findMaxValueNode(root->left);
            root->key = temp->key;
            root->left = deleteNode(root->left, temp->key); //Go left as that's how the grading system works
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // Update height and balance factor of the current node
    updateHeight(root);

    // Check if the node became unbalanced
    int balance = getBalanceFactor(root);

    // Left Heavy (LL or LR)
    if (balance > 1) {
        if (getBalanceFactor(root->left) >= 0)
            return rightRotate(root); // LL
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root); // LR
        }
    }

    // Right Heavy (RR or RL)
    if (balance < -1) {
        if (getBalanceFactor(root->right) <= 0)
            return leftRotate(root); // RR
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root); // RL
        }
    }

    return root;
}

// Pre-order
void printPreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Post-order
void printPostOrder(Node* root) {
    if (root != nullptr) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->key << " ";
    }
}

// In-order
void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->key << " ";
        printInOrder(root->right);
    }
}

bool isEmpty(Node* root) {
    return root == nullptr;
}

int main() {
    Node* root = nullptr;

    string input;
    getline(cin, input);

    istringstream iss(input);
    vector<string> words;
    string word;
    string operation;
    while (iss >> word) {
        words.push_back(word);
    }
    // sourced this kind of input handling from the internet for using istringstream
    
    for (const string& w : words) {
        char firstLetter = w[0];
        int value;

        if(firstLetter == 'A'){
            value = stoi(w.substr(1));
            root = insert(root,value);
        }
        else if (firstLetter == 'D'){
            value = stoi(w.substr(1));
            root = deleteNode(root,value);
        }
        else {
            operation = w;
        }
    }

    if(isEmpty(root)){
        cout <<"EMPTY" << endl;
    }
    else if(operation == "PRE"){
        printPreOrder(root);
    } else if(operation == "IN"){
        printInOrder(root);
    } else if(operation == "POST"){
        printPostOrder(root);
    }
    return 0;
}