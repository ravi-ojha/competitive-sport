#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long int lli;

#define outd(x) printf("%lld", x)
#define inpd(x) scanf("%lld", &x)
#define spc cout<<" "
#define nl cout<<endl
#define mod 1000000007

lli fact(lli n){
	if(n == 0) return 1;
	lli f = n;
	while(--n){
		f *= n;
		f %= mod;
	}
	return (f%mod);
}
int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(0);
	lli t;
	cin >> t;
	while(t--){
		lli n, k;
		cin >> n >> k;
		lli c[200];

		vector<lli> a;
		vector<lli> b;
		
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; i++){
			lli x;
			cin >> x;
			x--;
			if(!c[x]) a.push_back(x);
			c[x] += 1;
		}
		sort(a.begin(), a.end());
		lli sz = a.size();
		lli ans = 0, i = sz-1;
		if(sz > 0)
		while(k-- && i >= 0){
			ans = (ans + (c[a[i]]*fact(n-1))%mod) %mod;				
			i--;
		}
		cout << ans;nl;
	}
	return 0;
}
