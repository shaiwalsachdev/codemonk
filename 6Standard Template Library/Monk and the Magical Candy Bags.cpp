/*
Our Monk loves candy!
While taking a stroll in the park, he stumbled upon N Bags with candies. 
The i'th of these bags contains Ai candies.
He picks up a bag, eats all the candies in it and drops it on the ground. 
But as soon as he drops the bag, the number of candies in the bag increases magically! 
Say the bag that used to contain X candies (before eating), now contains [X/2] candies! ,
where [x] is the greatest integer less than x (Greatest Integer Function).
Amazed by the magical spell, Monk can now have a lot more candies! 
But he has to return home in K minutes. In a single minute,Monk 
can consume all the candies in a single bag, regardless of the number of candies in it.
Find the maximum number of candies that Monk can consume.

Input:
First line contains an integer T. T test cases follow.
First line of each test case contains two space-separated integers N and K.
Second line of each test case contains N space-separated integers,the number of candies in the bags.

Output:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 105
0 ≤ K ≤ 105
0 ≤ Ai ≤ 1010

Sample Input(Plaintext Link)
 1
5 3
2 1 7 4 2
Sample Output(Plaintext Link)
 14
Explanation
The state of bags is:
2 1 7 4 2
Monk eats all candies from Third bag (7). The state of bags becomes:
2 1 3 4 2 
Monk eats all candies from Fourth bag (4). The state of bags becomes:
2 1 3 2 2
Monk eats all candies from Third bag (3). The state of bags becomes:
2 1 1 2 2 
Hence, the Monk eats 7+4+3= 14

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
	int t;
	si(t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		ll num;
		priority_queue <ll> pq;
		for(int i = 0;i < n;i++){
			sl(num);
			pq.push(num);
		}
		ll sum = 0;
		for(int i = 0;i < k;i++){
			
			ll p = pq.top();
			pq.pop();
			sum += p;
			pq.push((ll)(p/2));

		}
		pl(sum);
		pn;

	}
	return 0;
}