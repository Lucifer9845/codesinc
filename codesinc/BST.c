#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *left, *right;
};
typedef struct BST node;

node *insert(node *root, int key)
{
    if(root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->data = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(key<root->left)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

node *search(node *root, int key)
{
    if(root == NULL)
        return NULL;
    else if(key == root->data)
        return root;
    else if(key<root->data)
        return search(root->left, key);
    else 
        return search(root->right, key);
}

int main()
{
    int ch, n, i, key;
    node *root = NULL, *l;
    while(1)
    {
        printf("\n1.Insert\n2.InOrder\n3.preOrder\n4.PostOrder\n5.search\n6.exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : printf("enter N\n");
                    scanf("%d", &n);
                    for(i = 0;i<n;i++)
                    {
                        printf("enter value for %d\n", i+1);
                        scanf("%d", &key);
                        root = insert(root, key);
                    }
                    break;
            case 2 : inorder(root);
                    break;
            case 3 : preorder(root);
                    break;
            case 4 : postorder(root);
                    break;
            case 5 : printf("Enter the search key\n");
                    scanf("%d", &key);
                    l = search(root, key);
                    if(l == NULL)
                        printf("key not found\n");
                    else
                        printf("key found\n");      
            case 6 : exit(0);
        }
    }
}