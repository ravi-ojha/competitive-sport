#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#define MAX_NODES 32;
using namespace std;

vector <int> pos_freq[100];
int pos_end = 0;
vector <int> :: iterator itr;

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;

void dfs(struct node *curr, int value)
{
    if(curr == NULL)
    {
        return;
    }
    pos_freq[value].push_back(curr->data);
    if(pos_end < value)
    {
        pos_end = value;
    }
    if(curr->left != NULL)
    {
        dfs(curr->left,value+1);
    }
    if(curr->right != NULL)
    {
        dfs(curr->right,value+1);
    }
}
int main()
{
    root = (struct node *) malloc(sizeof(struct node));
    root->data = 1;
    root->left = (struct node *) malloc(sizeof(struct node));
    root->left->data = 2;
    root->left->left = (struct node *) malloc(sizeof(struct node));
    root->left->left->data = 7;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct node *) malloc(sizeof(struct node));
    root->left->right->data = 9;
    root->left->right->left = NULL;
    root->left->right->right = NULL;



    root->right = (struct node *) malloc(sizeof(struct node));
    root->right->data = 3;
    root->right->left = (struct node *) malloc(sizeof(struct node));
    root->right->left->data = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct node *) malloc(sizeof(struct node));
    root->right->right->data = 5;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    //printf("hoy....\n");
    dfs(root,0);
    //printf("bugger...\n");
    int i,line = 1;
    for(i=0;i<=pos_end;i++)
    {
        printf("Line #%d: ",line);
        line++;
        itr = pos_freq[i].begin();
        while(itr != pos_freq[i].end())
        {
            printf(" %d",(*itr));
            itr++;
        }
        printf("\n");
    }
    return 0;
}
