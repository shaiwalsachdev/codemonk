/*
You have a graph with N vertices and M edges. 
Someone has chosen N-1 edges of these M and claims 
that they form a spanning tree. Just check whether it's true or not.

Input

The first line contains one integer T denoting the number of test cases.
Each test case starts with a line containing 2 space-separated integers: N and M. 
Each of the following M lines contains description of one edge: 
two different space-separated integers a and b from 
1 to N each - numbers of vertices that are connected by this edge. 
The last line of each test case contains N - 1 space-separated integers - numbers of chosen edges. 
Edges are enumerated from 1 in the input order.

Output

For each test case output either YES if the chosen N-1 edges form a spanning tree or NO otherwise.

Constrains

1 <= T <= 20
1 <= N <= 5000
1 <= M <= 40 000
Sample Input(Plaintext Link)
2
4 4
1 2
1 3
2 3
1 4
1 2 3
4 4
1 2
1 3
2 3
1 4
2 3 4

Sample Output(Plaintext Link)
 NO
YES
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

int flag;
int ans;
int root(vector <int> &v,int i)
{
    while(v[ i ] != i)           //chase parent of current element until it reaches root.
    {
    	v[i] = v[v[i]];
    	i = v[ i ];
    }
    return i;
}
void union1(vector <int> &v,int A ,int B)
{
    int root_A = root(v,A);       
    int root_B = root(v,B); 
    if(root_A==root_B){
    	flag = 0;
    	return ; 
    }
    v[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}


int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		int i,j;
		vector <int> v;
		v.clear();
		v.resize(n+1,0);
		for(i=1;i<=n;i++)
			v[i]=i;

		int xx,yy;
		vector <pii > vv;
		vv.clear();
		
		vv.push_back(mp(0,0));
		for(i=1;i<=m;i++)
		{
			 
			scanf("%d %d",&xx,&yy);
			vv.push_back(mp(xx,yy));
		}

		ans = 0;
		
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&j);
			int x,y;
			flag = 1;
			x=vv[j].first;y=vv[j].second;
			union1(v,x,y);
			if(flag==0){
				ans++;
			}
		}

		
		if(ans>0)
			pm("NO");
		else
			pm("YES");
	}
	return 0;
}
