/*
You are given a weighted graph with N vertices and M edges. Find the total weight of its maximum spanning tree.

Input

The first line contains one integer T denoting the number of test cases. Each test case starts with a line containing 2 space-separated integer: N and M. Each of the following M lines contain description of one edge: three different space-separated integers: a, b and c. a and b are different and from 1 to N each and denote numbers of vertices that are connected by this edge. c denotes weight of this edge.

Output

For each test case output one integer - the total weight of its maximum spanning tree.

Constraints

1 <= T <= 20
1 <= N <= 5000
1 <= M <= 100 000
1 <= c <= 10 000
Sample Input(Plaintext Link)
 1
3 3
1 2 2
2 3 3
1 3 4
Sample Output(Plaintext Link)
 7

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

int root(vector <int> &v,int i){
	while(v[i] != i){
		v[i] = v[v[i]];
		i = v[i]; 
	}
	return i;
}
void union1(vector <int> &v,int x,int y){
	int root_a = root(v,x);
	int root_b = root(v,y);
	v[root_a] = root_b;
}

int maximum_spanningtree(pair<int,pii > array[],int m,vector <int> &v){
	ll maximumcost = 0;
	for(int i = m-1;i >= 0;i--)
    {
		int cost = array[i].first;
		int x = array[i].second.first;
		int y = array[i].second.second;
		if(root(v,x) != root(v,y)){
			maximumcost += cost;
			union1(v,x,y);
		}
	}
	return maximumcost;
}

int main(){
	int t;
	si(t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		vector <int> v;
		v.clear();
		v.resize(n+1,0);
		for(int i=1;i<=n;i++)
			v[i]=i;

		pair<int,pii > array[m];
		int x,y,z;
		for(int i = 0;i < m;i++){
			scanf("%d %d %d",&x,&y,&z);
			array[i] = mp(z,mp(x,y)); 
		}
		sort(array,array+m);
		printf("%d\n",maximum_spanningtree(array,m,v));

	}

	return 0;
}