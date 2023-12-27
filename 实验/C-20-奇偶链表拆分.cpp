#define _CRT_SECURE_NO_WARNINGS


//≤‚ ‘”√¿˝
//10
//1 2 3 4 5 6 7 8 9 10

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


int main()
{
    Node* L = initList();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tailInsert(L, x);
    }

    Node* L1 = initList();
    Node* L2 = initList();
    Node* node = L->next;
    while (node)
    {
        if (node->data % 2 == 0)
        {
            tailInsert(L1, node->data);
        }
        else
        {
            tailInsert(L2, node->data);
        }
        node = node->next;
    }

    myprintf(L1);
    cout << endl;
    myprintf(L2);
}