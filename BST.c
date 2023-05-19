#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int val;
    struct Node *ls;
    struct Node *rs;
} Node;

Node* search(Node *root, int key){
    if(root == NULL || root->val == key){
        return root;
    }

    if(key > root->val){
        return (search(root->rs, key));
    }
    else{
        return (search(root->ls, key));
    }

}

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

    //srand(time(NULL));
    srand(6842);

    for(int i = 0; i < n; i++){
        array[i] = rand() % (max - min + 1) + min;
    }

    return array;
}

Node* find_less(Node *root){
    if(root->ls == NULL){
        return root;
    }

    return find_less(root->ls);
}

void delete_node(Node *root, int key){
    if(root == NULL || root->val == key){
        return;
    }

    if(key > root->val){
        delete_node(root->rs, key);
        if (root->rs != NULL && root->rs->val == key){
            Node *temp;
            if(root->rs->rs == NULL && root->rs->ls == NULL){
                temp = root->rs;
                root->rs = NULL;
                free(temp);
            }
            else if(root->rs->rs == NULL && root->rs->ls != NULL){
                temp = root->rs;
                root->rs = root->rs->ls;
                free(temp);
            }
            else if(root->rs->rs != NULL && root->rs->ls == NULL ){
                temp = root->rs;
                root->rs = root->rs->rs;
                free(temp);
            }
            else{
                Node *less_node;
                temp = root->rs;
                less_node = find_less(root->rs->rs);
                less_node->ls = root->rs->ls;
                root->rs = root->rs->rs;
                free(temp);
            }
        }
        return;
    }
    else{
        delete_node(root->ls, key);
        if (root->ls != NULL && root->ls->val == key){
            Node *temp;
            if(root->ls->rs == NULL && root->ls->ls == NULL){
                temp = root->ls;
                root->ls = NULL;
                free(temp);
            }
            else if(root->ls->rs == NULL && root->ls->ls != NULL){
                temp = root->ls;
                root->ls = root->ls->ls;
                free(temp);
            }
            else if(root->ls->rs != NULL && root->ls->ls == NULL ){
                temp = root->ls;
                root->ls = root->ls->rs;
                free(temp);
            }
            else{
                Node *less_node;
                temp = root->ls;
                less_node = find_less(root->ls->rs);
                less_node->ls = root->ls->ls;
                root->ls = root->ls->rs;
                free(temp);
            }

        }
        return;
    }

}

int *tree_height(Node *root){
    
}

void print_array(int* array, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

void print_node(Node *node){
    if(node !=  NULL){
        printf("%d \n", node->val);
    }
    else{
        printf("Node does not exist! \n");
    }
}

void print_tree(Node *root){
    if(root == NULL){
        return;
    }

    print_tree(root->ls);
    printf("%d ", root->val);
    print_tree(root->rs);
}

int main(){
    Node *root, *out;
    int *arr;
    int n = 10;
    int key = 40;
    
    arr = new_rand_array(n);
    print_array(arr, n);

    root = build_BST(arr, n);
    out = search(root , key);
    print_node(out);

    print_tree(root);
    printf("\n");


    
    delete_node(root, key);
    out = search(root , key);
    print_node(out);

    print_tree(root);
    printf("\n");




    add_node(root, key);
    out = search(root , key);
    print_node(out);

    print_tree(root);
    printf("\n");

    return 0;
}
