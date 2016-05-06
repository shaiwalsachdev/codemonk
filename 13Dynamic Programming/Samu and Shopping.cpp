/*
Samu is in super market and in a mood to do a lot of shopping. 
She needs to buy shirts, pants and shoes for herself and her family. 
There are N different shops. Each shop contains all these three items 
but at different prices. Now Samu has a strategy that she won't 
buy the same item from the current shop if she had already bought 
that item from the shop adjacent to the current shop.

Now Samu is confused, because although she want to follow her strategy 
strictly but at the same time she want to minimize the total money 
she spends on shopping. Being a good programmer, she asks for your help.

You are provided description about all N shops i.e costs of all three 
items in each shop. You need to help Samu find minimum money that 
she needs to spend such that she buys exactly one item from every shop.

Input Format: 
First line contain number of test cases T. Each test case in its first 
line contain N denoting the number of shops in Super Market. 
Then each of next N lines contains three space separated integers 
denoting cost of shirts, pants and shoes in that particular shop.

Output Format:
For each test case, output the minimum cost of shopping taking 
the mentioned conditions into account in a separate line.

Constraints :
1 ≤ T ≤ 10 
1 ≤ N ≤ 105
Cost of each item (shirt/pant/shoe) does not exceed 104

Sample Input(Plaintext Link)
 1
3
1 50 50
50 50 50
1 50 50
Sample Output(Plaintext Link)
 52
Explanation
There are two ways, each one gives 52 as minimum cost. One way is buy shirt from first shop, pant from second shop and shirt from third shop or she can buy shirt from first shop, shoe from second shop and shirt from third shop.

Both ways , cost comes up to 1 + 50 + 1 = 52

Time Limit: 2 sec(s) for each input file.

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
	int t;
	si(t);
	while(t--){
		int n;
		si(n);
		int dp[n][3];
		int cost[n][3];
		memset(dp,0,sizeof(dp));

		for(int i = 0;i < n;i++){
			scanf("%d %d %d",&cost[i][0],&cost[i][1],&cost[i][2]);
		}
	
		dp[0][0] = cost[0][0];
		dp[0][1] = cost[0][1];
		dp[0][2] = cost[0][2];

		for(int i = 1;i < n;i++){
			dp[i][0] =  min(dp[i-1][1],dp[i-1][2]) + cost[i][0];
			dp[i][1] =  min(dp[i-1][0],dp[i-1][2]) + cost[i][1];
			dp[i][2] =  min(dp[i-1][0],dp[i-1][1]) + cost[i][2]; 
		}
		pi(min(dp[n-1][2],min(dp[n-1][0],dp[n-1][1])));
		pn;		
	}
	return 0;
}