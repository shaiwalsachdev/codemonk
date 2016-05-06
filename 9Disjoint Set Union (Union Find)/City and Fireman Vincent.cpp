/*
Fatland is a town with N cities numbered 1, 2, ..., N, 
connected with 2-way roads. Vincent is a villian who wants 
to set the entire town ablaze. For each city, 
there is a certain risk factor E[i] for setting that city ablaze. 
But once a city c is set ablaze, all cities that can be reached from 
c will be set ablaze immediately.

The overall risk factor of setting some number of cities ablaze is 
the sum of the risk factors of setting each of the cities ablaze. 
Vincent's goal is to set the whole town ablaze with minimal risk by
 picking some set of cities to set ablaze. Let M be the minimum risk 
 he takes when setting the entire city ablaze. Calculate the number 
 of ways to pick a set of cities to obtain a risk of M.

Input:

The first line contains an integer N, the number of cities in Fatland.

The second line contains N space-separated integers, the i-th integer 
representing E[i]. (1-based index)

The third line contains an integer K, denoting the number 2-way roads.

Each of the next K lines contains 2 space-separated integers i, j, a road between cities i and j.

Output: Output one integer, W. The number of ways to pick a set of cities to
 obtain a risk of M, so that the entire town is set ablaze is U. W is
  the remainder when U is divided by 109+7=1000000007.

Constraints:

1 <= N <= 103

1 <= K <= 103

1 <= E[i] <= 103

Sample Input(Plaintext Link)
4
3 3 3 3
2
1 2
4 1
Sample Output(Plaintext Link)
 3
Explanation
Vincent can set cities 1 and 3 ablaze, 2 and 3 ablaze, or 4 and 3 ablaze for a risk of 6. Note that setting either 1, 2, 4 ablaze will set 1, 2, and 4 ablaze.

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
ll mod = 1e7+9;


int root(vector <ll> &v,int i)
{
    while(v[ i ] != i)           //chase parent of current element until it reaches root.
    {
    	v[i] = v[v[i]];
    	i = v[ i ];
    }
    return i;
}

void union1(vector <ll> &v,vector <ll> &size,int a ,int b)
{
    int root_a = root(v,a);       
    int root_b = root(v,b);  
    if(size[a]<=size[b]){
		v[root_a] = v[root_b];
		size[root_b]+= size[root_a];
	}
	else{
		v[root_b] = v[root_a];
		size[root_a]+= size[root_b];
	}

}
int main(){
	int n,k;
	ll x,y;
	si(n);
	vector <ll> values;
	vector <ll> v;
	vector <ll> size;
	v.clear();
	v.resize(n+1);
	size.clear();
	size.resize(n+1);
	values.clear();
	values.resize(n+1);
	
	for(int i = 0;i <= n;i++){
    	v[i] = i ;
    	size[i] = 1;
    }

	for(int i = 1;i <=n;i++){
		sl(values[i]);
	}
	si(k);
	while(k--)
	{
		scanf("%lld %lld",&x,&y);
		union1(v,size,x,y);
	}
	for (int i = 1; i <= n; i++)
		v[i] = root(v,i);

	map <ll,multiset <ll> > mp;
	for(int i = 1;i <= n;i++){
		mp[v[i]].insert(values[i]); 
	
	}
	map <ll,multiset <ll> >:: iterator it;
	multiset <ll>:: iterator it1;
	ll ans = 1;
	ll count = 0;
	for(it=mp.begin();it != mp.end();it++)
    {
    	count = 0;
    	
    	
    	multiset <ll> mp1 = it->second;
    	ll min = *(mp1.begin());
    	for(it1 = mp1.begin();it1 != mp1.end();it1++){
    		int flag = *it1;
    		if(flag>min)
    			break;
    		count++;
    	}
    	ans = (ans*count);
    	ans = ans % mod;
    	
    }
	printf("%lld\n",ans);
	

	return 0;
}