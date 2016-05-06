/*
Problem Statement : You can read the problem statement here: 
Robots and Paths Input is three integers M, N and P denoting the number of rows, 
number of columns and number of blocked cells respectively. In the next P lines, 
each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.
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
#define MOD 1000000007
int main(){

	int m,n,p;
	scanf("%d %d %d",&m,&n,&p);

	int Nways[m][n];

	memset(Nways,0,sizeof(Nways));
	int x,y;
	for(int i = 1;i <= p;i++){
		scanf("%d %d",&x,&y);
		Nways[x][y] = -1;
	}


	if(Nways[0][0] == -1){
		pm("0");
		pn;
		return 0;
	}
	else
		Nways[0][0] = 1;



	for(int i = 1;i < m;i++){
		if(Nways[i][0] != -1){
			Nways[i][0] = 1;
		}
		else
			break;
	}

	for(int i = 1;i < n;i++){
		if(Nways[0][i] != -1){
			Nways[0][i] = 1;
		}
		else
			break;
	}

	for(int i = 1;i < m;i++){
		for(int j = 1;j < n;j++){
			if(Nways[i][j] == -1)
				break;
			if(Nways[i][j-1] > 0)
				Nways[i][j] = (Nways[i][j] + Nways[i][j-1] + MOD) % MOD;

			if(Nways[i-1][j] > 0)
				Nways[i][j] = (Nways[i][j] + Nways[i-1][j] + MOD) % MOD;
		}
	}
	
	int ii,jj;
	pn;
	pm("Enter Destination:");
	
	scanf("%d %d",&ii,&jj);
	if(Nways[ii][jj] == -1){
		pm("0");
		pn;
	}
	else{
		pi(Nways[ii][jj]);
		pn;
	}

	return 0;
}