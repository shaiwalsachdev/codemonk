
/*
You are given a string S. S consists of several words separated by one or more spaces. Word consists of Latin letters as well as other symbols (but not spaces).
In each word which starts from lowercase Latin letter replace starting letter with uppercase Latin letter.

Input
The only line contains S

Output
Output one line with modified string S.

Constraints
1 <= length of S <= 30 000

Sample Input(Plaintext Link)
 Wish you were here
Sample Output(Plaintext Link)
 Wish You Were Here
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
 
int main(){
	string str;
	getline(cin,str);
	char och;
	char nch = str[0];
	int i = 1;
	if(isalpha(str[0]))
		str[0] = toupper(nch);
	for(int i = 1;i < str.length();i++){
		
		och =  nch;
		nch = str[i];
		if(och == ' ' && isalpha(nch))
			str[i] = toupper(nch);
	}
 
	cout << str <<endl;
	return 0;
}