/*
You are given a string S. Find the number of different substrings in S.

Input
One line containing a string S consisting of lowercase Latin letters.

Output
Output one integer - answer to the question.

Constraints
1 <= length of S <= 1200

Sample Input(Plaintext Link)
 abc
Sample Output(Plaintext Link)
 6

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


int main(){
	set <ll> substrings;
	
	int prime  = 101;
	string str;
	cin >> str;
	int l = str.length();
	for(int i = 0;i < l;i++){
		ll p = 0;
		string s = "";
		for(int j = i;j < l;j++){
			p = p*101 + str[j];
			s = s +str[j];
			cout << s <<endl;
			substrings.insert(p);
		}

	}
	cout <<substrings.size() << endl;

	return 0;
}