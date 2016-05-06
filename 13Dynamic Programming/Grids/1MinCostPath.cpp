/*
Problem Statement : Given a cost matrix Cost[][] 
where Cost[i][j] denotes the Cost of visiting cell with coordinates (i,j), 
find a min-cost path to reach a cell (x,y) from cell (0,0) under the condition that you can only travel one step right 
or one step down. (We assume that all costs are positive integers)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define si(a)     scanf("%d", &a)
#define sl(a)     scanf("%lld", &a)
#define pi(a)     printf("%d", a)
#define pl(a)     printf("%lld", a)
#define pm(str)   printf("%s\n",str)
#define pn        printf("\n")

int main(){

	int m,n;
	scanf("%d %d",&m,&n);

	int Cost[m][n];

	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)
			scanf("%d",&Cost[i][j]);

	int MinCost[m][n];

	memset(MinCost,0,sizeof(MinCost));
	MinCost[0][0] = Cost[0][0];

	for(int i = 1;i < m;i++)
		MinCost[i][0] = Cost[i][0] + MinCost[i-1][0];

	for(int i = 1;i < n;i++)
		MinCost[0][i] = Cost[0][i] + MinCost[0][i-1];

	for(int i = 1;i < m;i++){
		for(int j = 1;j < n;j++){
			MinCost[i][j] = min(MinCost[i][j-1],MinCost[i-1][j])+Cost[i][j];
		}
	}
	
	pi(MinCost[m-1][n-1]);
	pn;

	return 0;
}