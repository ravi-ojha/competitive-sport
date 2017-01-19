#include <bits/stdc++.h>
#define DEBUG true
using namespace std;


int findParent(int i, int parent[]) {
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i],parent);
    return parent[i];
}

void unionNodes(int a,int b,int parent[],int size[]) {
    int parent_a = findParent(a,parent),parent_b=findParent(b,parent);
    if(parent_a==parent_b) {
        return;
    }

    //the larger connected component eats up the smaller one
    if(size[parent_a]>=size[parent_b]) {
         size[parent_a]+=size[parent_b];
         parent[parent_b]=parent_a;
    } else {
         size[parent_b]+=size[parent_a];
         parent[parent_a]=parent_b;
    }
    return;
}
 
int main() {
 
    int N, P, i;
    scanf(" %d",&N);
    int parent[100001]={0}, size[100001]={0};
    for(i=1;i<=N;i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
 
    for(i=1;i<=N;i++) {
        scanf(" %d",&P);
        unionNodes(i, P, parent, size);
    }
 
    int result = 0;
    for(i=1; i<=N; i++) {
        if(findParent(i, parent) == i) {
            result++;
        }
 
    }
    printf("%d\n",result);
    return 0;
}
