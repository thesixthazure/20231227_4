#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* l;
    Node* r;

    Node(int x) : data(x), l(nullptr), r(nullptr) {}
};

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int lh = getHeight(root->l);
        int rh = getHeight(root->r);
        return (lh > rh) ? (lh + 1) : (rh + 1);
    }
}

void print(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        print(root->l);
        print(root->r);
    }
}

bool fullTree(Node* root, int height, int depth) {
    if (root == NULL) {
        return true;
    }
    if (root->l == NULL && root->r == NULL) {
        return (height == depth);
    }
    if (root->l && root->r) {
        return fullTree(root->l, height, depth + 1) && fullTree(root->r, height, depth + 1);
    }
    return false;
}
//完全
bool wanquan_tree(Node* root, int index, int nodeCount) {
    if (root == NULL) {
        return true;
    }
    if (index >= nodeCount) {
        return false;
    }
    return (wanquan_tree(root->l, 2 * index + 1, nodeCount) && wanquan_tree(root->r, 2 * index + 2, nodeCount));
}


int main() {
    // 创建二叉树
    Node* root = new Node(1);
    root->l = new Node(2);
    root->r = new Node(3);
    root->l->l = new Node(4);
    //root->left->right = new Node(5);

    //print(root);
    int height = getHeight(root);

    if (fullTree(root, height, 1)) {
        printf("是满二叉树\n");
    }
    else {
        printf("不是满二叉树\n");
    }
   
    int nodeCount = 4;
    if (wanquan_tree(root, 0, nodeCount)) {
        printf("是完全二叉树\n");
    }
    else {
        printf("不是完全二叉树\n");
    }
    return 0;
}