/*
Monk's birthday is coming this weekend! He wants to plan a Birthday party and is preparing an invite list with his friend Puchi. He asks Puchi to tell him names to add to the list.
Puchi is a random guy and keeps coming up with names of people randomly to add to the invite list, even if the name is already on the list! Monk hates redundancy and hence, enlists the names only once. 
Find the final invite-list, that contain names without any repetition.

Input:
First line contains an integer T. T test cases follow.
First line of each test contains an integer N, the number of names that Puchi pops up with.

Output:
For each testcase,Output the final invite-list with each name in a new line. The names in the final invite-list are sorted lexicographically.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Length of each name ≤ 105

Sample Input(Plaintext Link)
 1
7
chandu
paro
rahul
mohi
paro
arindam
rahul
Sample Output(Plaintext Link)
 arindam
chandu
mohi
paro
rahul
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

	int t;
	si(t);
	while(t--){
		int n;
		si(n);
		
		map<string,int> mp;
		string flag;
		
		for(int i = 0;i < n;i++){
			cin >> flag;
			
			if(mp.count(flag) == 0)
				mp[flag] = 1;
		}
		map<string,int> :: iterator it;
		for(it=mp.begin();it!=mp.end();it++)
    	{
    		cout<<it->first<<endl;
    	}

	}
	return 0;
}