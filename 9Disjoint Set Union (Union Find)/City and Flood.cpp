/*
Fatland is a town that started with N distinct empires, namely empires 1, 2, ..., N. But over time, the armies of some of these empires have taken over other ones. Each takeover occurred when the army of empire i invaded empire j. After each invasion, all of empire j became part of empire i, and empire j was renamed as empire i.

Empire Huang, leader of Badland, wants to invade Fatland. To do this, he needs to calculate how many distinct empires still remain in Fatland after all the takeovers. Help him with this task.

Input:

The first line contains an integer N, the number of empires that were originally in Fatland.

The second line contains an integer K, denoting the number of takeovers that took place.

Each of the next K lines contains 2 space-separated integers i, j, representing that the army of empire i took over that of empire j. As a result, empire j does not exist anymore and is now renamed as empire i. It is guaranteed that empire i still exists.

Output: Output one integer, the number of empires that exist in Fatland.

Constraints:

1 <= N <= 105

1 <= K <= 105

Sample Input(Plaintext Link)
 4
2
1 2
4 1
Sample Output(Plaintext Link)
 2
Explanation
Fatland started with empires 1, 2, 3, 4. First, empire 1 invaded empire 2, so empire 2 was renamed to empire 1. Then, empire 4 invaded empire 1. So what were at the beginning empires 1 and 2 were renamed to empire 4. Now, only empires 3 and 4 remain, so the answer is 2.

Time Limit: 1 sec(s) for each input file.
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


void initialize(vector <int> &v,int N)
{
    for(int i = 0;i<=N;i++)
    	v[ i ] = i ;
}
int root(vector <int> &v,int i)
{
    while(v[ i ] != i)           //chase parent of current element until it reaches root.
    {
    	i = v[ i ];
    }
    return i;
}

void union1(vector <int> &v,int A ,int B)
{
    int root_A = root(v,A);       
    int root_B = root(v,B);  
    v[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}
 
int main()
{
	int n,k;
	int x,y;
	si(n);
	
	si(k);
	vector <int> v;
	v.clear();
	v.resize(n+1);
	initialize(v,n);
	while(k--)
	{
		scanf("%d %d",&x,&y);
		union1(v,x,y);
	}
	
	int count = 0;
	for(int i=1 ; i<=n ; ++i)
	{
		if(v[i]==i)
			count++;
	}
	pi(count);
	pn;
}