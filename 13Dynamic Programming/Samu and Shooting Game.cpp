/*
Samu is playing a shooting game in play station. There are two apples to aim in this shooting game. Hitting first apple will provide her X points and hitting second apple will provide her Y points. And if she misses the apple she chose to hit, she wont get any point.
Now she is having N coins and each shoot will cost her 1 coin and she needs to score at least W points to win the game.

Samu don't like to loose at any cost. At each turn, she has two choices. The choices include:-

Hitting first apple with probability P1 percent. However, she might miss it with probability (1-P1) percentage.
Hitting second apple with probability P2 percent. However, she might miss it with probability (1-P2) percentage.
She would like to know what is the maximal expected probability(as a percentage b/w 0 and 100) of winning the shooting game.

Input Format: 
First line contains the number of test cases T. 
Each test case consists of six space separated integers of the form X Y N W P1 P2 as described in the statement.

Output Format: 
For each test case, print the result as described above in a separate line.

Note:
Choosing to hit any apple is entirely her choice. Both are independent events meaning P1 + P2 may/may not exceed 100.
Output must contain 6 digits after decimal.

Constraints: 
1 ≤ T ≤ 10 
1 ≤ X,Y ≤ 10 
1 ≤ N,W ≤ 103 
0 ≤ P1,P2 ≤ 100

Sample Input(Plaintext Link)
 1
2 3 2 5 50 25
Sample Output(Plaintext Link)
 12.500000
Explanation
Samu is getting 2 points from shooting first apple and 3 points from shooting second Apple.

She had 2 chances to shoot and she need to score atleast 5 points so anyhow she need to shoot Apple 1 in one shoot and Apple 2 in another shoot , if she wants to win.

The maximum probability of winning is 0.5 * 0.25 = 0.125 = 12.5%


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

double pp1;
double pp2;
int w;
int x,y;
int n;
double dp[1002][1002];

double solve(int n,int w){
    double ans=0;
    if(w<=0)
        return 1.0;
    if(n<=0)
        return 0.0;
    if(dp[w][n]!=-1)
        return dp[w][n];
    double ans1=pp1*solve(n-1,w-x)+(1.0-pp1)*solve(n-1,w);
    double ans2=pp2*solve(n-1,w-y)+(1.0-pp2)*solve(n-1,w);
    dp[w][n]=max(ans1,ans2);
    return dp[w][n];
}

int main()
{
	int t;
    int p1,p2;
    si(t);
    
    while(t--){
        scanf("%d %d %d %d %d %d",&x,&y,&n,&w,&p1,&p2);
     
      for(int i=1;i<=w;i++){
           for(int j=1;j<=n;j++){
               dp[i][j]=-1;
           }
       }
  
      	pp1 = p1 * 0.01;
      	pp2 = p2 * 0.01;
        printf("%.6f\n",solve(n,w)*100);
    }
    
	return 0;
}