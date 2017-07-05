#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#define MAX_NODES 32;
using namespace std;




struct BTreeNode{
   int val;
   BTreeNode *left,*right;
}*root;
void solve_problem(BTreeNode *root, int value);
int neg_freq[1024] = {0};
int neg_max = 0;
int pos_freq[1024] = {0};
int pos_max = 0;
void printVerticalSum(BTreeNode *root) {

    solve_problem(root,0);
    int j;
    for(j=neg_max;j>0;j--)
    {
        printf("%d ",neg_freq[j]);
    }
    for(j=0;j<=pos_max;j++)
    {
        printf("%d ",pos_freq[j]);
    }
}


void solve_problem(BTreeNode *root, int value)
{
    if(root == NULL)
    {
        return;
    }
    if(value < 0)
    {
        int t_value = (-1)*value;
        neg_freq[t_value] += root->val;
        if(neg_max < t_value)
        {
            neg_max = t_value;
        }
    }
    else
    {
        pos_freq[value] += root->val;
        if(pos_max < value)
        {
            pos_max = value;
        }
    }
    if(root->left != NULL)
    {
        solve_problem(root->left,value - 1);
    }
    if(root->right != NULL)
    {
        solve_problem(root->right,value + 1);
    }

}

int main()
{
    root = (struct BTreeNode *) malloc(sizeof(struct BTreeNode));
    root->val = 1;
    root->left = (struct BTreeNode *) malloc(sizeof(struct BTreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct BTreeNode *) malloc(sizeof(struct BTreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    //printf("hoy....\n");
    printVerticalSum(root);
    //printf("bugger...\n");

    return 0;
}
