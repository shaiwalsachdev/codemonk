/*
Let's consider some weird country with N cities and M bidirectional roads of 3 types.
It's weird because of some unusual rules about using these roads: 
men can use roads of types 1 and 3 only and women can use roads of types 2 and 3 only.
Please answer the following very interesting question: 
what is maximum number of roads it's possible to destroy that the country 
will be still connected for both men and women? Connected country is country 
where it's possible to travel from any city to any other using existing roads.

Input

The first line contains 2 space-separated integer: N and M. 
Each of the following M lines contain description of one edge: 
three different space-separated integers: a, b and c. a and b are different 
and from 1 to N each and denote numbers of vertices that are connected by this edge. 
c denotes type of this edge.

Output

For each test case output one integer - 
maximal number of roads it's possible to destroy or -1 if the country 
is not connected initially for both men and women.

Constraints

1 <= N <= 1000
1 <= M <= 10 000
1 <= a, b <= N
1 <= c <= 3

Sample Input(Plaintext Link)
5 7
1 2 3
2 3 3
3 4 3
5 3 2
5 4 1
5 2 2
1 5 1

Sample Output(Plaintext Link)
2

Time Limit: 1 sec(s) for each input file.
*/
/***********************EDITORIAL*****************************
This problem can be solved with greedy approach.

Let's look at this problem in a different way - instead of deleting as much edges as possible, we'll try to pick as few as possible (and remove everything else).

We have graph for men and graph for women. Let's call them M-graph and W-graph. Obviously there is no need to add edge which doesn't connect something in any of graphs. Therefore any edge we take will connect two components in W-graph, or in M-graph, or in both (this is possible only for edges of 3rd type). You need to make 2N-2 merges (N-1 in W-graph and N-1 in M-graph). As we noticed, every edge will do either 1 merge or 2 merges (as we said before, if can make 2 merges only if it is edge of type 3 and it merges two components in both W-graph and M-graph at the same time). This leads us to a simple greedy: let's pick as many edges doing 2 merges as possible.

Add all edges of 3rd type which are merging distinct components. This can be done using DSU. Now you can actually find answer already - if you have used K edges of 3rd type, you made 2K merges already, and you'll need 2N-2-2K more merges, and it will take 1 edge per merge now. If you have a task to print edges, not only their number - it can be done by solving M-graph and W-graph in similar way, but starting with our partially connected by edges of 3rd type graphs instead of empty one.

And don't forget to check that original M-graph and W-graph are connected. Solution without this check will give you only 90 points.

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

void initialize(vector <int> &v,int n)
{
	for(int i=1;i<=n;i++)
			v[i]=i;
}
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

int main(){
		int n,m;
		scanf("%d %d",&n,&m);

		vector <int> v;
		v.clear();
		v.resize(n+1,0);
		initialize(v,n);

		
		vector <int> v1;
		v1.clear();
		v1.resize(n+1,0);
		initialize(v1,n);
		int x,y;
		ll z;
		
		ll common = 0;
		ll men = 0;
		ll women = 0;
		ll type3 = 0;
		set <int> M;
		set <int> W;
		for(int i = 0;i < m;i++){
			scanf("%d %d %lld",&x,&y,&z);
		
			int root_a = root(v,x);
			int root_b = root(v,y);
			if(z==3 || z==1){
				M.insert(x);
				M.insert(y);
			}
			if(z==3 || z==2){
				W.insert(x);
				W.insert(y);
			}


			if(z==3){
				if(root_a==root_b){
					type3++;
				}else {
					union1(v,x,y);
					common++;
				}
			}
			if(z==2){
				women++;	
			}
			if(z==1){
				men++;
			}
			
		}
		
		ll ans = type3 + ((men+common)-(n-1))+((women+common)-(n-1));
		if(M.size() != n || W.size() !=n)
			pm("-1");
		else{
			pl(ans);
			pn;
		}
		

	return 0;
}