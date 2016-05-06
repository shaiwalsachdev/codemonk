/*
There are N ants staying 
at the vertices of the N-regular polygon 
(one ant at one vertex). 
At some moment of time all the ants 
choose one of the edges their vertex 
is adjacent to and start walking along this edge. 
If two ants meet at some point of the edge they die. 
Please find the probability that all the ants will survive.

Input
The first line contains one integer T - number of test cases. 
The following T lines contain one integer each - N.

Output
We can consider answer as a fraction P / Q. 
For each test case output P * Q-1 modulo 109 + 7.

Constraints

T <= 1000
3 <= N <= 1011
Sample Input(Plaintext Link)
 1
3
Sample Output(Plaintext Link)
 250000002
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


const long long MOD = 1E9 + 7;
ll power(ll a, ll b) {
	//cout << a << " " << b << endl;
	ll ans = 1;
	while(b) {
		if(b%2) ans = (ans * a)%MOD;
		b = b/2;
		a = (a*a)%MOD;
	}
 
	return ans;
}

int main() {
    int t;
    si(t);
    while (t--) {
    	ll n;
    	sl(n);
    	ll ans = power(2, n - 1);
    	ans = power(ans, MOD - 2);
    	pl(ans);
    	pn;
    
    }
    return 0;
}