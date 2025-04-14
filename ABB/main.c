#include "BinTree.h"
#include <stdio.h>
void print_tree(BinTree* T){
    printf("Pre:      ");
    BinTree_pre(T->root);
    printf("\nIn Order: ");
    BinTree_in(T->root);
    putchar('\n');
}
int main(){
    BinTree *T = BinTree_create();
    if(!T){
        puts("Nao pude criar a arvore!");
        return -1;
    }

    int V[] = {12, 5, 18, 2, 9, 15, 19, 17, 13}, i;
    for(i = 0; i<sizeof(V)/sizeof(int); i++)
        if(!BinTree_insert(T, V[i]))
            printf("Erro ao inserir: V[%d] = %d\n", i, V[i]);
    //Exemplo de chamada da busca...
    BinTree_search(T->root, 12);
    print_tree(T);
    return 0;
}