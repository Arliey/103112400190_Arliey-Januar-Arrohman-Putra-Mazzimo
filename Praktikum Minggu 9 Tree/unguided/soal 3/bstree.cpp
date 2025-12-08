#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(int x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

int main() {
    address root = NULL;
    root = alokasi(6);

    root->left = alokasi(4);
    root->right = alokasi(7);

    root->left->left = alokasi(2);
    root->left->right = alokasi(5);
    root->left->left->left = alokasi(1); 
    root->left->left->right = alokasi(3);

    cout << "Pre-Order traversal  : ";
    preOrder(root);
    cout << endl;

    cout << "Post-Order traversal : ";
    postOrder(root);
    cout << endl;

    return 0;
}