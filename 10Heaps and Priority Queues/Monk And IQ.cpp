/*
Monk and his P-1 friends recently joined a college. He finds that N students have already applied for different courses before him. Courses are assigned numbers from 1 to C. He and his friends will follow the following conditions when choosing courses:- 
They will choose the course i (1 <= i <= C), for which the value of z is minimum. 
Here, z = x*c where c is the number of students already enrolled in the course i and 
x is the sum of IQ of the last two students who enrolled in that course. 
If a single student has applied for a course, then the value of x will be that student's IQ.
 If no student has enrolled for that course, then value of x will be 0. If the value of z is same for two courses, then they will choose the course with the minimum course number. You need to find which courses Monk and his friends should take after following the above conditions.
Note: Each of them will choose their courses, one at a time. Monk will choose his course first followed by his friends.

Input:
The first line contains the numbers C, P and N where C denotes the number of courses in that college, P denotes Monk and his friends and N denotes the number of students who have already applied for the courses.
The next line consists of N space separated integers Y[i] which denotes the IQ of the ith student. Here, the ith student chooses the ith course. 
The next line consists of P space separated integers X[i] which denotes the IQ of Monk and his friends.

Output:
Print P space separated integers in a line which denotes the course number which Monk and his friends have applied for.

Constraints:
1 <= C <= 100000
1 <= P <= 100000
1 <= N <= C
1 <= Y[i],X[i] <= 100000

Sample Input(Plaintext Link)
 5 4 4
2 8 5 1
9 10 5 1
Sample Output(Plaintext Link)
 5 4 1 3 
Explanation
In the sample test case, the last course has not been applied by anyone. So, its sum will be 0 initially. Hence, Monk will apply there as the value of z = 0.
Now Monk's first friend will apply for the 4th course as its value of z = 1, which is minimum of all the four courses.
Monk's second friend will apply for the 1st course as its value of z = 2, which is minimum of all the four courses.
Similarly, Monk's third friend will apply for the 3rd course as its value of z = 5, which is minimum of all the four courses.

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


void min_heapify(vector<pair<int,int> > &v,int i,int n){
	int left = 2*i;
	int right = 2*i + 1;
	int smallest = i;
	if(left <=n && v[left].second < v[i].second){
		smallest = left;
	}else if(left <=n && v[left].second == v[i].second){
		if(v[left].first < v[i].first)
			smallest = left;
	}
	
	if(right <=n && v[right].second < v[smallest].second)
		smallest = right;
	else if(right <=n && v[right].second == v[smallest].second){
		if(v[right].first < v[smallest].first)
			smallest = right;
	}

	
	if(smallest!=i){
		int i1 = v[smallest].first;
		int y1 = v[smallest].second;
		int i2 = v[i].first;
		int y2 = v[i].second;
		swap(i1,i2);
		swap(y1,y2);
		v[smallest] = make_pair(i1,y1);
		v[i] = make_pair(i2,y2);
		min_heapify(v,smallest,n);
	}

}


void bulidminheap(vector<pair<int,int> > &v,int n){
	for(int i = n/2;i >= 1;i--){
		min_heapify(v,i,n);
	}
}

int main()
{
	int c,p,n;
	vector<int> x,count;
	scanf("%d %d %d",&c,&p,&n);
	
	x.clear();
	x.resize(p+1,0);
	count.clear();
	count.resize(c+1,0);
	int t;
	vector<pair<int,int> > v;
	vector<int> vv[c+1];
	v.clear();
	v.resize(c+1,make_pair(0,0));
	
	

	for(int i = 1;i <= n;i++){
		si(t);
		count[i]++;
		v[i] = make_pair(i,t);
		vv[i].push_back(t);
	}
	for(int i = n+1;i <= c;i++){
		v[i] = make_pair(i,0);
		count[i] = 0;
	}
	for(int i = 1;i <= p;i++){
		si(x[i]);
	}
	
	bulidminheap(v,c);
	
	for(int i = 1;i <= p;i++){
		int mini = v[1].first;
		printf("%d ",mini);
		vv[mini].push_back(x[i]);
		count[mini]++;
		int newt;
		if(vv[mini].size()==1)
			newt = count[mini]*vv[mini][0];
		else{
			int ii = vv[mini].size()-1;
			int jj = vv[mini].size()-2;
			 newt = count[mini]*(vv[mini][ii] + vv[mini][jj]);
		}
	
		v[1].second = newt;
		
		
 		min_heapify(v,1,c);
 	}
	cout << endl;
 
	return 0;
}