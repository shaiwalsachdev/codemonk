/*
You are given a string S. 
Find the length of its the longest substring which occurs at least two times. 
Occurences can intersect.

Input
One line containing a string S consisting of lowercase Latin letters.

Output
Output one integer - answer to the question.

Constraints
1 <= length of S <= 1000000

Sample Input(Plaintext Link)
 abacaba
Sample Output(Plaintext Link)
 3

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
#define MAX 1000000

ll roll[1000001];
unordered_set <long long> S;
ll st[1000001];
string str;
int check(int span)
{
	S.clear();
	
	for (int i=0;i+span<=str.size();i++)
	{
		long long Q=st[i+span]-st[i];
		Q*=roll[1000000-i];
		if (S.find(Q)!=S.end())
			return true;
		S.insert(Q);
	}
	
	return false;
}
int main(){
	
	cin >>  str;
	ll len = str.length();

	roll[0] = 1;
	for(ll i = 1;i <=1000000;i++)
		roll[i] = roll[i-1]*173;


	for(ll i = 1;i <=str.size();i++){
		st[i] = st[i-1] + str[i-1]*roll[i-1];
	}
	ll left,right;
	left = 0;
	right = str.size();

	// binary search
	while (left<right)
	{
	ll mid = left + right + 1;
	mid/=2;
	if (check(mid))
		left = mid;
	else
		right = mid-1;
	}
	pl(left);
	pn;

	return 0;
}