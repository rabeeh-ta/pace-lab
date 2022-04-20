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
void CreateBST(int a[MAX], int n)
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
    printf("Binary Seacrh Tree created\n\n");
}
void Inorder(NODE tree)
{
    if (tree != NULL)
    {
        Inorder(tree->lchild);
        printf("%d ", tree->data);
        Inorder(tree->rchild);
    }
}
void Preorder(NODE tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        Preorder(tree->lchild);
        Preorder(tree->rchild);
    }
}
void Postorder(NODE tree)
{
    if (tree != NULL)
    {
        Postorder(tree->lchild);
        Postorder(tree->rchild);
        printf("%d ", tree->data);
    }
}
void SearchBST()
{
    NODE temp1;
    int key;
    printf("Enter the key to be searched : ");
    scanf("%d", &key);
    temp1 = tree;
    while (temp1 != NULL)
    {
        if (key == temp1->data)
        {
            printf("The key %d found in the BST", key);
            return;
        }
        else if (key < temp1->data)
            temp1 = temp1->lchild;
        else
            temp1 = temp1->rchild;
    }
    printf("Key %d not found in the BST", key);
}
int main()
{
    int a[MAX], n, i, choice;
    while (1)
    {
        printf("\n\n****MENU***");
        printf("\n1. Create a BST of n integers\n2. Traverse the BST inInorder\n3. Traverse the BST in Preorder\n4. Traverse the BST inPostorder\n5. Search the BST for a given element (KEY)\n6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of integers : ");
            scanf("%d", &n);
            printf("Enter the elements\n");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);
            CreateBST(a, n);
            break;
        case 2:
            printf("Inorder Traversal :\n");
            Inorder(tree);
            break;
        case 3:
            printf("Preorder Traversal :\n");
            Preorder(tree);
            break;
        case 4:
            printf("Postoder Traversal :\n");
            Postorder(tree);
            break;
        case 5:
            SearchBST();
            break;
        case 6:
            exit(0);
            break;
        }
    }
}
