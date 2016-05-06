/*
Our monk loves food. Hence,he took up position of a manager at Sagar,a restaurant that serves people with delicious food packages. It is a very famous place and people are always queuing up to have one of those packages. Each package has a cost associated with it. The packages are kept as a pile. The job of a manager is very difficult. He needs to handle two types of queries:

1) Customer Query:
When a customer demands a package, the food package on the top of the pile is given and the customer is charged according to the cost of the package. This reduces the height of the pile by 1. 
In case the pile is empty, the customer goes away empty-handed.

2) Chef Query:
The chef prepares a food package and adds it on top of the pile. And reports the cost of the package to the Manager.
Help him manage the process.

Input:
First line contains an integer Q, the number of queries. Q lines follow.
A Type-1 ( Customer) Query, is indicated by a single integer 1 in the line.
A Type-2 ( Chef) Query, is indicated by two space separated integers 2 and C (cost of the package prepared) .

Output:
For each Type-1 Query, output the price that customer has to pay i.e. cost of the package given to the customer in a new line. If the pile is empty, print "No Food" (without the quotes).

Constraints:
1 ≤ Q ≤ 105
1 ≤ C ≤ 107

Sample Input(Plaintext Link)
 6
1
2 5
2 7
2 9
1
1
Sample Output(Plaintext Link)
 No Food
9
7
Explanation
Initially, The pile is empty.
Chef adds a package with cost=5.
Chef adds a package with cost=7.
Chef adds a package with cost=9.
Customer takes the package on the top i.e. cost=9. Now package of cost=7 on top. Customer takes the package on the top i.e. cost=7.

Time Limit: 5 sec(s) for each input file.
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
	int Q;
	si(Q);
	stack <int> st;
	while(Q--){
		int qnumber,cost;
		si(qnumber);
		if(qnumber == 1)
		{
			if(st.empty())
				pm("No Food");
			else{
				pi(st.top());
				pn;
				st.pop();
			}
		}else{
			si(cost);
			st.push(cost);
		}

	}
	return 0;

}