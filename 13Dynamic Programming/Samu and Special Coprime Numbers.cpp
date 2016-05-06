/*
Samu had come up with new type of numbers, 
she named them Special Coprime numbers. 
Special Coprime numbers follow a property : 
A number N is said to be Special Coprime 
if sum of its digits as well as the sum of 
the squares of its digits are coprime to each other.

Now she started counting numbers that are Special Coprime. 
But soon she get bored and decided to write a program that can help do it. 
Now she want you to help her to find count of such numbers between L and R ,
 where both L and R are included.

Input Format : 
First line contain number of test cases T.
Each test case contains two space separated 
integers L and R, denoting the range in
which you need to find the count of Special Coprime numbers.

Output Format : 
For each test case you need to print the count of such numbers in range [L,R]

Constraints :
1 ≤ T ≤ 10^3 
1 ≤ L ≤ R ≤ 10^18

Sample Input(Plaintext Link)
 1
5 15
Sample Output(Plaintext Link)
 3
Explanation
Between 5 and 15 there are 3 Special Coprime numbers : 10 , 12 , 14
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

ll int digit[20];
ll int len;
ll  dp[20][200][1500];
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
ll solver(int pos , int sum,int sqsum,int check)
{
    ll int endr,curr,ans=0;

    if(pos==-1 && sum==0)
        return 0;
    if(pos==-1)
        return __gcd(sum,sqsum)==1;

    if(!check && dp[pos][sum][sqsum]!=-1)
        return dp[pos][sum][sqsum];

    if(check==1)
        endr=digit[pos];
    else
        endr=9;

    for(curr=0;curr<=endr;curr++)
    {
        ans+=solver(pos-1,sum+curr,sqsum+curr*curr,check && curr==endr);
    }

    if(!check)
        dp[pos][sum][sqsum]=ans;

    return ans;

}

ll findout(ll num)
{
    ll x;
    len=0;
    while(num>0)
    {
        digit[len++]=num%10;
        num/=10;
    }
  
    return solver(len-1,0,0,1);
}
int main()
{
    ll int t,l,r,num,i,j,k;
    for(i=0;i<20;i++)
            for(j=0;j<200;j++)
                for(k=0;k<1500;k++)
                    dp[i][j][k]=-1;
   
    si(t);
	while(t--)
    {
        cin>>l>>r;
        cout<<findout(r)-findout(l-1)<<endl;
    }
}
