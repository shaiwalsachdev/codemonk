/*You are given an array A of size N, and Q queries to deal with. For each query, you are given an integer X, and you're supposed to find out if X is present in the array A or not.

Input:
The first line contains two integers, N and Q, denoting the size of array A and number of queries. The second line contains N space separated integers, denoting the array of elements Ai. The next Q lines contain a single integer X per line.

Output:
For each query, print YES if the X is in the array, otherwise print NO.

Constraints:
1 <= N, Q <= 105
1 <= Ai <= 109
1 <= X <= 109

Sample Input(Plaintext Link)
 5 10
50 40 30 20 10
10
20
30
40
50
60
70
80
90
100
Sample Output(Plaintext Link)
 YES
YES
YES
YES
YES
NO
NO
NO
NO
NO
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

	int N;
	int Q;
	scanf("%d %d", &N,&Q);
	vector<int> v;
	v.clear();
	v.resize(N);
	for(int i = 0;i < N;i++){
		si(v[i]);
	}
	
    sort(v.begin(),v.end());
    int item;
    for(int i = 1;i <= Q;i++){
    	si(item);
    	if(binary_search(v.begin(),v.end(),item))
    		pm("YES");
    	else
    		pm("NO");
    }
	
	return 0;
}