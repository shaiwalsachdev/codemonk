/*
The statement of this problem is very simple: you are given a non-negative integer X. Whether it's divisible by 41?

Input
The first line contains one integer T - denoting the number of test cases. The following T lines contain 4 integers a[0], a1, c, n each and describe each test case:

Let's consider decimal representation of the number X as an array where a[0] is the leftmost (highest) digit. You are given a[0], a1 and each a[i] for 2 <= i <= n-1 can be found by formula:

a[i] = ( a[i - 1]*c + a[i - 2] ) modulo 10

Output
For each test case output YES if the corresponding integer is divisible by 41 and NO otherwise.

Constraints

T <= 2000
1 <=N <= 50000
0 <= a[0], a1, c < 10
Sample Input(Plaintext Link)
 5
1 4 6 2
4 1 4 2
8 2 1 2
2 8 8 2
1 2 1 3
Sample Output(Plaintext Link)
 NO
YES
YES
NO
YES
Explanation
Numbers: 14, 41, 82, 28, 123.

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
		int a0,a1,c,n;
		scanf("%d %d %d %d",&a0,&a1,&c,&n);
		vector<int> v;
		v.clear();
		v.resize(n);
		v[0] = a0;
		v[1] = a1;
		
		if (n == 1) {
        	if (a0 == 0) {
            	pm("YES");
        	}
        	else {
            	pm("NO");
        	}
        	continue;
    	}
		for(int i = 2;i < n;i++){
			v[i] = c*v[i-1] + v[i-2];
			v[i] = v[i] % 10;
		}
		// Now the number is generated 

		ll curr = v[0]*10 + v[1];
		ll rem = 0;
		for(int i = 2;i < n;i++){
			rem = curr % 41; 
			curr = rem*10 + v[i]; 
		}
		if(curr%41 ==0){
			pm("YES");
			
		}
		else{
			pm("NO");
			
		}
	}
	return 0;
}