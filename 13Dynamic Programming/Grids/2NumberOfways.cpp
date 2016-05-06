/*
Problem Statement : Given a 2-D matrix with M rows and N columns, 
find the number of ways to reach cell with coordinates (i,j) from starting cell 
(0,0) under the condition that you can only travel one step right or one step down.
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

	int NWays[m][n];

	memset(NWays,0,sizeof(NWays));
	NWays[0][0] = 1;

	for(int i = 1;i < m;i++)
		NWays[i][0] = 1;

	for(int i = 1;i < n;i++)
		NWays[0][i] = 1;

	for(int i = 1;i < m;i++){
		for(int j = 1;j < n;j++){
			NWays[i][j] = NWays[i][j-1] + NWays[i-1][j];
		}
	}
	
	int ii,jj;
	pn;
	pm("Enter Destination:");
	
	scanf("%d %d",&ii,&jj);
	pi(NWays[ii][jj]);
	pn;

	return 0;
}