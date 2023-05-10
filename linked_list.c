#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

node *new_list(int n)
{
    node *head;
    node *temp_ptr;

    head = (node *)malloc(1 * sizeof(node));
    temp_ptr = head;

    for (int i = 0; i < n; i++)
    {
        temp_ptr->val = i;
        if (i == n - 1)
        {
            temp_ptr->next = NULL;
            break;
        }
        temp_ptr->next = (node *)malloc(1 * sizeof(node));
        temp_ptr = temp_ptr->next;
    }

    return head;
}

node *new_rand_list(int n)
{
    // srand( time(NULL) );
    srand(1);
    node *head;
    node *temp_ptr;
    int max, min;

    max = 100;
    min = 0;

    head = (node *)malloc(1 * sizeof(node));
    temp_ptr = head;

    for (int i = 0; i < n; i++)
    {
        temp_ptr->val = rand() % (max - min + 1) + min;
        ;
        if (i == n - 1)
        {
            temp_ptr->next = NULL;
            break;
        }
        temp_ptr->next = (node *)malloc(1 * sizeof(node));
        temp_ptr = temp_ptr->next;
    }

    return head;
}

void print_list(node *head)
{
    node *temp_ptr;

    temp_ptr = head;
    while (temp_ptr != NULL)
    {
        printf("%d ", temp_ptr->val);
        temp_ptr = temp_ptr->next;
    }
}

node *list_reverse(node *old_head)
{
    node *new_head, *temp_ptr;

    if (old_head->next != NULL)
    {
        new_head = list_reverse(old_head->next);
        temp_ptr = new_head;
        while (temp_ptr->next != NULL)
        {
            temp_ptr = temp_ptr->next;
        }
        old_head->next = NULL;
        temp_ptr->next = old_head;
        return new_head;
    }
    else
    {
        old_head->next = NULL;
        return old_head;
    }
}

node *merge_list(node *list1, node *list2)
{

    node *out_list, *insert_node, *this_node, *last_node, *insr_iter;

    if (list1->val < list2->val)
    {
        out_list = list1;
        insr_iter = list2;
    }
    else
    {
        out_list = list2;
        insr_iter = list1;
    }

    insert_node = insr_iter;
    insr_iter = insr_iter->next;

    if (out_list->next == NULL || insert_node->val < out_list->next->val)
    {
        insert_node->next = out_list->next;
        out_list->next = insert_node;
    }

    insert_node = insr_iter;
    last_node = out_list;
    this_node = out_list->next;

    while (insert_node != NULL && this_node != NULL)
    {
        if (insert_node->val < this_node->val)
        {
            insr_iter = insr_iter->next;
            last_node->next = insert_node;
            last_node->next->next = this_node;
            last_node = insert_node;
            insert_node = insr_iter;
        }
        else if (this_node->next == NULL || insert_node->val < this_node->next->val)
        {
            insr_iter = insr_iter->next;
            insert_node->next = this_node->next;
            this_node->next = insert_node;
            last_node = this_node;
            this_node = insert_node;
            insert_node = insr_iter;
        }
        else
        {
            last_node = this_node;
            this_node = this_node->next;
        }
    }

    return out_list;
}

node *merge_list2(node *list1, node *list2)
{
    node *itr, *temp, *out;

    itr = (node *)malloc(sizeof(node));
    temp = itr;

    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val > list2->val)
        {
            itr->next = list1;
            itr = list1;
            list1 = list1->next;
        }
        else
        {
            itr->next = list2;
            itr = list2;
            list2 = list2->next;
        }
    }

    if (list1 == NULL)
    {
        itr->next = list2;
    }

    if (list2 == NULL)
    {
        itr->next = list1;
    }

    out = temp->next;
    free(temp);
    return (out);
}

node *list_merge_sort(node *head, int n)
{
    if (n == 1)
        return head;

    node *node1, *node2, *temp_node, *out_node;

    node1 = head;
    temp_node = head;

    for (int i = 1; i < (n / 2); i++)
    {
        temp_node = temp_node->next;
    }

    node2 = temp_node->next;
    temp_node->next = NULL;

    node1 = list_merge_sort(node1, n / 2);
    node2 = list_merge_sort(node2, n - (n / 2));
    // out_node = merge_list(node1, node2);
    out_node = merge_list2(node1, node2);
    return out_node;
}

void free_list(node *head)
{

    if (head != NULL)
    {
        free_list(head->next);
        // printf("%p free success! \n",  head);
        free(head);
        return;
    }

    return;
}

void chk_sort(node *list)
{
    node *iter;
    int temp;

    iter = list;
    temp = iter->val;
    iter = iter->next;

    while (iter != NULL)
    {
        if (temp < iter->val)
        {
            printf("ERROR! \n");
            return;
        }
        temp = iter->val;
        iter = iter->next;
    }
    printf("SORT CORRECT!\n");
}

int main()
{
    node *list1;
    int n = 100;

    list1 = new_rand_list(n);
    print_list(list1);
    printf("\n");

    list1 = list_reverse(list1);
    print_list(list1);
    printf("\n");

    list1 = list_merge_sort(list1, n);
    print_list(list1);
    printf("\n");
    chk_sort(list1);

    free_list(list1);

    /*
        list1= new_list(5);
        print_list(list1);
        free_list(&list1);
    */

    return 0;
}