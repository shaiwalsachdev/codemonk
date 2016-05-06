/*
You are given a number N. How many zeroes does N! end on?

Input
The first line contains one integer T - number of test cases. The following T lines contain one integer each - N.

Output
For each test case output one integer per line - the answer for this question.

Constraints

T <= 1000
0 <= N <= 1011
Sample Input(Plaintext Link)
 3
9
11
20
Sample Output(Plaintext Link)
 1
2
4
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


ll answer(ll p){
	ll k = 5;
	ll ans = 0;
	while(p > 1){
		p = p/k;
		ans +=  p;
		k = k * 5;
		 
	}
	return ans;
}
int main(){
	int t;
	si(t);
	while(t--){
		ll p;
		sl(p);
		pl(answer(p));
	}
	return 0;
}