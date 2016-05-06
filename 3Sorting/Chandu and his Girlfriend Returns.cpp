/*In the previous problem Chandu bought some unsorted arrays 
and sorted them (in non-increasing order). 
Now, he has many sorted arrays to give to his girlfriend. But, 
the number of sorted arrays are very large so Chandu decided to 
merge two sorted arrays into one sorted array. But he is too lazy to do that. 
So, he asked your help to merge the two sorted arrays into one sorted array (in non-increasing order).

Input:
First line contains an integer T, denoting the number of test cases.
First line of each test case contains two space separated integers N and M, denoting the size of the two sorted arrays.
Second line of each test case contains N space separated integers, denoting the first sorted array A.
Third line of each test case contains M space separated integers, denoting the second array B.

Output:
For each test case, print (N + M) space separated integer representing the merged array.

Constraints:
1 <= T <= 100
1 <= N, M <= 5*104
0 <= Ai, Bi <= 109

Sample Input(Plaintext Link)
 1
4 5
9 7 5 3
8 6 4 2 0
Sample Output(Plaintext Link)
 9 8 7 6 5 4 3 2 0
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
int N,M;
vector<ll> c;
	

void merge(vector <ll> &a,vector <ll> &b,int N,int M){
	int p = 0;
	int q = 0;
	
    ll k = 0;
    int i = 0;
	while(true){
		    if(p==N || q==M){
		    	break;
		    }
		    if(p<N && q<M){
		       k = max(a[p],b[q]);
		       if(k==a[p])
		       	 p++;
		       else
		       	 q++;
			}
			c[i] = k;
			i++;
	}
	if(p==N){
		for(int j = q;j<M;j++)
			c[i++] = b[j];
	}
	if(q==M){
		for(int j = p;j<N;j++)
			c[i++] = a[j];
	}
}


int main(){

    vector<ll> a,b;
    int t;
    si(t);
    while(t--){
    	scanf("%d %d",&N,&M);
    	a.clear();
    	b.clear();
    	a.resize(N);
    	b.resize(M);
    	c.clear();
        c.resize(N+M);
    	for(int i=0;i<N;i++)
    		sl(a[i]);
    	for(int i=0;i<M;i++)
    		sl(b[i]);

    	merge(a,b,N,M);
    	for(int i=0;i<(N+M);i++)
		printf("%lld ",c[i]);
		pn;
    	
    }
	return 0;
}