/*
It is very important to understand relationship between variables to draw the right conclusion from a statistical analysis. The relationship between variables determines how the right conclusions are reached. Without an understanding of this, you can fall into many pitfalls that accompany statistical analysis and infer wrong results from your data.

Linear programming (LP; also called linear optimization) is a method to achieve the best outcome (such as maximum profit or lowest cost) in a mathematical model whose requirements are represented by linear relationships. More formally, linear programming is a technique for the optimization of a linear objective function, subject to linear equality and linear inequality constraints.

We are not going to present some LP theory, but let's have a look at combinatorial problem related to this theory. Suppose you have a set of N variables. There are M relationships of some pairs of these variables. More formally, you have M relationships of type ai, bi, ci which means that variables ai and bi are in a relationship with quantitative coefficient ci. Quantitative coefficient of a connected set S of variables is a product of all relationship quantitative coefficients in this set.

Set S of variables is called connected if any two variables in this set are connected. Variables x and y are called connected if at least one of the following conditions is satisfied:

x and y are put in relationship directly
there is such a variable z that x and z are connected and y and z are connected too.
You are given a connected set S of N variables and M relationships. Your task is to leave some of these relationships in such a way that S is still connected and its quantitative coefficient is minimal possible.

Input

The first line contains one integer T denoting the number of test cases.
Each test case starts with a line containing 2 space-separated integer: N and M. Each of the following M lines contain description of one relationship: three different space-separated integers: a, b and c. a and b are different and from 1 to N each and denote numbers of vertices that are connected by this edge. c denotes quantitative coefficient of this relationship. It's guaranteed that the given set is initially connected.

Output

For each test case output one integer - minimal possible quantitative coefficient. As the the answer can be very big output it modulo 109 + 7.

Constraints

1 <= T <= 20
1 <= N <= 1500
1 <= M <= 31313
1 <= ai, bi <= N
1 <= ci <= 109
Sample Input(Plaintext Link)
 1
3 3
1 2 1234567
2 3 2345678
1 3 3456789

Sample Output(Plaintext Link)
 896631161
Time Limit: 5 sec(s) for each input file.

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
ll mod = 1e9 + 7;
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

ll minimumproduct_spanningtree(pair<ll,pii > array[],int m,vector <int> &v){
	ll minimumcost = 1;
	for(int i = 0;i <= m-1;i++)
    {
		ll cost = array[i].first;
		int x = array[i].second.first;
		int y = array[i].second.second;
		
		if(root(v,x) != root(v,y)){
			
			minimumcost *= cost;
			minimumcost = minimumcost %mod;
			union1(v,x,y);
		}
	}
	return minimumcost;
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

		pair<ll,pii > array[m];
		int x,y;
		ll z;
		for(int i = 0;i < m;i++){
			scanf("%d %d %lld",&x,&y,&z);
			array[i] = mp(z,mp(x,y)); 
		}
		sort(array,array+m);
		printf("%lld\n",minimumproduct_spanningtree(array,m,v));

	}

	return 0;
}