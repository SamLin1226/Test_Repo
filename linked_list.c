#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int val;
    struct node* next;
} node;

node* new_list(int n){
    node *head;
    node *temp_ptr;

    head = (node*)malloc(1 * sizeof(node));
    temp_ptr = head;

    for(int i = 0; i < n; i++){
        temp_ptr->val = i;
        if(i == n-1){
            temp_ptr->next = NULL;
            break;
        }
        temp_ptr->next = (node*)malloc(1 * sizeof(node));
        temp_ptr = temp_ptr->next;
    }

    return head;
}

node* new_rand_list(int n){
    srand( time(NULL) );
    node *head;
    node *temp_ptr;
    int max, min;
    
    max = 100;
    min = 0;

    head = (node*)malloc(1 * sizeof(node));
    temp_ptr = head;

    for(int i = 0; i < n; i++){
        temp_ptr->val = rand() % (max - min + 1) + min;;
        if(i == n-1){
            temp_ptr->next = NULL;
            break;
        }
        temp_ptr->next = (node*)malloc(1 * sizeof(node));
        temp_ptr = temp_ptr->next;
    }

    return head;
}


void print_list(node *head){
    node* temp_ptr;
    
    temp_ptr = head;
    while(temp_ptr != NULL){
        printf("%d ",temp_ptr->val);
        temp_ptr = temp_ptr->next;
    }

}

node* list_reverse(node *old_head){
    node *new_head, *temp_ptr;
    
    if(old_head->next != NULL){
        new_head = list_reverse(old_head->next);
        temp_ptr = new_head;
        while(temp_ptr->next != NULL){
            temp_ptr = temp_ptr->next;
        }
        old_head->next = NULL;
        temp_ptr->next = old_head;
        return new_head;
    }
    else{
        old_head->next = NULL;
        return old_head;
    }
}

node *merge_list(node *list1, node *list2){
    node *node1, *temp_node1, *node2, *temp_node2, *out_node;
    int c = 0;

    node1 = list1;
    node2 = list2;

    while(node1 != NULL || node2 != NULL){
        if(node1->val > node2->val){
            temp_node1 = node1;
            if(c == 0){
                out_node = node1;
            }
            temp_node1->next = node2;
            temp_node2->next = node1;
            node1 = node1->next;
            
        }
        else{
            temp_node2 = node2;
            if(c == 0){
                out_node = node2;
            }
            temp_node2->next = node1;
            temp_node1->next = node2;
            node2 = node2->next;
        }
        c++;
    }
    return out_node;
}

node *list_merge_sort(node *head, int n){
    if(n == 1)
        return head;

    node *node1, *node2, *out_node;
    
    node1 = head;
    node2 = head;
    for(int i = 0; i < n/2; i++){
        node2 = node2->next;
    }
    node1 = list_merge_sort(node1,n/2);
    node2 = list_merge_sort(node2,n-(n/2));
    out_node = merge_list(node1, node2);
    return out_node;

}

void free_list(node *head){
    
    if(head->next != NULL){
        free_list(head->next);
        free(head);
        return;
    }
    else{
        return;
    }
}

int main(){
    node *list1;
    int n = 10;

    list1 = new_rand_list(n);
    print_list(list1);
    list1 = list_reverse(list1);
    printf("\n");
    print_list(list1);
    printf("\n");
    /*
    list1 = list_merge_sort(list1, n);
    print_list(list1);
    printf("\n");
*/
    free_list(list1);


/*
    list1= new_list(5);
    print_list(list1);
    free_list(&list1);
*/
    return 0;
}