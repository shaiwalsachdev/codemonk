/*
Monk A loves to complete all his tasks just before the deadlines for introducing unwanted thrill in his life. But, there is another Monk D who hates this habit of Monk A and thinks it's risky.

To test Monk A, Monk D provided him tasks for N days in the form of an array Array, where the elements of the array represent the number of tasks.

The number of tasks performed by Monk A on the ith day is the number of ones in the binary representation of Arrayi.

Monk A is fed up of Monk D, so to irritate him even more, he decides to print the tasks provided in non-decreasing order of the tasks performed by him on each day. Help him out!

Input:
The first line of input contains an integer T, where T is the number of test cases.
The first line of each test case contains N, where N is the number of days.
The second line of each test case contains Array array having N elements, where Arrayi represents the number of tasks provided by Monk D to Monk A on ith day.

Output:
Print all the tasks provided to Monk A in the non-decreasing order of number of tasks performed by him.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= Arrayi <= 1018

Note:
If two numbers have the same number of ones (set bits), print the one which came first in the input first, and then the other one, as in the input.

Sample Input(Plaintext Link)
 1
4
3 4 7 10
Sample Output(Plaintext Link)
 4 3 10 7
Explanation
In the sample input, T = 1 and N = 4, where N is the number of days.

Tasks provided to Monk A on first day is 3 and binary representation of 3 is { 11 }2, which contains 2 ones.

Tasks provided to Monk A on second day is 4 and binary representation of 4 is { 100 }2, which contains 1 ones.

Tasks provided to Monk A on third day is 7 and binary representation of 7 is { 111 }2, which contains 3 ones.

Tasks provided to Monk A on fourth day is 10 and binary representation of 10 is { 1010 }2, which contains 2 ones.

So the Output will be: 4 3 10 7

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

ll count (ll n){
	ll c = 0;
	while(n!=0){
		if(n%2==1)
			c++;
		n = n/2;
	}
	return c;
}
bool compare(const pair<ll,ll> &a,const pair<ll,ll> &b){
	if(a.second < b.second)
		return 1;
	else
		return 0;
}
int main(){
	int t;
	si(t);
	while(t--){
		ll n;
		sl(n);
		ll temp;
		vector<pair<ll,ll> > v;
		for(ll i = 0;i < n;i++){
			sl(temp);
			
			v.push_back(make_pair(temp,count(temp)));
		}
		
		stable_sort(v.begin(),v.end(),compare);
		
		for(int i = 0;i < n;i++){
			printf("%lld ",v[i].first);
		}
		pn;
	}

	return 0;
}