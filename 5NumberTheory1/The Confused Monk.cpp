/*
The Monk wants to teach all its disciples a lesson about patience, 
since they are always in a hurry to do something crazy. To teach them this, 
he gives them a list of N numbers, which may or may not be distinct. 
The students are supposed to solve a simple Mathematical equation based
on the array of these N numbers.

g(x) - GCD (a[ 0 ], a[ 1 ], a[ 2 ]... a[n-1] )
f(x) - (a[ 0 ] * a[ 1 ] * a[ 2 ]... * a[n-1] )
The value of the MonkQuotient is: 10^9 + 7.

The equation to be solved is: ( f(x)^g(x) ) % MonkQuotient

Input constraints:
The first line of input will contain an integer — N. 
The next line will contain N integers denoting the elements of the list.

Output constraints:
Print the required answer of the equation.

Constraints:
1 ≤ N ≤ 50 
1 ≤ Ai ≤ 103

Sample Input(Plaintext Link)
 2
2 6
Sample Output(Plaintext Link)
 144
Explanation
Here we can see that the product of the elements of array is 12 and the GCD of the array comes out to be 2 . Thus the answer would be 12^2 which is 144.
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
ll mod = 1e9 + 7;
int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

ll midpow(ll a,ll b){
	
	ll sum = 1;
	while(b!=0){
		if(b%2==1){
			sum = (sum*a)%mod;
		}
		a = (a*a)%mod;
		b=b/2;
	}
	return sum;
}
int main(){
	vector<ll> v;
	int n;
	si(n);
	ll fx = 1;
	ll gx = 0;
	v.clear();
	v.resize(n);
	for(int i = 0;i<n;i++)
		sl(v[i]);

	sort(v.begin(),v.end());
	if(n>=2){
		gx = gcd(v[0],v[1]);
		for(int i = 2;i<n;i++)
			gx = gcd(gx,v[i]);
	}
	else {
		gx = v[0];
	}

	for(int i = 0;i<n;i++){
		fx = fx * v[i];
		fx = fx % (mod);
	}
	
	pl(midpow(fx,gx));
	pn;

	return 0;
}