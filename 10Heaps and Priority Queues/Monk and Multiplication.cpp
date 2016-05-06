/*
The Monk learned about priority queues recently and asked his teacher for an interesting problem. 
So his teacher came up with a simple problem. He now has an integer array A. 
For each index i, he wants to find the product of the largest, 
second largest and the third largest integer in the range [1,i].
Note: Two numbers can be the same value-wise but they should be distinct index-wise.

Input:
The first line contains an integer N, denoting the number of elements in the array A.
The next line contains N space separated integers, each denoting the ith integer of the array A.

Output:
Print the answer for each index in each line. If there is no second largest or 
third largest number in the array A upto that index, then print "-1", without the quotes.

Constraints:
1 <= N <= 100000
0 <= A[i] <= 1000000

Sample Input(Plaintext Link)
 5
1 2 3 4 5
Sample Output(Plaintext Link)
 -1
-1
6
24
60
Explanation
There are 5 integers 1,2,3,4 and 5.
For the first two indexes, since the number of elements is less than 3, so -1 is printed.
For the third index, the top 3 numbers are 3,2 and 1 whose product is 6.
For the fourth index, the top 3 numbers are 4,3, and 2 whose product is 24.
For the fifth index, the top 3 numbers are 5,4 and 3 whose product is 60.

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
	int n;
	si(n);
	vector<ll> v;
	v.clear();
	v.resize(n);
	for(int i = 0;i < n;i++)
		sl(v[i]);

	priority_queue <ll> pq;
	for(int i = 0;i < n;i++){
		pq.push(v[i]);
		if(pq.size() < 3){
			pm("-1");
		}
		else{
			ll i = pq.top();
			pq.pop();
			ll j = pq.top();
			pq.pop();
			ll k = pq.top();
			pq.pop();
			pq.push(i);
			pq.push(j);
			pq.push(k);
			pl(i*j*k);
			pn;
		}
	}


	return 0;
}