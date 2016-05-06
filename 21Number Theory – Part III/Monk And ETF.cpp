/*Monk And ETF
*/
/*
Monk has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Note:
ETF is an arithmetic function that counts the positive integers less than or equal to N that are relatively prime to N. To learn more about ETF, click here.

Input:
The first line contains the number of test cases i.e. T.
The next T lines will contain three integers L, R and K.

Output:
Print the answer in a new line after rounding off the first 6 digits after the decimal place.

Constraints:
1 <= T <= 10
1 <= L <= R <= 1012
0 <= R - L <= 105
1 <= K <= 106

Sample Input(Plaintext Link)
 3
1 4 2
2 5 2
3 10 4
Sample Output(Plaintext Link)
 0.500000
0.750000
0.375000
Explanation
In Case 1:
ETF values of numbers from 1 to 4 are - 1, 1, 2, 2. Probability that ETF value is divisible by 2 is (2/4) = 0.5
In Case 2:
ETF values of numbers from 2 to 5 are - 1, 2, 2, 4. Probability that ETF value is divisible by 2 is (3/4) = 0.75
In Case 3:
ETF values of numbers from 3 to 10 are - 2, 2, 4, 2, 6, 4, 6, 4. Probability that ETF value is divisible by 4 is (3/8) = 0.375
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
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) {
        res -= res / n;
    }
    return res;
}
int main(){ 
	int t;
	si(t);
	while(t--){
		ll l ,r ,k;
		scanf("%lld %lld %lld",&l,&r,&k);
		
		ll count  = 0;
		for(int i = l;i <=r;i++){
			if(phi(i) % k == 0)
				count++;
		}
		float prob  = (float)count / (float)(r-l+1);
		printf("%.6f\n",prob);
		
	}
	return 0;
}