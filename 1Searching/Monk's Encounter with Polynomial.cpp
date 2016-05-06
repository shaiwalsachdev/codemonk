/*Our monk, while taking a stroll in the park, stumped upon a polynomial ( A X2 + B X +C ) lying on the ground. The polynomial was dying! Being considerate, our monk tried to talk and revive the polynomial. The polynomial said: 
I have served my purpose, and shall not live anymore. Please fulfill my dying wish. Find me the least non-negative integer Xo, that shall make my value atleast K i.e., A Xo2 + B Xo + C >= K . 

Help our Monk fulfill the polynomial's dying wish!


Input: 
The first line contains an integer T. T test cases follow. 
Each test case consists of four space-separated integers A, B, C and K. 

Output:
For each test case, output the answer in a new line.

Constraints:
1 ≤ T ≤ 105
1 ≤ A,B,C ≤ 105
1 ≤ K ≤ 1010

Sample Input(Plaintext Link)
 3
3 4 5 6
3 4 5 5
3 4 5 150
Sample Output(Plaintext Link)
 1
0
7
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
ll binsearch(ll left,ll right,ll a,ll b,ll c,ll k){
	while(left<right){
		ll mid = (left +right)/2;
		ll h = a*mid*mid+b*mid + c;
		if(h>=k)
			right = mid;
		else 
			left = mid + 1;
	}
	return right;
}


int main(){
	ll t,a,b,c,k;
	sl(t);
	
	while(t--){
		scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
		printf("%lld\n", binsearch(0,1e5,a,b,c,k));
	}

}

