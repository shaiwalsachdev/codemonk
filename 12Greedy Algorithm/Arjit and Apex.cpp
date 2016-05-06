/*
Arjit, Protector of The Realm, has an important task at hand. 
M new subjects are soon going to become a part of The Realm. 
The Realm, though, already has N subjects who are well skilled 
in the ways of The Realm. He wants the new subjects too to become perfect in the ways.

As any Protector would, Arjit also decides that the existing 
subjects should train the new subjects in the ways. What's so 
special about this situation though? Each current subject of 
The Realm has a special skill Sc and he has reached a level of 
proficiency Pc at this. Every new subject of The Realm feels his 
favourite skill he would like to have is Sn and reach a proficiency Pn at it.

Let's call a current subject Foo and a new subject Bar. 
Foo can train Bar if Foo's special skill is the same one that Bar 
feels is his favourite. This is what we call a good pair.
 If Foo's special skill and Bar's favourite skill are the same and also Foo's 
 proficiency is the same that Bar wants to achieve, we call it a great combination.

Let A be the number of good pairs and B be the number of great combinations. 
Arjit would like to maximize the number of new subjects to be trained by current subjects, 
i.e., number of good pairs. And, after maximizing number the number of good pairs,
 he wishes to maximize the number of great combinations.

Arjit wishes to have at least G good pairs and at least H great combinations.
If only the good pairs criteria is met, print "Good" (without quotes).
If both criterion are met, print "Great" (without quotes).
Else, print ":(" (without quotes).

Input:
The first line of input contains T. T test cases follow.
The first line of each test case has two integers, M and N.
In the following M lines, there are two integers on each line, 
U and V denoting favourite skill and proficiency they wish to obtain.
In the N lines that follow, there are two integers on each line, 
W and X denoting the special skill and the level of proficiency that has been reached.
The last line of each test case has two integers, G and H.

Output:
Print "Good", "Great" or ":(" (without quotes) on a new line for each test case.

Constraints:
1 ≤ T ≤ 10
1 ≤ M, N ≤ 105
1 ≤ U, V, W, X ≤ 104
1 ≤ G, H ≤ 105

See the example to understand better.

Sample Input(Plaintext Link)
 1
2 2
1 1
2 3
1 1
2 3
2 2
Sample Output(Plaintext Link)
 Great
Explanation
You have 2 new subjects and 2 current members of the realm.
Each new member is perfectly matched with an existing member of the realm.
So, good pair count is 2 and great combination count is also 2.
So, the output is "Great" (without quotes).

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
	vector<bool> v,v1;
	int t;
	si(t);
	while(t--){
		int m,n;
		scanf("%d %d",&m,&n);
		v.clear();
		v1.clear();
		v.resize(10001,false);
		v1.resize(10001,false);
		int x,y;
		for(int i = 1;i <= m;i++){
			scanf("%d %d",&x,&y);
			v[x] = true;
			v1[y] = true;
		}
		int count = 0;
		int count1 = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d %d",&x,&y);
			if(v[x]){
				count++;
			}
			if(v[x] && v1[y]){
				count1++;
			}
		}
		int h,g;
		scanf("%d %d",&g,&h);
		if(count == g && count1 == h){
			pm("Great");
		}else if(count == g){
			pm("Good");
		}else {
			pm(":(");
		}

	}
	return 0;
}