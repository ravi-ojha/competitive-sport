int g[LIMIT+1][LIMIT+1];//contain the graph weight
int used[LIMIT+1];//vertex is used
int min_e[LIMIT+1];//weight of maximum allowable edge
int sel[LIMIT+1]; //contain the end of longest edge
int n;// no of vertex in graph
void init()
{
    //used for initializing the graph
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]=0;
    for(int i=0;i<n;i++)
    {
        used[i]=0;
        min_e[i]=-INF;
        sel[i]=-1;
    }
}
int prim()
{
    int total=0;
    min_e[0]=0;
    for(int i=0;i<n;i++)
    {
        int v=-1;
        for(int j=0;j<n;j++)
        {
            if(!used[j]&&(v==-1||min_e[j]>min_e[v]))
             v=j;
        }
        used[v]=1;
        if(sel[v]!=-1)
        {
            total+=g[v][sel[v]];
        }
        for(int j=0;j<n;j++)
        {
            if(g[v][j]>min_e[j])
            {
                min_e[j]=g[v][j];
                //total+=min_e[j];
                sel[j]=v;
            }
        }
    }
    //if(total==-1)total=0;
    return total;
}
