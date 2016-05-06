/*
Tanmay is a legendary spammer - everyone in the spamming world knows and 
admires his abilities to spam anyone, anytime, anywhere. 
He decided to guide one of his mentors, named Arjit, as part of the Apex body of spamming.

Tanmay has no doubts on his skills of teaching and making his mentor, Arjit, 
learn about the art of spamming. But, he surely has serious doubt on Arjit's skills of learning, 
implementing and executing whatever he has decided to teach him as part of the syllabus of spamming.

Tanmay has sent Arjit to test his skills, 
but he's getting extremely anxious about the performance of his mentee. 
So, to calm himself down he asks you to help him 
find out the maximum and the minimum productivity attained by Arjit in his travel.

Arjit has the option to visit N Facebook groups - 
where every Facebook group has some potential which can be negative,
zero or positive. Now, he can decide to visit a group if he wants to or not. 
(Depending on the lessons taught to him by the great master!) 
The total productivity attained by Arjit is the product of all the groups he decides to visit.

Given the values of all the groups, 
find out the maximum and minimum spamming potential he can achieve and 
let Tanmay know about it, so that he calm himself down.

Input format:
The first line contains an integer, T, denoting the number of test cases. 
Each line of the test case contains an integer, N, denoting the size of the array.
 The next line contains N integers, denoting the value of the numbers in the array.

Output format:
Print the maximum product you can obtain followed by the minimum product. 
A space separates both these outputs. Answer to each test case is on a new line.

Constraints:
1 ≤ T ≤ 500
1 ≤ N ≤ 18
-10 ≤ Ni ≤ 10

Note:
In some cases only one element may be considered for minimum or maximum product.
If the array is (1, 2, 3), minimum product is 1 whereas maximum product is 6.
When the array is (-1, -2), minimum product is -2 whereas maximum product is 2.

Sample Input(Plaintext Link)
 2
4
1 0 2 10
3
0 0 0
Sample Output(Plaintext Link)
 20 0
0 0
Explanation
In the first test case, the maximum product is the product of all the numbers except 0, 
whereas the minimum product is the product of all numbers including 0.
In the second test case, the maximum and minimum product both are 0 as 0 is the only available number.

Time Limit: 1 sec(s) for each input 
*/

/*
................Editorial................
We are given an array. Let's call it A. We have two aims:
1. Obtain maximum product.
2. Obtain minimum product.

For minimum product, we have two cases:
1. When the smallest number in A is ≥ 0. In this case, the minimum product is the that number itself, as we are considering single numbers to be minimum products.
2. When the smallest number in A is ≤ 0. In this case, the minimum product would be the product of the smallest odd number of negative numbers. 
This way the product is always negative and magnitude is maximized. As a result of this the product is minimized.
If |a| ≥ |b|, but a ≤ 0 and b ≤ 0, then a ≤ b.
Now, we may have some positive numbers in the array. The product of all the positive numbers and product of smallest odd number of negative numbers would give the minimum product.

For maximum product, our answer is the product of smallest even number of negative numbers and all positive numbers. Handling cases where 0 is the answer is an exercise left to the reader :)
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

int main()
{
	int t;
	si(t);
	while(t--){
		vector <int> v;
		int n;
		int positive = 0;
		int negative = 0;
		int zeros = 0;
		si(n);
		v.clear();
		v.resize(n);
		int t;
		for(int i = 0;i < n;i++){
			si(t);
			if(t > 0)
				positive++;
			else if(t < 0)
				negative++;
			else
				zeros++;

			v[i] = t;
		}
		sort(v.begin(),v.end());
		ll minpro = 1;
		ll maxpro = 1;
		// Odd Number of negatives
		if(negative % 2 ==1){
			// MaxProduct
			// if only one negative number then we get Maxproduct
			if(negative ==1 && positive ==0){
				if(zeros>0)
					maxpro = 0;
				else
					maxpro = v[0];
			}else {

				for(int i = 0;i < negative-1;i++){
					maxpro = v[i]*maxpro;
				}
				for(int j = negative;j < n;j++){
					if(v[j]!=0)
						maxpro = v[j]*maxpro;
				}
			}
			for(int i = 0;i < n;i++){
				if(v[i]!=0)
					minpro = minpro*v[i];
			}

		}else{
			if(negative == 0){
				if(zeros ==0){
					minpro = v[0];
					for(int i = 0;i < n;i++)
						maxpro = maxpro*v[i];
			
				}else if(zeros > 0){
					minpro = 0;
					if(positive==0)
						maxpro=0;
					else{
						for(int i = 0;i < n;i++){
							if(v[i]!=0)
								maxpro = maxpro*v[i];
						}
					}
				}

			}else {
				 if(positive==0){
				 	
				 	for(int i=0;i<negative-1;i++)
						minpro=v[i]*minpro;
					
					for(int i=0;i<negative;i++)
					
						maxpro=v[i]*maxpro;
					
				 }else{
				 		for(int i = 0;i < n;i++){
							if(v[i]!=0)
								maxpro = maxpro*v[i];
						}
						for(int i = 0;i < negative-1;i++){
							minpro = v[i]*minpro;
						}
						for(int j = negative;j < n;j++){
							if(v[j]!=0)
								minpro = v[j]*minpro;
						}

				 }
			}
		}
		printf("%lld %lld\n",maxpro,minpro);
	}
	return 0;
}