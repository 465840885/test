#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <iterator>

using namespace std;

struct node
{
    node *pnext;
    node *ppre;
    int id;
    char _pad[4];
};

union u_node
{
    //int a[5];       //20
    short b;     //2
    //double c;    //8
    char p2;     //1
};

void printNodeList(node *pn)
{
    while(pn != nullptr)
    {
        cout << pn->id << endl;
        pn = pn->pnext;
    }
}

node* reserveNode(node *pn)
{
    node *temp,*tmp;
    while(pn->pnext != nullptr)
    {
        tmp = pn;
        temp = pn->pnext;
        pn = pn->pnext;
        tmp->pnext = tmp->ppre;
        tmp->ppre = temp;
    }
    pn->pnext = pn->ppre;
    pn->ppre = nullptr;
    return pn;
}

int main()
{
    //cout << sizeof(u_node) << endl;
    node *pA,*pB,*pC;
    pA = new node;
    pB = new node;
    pC = new node;

    pA->ppre = nullptr;
    pA->pnext = pB;
    pA->id = 1;

    pB->ppre = pA;
    pB->pnext = pC;
    pB->id = 2;

    pC->ppre = pB;
    pC->pnext = nullptr;
    pC->id = 3;

    pA->pnext = pA->pnext->pnext;
    pA->pnext->ppre = pA;
    delete pB;

    printNodeList(pA);
    return 0;
}
