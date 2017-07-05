#include <stdio.h>
#include <stdlib.h>

int main(){
    // Example weighted graph
    int weights[5][5] = {{0,5,7,9,3},
            {5,0,6,11,15},
            {7,6,0,6,8},
            {9,11,6,0,7},
            {3,15,8,7,0}};
    int length = 5;
    // temp array -- for marking changes
    int array[length][length];
    // to keep track of visited nodes
    int visited[length];
    // to keep minimun spanning tree
    int mst[length][length];
    // start node
    int seed,i,j;

    // initialization -- If you dynamically allocate memory, this
    //    can be removed
    for(i = 0; i < length; ++i){
        for(j = 0; j < length; ++j){
            array[i][j] = weights[i][j];
            mst[i][j]=0;
        }
        visited[i] = 0;
    }
    seed = 0;

    visited[seed] = 1;
    for(i = 0; i < length; ++i){
        array[seed][i] = 0;
    }

    int min;
    int next_item;
    int k = 0;
    while(1){
        if(k == length)
            break;
        min = 9999;
        for(i = 0; i < length; ++i){
            if(visited[i] == 0)
                continue;
            for(j = 0; j < length; ++j){
                if((array[j][i] != 0)
                    && ((min == 9999)
                    || (min > array[j][i]))){
                    min = array[j][i];
                    seed = i;
                    next_item = j;
                }
            }
        }
        visited[next_item] = 1;
        mst[next_item][seed] = mst[seed][next_item] =
                    weights[seed][next_item];
        for(j= 0; j < length; ++j){
            array[next_item][j] = 0;
        }
        k++;
    }
    return 0;
}
