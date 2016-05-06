/*
Monk was asked to answer some queries in an interview. He is given an empty array A. Queries are of 4 types:-
1. 1 X - Add number X to the array A.
2. 2 X - Remove a single instance of number X from the array A. If not possible, print "-1" without the quotes.
3. 3 - Find the maximum element in the array A.
4. 4 - Find the minimum element in the array A.

Input:
The first line contains the integer Q.
The next Q lines will each contain a query like the ones mentioned above.

Output: 
For queries 3 and 4, print the answer in a new line. If the array is empty for query 3 and 4, then print "-1" without the quotes.

Constraints:
1 <= Q <= 100000
1 <= X <= 100000

Sample Input(Plaintext Link)
 5
1 5
1 9
1 6
3
2 1
Sample Output(Plaintext Link)
 9
-1
Explanation
There are 5 queries.
Query 1 - 5 is added to the array.
Query 2 - 9 is added to the array.
Query 3 - 6 is added to the array.
Query 4 - The maximum element in the array is 9.
Query 5 - Since there is no element in the array with value 1, so the output is -1.

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
 
	priority_queue <int> pqmax,pqmin,temp;
	vector<int> v(100001,false);
	int q;
	si(q);
	while(q--){	
		int x;
		int y;
		si(x);
		if(x==1){
			si(y);
			v[y]++;
			pqmax.push(y);
			pqmin.push(-1*y);
		}else if(x==2){
			si(y);
			if(v[y] > 0)
				v[y]--;
			else
				printf("-1\n");
			
		}else if(x==3){
			while(pqmax.size() && v[pqmax.top()]==0)
				pqmax.pop();
			if(pqmax.size())
				printf("%d\n",pqmax.top());
			else
				printf("-1\n");
		}else{
			while(pqmin.size() && v[pqmin.top()*-1]==0)
				pqmin.pop();
			if(pqmin.size())
				printf("%d\n",(pqmin.top()*-1));
			else
				printf("-1\n");
		}
	}
	return 0;
}