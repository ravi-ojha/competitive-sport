#include <iostream>
#include <queue>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
vector < pair<int, int> > v;

int bfs(node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    queue < pair<node *, int> > q;
    q.push(make_pair(root,0));
    int h = 0;
    while(!q.empty())
    {
        pair <node *, int> tt = q.front();
        node * tmp = tt.first;
        v.push_back(make_pair(tmp->data,tt.second));
        q.pop();
        h++;
        if(tmp->left != NULL)
        q.push(make_pair(tmp->left, h));
        if(tmp->right != NULL)
        q.push(make_pair(tmp->right, h));
    }
    return 0;
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Level Order traversal of binary tree is \n");
  bfs(root);
  for(int i=0;i<v.size();i++)
  {
      printf(" %d %d\n",v[i].first, v[i].second);
  }
  return 0;
}
