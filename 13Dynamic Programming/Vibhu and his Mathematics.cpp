/*
Vibhu and his Mathematics

In code world all genders are considered equal 
( It means their is nothing like male or female). 
Now their are N distinct persons living in this hypothetical world. 
Each person can pair up with any other person or can even remain single. 
One day Vbhu planned to visit code world. Being a maths guy , 
he always try to be mathematical. So he started counting 
the ways in which N persons living in code world can make pairs or remain single. 
A single person can make pair with at most one other person.
Seeing that N can be large , Vibhu ask you for help. 
Now being a great programmer you need to help 
Vbhu count the number of ways in which N persons 
living in code world can make pairs or remain single.

Note : Its not necessary that everyone is required 
to make pair with someone. Person can remain single also.

Input Format : 
First line contain number of test cases T. 
Then next T lines contain a single integer N , 
denoting the number of persons living in code world.

Output Format : 
You need to print the number of ways in which 
N different persons can make their pairs or stay single.
 As answer can be large so print it modulo 109+7.

Constraints :
1 <= T <=105 
1 <= N <=106

Warning: Large Input/Output data, be careful with certain languages

Sample Input(Plaintext Link)
 2
2
3

Sample Output(Plaintext Link)
 2
4

Explanation
In first test case , For N=2 answer will be 2. 
Possible ways are : {1},{2} (It means Person 1 and 
Person 2 are single) {1,2} (It means Person 1 and Person 2 had formed a pair)

For second test case , For N=3 , answer will be 4. 
Possible ways are : {1},{2},{3} 
(It means all three Persons are single) {1,2},{3} (It means Person 1 and 
Person 2 had formed a pair and Person 3 is single) {1},{2,3} 
(It means Person 2 and Person 3 had formed a pair and Person 1 is single) 
{1,3},{2} (It means Person 1 and Person 3 had formed a pair and Person 2 is single)

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
#define MAX 1000001
#define MOD 1000000007
int main(){
	
	int t;
	si(t);
	ll array[MAX] = {0};

	array[0] = 1;
	array[1] = 1;

	for(int i = 2;i <MAX;i++){
		array[i] = array[i-1] + (i-1)*array[i-2];
		array[i] = array[i] % MOD;
	}

	while(t--){
		int q;
		si(q);
		pl(array[q]);
		pn;
	}

	return 0;
}