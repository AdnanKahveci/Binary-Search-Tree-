// BTS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct n
{
    int data;
    n* left;
    n* right;
};

n* insert(n* agac, int x) {
    if (agac==NULL)
    {
        n* root = new n();
        root->left = NULL;
        root->right = NULL;
        root->data = x;
        return root;
    }
    if (agac->data<x)
    {
        agac->right = insert(agac->right, x);
        return agac;
    }
    agac->left = insert(agac->left, x);
    return agac;
}

void dolas(n* agac){
    if (agac==NULL)
    {
        return;
    }
    dolas(agac->right);
    cout << agac->data;
    dolas(agac->left);
}
int search(n* agac, int aranan) {
    if (agac == NULL)
        return -1;
    if (agac->data == aranan)
        return 1;
    if (search(agac->right, aranan) == 1)
        return 1;
    if (search(agac->left, aranan) == 1)
        return 1;
    return -1;
}
int max(n* agac) {
    while (agac->right!=NULL)
    {
        agac = agac->right;
    }
    return agac->data;
}
int min(n* agac) {
    while (agac->left != NULL)
    {
        agac = agac->left;
    }
    return agac->data;
}


n* sil(n* agac,int x) {
    if (agac==NULL)
    {
        return NULL;
    }
    if (agac->data==x)
    {
        if (agac->left == NULL && agac->right == NULL) {
            return NULL;
        }
        if (agac->right!=NULL)
        {
            agac->data = min(agac->right);
            agac->right = sil(agac->right, min(agac->right));
            return agac;
        }
        if (agac->left!=NULL){ 
            agac->data = max(agac->left);
            agac->left = sil(agac->left, max(agac->left));
            return agac;
        }
    }
    if (agac->data < x)
    {
        agac->right = sil(agac->right, x);
        return agac;
    }
    if (agac->data >x)
    {
        agac->left = sil(agac->left, x);
        return agac;

    }  
}



int main()
{
    n* agac = NULL;
    agac = insert(agac, 56);
    agac = insert(agac, 200);
    agac = insert(agac, 26);
    agac = insert(agac, 190);
    agac = insert(agac, 213);
    agac = insert(agac, 18);
    agac = insert(agac, 28);
    agac = insert(agac, 12);    
    agac = insert(agac, 24);
    agac = insert(agac, 27);
    
    sil(agac, 213);
    dolas(agac);
}