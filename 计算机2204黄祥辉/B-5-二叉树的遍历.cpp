#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<stack>
#include<vector>

using namespace std;

stack<int> st;
vector<int> res;

struct Node {
    int data;
    Node* l;
    Node* r;

    Node(int x) : data(x), l(nullptr), r(nullptr) {}
};



void preprint(Node* root) {
    if (root != nullptr) {
        //cout << root->data << " ";
        st.push(root->data);
        preprint(root->l);
        preprint(root->r);
    }
}

void inprint(Node* root) {
    if (root != nullptr) {
        //cout << root->data << " ";

        inprint(root->l);
        st.push(root->data);
        inprint(root->r);
    }
}

void bcprint(Node* root) {
    if (root != nullptr) {
        //cout << root->data << " ";

        bcprint(root->l);
        bcprint(root->r);
        st.push(root->data);
    }
}




int main() {
    // 创建二叉树
    Node* root = new Node(1);
    root->l = new Node(2);
    root->r = new Node(3);
    root->l->l = new Node(4);
    root->l->r = new Node(5);

    //前序
    puts("前序遍历：");
    preprint(root);
    while (!st.empty())
    {
        int x = st.top();
        res.push_back(x);
        st.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    res.clear();

    puts("中序遍历：");
    inprint(root);
    while (!st.empty())
    {
        int x = st.top();
        res.push_back(x);
        st.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    res.clear();

    puts("后序遍历：");
    bcprint(root);
    while (!st.empty())
    {
        int x = st.top();
        res.push_back(x);
        st.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    res.clear();




    return 0;
}