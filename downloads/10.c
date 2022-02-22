
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct node
{
    int data;
    struct node *lchild, *rchild;
};
typedef struct node *NODE;
NODE tree = NULL;
void createBST(int a[MAX], int n)
{
    NODE temp, p, q;
    int i;
    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node *));
        temp->data = a[i];
        temp->lchild = temp->rchild = NULL;
        if (tree == NULL)
            tree = temp;
        else
        {
            p = q = tree;
            while (q != NULL)
            {
                p = q;

                if (a[i] < p->data)
                    q = p->lchild;
                else if (a[i] > p->data)
                    q = p->rchild;
                else
                {
                    free(temp);
                    break;
                }
            }
            if (q == NULL)
            {
                if (a[i] < p->data)
                    p->lchild = temp;
                else
                    p->rchild = temp;
            }
        }
    }
    printf("binary search tree created\n\n");
}

void inorder(NODE tree)
{
    if (tree != NULL)
    {
        inorder(tree->lchild);
        printf("%d", tree->data);
        inorder(tree->rchild);
    }
}
void preorder(NODE tree)
{
    if (tree != NULL)
    {
        printf("%d", tree->data);
        preorder(tree->lchild);
        preorder(tree->rchild);
    }
}
void postorder(NODE tree)
{
    if (tree != NULL)
    {
        postorder(tree->lchild);
        postorder(tree->rchild);
        printf("%d", tree->data);
    }
}
void SearchBST(NODE tree)
{
    NODE temp1;
    int key;
    printf("enter the key to be searched:");
    scanf("%d", &key);
    temp1 = tree;
    while (temp1 != NULL)
    {
        if (key == temp1->data)
        {
            printf("the key %d found in the BST", key);
            return;
        }
        else if (key < temp1->data)
            temp1 = temp1->lchild;
        else
            temp1 = temp1->rchild;
    }
    printf("key %d not found in the BST", key);
}

int main()
{
    int a[MAX], n, i, choice;
    while (1)
    {
        printf("\n\n************MENU**********");
        printf("\n1. create a BST of n integers\n2.traverse the BST in inorder\n3.traverse the BST in preorder\n4. traverse BST in postorder \n5.search the BST for a given element(key)\n6.exit\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the number of integers:");
            scanf("%d", &n);
            printf("enter the elements\n");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);
            createBST(a, n);
            break;
        case 2:
            printf("inorder traversal:\n");
            inorder(tree);
            break;
        case 3:
            printf("preorder traversal:\n");
            preorder(tree);
            break;
        case 4:
            printf("postorder traversal:\n");
            postorder(tree);
            break;
        case 5:
            SearchBST(tree);
            break;
        case 6:
            exit(0);
            break;
        }
    }
}
