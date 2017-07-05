#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#define MAX_NODES 32;
using namespace std;

vector <int> neg_freq[100];
int neg_end = 0;
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
    if(value >= 0)
    {
        pos_freq[value].push_back(curr->data);
        if(pos_end < value)
        {
            pos_end = value;
        }
    }
    else
    {
        int t_value = (-1)*value;
        neg_freq[t_value].push_back(curr->data);
        if(neg_end < t_value)
        {
            neg_end = t_value;
        }
    }
    if(curr->left != NULL)
    {
        dfs(curr->left,value-1);
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
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct node *) malloc(sizeof(struct node));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    //printf("hoy....\n");
    dfs(root,0);
    //printf("bugger...\n");
    int i,line = 1;
    for(i=neg_end;i>0;i--)
    {
        printf("Line #%d: ",line);
        line++;
        itr = neg_freq[i].begin();
        while(itr != neg_freq[i].end())
        {
            printf(" %d",(*itr));
            itr++;
        }
        printf("\n");
    }
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
