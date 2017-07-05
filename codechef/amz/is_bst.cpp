#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#define MAX_NODES 32;
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;

int arr[128];
int idx = 0;

void inorder(struct node *curr)
{
    if(curr == NULL)
    {
        return;
    }
    if(curr->left != NULL)
    {
        inorder(curr->left);
    }
    arr[idx] = curr->data;
    idx++;
    if(curr->right != NULL)
    {
        inorder(curr->right);
    }
}
int main()
{
//    root = (struct node *) malloc(sizeof(struct node));
//    root->data = 1;
//    root->left = (struct node *) malloc(sizeof(struct node));
//    root->left->data = 2;
//    root->left->left = (struct node *) malloc(sizeof(struct node));
//    root->left->left->data = 7;
//    root->left->left->left = NULL;
//    root->left->left->right = NULL;
//    root->left->right = (struct node *) malloc(sizeof(struct node));
//    root->left->right->data = 9;
//    root->left->right->left = NULL;
//    root->left->right->right = NULL;
//
//
//
//    root->right = (struct node *) malloc(sizeof(struct node));
//    root->right->data = 3;
//    root->right->left = (struct node *) malloc(sizeof(struct node));
//    root->right->left->data = 4;
//    root->right->left->left = NULL;
//    root->right->left->right = NULL;
//    root->right->right = (struct node *) malloc(sizeof(struct node));
//    root->right->right->data = 5;
//    root->right->right->left = NULL;
//    root->right->right->right = NULL;

    root = (struct node *) malloc(sizeof(struct node));
    root->data = 9;
    root->left = (struct node *) malloc(sizeof(struct node));
    root->left->data = 5;
    root->left->left = (struct node *) malloc(sizeof(struct node));
    root->left->left->data = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct node *) malloc(sizeof(struct node));
    root->left->right->data = 6;
    root->left->right->left = NULL;
    root->left->right->right = NULL;



    root->right = (struct node *) malloc(sizeof(struct node));
    root->right->data = 12;
    root->right->left = (struct node *) malloc(sizeof(struct node));
    root->right->left->data = 10;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct node *) malloc(sizeof(struct node));
    root->right->right->data = 16;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    //printf("hoy....\n");
    inorder(root);
    //printf("bugger...\n");
    int i;
    for(i=0;i<idx;i++)
    {
        printf(" %d",arr[i]);
    }
    return 0;
}
