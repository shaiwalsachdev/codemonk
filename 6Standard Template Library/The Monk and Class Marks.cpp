/*
Monk is a multi-talented person, and prepares results for his college in his free time. 
(Yes, he is still in love with his old college!) He gets a list of students with their marks. 
The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in 
decreasing order of marks. And if two students have the same marks, 
they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

Output format:
You must print the required list.

Constraints:
1 <= N <= 105
1 <= | Length of the name | <= 100 
1 <= Marks <= 100

Sample Input(Plaintext Link)
 3
Eve 78
Bob 99
Alice 78
Sample Output(Plaintext Link)
 Bob 99
Alice 78
Eve 78
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


bool compare(const pair<string,int>&i,const pair<string,int>&j){
	if(i.second > j.second)
		return 1;
	else if(i.second == j.second){
		  if(i.first < j.first)
		  	return 1;
		  else
		  	return 0;
		} 
	else
		return 0;
}



int main(){

	vector <pair<string,int> > v;
	int n;
	si(n);
	int flag;
	string flag1;
	for(int i = 0;i < n;i++){
		cin >> flag1;
		si(flag);
		v.push_back(mp(flag1,flag));
	}

	sort(v.begin(),v.end(),compare);
	for(int i = 0;i < n;i++){
		
	}

	for(int i = 0;i < n;i++){
		printf("%s %d\n",v[i].first.c_str(),v[i].second);
	}
	return 0;
}