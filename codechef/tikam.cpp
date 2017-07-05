# include <iostream>
# include <vector>
# define inf 2000000000
# define LEFT(x) (2*x+1)
# define RIGHT(x) (2*x+2)

using namespace std;

int ID=0, globalmap[200005], leftChild[200005]={-2}, rightChild[200005]={-2}, health[200005];
int minHealth[200005]={0}, lazy[200005]={0}, newChef[200005]={0};

vector <vector<int> > child;

void dfs(int index) {
	cout<<"DFS for index "<<index<<endl;
	globalmap[ID++] = index;
	int numChild = child[index].size();
	if(numChild == 0) {
		leftChild[index] = rightChild[index] = -1;
	}
	else {
		leftChild[index] = ID;
		for(int i=0;i<numChild;i++) {
			dfs(child[index][i]);
		}
		rightChild[index] = ID - 1;
	}
}

void buildTree(int start, int end, int index) {
	if(start>end)
		return;
	if(start==end) {
		minHealth[index] = health[globalmap[start]];
		cout<<"Updated minHealth of "<<start<<"by "<<health[globalmap[start]]<<endl;
		return;
	}
	int mid = (start+end)/2;
	buildTree(start, mid, LEFT(index));
	buildTree(mid+1, end, RIGHT(index));
	minHealth[index] = min(minHealth[LEFT(index)], minHealth[RIGHT(index)]);
	return;
}

void update(int st, int end, int left, int right, int index, int life) {
	if(left>end || right<st)
		return;
	if(st>end || left>right)
		return;
	if(newChef[index]==(end-st+1))
		return;
	if(left>=st && right<=end) {
		if(life+lazy[index] < minHealth[index]) {
			lazy[index] += life;
			return;
		}
		else {
			if(st==end) {
				minHealth[index] = inf;
				lazy[index] = 0;
				newChef[index] = 1;
				return;
			}
			lazy[LEFT(index)] += lazy[index];
			lazy[RIGHT(index)] += lazy[index];
			lazy[index] = 0;
		}
	}
	update(st,end,left,(left+right)/2,LEFT(index),life);
	update(st,end,(left+right)/2 + 1,right,RIGHT(index),life);
	newChef[index] = newChef[LEFT(index)] + newChef[RIGHT(index)];
}

int query(int st, int end, int left, int right, int index) {
	if(st>end || st>right || end<left)
		return 0;
	if(left>=st && end>=right)
		return (right-left+1) - newChef[index];
	return query(st,end,left,(left+right)/2,LEFT(index)) + query(st,end,(left+right)/2 + 1,right,RIGHT(index));
}

int main() {
	int numChef,senior,numQuery,chef,poison;
	scanf("%d", &numChef);
	for(int i=0;i<=numChef;i++)
		child.push_back(vector<int>());
	for(int i=1;i<=numChef;i++) {
		scanf("%d %d", &health[i],&senior);
		child[senior].push_back(i);
	}
	dfs(0);
	cout<<ID<<endl;
	buildTree(1,numChef,0);
	for(int i=0;i<=numChef;i++) {
		cout<<endl;
		cout<<leftChild[i]<<" ";
		cout<<rightChild[i]<<endl;
		cout<<endl;
	}
	scanf("%d",&numQuery);
	while(numQuery--){
		int type;
		scanf("%d", &type);
		if(type==1) {
			scanf("%d %d", &chef, &poison);
			if(leftChild[chef] != -1) {
				update(leftChild[chef],rightChild[chef],1,numChef,0,poison);
			}
		}
		else {
			scanf("%d", &chef);
			int ans = 0;
			if(leftChild[chef] != -1) {
				ans += query(leftChild[chef],rightChild[chef],1,numChef,0);
			}
			printf("%d\n", ans);
		}

		for(int i=0;i<=numChef;i++) {
			printf("\nHealth : %d\n", health[i]);
			printf("minHealth = %d\n", minHealth[i]);
			printf("lazy = %d\n", lazy[i]);
			printf("newChef = %d\n", newChef[i]);
		}
	}
}