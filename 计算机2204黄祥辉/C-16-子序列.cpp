#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* initList() {
    Node* L = (Node*)malloc(sizeof(Node));
    L->data = 0;
    L->next = NULL;
    return L;
}

void tailInsert(Node* L, int data) {
    Node* node = L;
    for (int i = 0; i < L->data; i++) {
        node = node->next;
    }
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    node->next = n;
    L->data++;
}

void myprintf(Node* L) {
    Node* node = L->next;
    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

bool isSubsequence(Node* A,Node* B) {
    if (B == NULL) {
        // B 为空序列
        return true;
    }
    if (A == NULL) {
        // A 为空序列
        return false;
    }

    if (A->data == B->data) {
        return isSubsequence(A->next, B->next);
    }
    else {
        return isSubsequence(A->next, B);
    }
}

int main()
{
    Node* L1 = initList();
    Node* L2 = initList();
    ////用例1
    //tailInsert(L1, 1);
    //tailInsert(L1, 2);
    //tailInsert(L1, 3);
    //tailInsert(L1, 4);
    //tailInsert(L1, 5);
    //tailInsert(L2, 2);
    //tailInsert(L2, 4);

    tailInsert(L1, 1);
    tailInsert(L1, 3);
    tailInsert(L1, 5);
    tailInsert(L1, 7);
    tailInsert(L2, 1);
    tailInsert(L2, 2);
    tailInsert(L2, 3);
    myprintf(L1);
    myprintf(L2);
    cout << endl;
   /* bool f = isSubsequence(L1->next, L2->next);
    cout << f<<endl;*/


    if (isSubsequence(L1->next, L2->next))cout << "是子序列";
    else cout << "不是子序列";
	return 0;
}