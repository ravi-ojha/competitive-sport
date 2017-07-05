#include <bits/stdc++.h>
using namespace std;

void break(int target, int coins[])
{
	coinslimit = {target/coins[0], target/coins[1]};
	vector <int> t1;
	vector <int> t2;
	for(int j=0;j<=coinslimit[0];j++)
	{
		t1.push_back(j);
	}
	for(int j=0;j<=coinslimit[1];j++)
	{
		t2.push_back(j);
	}

	vector <int> t3;
	vector <int> t4;

	for(int i=0;i<t1.size();i++)
	{

	}


}

int ac = 421;
int cc = 11;

int target = 4000;


void method2(){

    int da = target/ac;

    for(int i=0;i<=da;i++){
            int rem = target-(i*ac);
            if(rem < 0){
                break;
            }else{
                if(rem%cc==0){
                    printf("\n%d, %d ---- %d + %d = %d \n", i, rem/cc, i*ac, (rem/cc)*cc, target);
                }
            }
        }
    }
}

int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{

	}
	return 0;
}
