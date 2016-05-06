/*
This is the story in Zimbo, the kingdom officially made for monkeys. 
Our Code Monk visited Zimbo and declared open a challenge in the kingdom, 
thus spoke to all the monkeys :

You all have to make teams and go on a hunt for Bananas. 
The team that returns with the highest number of Bananas will be 
rewarded with as many gold coins as the number of Bananas with them. May the force be with you!

Given there are N monkeys in the kingdom. Each monkey who wants to team 
up with another monkey has to perform a ritual. Given total M rituals are performed. 
Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, 
then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.

Input:
First line contains an integer T. T test cases follow. 
First line of each test case contains two space-separated N and M. M lines follow. 
Each of the M lines contains two integers Xi and Yi, 
the indexes of monkeys that perform the i'th ritual. 
Last line of the testcase contains N space-separated integer constituting the array A.

Output:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 105
0 ≤ M ≤ 105
0 ≤ Ai ≤ 1012

Sample Input(Plaintext Link)
 1
4 3
1 2
2 3
3 1
1 2 3 5
Sample Output(Plaintext Link)
 6
Explanation
Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.

Time Limit: 3 sec(s) for each input file.
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
vector<int> adj[100001];

void dfs(int i,vector<bool> &visited,vector<ll> &v,ll &sum){
	visited[i] = true;
	sum = sum + v[i];
	for(int j = 0;j < adj[i].size();j++){
		if(visited[adj[i][j]]==false){
			dfs(adj[i][j],visited,v,sum);
		}
	}
}


int main(){
	int t;
	si(t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)
			adj[i].clear();
		
		vector<bool> visited(n+1,false);
		vector<ll> v(n+1,0);
		int x,y;
		for(int i = 1; i<= m;i++){
			scanf("%d %d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}

		for(int i = 1;i <= n;i++)
			sl(v[i]);
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			if(visited[i]==false){
				ll s = 0;
				dfs(i,visited,v,s);
				ans = max(ans,s);

			}
		}
		pl(ans);
		pn;

	}
	return 0;
}