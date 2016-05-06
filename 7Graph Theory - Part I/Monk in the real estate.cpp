/*
The Monk wants to buy some cities. To buy two cities, he needs to buy the road connecting those two cities. Now, you are given a list of roads, bought by the Monk. You need to tell how many cities did the Monk buy.

Input:
First line contains an integer T, denoting the number of test cases. The first line of each test case contains an integer E, denoting the number of roads. The next E lines contain two space separated integers X and Y, denoting that there is an road between city X and city Y.

Output:
For each test case, you need to print the number of cities the Monk bought.

Constraint:
1 <= T <= 100
1 <= E <= 1000
1 <= X, Y <= 10000

Sample Input(Plaintext Link)
 1
3
1 2
2 3
1 3
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

int main(){

	int t;
	si(t);
	while(t--){
		int e;
		si(e);
		int x,y;
		vector<bool> v(10001,false);
		for(int i = 1;i <= e ;i++){
			scanf("%d %d",&x,&y);
			v[x] = true;
			v[y] = true;
		}
		int count = 0;
		for(int i = 1;i <= 10000 ;i++){
			if(v[i]==true)
				count++;
		}
		pi(count);
		pn;
	}
	return 0;
}