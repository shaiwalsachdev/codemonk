/*
As the Monk is also taking part in the CodeMonk Series, this week he learned about hashing. Now he wants to practice some problems. So he came up with a simple problem. Firstly, he made a hash function F such that:

F(x) = x % 10

Now using this function he wants to hash N integers and count the number of collisions that will occur while hashing the integers.

Input:
The first line contains an integer T, denoting the number of test cases.
The first line of each test case contains an integer N, denoting the number of integers to hash.
The next line contains N space separated integers, denoting the integer X to hash.

Output:
For each test case, print the number of collisions that will occur while hashing the integers.

Constraints:
1 <= T <= 10
1 <= N <= 100
0 <= X <= 105

Sample Input(Plaintext Link)
 2
3
1 2 3
4
1 1 2 3
Sample Output(Plaintext Link)
 0
1
Explanation
In the first case, there will be no collisions as each integer will be hashed to a different index.
F(1) = 1 % 10 = 1
F(2) = 2 % 10 = 2
F(3) = 3 % 10 = 3

In the second case, there will be 1 collision at index 1 as the first two integers will hash to the same index.

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
		int n;
		si(n);
		int x;
		vector<int> v(10,-1);
		int count = 0;
		for(int i = 0;i < n;i++){
			si(x);
			int index = x % 10;
			if(v[index]!= -1)
			    count++;
			else
			   v[index] = x;
		}
		pi(count);
		pn;

	}
	return 0;
}