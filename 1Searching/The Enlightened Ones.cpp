/*
There are N temples in a straight line and K monks who want to spread their enlightening power to the entire road of temples. All the monks have an enlightenment value, which denotes the range of enlightenment which they can spread in both the directions. Since, they do not want to waste their efficiency on trivial things of the world, they want to keep their range minimum.

Also, when we say that the N temples are in a straight line, we mean that that all the temples lie on something like an X-axis in a graph.

Find the minimum enlightenment value such that all the temples can receive it.

Input Format:
The first line contains two integers, N and K - denoting the number of temples and number of monks. The next line contains N integers denoting the position of the temples in the straight line.

Output format:
Print the answer in a new line.

Constraints:
1 <= N <= 105
1 <= K < N 
1 <= Positioni <= 107

Update: 
The enlightenment value is an integer.

Sample Input(Plaintext Link)
 3 2
1 5 20
Sample Output(Plaintext Link)
 2
Explanation
The optimal answer is 2. A monk positioned at 3, can serve temples at 1 and 5. The other monk can be placed at 18, to serve temple at 20.
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

vector <ll> v;

bool check(ll mid,int k){
	ll monk = v[0] + mid;
	k--;
	
	for(int i = 1;i < v.size();i++){
		if(monk + mid >= v[i])
			continue;
		if(k == 0)
			return false;

		monk = v[i] + mid;
		k--;
	}
	
	return true;
}

int main()
{
  int n,k;

  scanf("%d %d",&n,&k);

  v.clear();
  v.resize(n);

  for(int i = 0;i < n;i++){
  	 sl(v[i]);
  }

  sort(v.begin(),v.end());
  
  ll left = 0 ;
  ll right = 1e7;
  ll mid = 0;
  while(left<=right){
  	mid = (left+right)/2; 
  	bool a = check(mid,k);
  	bool b = check(mid-1,k);
  	if(a & b)
  		right = mid - 1;
  	if(a & !b)
  		break;
  	if(!a & !b)
  		left = mid + 1;
  }
   
   pl(mid);
   pn;

  return 0;
}