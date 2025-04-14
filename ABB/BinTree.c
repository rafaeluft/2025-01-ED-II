#include "BinTree.h"
#include <stdio.h>
#include <stdlib.h>

TNo* TNo_createNFill(int);
BinTree* BinTree_create(){
    BinTree* T = malloc(sizeof(BinTree));
    if(T){
        T->root = NULL;
    }
    return T;
}

TNo* TNo_createNFill(int key){
    TNo* node = malloc(sizeof(TNo));
    if(node){
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->p = NULL;
    }
    return node;
}

bool BinTree_insert(BinTree* T, int key){
    TNo* z = TNo_createNFill(key);
    if(z == NULL) return false;
    TNo *x = T->root, *y = NULL;
    while(x != NULL){
        y = x;
        x = (z->key < x->key) ? x->left: x->right;
    }
    z->p = y;
    if(y==NULL)
        T->root = z;
    else
        if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
    return true;
}

void BinTree_pre(TNo* root){
    if(root!=NULL){
        printf("%02d, ", root->key);
        BinTree_pre(root->left);
        BinTree_pre(root->right);
    }
}
void BinTree_in(TNo* root){
    if(root!=NULL){
        BinTree_in(root->left);
        printf("%02d, ", root->key);
        BinTree_in(root->right);
    }
}
TNo* BinTree_search(TNo* x, int k){
    while(x!=NULL && k != x->key){
        printf("Estou em: [%d]\n",x->key);
        x = (k < x->key)? x->left: x->right;
    }
    return x;
}
TNo* BinTree_search_r(TNo* x, int k){
    if(x!=NULL)
        printf("Estou em: [%d]\n",x->key);
    if (x == NULL || k==x->key)
        return x;
    return BinTree_search_r((k < x->key)? x->left:x->right, k);
}
