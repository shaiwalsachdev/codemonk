/*
Monk has magical powers, by which he can compare any part of the strings 
and figure out if they're equal. 
His magical powers are faster than a super computer even. 
So, to prove his worth, he's given a string and he has to answer multiple queries based on the string.

Every query will have four integers - L1, R1, L2, R2. 
The first two integers denoting String [ L1, R1 ] (including both L1 and R1) 
denoting the first substring, the next two integers 
denoting the second substring String [ L2, R2 ] (including both L2 and R2).

For every query, you've to answer in Yes or No whether 
the two substrings are equal or not. Easy enough?

Input:
The first line contains a string, S.
Then, an integer Q denoting the number of queries in the next line.
Then, for every query, there will be 4 integers L1 R1 L2 R2, 
denoting the substring S[L1 R1] and S[L2 R2].

Output:
For each query output "Yes" if the two substrings are same , else output "No".

Constraints:
1 ≤ |S| ≤ 105
1 ≤ Q ≤ 105
1 ≤ L1 ≤ R1 ≤ |S|
1 ≤ L2 ≤ R2 ≤ |S|
The string will contain only lowercase letters.

Sample Input(Plaintext Link)
 monkandhismonkiness
4
1 1 3 3
1 4 11 14
3 3 6 6
4 5 14 17
Sample Output(Plaintext Link)
No
Yes
Yes
No
Explanation
For Query 1 , it denotes the substrings "m" and "n" which do not match
For Query 2 , it denotes the substrings "monk" and "monk" which do match
For Query 3 , it denotes the substrings "n" and "n" which do match
For Query 4 , it denotes the substrings "ka" and "ki" which do not match

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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

int main()
{
	string s;
	cin >> s;
	int q;
	int l1,r1,l2,r2;
	si(q);
	int flag = 1;
	for(int i = 1;i < s.size();i++){
		if(s[i] != s[i-1]){
			flag = 0;
			break;
		}

	}
	while(q--){
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		int flag1 = r1 - l1 + 1;
		int flag2 = r2 - l2 + 1;
		if(flag){
			
			if(flag1 == flag2)
				pm("Yes");
			else
				pm("No"); 
		}
		else{
			string a = s.substr(l1-1,flag1);
			string b = s.substr(l2-1,flag2);
			if(a==b)
				pm("Yes");
			else
				pm("No"); 

		}
	}

	return 0;
}