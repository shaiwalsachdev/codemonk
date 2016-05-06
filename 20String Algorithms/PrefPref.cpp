/*
You are given two string S and T. Find the maximal length of some prefix of the string S which occurs in strings T as subsequence.

Input
The first line contains string S. The second line contains string T. Both strings consist of lowecase Latin letters.

Output
Output one integer - answer to the question.

Constraints
1 <= length of S, T <= 106

Sample Input(Plaintext Link)
 digger
biggerdiagram
Sample Output(Plaintext Link)
 3
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

int main()
{

	string s,t;
	cin >> s;
	cin >> t;
	int j = 0;
	int count = 0;
	for(int i = 0;i < t.length();i++){
		if(s[j]==t[i]){
			count++;
			j++;
		}
	}
	pi(count);
	pn;
	
	return 0;
}