/*Chandu is a bad student. Once his teacher asked him to print the reverse of a given string. He took three hours to solve it. The teacher got agitated at Chandu and asked you the same question. Can you solve it?

Input:
The first line contains an integer T, denoting the number of test cases.
Each test case contains a string S, comprising of only lower case letters.

Output:
For each test case, print the reverse of the string S.

Constraints:

1 <= T <= 10
1 <= |S| <= 30

Sample Input(Plaintext Link)
 2
ab
aba
Sample Output(Plaintext Link)
 ba
aba
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
	int t;
	string str;
	si(t);
	while(t--){
		cin >> str;
		int len = str.size();
		int l = len - 1;
		for(int i = 0;i < len/2;i++){
			char c = str[i];
			str[i] = str[l];
			str[l] = c;
			l--;
		}
		pm(str.c_str());

	}

	return 0;
}