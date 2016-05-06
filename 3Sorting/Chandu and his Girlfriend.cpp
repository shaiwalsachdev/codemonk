/*
Chandu's girlfriend loves arrays that are sorted in non-increasing order. 
Today is her birthday. Chandu wants to give her some sorted arrays on her birthday. 
But the shop has only unsorted arrays.
 So, Chandu bought T unsorted arrays and is trying to sort them. 
 But, he doesn't have much time to sort the arrays manually 
 as he is getting late for the birthday party. 
 So, he asked you to write a program to sort the T arrays in non-increasing order. 
 Help him, or his girlfriend will kill him.

Input:
First line contains an integer T, denoting the number of test cases.
First line of each test case contains an integer N, denoting the size of the array.
Second line contains N space separated integers, denoting the array elements Ai.

Output: 
For each test case, print the sorted array in non-increasing order.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= Ai <= 109

Sample Input(Plaintext Link)
 2
5
2 5 2 4 3
5
5 4 2 3 1
Sample Output(Plaintext Link)
 5 4 3 2 2
5 4 3 2 1

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

int partition(vector <ll> &A,int start,int end){
	int pivot = A[start];
	int i = start + 1;
	for(int j = start + 1;j<=end;j++){
		if(A[j] > pivot){
			swap(A[i],A[j]);

			i++;
		}
	}
	swap(A[start],A[i-1]);

	return i-1;
}

int rand_pivot(vector <ll> &A,int start,int end){
	int random = start + rand()%(end-start+1);
	swap(A[random],A[start]);
	return partition(A,start,end);
}
void quick_sort(vector <ll> &A,int start,int end){
	if(start < end){
		int pivot = rand_pivot(A,start,end);

		quick_sort(A,start,pivot-1);
		quick_sort(A,pivot+1,end);
	}
}

int main(){
	int t;
	vector <ll> v;
	si(t);
	while(t--){
		ll N;
		sl(N);
		v.clear();
		v.resize(N);
		for(int i = 0;i < N;i++)
			sl(v[i]);
		quick_sort(v,0,N-1);
		for(int i = 0;i < N;i++){
			pl(v[i]);
			printf(" ");
		}
		pn;
	}
}