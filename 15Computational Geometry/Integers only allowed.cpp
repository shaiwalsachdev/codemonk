/*
You have a polygon described by coordinates of its vertices. Can you find how many points with integer coordinates lay strictly inside it?

Input
The first line contains an integer N - number of vertices. Next N lines contain 2 space-separated integers each and describe polygon vertices in clockwise order. Note that polygon can be convex and non-convex as well.

Output
Output one integer - answer for the problem

Constraints

3 <= N <= 1000
|xi|, |yi| <= 106
Sample Input(Plaintext Link)
 4
0 0
0 2
2 2
2 0
Sample Output(Plaintext Link)
 1
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

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	int n;
	vector<ll> x;
	vector<ll> y;
	si(n);
	x.clear();
	y.clear();
	x.resize(n+1);
	y.resize(n+1);


	for(int i = 0;i < n;i++)
		scanf("%lld %lld",&x[i],&y[i]);

	x[n] = x[0];
	y[n] = y[0];

	ll area = 0;
	for (int i=0;i<n;i++)
		area += x[i+1]*y[i]-x[i]*y[i+1];
	
	area = abs(area)/2;
	
	ll u = 0;
	ll border = 0;
	for(int i = 0;i < n;i++){
		u = gcd(abs(x[i+1]-x[i]),abs(y[i+1]-y[i]));
		cout << u << endl;
		border += u;	
	}

	

	pl(abs(area+1)-(border/2));
	pn;
	return 0;
}