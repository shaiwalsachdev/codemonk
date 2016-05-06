/*
Problem Statement : You are given a 2-D matrix A of n rows and m columns 
where A[i][j] denotes the calories burnt. Two persons, a boy and a girl, 
start from two corners of this matrix. The boy starts from cell (1,1) 
and needs to reach cell (n,m). On the other hand, 
the girl starts from cell (n,1) and needs to reach (1,m). 
The boy can move right and down. The girl can move right and up. 
As they visit a cell, the amount in the cell A[i][j] is added to 
their total of calories burnt. You have to maximize the sum of 
total calories burnt by both of them under the condition that 
they shall meet only in one 
cell and the cost of this cell shall not be included in either of their total.
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
#define MAX 1005
int boy1[MAX][MAX];
int boy2[MAX][MAX];
int girl1[MAX][MAX];
int girl2[MAX][MAX];
int main(){
	int n,m;
	//scanf("%d %d",&n,&m);
	cin >> n >> m;

	int cal[MAX][MAX];



	
	
	for(int i = 1;i <=n;i++)
		for(int j = 1;j <=m;j++){
			//si(cal[i][j]);
			cin >> cal[i][j];
		}

	// For storing Boy from start to every position
	for(int i = 1;i <=n;i++)
		for(int j = 1;j <=m;j++)
			boy1[i][j] =  max(boy1[i-1][j],boy1[i][j-1]) + cal[i][j];
		
	//Boy from end point  to every position
	for(int i = n;i >=1;i--)
		for(int j = m;j >=1;j--)
			boy2[i][j] =  max(boy2[i+1][j],boy2[i][j+1]) + cal[i][j];

	// Girl From (n,1) to every position

	for(int i = n;i >=1;i--)
		for(int j = 1;j <=m;j++)
			girl1[i][j] =  max(girl1[i][j-1],girl1[i+1][j]) + cal[i][j];

    // Girl from (1,m) to every position

	for(int i = 1;i <=n;i++)
		for(int j = m;j >=1;j--)
			girl2[i][j] =  max(girl2[i][j+1],girl2[i-1][j]) + cal[i][j];

    // Meeting Point
    int ans = 0;
	for(int i = 2;i <n;i++){
		for(int j = 2;j <m;j++){
			int op1 = boy1[i][j-1] +  boy2[i][j+1] + girl1[i+1][j] +  girl2[i-1][j];
			int op2 = boy1[i-1][j] +  boy2[i+1][j] + girl1[i][j-1] +  girl2[i][j+1];
			ans = max(ans,max(op1,op2));

		}
	}
	cout << ans << endl;
	//pi(ans);
	//pn;
	return 0;
}
