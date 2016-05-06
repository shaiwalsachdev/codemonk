/*
Puchi was crossing a river by jumping over stepping stones, carrying a bag containing N integers. 
Our Monk saw him from the banks and shouted out to him. 
Shaken by the sudden shout, Puchi dropped the bag in the river and all the integers got wet! 
This upset the integers.
There are N stepping stones available ahead. Puchi wants to dry these integers on these stones, 
such that each stone contains a single integer. 
The upset value of the i'th integer Ai (after rearrangement of the integers) 
is (Ai ^ Ai-1 ^ Ai-2) times Pi for i ≥ 2, and 0 otherwise. (where '^' is the bit wise XOR operator). 
Here, i represents the position of the said integer.

Puchi asks our Monk to find an order of arranging the numbers on the stones, 
such that sum of upset values is minimized. 
Help our Monk find the order, given the arrays A and P .
Input:
First line contains T. T test cases follow.
First line of each test case contains an integer N.
Second line of each test case contains N integers, forming the array A.
Third line of each test case contains N integers, forming the array P.

Output:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 12
0 ≤ Ai ,Pi ≤ 200

Sample Input(Plaintext Link)
 2
4
2 5 4 6
1 1 1 1
5
13 3 9 4 2
1 1 1 1 1
Sample Output(Plaintext Link)
 1
14
Explanation
For the first test case, optimal ordering can be 5 6 2 4. 
The upset values will be 0 ,0 ,(5^6^2)x1 , (6^2^4)x1 which amounts to 0+0+1+0=1.
For the second test case, optimal ordering can be 3 2 9 13 4. 
The upset values will be 0 ,0 ,(3^2^9)x1 ,(2^9^13)x1 ,(9^13^4)x1 which amounts to 8+6+0=14

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
int n;
vector<int> a, p;
 
int dp[12][1<<12][12][12];
bool exist[12][1<<12][12][12];
 
int solve(int i,  int mask, int p1, int p2)
{
	if (i == n) {
		return 0;
	}
 	if (!exist[i][mask][p1][p2]) {		
		int answer = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (!(mask & (1 << j))) {
				int cost = (a[p1] ^ a[p2] ^ a[j]) * p[i];
				answer = min(answer,  cost + solve(i+1, (mask | (1 << j)), p2, j));
			}
		}
		dp[i][mask][p1][p2] = answer;
		exist[i][mask][p1][p2] = true;
	}
 
	return dp[i][mask][p1][p2];
}
 
int main()
{
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		memset(exist, 0, sizeof(exist));
		
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		p.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int answer = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					int mask = 0;
					mask |= (1 << i);
					mask |= (1 << j);
					answer = min(answer, solve(2, mask, i, j));
				}
			}
		}
		cout << answer << endl;
	}
}