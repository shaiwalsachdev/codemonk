/*Puchi hates to carry luggage, but unfortunately he got a job to carry the luggage of his N friends in office. Each day, one of his N friends, gives him the luggage of a particular weight to carry. You will be given the weight of luggage of each friend in the array Weight, where Weighti is the weight of luggage of ith friend carried by Puchi on ith day. It is given that all the luggages carried by Puchi are distinct in their weights. 
As Prateek assigned this job to Puchi, so for each day, 
he wants to know the number of days in future when Puchi 
will have to carry the luggage , having weight less than the weight of luggage of current day.
Please help Prateek for the same.

Input:
The first line contains a single integer T, denoting the number of test cases. In each test case, the following input will be present: 
First line contains an integer N, where N represents the number of friends.
Next N line contains N integers, where ith line contains ith integer, which represents Weighti.

Output:
Output exactly T lines. Each line contains N integer separated by a space, where ith integer represents the number of luggage of future, which are less than the weight of luggage of the current day.

Constraints:

Subtask 1:
1 <= T <= 30
1<= N <= 104
1<= Weighti <= 106 
Subtask 2:
1 <= T <= 10
1<= N <= 105
1<= Weighti <= 106

Sample Input(Plaintext Link)
 1
4
2
1
4
3
Sample Output(Plaintext Link)
 1 0 1 0
Explanation
In sample input, given T =1 in first line and N = 4 in next line. In next 4 lines, Weighti i.e weight of luggage of each friend on ith day is given.

For weight on first day i.e 2 ,future weights smaller than 2 are {1} . Therefore output for this weight will be 1.
For weight on second day i.e 1, no future weights are smaller than 1. So output for this weight will be 0.
For weight on third day i.e 4, future weights smaller than 4 are {3}. So output for this weight will be 1.
For weight on fourth day i.e 3, no future weights are smaller than 3. So output for this weight will be 0.
So the final output is {1, 0, 1, 0}.

*/
/*Puchi and Luggage - Editorial

Author: Prateek Garg
Tester: Pulkit Mendiratta
Editorialist: Prateek Garg

Difficulty: Easy-Medium

Pre-Requisites: Merge Sort, Inversion.
Please refer to the Author's Solution for the Editorial. 
This problem is based on Merge Sort. (Refer to Sorting - Code Monk) 
The objective of the problem is finding the number of Inversions for each element in the given array. 
(Refer to Inversions)

Problem: Find the number of inversions for each element using merge sort.

Explanation:

The procedure is same as Merge Sort Algorithm, with a few changes made in the merge() function.
Merge Sort makes recursive calls to arrays of half the size,that are sorted individually and merged. 
While merging the arrays, we can check if a number in the left array i.e 
Weightp is greater than a number in the right i.e Weightq and contributes to the count of inversions. In such a case, all the remaining numbers in the left array after Weightp are also greater than Weightq (as the arrays are sorted) and contribute to the count of inversions. 

Also note that, we exploit the fact here that all the numbers are Distinct. 
Hence, we can hash the positions of each number i.e. 
the array Frequency[ i ] stores the position of a number i in 
the initial array Weight. Hence, when we encounter an inversion , 
we trace the position in the array where the element is present and 
increment its contribution to the overall inversion count.
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

const int MAX1 = 1000005;

int Frequency[MAX1]; // Like a Hash Map 

ll inv;

void merge(vector <int> &weight,int start,int mid,int end)
{
    int p=start;
    int q=mid+1;
    int k=0;
    int counter = 0;
    vector <int> Arr;
    Arr.clear();
    Arr.resize(end-start+1);
    for(int i=start;i<=end;i++)
    {
        if(p>mid)
        {
            Arr[k++] = weight[q++];
        }
        else if(q>end)
        {
            Arr[k++] = weight[p];
            Frequency[weight[p]] += counter;
            p++;
        }
        else if(weight[p] <= weight[q])
        {
            Arr[k++] = weight[p];
            Frequency[weight[p]] += counter;
            p++;
        }
        else
        {
            Arr[k++] = weight[q++];
            inv += mid-p+1;
            counter++;
        }
    }
    for(int i=0;i<k;i++)
    {
        weight[start++] = Arr[i];
    }
}
void merge_sort(vector <int> &weight,int left,int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        merge_sort(weight,left,mid);
        merge_sort(weight,mid+1,right);
        merge(weight,left,mid,right);
    }
}


int main(){
	
	int t;
	si(t);
	while(t--){
		vector<int> weight,copied;
		int N;
		si(N);
		weight.clear();
		copied.clear();
		weight.resize(N);
		copied.resize(N);

		for(int i = 0;i<MAX1;i++)
			Frequency[i] = 0;

		
		for(int i = 0;i < N;i++){
			si(weight[i]);
			copied[i] = weight[i];
		}
		merge_sort(weight,0,N-1);
		for(int i = 0;i < N;i++)
			printf("%d ",Frequency[copied[i]]);
		pn;
		
	}
	return 0;
}