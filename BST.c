#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int val;
    struct Node *ls;
    struct Node *rs;
} Node;

Node *init_root(int val){
    Node *root;
    root = (Node*)malloc(sizeof(Node));
    root->val = val;
    root->ls = NULL;
    root->rs = NULL;
    return root;
}

void add_node(Node *root, int val){
    
    if(root == NULL){ 
        return;
    }

    if(val > root->val){
        add_node(root->rs, val);
        if(root->rs == NULL){
            root->rs = (Node*) malloc(sizeof(Node)); 
            root->rs->val = val;
            root->rs->rs = NULL;
            root->rs->ls = NULL;
        }
    }
    else{
        add_node(root->ls, val);
        if(root->ls == NULL){
            root->ls = (Node*) malloc(sizeof(Node)); 
            root->ls->val = val;
            root->ls->rs = NULL;
            root->ls->ls = NULL;
        }
    }
    
    return;
}

Node *build_BST(int *arr, int n){
    Node *root;
    root = init_root(arr[0]);
    for(int i = 1; i < n; i++){
        add_node(root, arr[i]);
    }

    return root;
}

int *new_rand_array(int n){
    int min, max;
    int *array;

    min = 0;
    max = 100;

    array = (int*)calloc(n, sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        array[i] = rand() % (max - min + 1) + min;
    }

    return array;
}


int main(){
    Node *root;
    int *arr;
    int n = 10;
    
    arr = new_rand_array(n);
    root = build_BST(arr, n);


    return 0;
}