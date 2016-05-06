/*Chandu is very fond of strings. (Or so he thinks!) But, he does not like strings which have same consecutive letters. No one has any idea why it is so. He calls these strings as Bad strings. So, Good strings are the strings which do not have same consecutive letters. Now, the problem is quite simple. Given a string S, you need to convert it into a Good String.

You simply need to perform one operation - if there are two same consecutive letters, delete one of them.

Input:
The first line contains an integer T, denoting the number of test cases.
Each test case consists of a string S, which consists of only lower case letters.

Output:
For each test case, print the answer to the given problem.

Constraints:
1 <= T <= 10
1 <= |S| <= 30

Sample Input(Plaintext Link)
 3
abb
aaab
ababa
Sample Output(Plaintext Link)
 ab
ab
ababa
Explanation
In the first case, S = "abb". Since, S has same consecutive letter 'b' we will delete one of them. So, the good string will be "ab".

In the second case, S = "aaab" and since S has same consecutive letter 'a' we will delete them one by one. aaab -> aab -> ab. So, the good string will be "ab".

In the third case, S = "ababa" and S has no same consecutive letter. So, the good string will be "ababa".*/
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
	si(t);
	while(t--){
		string str;
		string ans = "";
		cin >> str;
		char c = str[0];
		ans = ans + c;
		for(int i = 1;i < str.size();i++){
			if(c == str[i])
			  	continue;
			else {
				ans = ans + str[i];
				c = str[i];
			}
		}
		pm(ans.c_str());
	}

   return 0;	
}