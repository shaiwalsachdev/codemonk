/*
Our Code Monk recently learnt about Graphs and is very excited!

He went over to the Graph-making factory to watch some freshly prepared graphs. 
Incidentally, one of the workers at the factory was ill today,
 so Monk decided to step in and do her job.

The Monk's Job is to Identify whether the incoming graph is a tree or not. 
He is given N, the number of vertices in the graph and the degree of each vertex.

Find if the graph is a tree or not.

Input:
First line contains an integer N, the number of vertices.
Second line contains N space-separated integers, the degrees of the N vertices.

Output:
Print "Yes" (without the quotes) if the graph is a tree or "No" (without the quotes) otherwise.

Constraints:
1 ≤ N ≤ 100
1 ≤ Degreei ≤ 1000

References:
Graphs and Trees

Sample Input(Plaintext Link)
 3
1 2 1
Sample Output(Plaintext Link)
 Yes
Time Limit: 2 sec(s) for each input file.
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
	int N;
	si(N);
	vector<int> v;
	v.clear();
	v.resize(N,0);
	ll sum = 0;
	for(int i = 0;i < N;i++){
		si(v[i]);
		sum = sum + v[i];
	}
	if(sum==2*(N-1))
		pm("Yes");
	else
		pm("No");

	return 0;
}